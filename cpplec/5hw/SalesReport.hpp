//
//  SalesReport.hpp
//  cpplec
//
//  Created by 하동준 on 2021/04/02.
//

#ifndef SalesReport_hpp
#define SalesReport_hpp

#include <stdio.h>
#include "Salesman.hpp"
#include <memory>
using std::unique_ptr;
using std::shared_ptr;

class SalesReport{
private:
    Salesman** team;
    size_t count = 0;
//    unique_ptr<Salesman[]> team;
//    Salesman** team;
//    shared_ptr<shared_ptr<Salesman>[]> team;
    double highestSales;
    double averageSales;
    size_t m_number;
public:
    SalesReport();
    SalesReport(const size_t& number);
    ~SalesReport();
    void computeStats();
    Salesman* getBestClerk();
    string getTeamInfo();
    size_t getNumber();
    void addMember();
};

#endif /* SalesReport_hpp */
