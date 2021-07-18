#include <iostream>
#include <string>
#include <fstream>
#include "djh.h"

using namespace std;

int main(){
    djh::printName();
    int row, col;
    ifstream fin("testMap.txt");
    if (!fin.is_open()){
        cerr << "파일 오픈 실패";
        exit(0);
    }
    fin >> row >> col;
    auto pnum3= make_unique<unique_ptr<int[]>[]>(row);
    //int** map = new int* [row];
    for (int i =0; i < row; i++){
        pnum3[i] = make_unique<int[]>(col);
        //map[i] = new int[col];
    }
    while (!fin.eof()){
        for(int i = 0; i < row;i++){
            for(int j = 0; j < col; j++){
                fin >> pnum3[i][j];
                //fin >> map[i][j];
            }
        }
    }
   

    if (pnum3 != nullptr) {
        for(int i = 0; i < row;i++){
            for(int j = 0; j < col; j++){
                cout << (pnum3[i][j]==0?"○":"●");
            }
            cout<<endl;
        }        cout<<endl;
        
    }
    
    return 0;
}
