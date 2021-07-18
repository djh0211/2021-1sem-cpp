//
//  Rectangle.cpp
//  cpplec
//
//  Created by 하동준 on 2021/04/01.
//

#include "Rectangle.hpp"

Rectangle::Rectangle(){
    x=1; y=1;
}

    
Rectangle::Rectangle(int xx, int yy){
    x=xx; y=yy;
}

Rectangle::Rectangle(int xx){
    x=xx; y=xx;
}

bool Rectangle::isSquare(){
    bool boolean = false;
    if(x==y){
        boolean = true;
    }
    else
        boolean = false;
    return boolean;
}
