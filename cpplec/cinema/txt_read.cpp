//
//  txt_read.cpp
//  cpplec
//
//  Created by 하동준 on 2021/04/09.
//

#include "txt_read.hpp"
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;


void txt_read::getinfo(){
    
    ifstream fin(address);
    if (!fin.is_open()){
        cerr << "파일 오픈 실패";
        exit(0);
    }
    
    
    string buffer;
    
    getline(fin, buffer);
    movie_num = stoi(buffer);
    name = new string[movie_num];
    rc = new string[movie_num*2];
    
    while (!fin.eof()){
        for(int i = 0; i < movie_num;i++){
            fin >> name[i];
            fin >> rc[i*2] >> rc[i*2+1];
            }
    }
}

txt_read::txt_read(const string & add)
{
    this->address=add;
    getinfo();
}

txt_read::txt_read(const txt_read & txt)
{
    address = txt.address;
    getinfo();
}

txt_read::txt_read(txt_read && txt) noexcept
    : address(txt.address){
        getinfo();
        txt.address = nullptr;
}

txt_read::~txt_read(){
    if(name!=nullptr){
        delete[] name;
        name=nullptr;

    }
    if(rc!=nullptr){
        delete[] rc;
        rc=nullptr;
    }

    
    cout<<"name, rc 메모리 해제."<<endl;
    cout<<"txt_read 객체가 소멸됩니다."<<endl;
}

