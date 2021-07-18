//
//  Salesman.cpp
//  cpplec
//
//  Created by 하동준 on 2021/04/02.
//

#include "Salesman.hpp"
#include <iostream>
using namespace std;

Salesman::Salesman():Salesman("NoInfo", 0.0){
    
}
Salesman::Salesman(const string& name)
:Salesman(name,0.0){
    
}
Salesman::Salesman(const string& name, const double& sales)
:m_name(name), m_sales(sales){
    
}
Salesman::~Salesman(){
    
}
void Salesman::setName(const string& name){
    m_name = name;
}
void Salesman::readInput(){
    cout<<"이름 : ";
    cin>>m_name;
    cout<<"실적 : ";
    cin>>m_sales;
}
double Salesman::getSales(){
    return m_sales;
}
string Salesman::getSalesmanInfo(){
    return "이름 : "+m_name+", 판매액 : "+to_string(m_sales);
}
void Salesman::setSales(const int& sales){
    m_sales = sales;
}

