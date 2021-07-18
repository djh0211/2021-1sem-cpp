//
// Created by 하동준 on 2021/03/11.
//
#include "myheader/djh.h"
#include <iostream>

using namespace std;

int main(){
    djh::printName();

    int grade [5]={10, 5, 8, 20, 12};
    for(size_t i=0; i<5;i++){
        int q=grade[i];
        cout<<"번호 "<<i<<" : ";
        for(size_t j=0;j<q;j++){
            cout<<"*";
        }
        cout<<endl;
    }

    return 0;
}

