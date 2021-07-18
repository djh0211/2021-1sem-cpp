//
//  12main.cpp
//  cpplec
//
//  Created by 하동준 on 2021/05/24.
//

#include <stdio.h>
#include <list>
#include <string>
#include <iostream>
#include "djh.h"

using namespace std;

template<typename T>
void printArr(list<T>& v){
    for(auto it = v.begin(); it!= v.end(); it++){
        cout << *it << " ";
    }
    cout<<endl;
}



list<string> getStudent(list<list<string>>& std, list<string>& droplist){
    list<string> temp;
    for (auto s: std) {
        for (auto t:s) {
            temp.push_back(t);
        }
    }
    temp.sort();
    temp.unique();
    
    for(auto it = droplist.begin(); it!= droplist.end(); it++){
        temp.remove(*it);
        
    }
    return temp;
}

int main(){
    djh::printName();
    
    list<list<string>> std;
    std.push_back({"greenjoa1","bluejoa1","greenjoa3"});
    std.push_back({"greenjoa1","greenjoa3"});
    std.push_back({"redjoa1","greenjoa2","bluejoa2"});
    list<string> droplist({"greenjoa2","bluejoa1"});
    
    auto student = getStudent(std, droplist);
    
    printArr(student);
    
    
    

}
