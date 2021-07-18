//
//  GeneralTicket.hpp
//  cpplec
//
//  Created by 하동준 on 2021/04/29.
//

#ifndef GeneralTicket_hpp
#define GeneralTicket_hpp

#include <stdio.h>
#include "Ticket.hpp"


class GeneralTicket : public Ticket{
private:
    bool payByCredit;
    double g_price;
    double gt_price;
    int t_id;
public:
    GeneralTicket()=delete;
    GeneralTicket(double, bool);
    ~GeneralTicket();
    double getPrice() const;//티켓가격
    double getrPrice() const;//지불가격

    bool getPayByCredit() const;
    void show() const;
    int getid() const;
};

#endif /* GeneralTicket_hpp */
