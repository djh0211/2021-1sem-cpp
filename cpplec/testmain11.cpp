//
//  testmain11.cpp
//  cpplec
//
//  Created by 하동준 on 2021/05/16.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <typeinfo>
#include "CMyPoint.hpp"
#include "Stack.hpp"
#include "djh.h"

using namespace std;

template<typename T>
void printArr(T* arr, size_t N){
    for (int i=0; i<N; i++) {
        cout<<arr[i]<<endl;
    }
    cout<<endl;
}

template<>//예외알고리즘 경우
void printArr(char* arr, size_t N){
    
    cout<<arr<<endl;
    
}

template<typename T, size_t N>
void showArr(T(&arr)[N]){
    for (T(i) : arr) {
        cout<< i << endl;
    }
    cout<<endl;
}

template<typename T, size_t N>
void sortDesc(T(&arr)[N]){
    for (size_t i = 0; i<N -1; i++) {
        for (size_t j =i+1; j<N; j++) {
            if(arr[i] < arr[j]){
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout<<endl;
}
//오름차순
template<typename T, size_t N>
void sortAsc(T(&arr)[N]){
    for (size_t i = 0; i<N -1; i++) {
        for (size_t j =i+1; j<N; j++) {
            if(arr[i] > arr[j]){
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout<<endl;
}


int main(){
    djh::printName();
//    Stack<int> istack;
//    istack.push(10);
//    istack.push(20);
//    istack.push(30);
//    istack.push(40);
//    istack.push(50);//LIFO
//    int item;
//    while (istack.pop(item)) {
//        cout<<item<<endl;
//    }
//    
//    Stack<double> dstack;
//    dstack.push(10.0);
//    dstack.push(20.0);
//    dstack.push(30.0);
//    dstack.push(40.0);
//    dstack.push(50.0);
//    int ditem;
//    while (istack.pop(ditem)) {
//        cout<<ditem<<endl;
//    }
//    
//    Stack<string> sstack;
//    sstack.push("greenjoa1");
//    sstack.push("greenjoa2");
//    sstack.push("greenjoa3");
//    string sitem;
//    while (sstack.pop(sitem)) {
//        cout<<sitem<<endl;
//    }
//    
//    Stack<CMyPoint> pstack;
//    pstack.push(CMyPoint(10,20));
//    pstack.push(CMyPoint(30,25));
//    pstack.push(CMyPoint(15,45));
//    CMyPoint pitem;
//    while (pstack.pop(pitem)) {
//        cout<<pitem<<endl;
//    }
    
//    Stack<> stack; //int stack
//    Stack<int, 40> istack;

    
    CMyPoint arr[]{ CMyPoint(10,20), CMyPoint(25,30), CMyPoint(15,10)};
    sortAsc(arr);
    showArr(arr);
    
    
//
//    int arr1[] = {1,2,3,4,5};
//    size_t arr1_len = sizeof(arr1)/sizeof(arr1[0]);
//    double arr2[] = {1.1,2.2,3.3,4.4,5.5,6.6};
//    size_t arr2_len = sizeof(arr2)/sizeof(arr2[0]);
//    string arr3[]{"greenjoa1","greenjoa2","greenjoa3"};
//    size_t arr3_len = sizeof(arr3)/sizeof(arr3[0]);
//    char arr4[] = {'a','b',0};
//    size_t arr4_len = sizeof(arr4)/sizeof(arr4[0]);
//
//    sortDesc(arr1);
//    showArr(arr1);
//    sortDesc(arr2);
//    showArr(arr2);
//    sortDesc(arr3);
//    showArr(arr3);

//
        
    
//    cout<<arr1<<endl;//주소
//    cout<<arr4<<endl;//ab(널값만날때까지 출력해냄)
    
//    printArr<int>(arr1,arr1_len);
//    printArr<double>(arr2,arr2_len);
//    printArr<string>(arr3,arr3_len);
//    printArr<char>(arr4,arr4_len);


}
