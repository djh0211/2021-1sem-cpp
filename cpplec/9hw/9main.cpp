//
//  9main.cpp
//  cpplec
//
//  Created by 하동준 on 2021/04/29.
//

#include <stdio.h>
#include "Ticket.hpp"
#include "GeneralTicket.hpp"
#include "AdvancedTicket.hpp"
#include "TicketManager.hpp"
#include <iostream>
#include "djh.h"

using namespace std;

int main(){
    djh::printName();
    TicketManager manager("아이유 콘서트", 10);
    manager.buy(new AdvancedTicket(1000, 40));
    manager.buy(new AdvancedTicket(1500, 30));
    manager.buy(new AdvancedTicket(2000, 25));
    manager.buy(new AdvancedTicket(1000, 5));
    manager.buy(new GeneralTicket(2000, true));
    manager.buy(new GeneralTicket(1500, false));
    cout<<manager<<endl;
    manager.showGeneralTicket(true);
    manager.showGeneralTicket(false);
    manager.showAdvancedTicket();

    
}
