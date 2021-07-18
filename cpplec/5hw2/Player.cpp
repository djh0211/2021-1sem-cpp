//
//  Player.cpp
//  cpplec
//
//  Created by 하동준 on 2021/04/01.
//

#include "Player.hpp"
#include <iostream>
using namespace std;

Player::Player(string _name){
    name = _name;
}
void Player::setName(const string& _name){
    name = _name;
}
string Player::getName(){
    return name;
}
void Player::roll(Dice& dice1, Dice& dice2){
    cout<<name<<"님께서 주사위를 던졌습니다."<<endl;
    dice1.roll();
    dice2.roll();
    total = dice1.getFaceValue() + dice2.getFaceValue();

}
int Player::getTotal(){
    return total;
}
