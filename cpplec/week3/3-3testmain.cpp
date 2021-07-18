//
//  3-3testmain.cpp
//  cpplec
//
//  Created by 하동준 on 2021/03/17.
//
#include <stdlib.h>
#include <iostream>
#include <string>
#include <malloc/malloc.h>
using namespace std;

int r, c;
int** makeArray(){
    int row, col;
    cout<<"생성하고자 하는 행과 열의 개수를 입력하세요 : ";
    cin>> row >> col;
    int*(*arr)= new int* [row];
    for(int i=0;i<row;i++){
        arr[i] = new int[col];
    }
    r=row;
    c=col;
    return arr;
}

void initArray(int** (&arr)){
    int row = r;
    int col = c;
    int num = 0;
    cout<<row<<col;
    for(int i = 0; i < row; i++){
        for(int j=0 ; j<col ; j++){
            arr[i][j] = num++;
        }
    }
    
    //위치셔플
    for (int i = 0;i < 100; i++){
        int r1 = rand() % row;
        int c1 = rand() % row;
        int r2 = rand() % row;
        int c2 = rand() % row;
        if(r1 != r2 || c1 != c2){
            int temp = arr[r1][c1];
            arr[r1][c1] = arr[r2][c2];
            arr[r2][c2] = temp;
        }
        else
            i--;
    }
}

void printArray(int** (&arr)){
    int row=r;
    int col=c;
    for(int i = 0; i < row; i++){
        for(int j=0 ; j<col ; j++){
            cout << arr[i][j]<<" ";
        }
        cout << endl;
    }
}

void deleteArray(int** (&arr)){
    int row=r;
    for(int i = 0; i < row; i++){
        delete[] arr[i];
    }
    delete[] arr;
    arr = nullptr;
}
 
int main(){
    int** arr = makeArray();
    initArray(arr);
    printArray(arr);
    deleteArray(arr);
    //cout<<(sizeof(arr[0]));
    return 0;
}
