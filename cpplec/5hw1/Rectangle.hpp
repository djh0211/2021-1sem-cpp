//
//  Rectangle.hpp
//  cpplec
//
//  Created by 하동준 on 2021/04/01.
//

#ifndef Rectangle_hpp
#define Rectangle_hpp

#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include "Lamp.hpp"

using std::string;
using std::cout;
using std::endl;

class Rectangle{
private:
    int x;
    int y;
public:
    bool isSquare();
    Rectangle();
    Rectangle(int , int );
    Rectangle(int);
    
    
};


#endif /* Rectangle_hpp */
