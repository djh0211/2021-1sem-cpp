//
//  AdvancedTicket.hpp
//  cpplec
//
//  Created by 하동준 on 2021/04/29.
//

#ifndef AdvancedTicket_hpp
#define AdvancedTicket_hpp

#include <stdio.h>
#include "Ticket.hpp"
#include <iostream>

using namespace std;

class AdvancedTicket: public Ticket{
private:
    int advancedDays;
    double at_price;
    double a_price;
    int t_id;
    

public:
    AdvancedTicket()=delete;
    AdvancedTicket(double, int);
    ~AdvancedTicket();
    double getPrice() const;
    double getrPrice() const;

    int getAdvanceDays() const;
    void show() const;
    int getid() const;
    
};


#endif /* AdvancedTicket_hpp */
