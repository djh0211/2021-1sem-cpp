//
//  12ex.cpp
//  cpplec
//
//  Created by 하동준 on 2021/05/25.
//

#include <stdio.h>
#include <list>
#include <string>
#include <iostream>

using namespace std;

template<typename T>
void printArr(list<T>& v){
    for(auto it = v.begin(); it!= v.end(); it++){
        cout << *it << " ";
    }
    cout<<endl;
}

int main(){
    list<int> list1({1,2,3,3,3,4,5});
    list1.unique();
    printArr(list1);
}
