//
//  3-2testmain.cpp
//  cpplec
//
//  Created by 하동준 on 2021/03/17.
//

#include "3-2testmain.hpp"
#include <iostream>
#include <string>
using namespace std;

int* makeArray(int& num){
    cout << "학생수: ";
    cin>>num;
    int* temp = new int[num];
    for(int i =0;i<num;i++){
        cout<<i+1<<"번 학생 성적: ";
        cin>>temp[i];
        
    }
    return temp;
}

void deleteArray(int* (&arr)){
    delete[] arr;
    arr = nullptr;
}

void printArray(int* (&arr), const int SIZE){
    cout<<"원본 데이터: ";
    for(int i = 0; i<SIZE;i++)
        cout << arr[i] << "\t";
    cout << endl;
}

int** sortArray(const int* std, const int num){
    int** arr = new int*[num];
    for(int i=0;i<num;i++){
        arr[i] = const_cast<int*>(&std[i]);
    }
    for(int i=0;i<num-1;i++){
        for(int j=i+1;j<num;j++){
            if(*arr[i]>*arr[j]){
                int* temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}

void printSortedArray(int** (&arr), const int SIZE){
    cout<<"정렬 데이터: ";
    for(int i = 0; i<SIZE;i++)
        cout << *arr[i] << "\t";
    cout << endl;
}

void deleteSortedArray(int** (&arr)){
    delete[] arr;
    arr = nullptr;
}


int main(){
    int num;
    int* std = makeArray(num);
    printArray(std, num);
    int** sortedStd = sortArray(std, num);
    printSortedArray(sortedStd, num);
    printArray(std, num);
    deleteArray(std);
    deleteSortedArray(sortedStd);
    
    if(std==nullptr){
        cout<<"int* 메모리 정리끝~~"<<endl;
    }
    if(sortedStd==nullptr){
        cout<<"int** 메모리 정리끝~~"<<endl;
    }
}
