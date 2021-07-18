//
//  TicketManager.cpp
//  cpplec
//
//  Created by 하동준 on 2021/05/11.
//

#include "TicketManager.hpp"
#include <typeinfo>

TicketManager::~TicketManager(){
    if(ticket != nullptr){
        for(size_t i = 0; i<count; i++){
            delete ticket[i];
        }
        delete[] ticket;
        ticket = nullptr;
    }
    if(ticket==nullptr){
        cout<<"TicketManager 소멸자"<<endl;
    }
}
TicketManager::TicketManager(const string& name, const int number){
    m_name = name;
    totalNumber = 10;
    if(totalNumber>0){
        ticket = new Ticket* [totalNumber];
    }
    else{
        ticket = nullptr;
    }
    
            
}
void TicketManager::buy(Ticket* t){
    if(count < totalNumber){
        ticket[count++] = t;
    }
}
int TicketManager::getcount(){
    return count;
}

void TicketManager::show() const{
    cout<<"-----티켓 예약 현황-----"<<endl;
    cout<<endl;
    cout<<"총 예약 매수 : "<<count<<endl;
    cout<<"--------------------"<<endl;
    int sum = 0;
    for(size_t i = 0; i < count; i++){
        ticket[i]->show();
        cout<<endl;
        sum += ticket[i]->getrPrice();
    }
    cout<<"--------------------"<<endl;
    cout<<"총 예약 금액 : "<< sum<<endl;
    cout<<"--------------------"<<endl;

}
ostream& operator<<(ostream& out, const TicketManager& manager){
    manager.show();
    return out;
}

void TicketManager::showGeneralTicket(const bool& card){
    int sum = 0;
    if(card == true){
        for(size_t i=0; i<count; i++){
            if(ticket[i]->getid()==1){//카드결제한 generalticket
                cout<<"-----일반 예약 현황-----"<<endl;
                cout<<endl;
                cout<<"카드결제 여부 : true"<<endl;
                cout<<"--------------------"<<endl;
                ticket[i]->show();
                cout<<endl;
                sum += ticket[i]->getrPrice();
                
            }
        }
        cout<<"--------------------"<<endl;
        cout<<"총 예약 금액 : "<< sum<<endl;
        cout<<"--------------------"<<endl;
    }
    if(card == false){
        for(size_t i=0; i<count; i++){
            if(ticket[i]->getid()==2){//카드결제한 generalticket
                cout<<"-----일반 예약 현황-----"<<endl;
                cout<<endl;
                cout<<"카드결제 여부 : false"<<endl;
                cout<<"--------------------"<<endl;
                ticket[i]->show();
                cout<<endl;
                sum += ticket[i]->getrPrice();
                
            }
        }
        cout<<"--------------------"<<endl;
        cout<<"총 예약 금액 : "<< sum<<endl;
        cout<<"--------------------"<<endl;
    }
    
    

}
void TicketManager::showAdvancedTicket(){
    int sum = 0;
    cout<<"-----사전 예약 현황-----"<<endl;
    cout<<endl;
    for(size_t i=0; i<count; i++){
        if(ticket[i]->getid()==3){//advanced ticket
            
            
            ticket[i]->show();
            cout<<endl;
            sum += ticket[i]->getrPrice();
            
        }
    }
    cout<<"--------------------"<<endl;
    cout<<"총 예약 금액 : "<< sum<<endl;
    cout<<"--------------------"<<endl;
}
