#pragma once
#include <iostream>
using std::cout;
using std::endl;
class TV{
    
private:
    bool m_isOn;    //멤버변수들
    int m_volume;
    int m_channel;
public:
    void powerOnOff();
    void setVolume(int volume);
    int getVolume();
    void setChannel(int Channel);
    int getChannel();
    void showStatus();
    
    
   

};

void TV::powerOnOff() {
    m_isOn = !m_isOn;
}

void TV::setVolume(int volume){
    m_volume = volume;
}
int TV::getVolume(){
    return m_volume;
}

void TV::setChannel(int Channel) {
    m_channel = Channel;
}
int TV::getChannel(){
    return m_channel;
}
void TV::showStatus(){
    if (m_isOn){
        cout << "채널 : " <<m_channel <<", 볼륨 : "<< m_volume<<" 시청중"<< endl;
    }
}

int main(){
    TV tv1;
    tv1.powerOnOff();
    tv1.setVolume(3);
    tv1.showStatus();
}






