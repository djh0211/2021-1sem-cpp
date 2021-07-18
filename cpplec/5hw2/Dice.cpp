//
//  Dice.cpp
//  cpplec
//
//  Created by 하동준 on 2021/04/01.
//

#include "Dice.hpp"
#include <cstdlib>

Dice::Dice(){
    faceValue = 0;
}
void Dice::roll(){
    faceValue = rand()%6+1;
}

int Dice::getFaceValue(){
    return faceValue;
}
