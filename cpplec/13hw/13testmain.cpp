//
//  13testmain.cpp
//  cpplec
//
//  Created by 하동준 on 2021/05/29.
//

#include <stdio.h>
#include "Student.hpp"
#include <map>
#include <iostream>

using namespace std;

int main(){
    map<string, Student> cppClassA;
    cppClassA["greenjoa1"]=Student("greenjoa1", "홍길동", 60);
    cppClassA.insert({"greenjoa2", Student("greenjoa2","김길동", 70) });
    cppClassA.insert({"greenjoa3", Student("greenjoa3","이길동", 80) });
    cppClassA.emplace("greenjoa4", Student("greenjoa4","최길동", 90));
    cout<<"-----------cppClasssA----------"<<endl;

    for (const auto& p : cppClassA) {
        cout<<p.first<<" : "<<p.second<<endl;
    }
    
    auto pos = cppClassA.find("greenjoa3");
    if (pos!= cppClassA.end()) {
        cout << pos->first<< " : "<<pos->second <<endl;
    }
    
    map<string, Student> cppClassB;
    cppClassB.insert({"greenjoa5", Student("greenjoa5","박길동", 77) });
    cppClassB.insert({"greenjoa6", Student("greenjoa6","고길동", 85) });
    cppClassB.emplace("greenjoa3", Student("greenjoa3","이길동", 80));
    
    cout<<"-----------cppClasssB----------"<<endl;
    for (const auto& p : cppClassB) {
        cout<<p.first<<" : "<<p.second<<endl;
    }
    
    cppClassA.merge(cppClassB);
    
    cout<<"-----------cppClasssA----------"<<endl;
    for (const auto& p : cppClassA) {
        cout<<p.first<<" : "<<p.second<<endl;
    }
    
    cout<<"-----------cppClasssB----------"<<endl;
    for (const auto& p : cppClassB) {
        cout<<p.first<<" : "<<p.second<<endl;
    }
    
    auto node = cppClassA.extract("greenjoa1");
    cout<<node.key()<<" , "<<node.mapped()<<endl;
    cppClassB.insert(move(node));
    cout<<"-----------cppClasssA----------"<<endl;
    for (const auto& p : cppClassA) {
        cout<<p.first<<" : "<<p.second<<endl;
    }
    
    cout<<"-----------cppClasssB----------"<<endl;
    for (const auto& [key, value] : cppClassB) {
        cout<<key<<" : "<<value<<endl;
    }
    
    
}
