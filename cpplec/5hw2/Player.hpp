//
//  Player.hpp
//  cpplec
//
//  Created by 하동준 on 2021/04/01.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <string>
#include "Dice.hpp"

using std::string;

class Player{
private:
    string name;
    int total=0;
public:
    void setName(const string& _name);
    string getName();
    void roll(Dice& dice1, Dice& dice2);
    int getTotal();
    
    Player()=delete;
    Player(string);
    
};
#endif /* Player_hpp */
