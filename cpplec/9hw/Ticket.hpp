//
//  Ticket.hpp
//  cpplec
//
//  Created by 하동준 on 2021/04/28.
//

#ifndef Ticket_hpp
#define Ticket_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Ticket{

    
protected:
    static int nConstr;
    int number;
    double price;
    int t_id;
    
public:
    Ticket();
    Ticket(double);
    virtual ~Ticket(){
        cout<<"가상소멸자"<<endl;
    }
    int getNumber() const;
    virtual double getPrice() const;
    virtual double getrPrice() const;
    void setPrice(const double& price);
    virtual void show() const;
    virtual int getid() const;
    
};

#endif /* Ticket_hpp */
