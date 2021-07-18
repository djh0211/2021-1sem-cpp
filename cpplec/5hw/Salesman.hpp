//
//  Salesman.hpp
//  cpplec
//
//  Created by 하동준 on 2021/04/02.
//

#ifndef Salesman_hpp
#define Salesman_hpp

#include <stdio.h>
#include <string>
using std::string;
class Salesman{
private:
    string m_name;
    double m_sales;
public:
    Salesman();
    Salesman(const string& name, const double& sales);
    Salesman(const string& name);
    ~Salesman();
    void setName(const string& name);
    void readInput();
    string getSalesmanInfo();
    void setSales(const int& sales);
    double getSales();
};


#endif /* Salesman_hpp */
