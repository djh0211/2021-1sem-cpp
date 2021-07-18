//
//  AdvancedTicket.cpp
//  cpplec
//
//  Created by 하동준 on 2021/04/29.
//

#include "AdvancedTicket.hpp"
#include "Ticket.hpp"
#include <iostream>

using namespace std;




AdvancedTicket::AdvancedTicket(double a_price, int days) : Ticket(a_price){
    advancedDays = days;
    t_id = 3;
    this->a_price = a_price;
    if(days>=30){
        at_price = a_price*0.5;
    }
    else if (days<30 && days>=20){
        at_price = a_price*0.7;
    }
    else if (days<20 && days>=10){
        at_price = a_price*0.9;
    }
    else if(days<10 && days>=0){
        at_price = a_price;
    }
    
    
}
AdvancedTicket::~AdvancedTicket(){
    cout<<"AdvancedT 소멸자"<<endl;

}
double AdvancedTicket::getPrice() const{
    return a_price;
}
double AdvancedTicket::getrPrice() const{
    return at_price;
}
int AdvancedTicket::getAdvanceDays() const{
    return advancedDays;
}
void AdvancedTicket::show() const{
    Ticket::show();
    cout<<"사전예약일 : "<<getAdvanceDays()<<endl;
    cout<<"지불금액 : "<<this->at_price<<endl;

}
int AdvancedTicket::getid() const{
    return t_id;
}

