//
//  5hw1main.cpp
//  cpplec
//
//  Created by 하동준 on 2021/04/01.
//

#include "djh.h"
#include "Rectangle.hpp"
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>


using std::cout;
using std::endl;


int main(){
    djh::printName();
    
    Rectangle rect1;
    Rectangle rect2(3,5);
    Rectangle rect3(3);
    
    if(rect1.isSquare()) cout<<"rect1은 정사각형이다."<<endl;
    if(rect2.isSquare()) cout<<"rect2는 정사각형이다."<<endl;
    if(rect3.isSquare()) cout<<"rect3은 정사각형이다."<<endl;

}
