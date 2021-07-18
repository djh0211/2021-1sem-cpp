//
//  DiceMain.cpp
//  cpplec
//
//  Created by 하동준 on 2021/04/01.
//

#include <stdio.h>
#include "djh.h"
#include <iostream>
#include "Dice.hpp"
#include "Player.hpp"
#include <ctime>
using namespace std;

int main(){
    djh::printName();
    
    srand((unsigned)time(NULL));
    Dice dice1, dice2;
//    cout<<dice1.getFaceValue(); //주사위 초기값 0
//    Player player1, player2;  //기본생성자 금지
    Player player1("temp1");
    Player player2("temp2");
// player1,2 초기 이름 설정
    player1.setName("홍길동");
    player2.setName("김길동");
// 이름변경
    player1.roll(dice1, dice2);
    player2.roll(dice1, dice2);
    if(player1.getTotal()>player2.getTotal()){
        cout<<player1.getName()<<"님 승리 ==> 점수 ("<<player1.getTotal()<<","<<player2.getTotal()<<")"<<endl;
    }
    else if(player1.getTotal()<player2.getTotal()){
        cout<<player2.getName()<<"님 승리 ==> 점수 ("<<player2.getTotal()<<","<<player1.getTotal()<<")"<<endl;
    }
    else{
        cout<<"무승부 ==> 점수 ("<<player1.getTotal()<<","<<player2.getTotal()<<")"<<endl;
    }



}
