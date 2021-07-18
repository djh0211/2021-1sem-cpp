//
//  MovieManager.cpp
//  cpplec
//
//  Created by 하동준 on 2021/04/09.
//

#include "MovieManager.hpp"
#include "Movie.hpp"
#include "txt_read.hpp"
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <term.h>


void MovieManager::showArray(int num){
    for(int i=0; i<movieList[num]->getcol();i++){
        cout << "\t"<<i+1;
    }
    cout<<"\n\n";
    for(int i = 0;i<movieList[num]->getrow(); i++){
        cout << static_cast<char>('A'+i)<<'\t';
        for(int j =0;j<movieList[num]->getcol();j++){
            cout << ((movieList[num]->getseats())[i][j]==0?"○":"●")<<'\t';
        }
        cout<<"\n\n";
    }
    
}

string MovieManager::getf_adress(){
    return f_adress;
}

MovieManager::MovieManager(const string& add ){
    f_adress = add;
    txt_read txtread(add);
    if(count >= txtread.movie_num){
        cout << "추가할 영화가 없습니다.\n"<<endl;
        return;
    }
    movieList = new Movie* [txtread.movie_num];
//    movieList = new Movie* [3];

   
    for(int i=0;i<txtread.movie_num;i++){
        movieList[count] = new Movie(count, txtread);
        count++;
        
    }
}

MovieManager::MovieManager(const MovieManager& A){
    movieList = A.movieList;
    f_adress = A.f_adress;
};

MovieManager::MovieManager(MovieManager&& A) noexcept
: movieList(A.movieList), f_adress(A.f_adress){
    for(int i=0;i<count;i++){
        A.movieList[i]->~Movie();
    }
    if(A.movieList!=nullptr){
        for(int i=0;i<count;i++){
            delete A.movieList[i];
            
        }
        delete [] A.movieList;
        A.movieList = nullptr;
    }
    
}
MovieManager::~MovieManager(){
    if(movieList!=nullptr){
        for(int i=0;i<count;i++){
            movieList[i]->~Movie();
            cout<<i<<" 번째 movie 소멸자(seats배열삭제) 완료"<<endl;

        }

        delete [] movieList;
        movieList = nullptr;
    }
    
    
    if(movieList == nullptr)
        cout<<"MovieManager 메모리 정리 완료"<<endl;
    
}

void MovieManager::make_reservation(int mymovie){
    cout << "========================영화 예매========================"<<endl;
    
    bool boolen = true;
    char a = 'y';
    while(boolen == true){
        this->showArray(mymovie-1);
        char x, y;
        cout<<"예매할 좌석을 선택하세요(ex: A1, B2) : ";
        cin >> x >> y;
        if (0 <= (x - 'A') && (x - 'A') < movieList[mymovie-1]->getrow() && 0 <= (y - '1') && (y - '1') < movieList[mymovie-1]->getcol()) {
            if (movieList[mymovie-1]->getseats()[x - 'A'][y - '1']==1) {
                cout << " 이미 예약된 자리입니다.\n";
                cout<<"계속 예약하시려면 y를, 중단하시려면 그 외 다른 문자를 입력하시오 :";
                cin>>a;
                if(a=='y')
                    boolen = true;
                else boolen = false;
            }
            else {
                movieList[mymovie-1]->getseats()[x - 'A'][y - '1']=1;
                cout << "예약이 완료되었습니다.\n";
                
                movieList[mymovie-1]->plusreserve();
                movieList[mymovie-1]->getreservationnum()[x - 'A'][y - '1']=rand()%1000+1;
                cout<<"예약번호는 "<<movieList[mymovie-1]->getreservationnum()[x - 'A'][y - '1']<<"입니다."<<endl;
                boolen = false;
                
            }
            
        }
        
        else {
            cout<<"없는 좌석입니다." << endl;
            cout<<"계속 예약하시려면 y를, 중단하시려면 그 외 다른 문자를 입력하시오 :";
            cin>>a;
            if(a=='y')
                boolen = true;
            else boolen = false;
            
        }
        
        
    }
}

