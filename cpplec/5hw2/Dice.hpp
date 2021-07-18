//
//  Dice.hpp
//  cpplec
//
//  Created by 하동준 on 2021/04/01.
//

#ifndef Dice_hpp
#define Dice_hpp

#include <stdio.h>

class Dice{
private:
    int faceValue;
public:
    void roll();
    int getFaceValue();
    Dice();
};

#endif /* Dice_hpp */
