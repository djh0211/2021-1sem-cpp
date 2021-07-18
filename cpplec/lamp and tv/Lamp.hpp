//
//  Lamp.hpp
//  cpplec
//
//  Created by 하동준 on 2021/03/30.
//

#ifndef Lamp_hpp
#define Lamp_hpp

#include <stdio.h>
#include <iostream>

using std::cout;
using std::endl;

class Lamp{
private:
    bool isOn = false;
    int illuminance = 0;
    
public:
    void powerOnOff();
    void changeLight();
    
   
};


#endif /* Lamp_hpp */
