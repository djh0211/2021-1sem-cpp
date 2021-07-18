//
//  5main.cpp
//  cpplec
//
//  Created by 하동준 on 2021/04/02.
//

#include "Salesman.hpp"
#include "SalesReport.hpp"
#include <string>
#include <iostream>
using namespace std;

int main(){
    SalesReport team1(3);
    team1.addMember();
    team1.addMember();
    team1.addMember();

   team1.computeStats();
    if(team1.getNumber()>0){
        cout<< team1.getBestClerk()->getSalesmanInfo()<<endl;
    }
    return 0;
}
