//
//  Lampmain.cpp
//  cpplec
//
//  Created by 하동준 on 2021/03/30.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include "djh.h"
#include "Lamp.hpp"
#include "User.hpp"



int main(){
    djh::printName();
    Lamp lamp1;
    Lamp lamp2;
    Lamp lamp3;
    
    User user1("하동준");
    user1.turnOnOff(lamp1);
    user1.changeLight(lamp1);
    user1.changeLight(lamp1);
    user1.changeLight(lamp1);
    user1.changeLight(lamp1);
    
    user1.turnOnOff(lamp2);
    user1.turnOnOff(lamp2);
    user1.changeLight(lamp2);

    user1.changeLight(lamp3);



}
