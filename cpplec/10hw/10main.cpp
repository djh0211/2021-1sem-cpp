//
//  10main.cpp
//  cpplec
//
//  Created by 하동준 on 2021/05/11.
//

#include <stdio.h>
#include <iostream>
//#include "ArrayDataSmart.hpp"
#include "ArrayData.hpp"
#include "djh.h"
using namespace std;


int main() {
    djh::printName();
    
    ArrayData<int> arr1;
    arr1.addElement(10);
    arr1.addElement(20);
    arr1.addElement(30);
    cout<<arr1<<endl;
    
    ArrayData<int> arr2 = arr1;
    cout<<arr2<<endl;
    
    ArrayData<int> arr3 = move(arr2);
    cout<<arr3<<endl;
    
//    ArrayDataSmart arr1(5);
//    arr1.addElement(10.1);
//    arr1.addElement(10.2);
//    arr1.addElement(10.3);
//    arr1.addElement(10.4);
//    arr1.backup();
//    arr1.addElement(10.5);
//    arr1.addElement(10.6);
//
//    cout << "arr1 : " << arr1 << endl;
//    cout << "------------restore----------" << endl;
//    arr1.restore();
//    cout << "arr1 : " << arr1 << endl;
//
//    cout << "======== 대입 =========" << endl;
//    ArrayDataSmart arr2(20);
//    arr2 = arr1;
//    cout << "arr2 : " << arr2 << endl;
//
//    cout << "========이동 대입=======" << endl;
//    ArrayDataSmart arr3(3);
//    arr3 = move(arr1);
//    cout <<"arr3 : " << arr3 << endl;


}
