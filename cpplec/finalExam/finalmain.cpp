//
//  finalmain.cpp
//  cpplec
//
//  Created by 하동준 on 2021/06/16.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include "DjhItems.hpp"
#include "DjhVehicle.hpp"
#include "DjhShoes.hpp"

using namespace std;

int main(){
    cout<<"201914185 하동준"<<endl;
    
//    DjhItems *a = new DjhItems("A1", "자동차", 2, 10000);
//    생성불가
    
    DjhVehicle *a = new DjhVehicle("A1", "자동차", 2, 10000, "건국차", "k9", 2500);
    DjhShoes * b= new DjhShoes("S1", "신발류", 3, 100, "여성용", "건국샌들", 240);

    a->buy("김길");
    a->buy("하길");
    a->buy("송길");
    
    b->buy("점순이");
    b->buy("점박이");
    b->buy("바둑이");


    cout<<*a<<endl;
    cout<<*b<<endl;


    
    
}
