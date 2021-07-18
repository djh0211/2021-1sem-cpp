//
//  User.cpp
//  cpplec
//
//  Created by 하동준 on 2021/03/30.
//

#include "User.hpp"
#include "Lamp.hpp"
//생성자
User::User(string name){
    m_name = name;
}

void User::turnOnOff(Lamp& lamp){
    lamp.powerOnOff();
    
};

void User::changeLight(Lamp& lamp){
    lamp.changeLight();
};
