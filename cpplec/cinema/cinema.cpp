#include <stdio.h>
#include <stdlib.h>
#include "djh.h"
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <unistd.h>
#include <term.h>
#include <iomanip>

using namespace std;


//
int getMovieNumber(){
    ifstream fin("/Users/hadongjun/xcode save/cpplec/cpplec/cinema/movie.txt");
    if (!fin.is_open()){
        cerr << "파일 오픈 실패";
        exit(0);
    }
    
    string buffer;
    
    getline(fin, buffer);
    int num = stoi(buffer);
    
    
    return num;
}
//
int*** makeArray(string* rc, int num){
    int*** array = new int** [num];
    for(int i=0; i<num; i++){
        array[i] = new int* [stoi(rc[2*i])];
        for(int j=0; j<stoi(rc[2*i]); j++){
            array[i][j] = new int [stoi(rc[2*i+1])];
        }
        
    }
    
    for(int i=0;i<num;i++){
        for(int j=0; j<stoi(rc[2*i]); j++){
            for(int k=0; k<stoi(rc[2*i+1]);k++){
                array[i][j][k] = 0;
            }
        }
    }
    return array;
}
//
void loadFile(string* name, string* rc){
    ifstream fin("/Users/hadongjun/xcode save/cpplec/cpplec/cinema/movie.txt");
    if (!fin.is_open()){
        cerr << "파일 오픈 실패";
        exit(0);
    }
    
    string buffer;
    
    getline(fin, buffer);
    int m_num = stoi(buffer);
    
    while (!fin.eof()){
        for(int i = 0; i < m_num;i++){
            fin >> name[i];
            fin >> rc[i*2] >> rc[i*2+1];
            }
    }
}
//
void showArray(int num, string* rc, int***(&array)){
    for(int i=0; i<stoi(rc[2*num+1]);i++){
        cout << "\t"<<i+1;
    }
    cout<<"\n\n";
    for(int i = 0;i<stoi(rc[2*num]); i++){
        cout << static_cast<char>('A'+i)<<'\t';
        for(int j =0;j<stoi(rc[2*num+1]);j++){
            cout << (array[num][i][j]==0?"○":"●")<<'\t';
        }
        cout<<"\n\n";
    }
    
}
//
void make_reservation(int mymovie, int num, int***(&array), int***(&reservation_num), int* reserve, string* rc){
    cout << "========================영화 예매========================"<<endl;
    
    bool boolen = true;
    char a = 'y';
    while(boolen == true){
        showArray(mymovie-1, rc, array);
        char x, y;
        cout<<"예매할 좌석을 선택하세요(ex: A1, B2) : ";
        cin >> x >> y;
        if (0 <= (x - 'A') && (x - 'A') < stoi(rc[(mymovie-1)*2]) && 0 <= (y - '1') && (y - '1') < stoi(rc[(mymovie-1)*2+1])) {
            if (array[mymovie-1][x - 'A'][y - '1']==1) {
                cout << " 이미 예약된 자리입니다.\n";
                cout<<"계속 예약하시려면 y를, 중단하시려면 그 외 다른 문자를 입력하시오 :";
                cin>>a;
                if(a=='y')
                    boolen = true;
                else boolen = false;
            }
            else {
                array[mymovie-1][x - 'A'][y - '1'] = 1;
                cout << "예약이 완료되었습니다.\n";
                reserve[mymovie-1]++;
                reservation_num[mymovie-1][x - 'A'][y - '1']=rand()%1000+1;
                cout<<"예약번호는 "<<reservation_num[mymovie-1][x - 'A'][y - '1']<<"입니다."<<endl;
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
//
void deleteArray(int***(&array), string* rc, int num){
    for(int i=0; i<num; i++){
        for(int j=0; j<stoi(rc[2*i]); j++){
            delete [] array[i][j];
        }
    }
    for(int i=0; i<num; i++){
        delete [] array[i];
    }
    delete [] array;
    array = nullptr;
    if(array == nullptr){
        cout<<"메모리정리완료"<<endl;
    }
}
//
void cancel_reservation(int resnum, int* reserve, int num, string* rc, int***(&array), int***(&reservation_num)){
    bool boolen = false;
    for(int i=0;i<num;i++){
        for(int j=0; j<stoi(rc[2*i]); j++){
            for(int k=0; k<stoi(rc[2*i+1]);k++){
                if(reservation_num[i][j][k] == resnum){
                    cout << "========================예매 취소========================"<<endl;
                    showArray(i, rc, array);
                    boolen = true;
                    cout<<"예매를 취소합니다."<<endl;
                    reserve[i]--;
                    array[i][j][k]=0;
                    reservation_num[i][j][k] = 0;
                    cout<<"========================수정된 좌석========================"<<endl;
                    showArray(i, rc, array);
                }
                
            }
        }
    }
    if(boolen==false)
        cout<<"예약번호가 존재하지 않습니다.\n";
}
//
void showArray2(int num, string* rc, int***(&array), int a, int b, int c){
    array[a][b][c]=1;
    for(int i=0; i<stoi(rc[2*num+1]);i++){
        cout << "\t"<<i+1;
    }
    cout<<"\n\n";
    for(int i = 0;i<stoi(rc[2*num]); i++){
        cout << static_cast<char>('A'+i)<<'\t';
        for(int j =0;j<stoi(rc[2*num+1]);j++){
            cout << (array[num][i][j]==0?"○":"★")<<'\t';
        }
        cout<<"\n\n";
    }
    
}
//
void print_reservation(int resnum, int* reserve, int num, string* rc, int***(&array), int***(&reservation_num), string* name){
        bool boolen = false;
        for(int i=0;i<num;i++){
            for(int j=0; j<stoi(rc[2*i]); j++){
                for(int k=0; k<stoi(rc[2*i+1]);k++){
                    if(reservation_num[i][j][k] == resnum){
                        boolen = true;
                        cout<<"예매하신 영화 : "<<name[i]<<endl;
                        cout<<"예매하신 좌석 : "<<('A'+j)<<(k+'1')<<endl;
                        cout<<"=====================영화 예매 좌석======================="<<endl;
                        int*** temparray = makeArray(rc, num);
                        showArray2(i, rc, temparray, i, j, k);
                        deleteArray(temparray, rc, num);
                    }
                    
                }
            }
        }
        if(boolen==false)
            cout<<"예약번호가 존재하지 않습니다.\n";
}


int main(){
    djh::printName();
    int num = getMovieNumber();
    string* name = new string[num];
    string* rc = new string [num*2];
    loadFile(name, rc);
    
    int*** array = makeArray(rc, num);
    int*** reservation_num = makeArray(rc, num);

    
    int* reserve = new int[num];
    for(int i=0;i<num;i++){
        reserve[i]=0;
    }
    

    bool status = true;
    while(status==true){
        
        cout << "========================메가박스 센트럴========================"<<endl;
        cout<<"1) 영화 예매  2) 예매 취소  3) 예매 확인  4) 종료"<<endl;
        cout<<"메뉴를 선택하세요 : ";
        int choice;
        cin>>choice;
        
        int limit[50] = {0, };
        for(int i=0;i<num;i++){
            limit[i]=stoi(rc[2*i])*stoi(rc[2*i+1]);
        }
        switch(choice){
            case 1:{
                cout << "========================영화 예매========================"<<endl;
                for(int i=0;i<num;i++){
                    cout<<(i+1)<<") "<<name[i]<<setw(5)<<limit[i]-reserve[i]<<"/"<<limit[i]<<endl;
                }
                cout<<"예매할 영화를 선택하세요 : ";
                int mymovie;
                cin>>mymovie;
                if(1<=mymovie && mymovie<=(num)){
                    if(reserve[mymovie-1]<limit[mymovie-1]){
                        make_reservation(mymovie, num, array, reservation_num, reserve, rc);

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
                cancel_reservation(resnum, reserve, num, rc, array, reservation_num);
                break;
            }
            case 3:{
                cout << "========================예약 확인========================"<<endl;
                cout<<"예약번호를 입력하세요:";
                int resnum;
                cin>>resnum;
                print_reservation(resnum, reserve, num, rc, array, reservation_num, name);
                break;

            }
            case 4:{
                cout<<"종료합니다. "<<endl;
                deleteArray(array, rc, num);
                deleteArray(reservation_num, rc, num);
                return 0;
            }
            default:{
                cout<<"다시 선택해주세요 : "<<endl;
                break;
            }
        }
    }
    showArray(0,rc,array);
    
    deleteArray(array, rc, num);
    
    
    
    return 0;
    
}


