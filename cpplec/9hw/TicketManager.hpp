//
//  TicketManager.hpp
//  cpplec
//
//  Created by 하동준 on 2021/05/11.
//

#ifndef TicketManager_hpp
#define TicketManager_hpp

#include <stdio.h>
#include <iostream>
#include "Ticket.hpp"
#include "GeneralTicket.hpp"
#include "AdvancedTicket.hpp"

using namespace std;

class TicketManager{
private:
    string m_name;
    int totalNumber;
    Ticket** ticket = nullptr;
    int count = 0;
public: 
    TicketManager()=delete;
    ~TicketManager();
    TicketManager(const string& name, const int number);
    void buy(Ticket* t);
    void show() const;
    int getcount();
    void showGeneralTicket(const bool& card);
    void showAdvancedTicket();
};
ostream& operator<<(ostream& out, const TicketManager& manager);

#endif /* TicketManager_hpp */
