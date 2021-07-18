//
//  SalesReport.cpp
//  cpplec
//
//  Created by 하동준 on 2021/04/02.
//

#include "SalesReport.hpp"
#include <string>
#include <iostream>

using namespace std;
SalesReport::SalesReport():SalesReport(0){
    
}
SalesReport::SalesReport(const size_t& number)
:m_number(number), averageSales(0.0), highestSales(0.0){
    if(m_number>0){
        team = new Salesman* [m_number];

    }
    else
        team = nullptr;
}
SalesReport::~SalesReport(){
    if(team!=nullptr){
        for(int i=0;i<m_number;i++){
            delete team[i];
            
        }
        delete [] team;
        team = nullptr;
    }
    if(team == nullptr)
        cout<<"메모리 정리 완료"<<endl;

}
void SalesReport::computeStats(){
    if(team!=nullptr){
        double sum = team[0]->getSales();
//        cout<<sum<<endl;
        highestSales = team[0]->getSales();
        for(size_t i=1;i<m_number;i++){
            if(highestSales < team[i]->getSales()){
                highestSales = team[i]->getSales();
            }
            sum+= team[i]->getSales();
        }
        averageSales = sum / m_number;
    }
    cout<<averageSales<<endl;
}
Salesman* SalesReport::getBestClerk(){
    size_t bestIndex = 0;
    for(size_t i=0;i<m_number;i++){
        if(team[bestIndex]->getSales()< team[i]->getSales()){
            bestIndex = i;

        }
    }
    return team[bestIndex];
}
string SalesReport::getTeamInfo(){
    string info="인원수 : "+to_string(m_number);
    info += "\n 평균 판매량 : "+to_string(averageSales);
    info += "\n 최고 판매량 : "+to_string(highestSales)+"\n";
    return info;
}
size_t SalesReport::getNumber(){
    return m_number;
}
void SalesReport::addMember(){
    if(count >= m_number){
        cout << "Salesman을 추가할 수 없습니다.\n"<<endl;
        return;
    }
    string name;
    double sales;
    
    cout<<"이름 : ";
    cin>>name;
    cout<<"실적 : ";
    cin>>sales;
    
    team[count++] = new Salesman(name, sales);
    
}