void MovieManager::cancel_reservation(int resnum){
    bool boolen = false;
    for(int i=0;i<count;i++){
        for(int j=0; j<movieList[i]->getrow(); j++){
            for(int k=0; k<movieList[i]->getcol();k++){
                if(movieList[i]->getreservationnum()[j][k] == resnum){
                    cout << "========================예매 취소========================"<<endl;
                    showArray(i);
                    boolen = true;
                    cout<<"예매를 취소합니다."<<endl;
                    movieList[i]->minusreserve();
                    movieList[i]->getseats()[j][k]=0;
                    movieList[i]->getreservationnum()[j][k]=0;
                    cout<<"========================수정된 좌석========================"<<endl;
                    showArray(i);
                }
                
            }
        }
    }
    if(boolen==false)
        cout<<"예약번호가 존재하지 않습니다.\n";
}

void MovieManager::print_reservation(int resnum){   ///
    bool boolen = false;
    for(int i=0;i<count;i++){
        for(int j=0; j<movieList[i]->getrow(); j++){
            for(int k=0; k<movieList[i]->getcol();k++){
                if(movieList[i]->getreservationnum()[j][k] == resnum){
                    boolen = true;
                    cout<<"예매하신 영화 : "<<movieList[i]->getname()<<endl;
                    cout<<"예매하신 좌석 : "<<('A'+j)<<(k+'1')<<endl;
                    cout<<"=====================영화 예매 좌석======================="<<endl;
                
                    txt_read temp(this->f_adress);
                    Movie temparray(i, temp);
                    temparray.getseats()[j][k]=1;
                    for(int i=0; i<temparray.getcol();i++){
                        cout << "\t"<<i+1;
                    }
                    cout<<"\n\n";
                    for(int i = 0;i<temparray.getrow(); i++){
                        cout << static_cast<char>('A'+i)<<'\t';
                        for(int j =0;j<temparray.getcol();j++){
                            cout << (temparray.getseats()[i][j]==0?"○":"★")<<'\t';
                        }
                        cout<<"\n\n";
                    }

                }
            
                    
            }
        }
    }

    if(boolen==false){
        cout<<"예약번호가 존재하지 않습니다.\n";
        return ;
    }
    
}

void MovieManager::showArray2(int num, int b, int c, Movie temp){
    temp.getseats()[b][c]=1;
    for(int i=0; i<temp.getcol();i++){
        cout << "\t"<<i+1;
    }
    cout<<"\n\n";
    for(int i = 0;i<temp.getrow(); i++){
        cout << static_cast<char>('A'+i)<<'\t';
        for(int j =0;j<temp.getcol();j++){
            cout << (temp.getseats()[i][j]==0?"○":"★")<<'\t';
        }
        cout<<"\n\n";
    }
    cout<<"keepgoing"<<endl;

}

void MovieManager::startmenu(){
    bool status = true;
    while(status==true){
        
        cout << "========================메가박스 센트럴========================"<<endl;
        cout<<"1) 영화 예매  2) 예매 취소  3) 예매 확인  4) 종료"<<endl;
        cout<<"메뉴를 선택하세요 : ";
        int choice;
        cin>>choice;
        
       
        switch(choice){
            case 1:{
                cout << "========================영화 예매========================"<<endl;
                for(int i=0;i<count;i++){
                    cout<<(i+1)<<") "<<this->movieList[i]->getname()<<setw(5)<<(movieList[i]->getlimit())-(movieList[i]->getreserve())<<"/"<<movieList[i]->getlimit()<<endl;
                }
                cout<<"예매할 영화를 선택하세요 : ";
                int mymovie;
                cin>>mymovie;
                if(1<=mymovie && mymovie<=(count)){
                    if(movieList[mymovie-1]->getreserve()<movieList[mymovie-1]->getlimit()){
                        make_reservation(mymovie);

                    }
                    else{
                        cout<<"매진입니다. "<<endl;
                        break;
                    }
                }
                else
                    cout<<"올바른 번호를 입력하세요"<<endl;
                break;
            }
            case 2:{
                cout<<"예약번호를 입력하세요:";
                int resnum;
                cin>>resnum;
                cancel_reservation(resnum);
                break;
            }
            case 3:{
                cout << "========================예약 확인========================"<<endl;
                cout<<"예약번호를 입력하세요:";
                int resnum;
                cin>>resnum;
                print_reservation(resnum);
                break;

            }
            case 4:{
                cout<<"종료합니다. "<<endl;
                return;
                
            }
            default:{
                cout<<"다시 선택해주세요 : "<<endl;
                break;
            }
        }
    }
}



