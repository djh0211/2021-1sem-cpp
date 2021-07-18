//
//  Ticket.cpp
//  cpplec
//
//  Created by 하동준 on 2021/04/28.
//

#include "Ticket.hpp"
#include <iostream>

using namespace std;

Ticket::Ticket(){
    cout<<"이건 기본생성자임"<<endl;
}
int Ticket::getid() const{
    return t_id;
}
Ticket::Ticket(double m_price){
    number = nConstr++;
    setPrice(m_price);
    t_id = 0;//ticket
    
}

int Ticket::nConstr = 1;


int Ticket::getNumber() const{
    return number;
}
double Ticket::getPrice() const{
    return price;
}
double Ticket::getrPrice() const{
    return price;
}
void Ticket::setPrice(const double& m_price){
    price = m_price;
}
void Ticket::show() const{
    cout<<"티켓번호 : "<<getNumber()<<endl;
    cout<<"가격정보 : "<<getPrice()<<endl;
    

}
