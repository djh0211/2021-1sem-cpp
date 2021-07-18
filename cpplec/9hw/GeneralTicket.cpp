//
//  GeneralTicket.cpp
//  cpplec
//
//  Created by 하동준 on 2021/04/29.
//

#include "GeneralTicket.hpp"
#include "Ticket.hpp"
#include <iostream>

using namespace std;

GeneralTicket::GeneralTicket(double g_price, bool credit) : Ticket(g_price){
    payByCredit = credit;
    this->g_price = g_price;
    if(payByCredit == true){
        this->gt_price = (g_price*1.1);
        t_id = 1;//general card true

    }
    else{
        this->gt_price = g_price;
        t_id = 2;//general card false
    }
}
GeneralTicket::~GeneralTicket(){
    cout<<"GeneralT 소멸자"<<endl;
}
double GeneralTicket::getPrice() const{
    return g_price;
}
double GeneralTicket::getrPrice() const{
    return gt_price;

}

bool GeneralTicket::getPayByCredit() const{
    return payByCredit;
}
void GeneralTicket::show() const{
    Ticket::show();
    if(getPayByCredit()){
        cout<<"카드결제여부 : true"<<endl;
    }
    else{
        cout<<"카드결제여부 : false"<<endl;

    }
    cout<<"지불금액 : "<<this->gt_price<<endl;
}
int GeneralTicket::getid() const{
    return t_id;
}
