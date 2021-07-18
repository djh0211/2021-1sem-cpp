//
//  User.hpp
//  cpplec
//
//  Created by 하동준 on 2021/03/30.
//

#ifndef User_hpp
#define User_hpp


#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include "Lamp.hpp"

using std::string;
using std::cout;
using std::endl;

class User{
private:
    string m_name;
public:
    void turnOnOff(Lamp& lamp);
    void changeLight(Lamp& lamp);
    
    User(string name);
};

#endif /* User_hpp */
