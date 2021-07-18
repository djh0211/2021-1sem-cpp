#include <iostream>
#include <string>
#include <fstream>
#include "djh.h"

using namespace std;

int** loadMap(int& row, int& col){
    ifstream fin("testdata.txt");
    if (!fin.is_open()){
        cerr << "파일 오픈 실패";
        exit(0);
    }
    fin >> row >> col;
    int** map = new int* [row];
    for (int i =0; i < row; i++){
        map[i] = new int[col];
    }
    while (!fin.eof()){
        for(int i = 0; i < row;i++){
            for(int j = 0; j < col; j++){
                fin >> map[i][j];
            }
        }
    }
        return map;
}

void showMap(int** (&map), const int row, const int col){
    for(int i = 0; i < row;i++){
        for(int j = 0; j < col; j++){
            cout << (map[i][j]==0?"○":"●");
        }
        cout<<endl;
    }
}
void deleteMap(int** (&map), const int row){
    
    
    
    for(int i = 0; i < row; i++){
        delete[] map[i];
    }
    delete[] map;
    map = nullptr;
    if(map==nullptr){
        cout<<"map 메모리정리완료"<<endl;
    }
}

void saveMap(int** (&map), const int row, const int col){
    ofstream fout("testdata.txt");//덮어쓰기
    if(!fout.is_open()){
        cerr << "파일 오픈 실패";
        exit(0);
    }
    fout << row << " " << col << endl;
    for(int i = 0; i < row;i++){
        for(int j = 0; j < col; j++){
            fout << map[i][j] << " ";
        }
        fout<<endl;
    }
}
int main(){
    djh::printName();
    int row, col;
    int** map = loadMap(row, col);
    if (map != nullptr) {
        showMap(map, row, col);
        cout<<endl;
        map[0][3] = 0;//맵의수정
        showMap(map, row, col);//수정된 맵 출력
        saveMap(map,row,col);//수정사항 txt파일에 반영
        deleteMap(map, row);//메모리정리
    }
    
    return 0;
}
