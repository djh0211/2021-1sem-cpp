//
//  Lamp.cpp
//  cpplec
//
//  Created by 하동준 on 2021/03/30.
//

#include "Lamp.hpp"
#include <iostream>

void Lamp::powerOnOff() {
    isOn = !isOn;
    if(isOn==true)
        cout<<"전원 on"<<endl;
    else
        cout<<"전원 off"<<endl;
    

}

void Lamp::changeLight(){
    if(isOn==true){
        if (illuminance == 0){
            illuminance=1;
            cout << "현재 조도는 "<<illuminance<<" 단 입니다."<<endl;

        }
        else{
            illuminance++;
            if(illuminance == 4){
                illuminance = 1;
            }
            
            cout << "현재 조도는 "<<illuminance<<" 단 입니다."<<endl;
        }
    }
    else{
        illuminance = 0;
        cout << "전원이 꺼져있습니다. "<< endl;
    }
}


