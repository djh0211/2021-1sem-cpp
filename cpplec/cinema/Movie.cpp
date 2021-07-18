//
//  Movie.cpp
//  cpplec
//
//  Created by 하동준 on 2021/04/09.
//

#include "Movie.hpp"
#include "txt_read.hpp"
#include <iostream>

Movie::Movie(int count, txt_read txtread){
    
    m_name = txtread.name[count];
    m_row = stoi(txtread.rc[count*2]);
    m_col = stoi(txtread.rc[count*2+1]);
    limit = m_row * m_col;
    seats = new int* [m_row];
    reservationnum = new int* [m_row];
    

    for(int i=0; i<m_row; i++){
        seats[i] = new int [m_col];
    }
    for(int i=0; i<m_row; i++){
        reservationnum[i] = new int [m_col];
    }
        
    for(int i=0;i<m_row;i++){
        for(int j=0;j<m_col;j++){
            seats[i][j]=0;
        }
    }
    for(int i=0;i<m_row;i++){
        for(int j=0;j<m_col;j++){
            reservationnum[i][j]=0;
        }
    }
}

Movie::Movie(const Movie& A){
    m_name = A.m_name;
    m_row = A.m_row;
    m_col = A.m_col;
    limit = A.limit;
    reserve = A.reserve;

    seats = A.seats;
    reservationnum = A.reservationnum;
    
   
}

Movie::Movie(Movie&& A) noexcept
    : m_name(A.m_name), m_row(A.m_row), m_col(A.m_col), seats(move(A.seats)), reservationnum(move(A.reservationnum)), limit(A.limit), reserve(A.reserve){
        A.seats = nullptr;
        A.reservationnum = nullptr;
        A.limit = 0;
        A.reserve = 0;
        if(seats !=nullptr){
            
            for(int i=0; i<this->m_row; i++){
                delete [] seats[i];
            }
            
            delete [] seats;
            seats = nullptr;
            
        }
        if(reservationnum !=nullptr){
            
            for(int i=0; i<this->m_row; i++){
                delete [] reservationnum[i];
            }
            
            delete [] reservationnum;
            reservationnum = nullptr;
            
        }
}


Movie::~Movie(){
    if(this->seats !=nullptr){
        cout<<"=========================="<<endl;

        for(int i=0; i<this->m_row; i++){
            delete[] this->seats[i];
            cout<<i<<"번째 행 삭제"<<endl;
        }
        
        
        delete[] this->seats;
        seats = nullptr;
        if(seats == nullptr){
            cout<<"seats 메모리정리완료"<<endl;
        }
    }
    if(reservationnum !=nullptr){

        for(int i=0; i<this->m_row; i++){
            delete[] this->reservationnum[i];
            cout<<i<<"번째 행 삭제"<<endl;

        }

        delete[] this->reservationnum;
        reservationnum = nullptr;
        if(reservationnum == nullptr){
            cout<<"reservationnum 메모리정리완료"<<endl;
        }
    }
    cout<<"movie 객체가 소멸됩니다."<<endl;

}
int Movie::getcol(){
    return m_col;
}

int Movie::getrow(){
    return m_row;

}
string Movie::getname(){
    return m_name;
}
int** Movie::getseats(){
    return seats;
}
int** Movie::getreservationnum(){
    return reservationnum;
}
int Movie::getlimit(){
    return limit;
}
int Movie::getreserve(){
    return reserve;
}
void Movie::plusreserve(){
    reserve++;
}
void Movie::minusreserve(){
    reserve--;
}
