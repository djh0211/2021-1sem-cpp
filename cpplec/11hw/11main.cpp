//
//  11main.cpp
//  cpplec
//
//  Created by 하동준 on 2021/05/19.
//

#include <stdio.h>
#include "djh.h"
#include <string>
#include <iostream>
#include "Student.hpp"

template <typename T, typename T1>
int search(T* arr, int size, T1 forsearch){
    int result = -1;
    
    for (int i = 0; i<size; i++) {
        if(arr[i] == forsearch){
            result = i;
        }
    }
    
    return result;
}




int main(){
    
    djh::printName();
    
    int arr[5] = {5,4,3,2,1};
    int idx1 = search<int>(arr, 5, 3);
    if(idx1 != -1){
        std::cout<<arr[idx1]<<endl;
    }
    
    std::string id[3] = {"greenjoa1", "greenjoa2", "greenjoa3"};
    int idx2 = search<std::string>(id, 3, "greenjoa2");
    if(idx1 != -1){
        std::cout<<id[idx2]<<endl;
    }
    
    Student std[] {Student("greenjoa1",70), Student("greenjoa2",50), Student("greenjoa3",80)};
    
    int idx3 = search(std, 3, "greenjoa2");
    if(idx3 != -1){
        std::cout<<std[idx3]<<endl;
    }
    
    int idx4 = search(std, 3, Student("greenjoa3",80));
    if(idx4 != -1){
        std::cout<<std[idx4]<<endl;
    }
    
    
}
