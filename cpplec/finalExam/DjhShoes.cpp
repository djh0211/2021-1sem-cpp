//
//  DjhShoes.cpp
//  cpplec
//
//  Created by 하동준 on 2021/06/16.
//

#include "DjhShoes.hpp"
#include <iostream>
#include <string>
#include "DjhItems.hpp"

using namespace std;

DjhShoes::DjhShoes(string num, string type, int quantity, int price, string sex, string shoeType, int size):DjhItems(num, type, quantity, price){
    this->sex = sex;
    this->shoeType = shoeType;
    this->size = size;
    
    
}
DjhShoes::~DjhShoes(){
    
}
void DjhShoes::buy(string consumer){
    this->vec2.push_back(consumer);
}
void DjhShoes::print2(){
    cout<<"-----------------"<<endl;
    cout<<"등록번호 : "<<this->num<<endl;
    cout<<"제품유형 : "<<this->type<<endl;
    cout<<"제품 개수 : "<<this->quantity<<endl;
    cout<<"가격 : "<<this->price<<endl;
    cout<<"-----------------"<<endl;
    cout<<"성별유형 : "<<this->sex<<endl;
    cout<<"신발종류 : "<<this->shoeType<<endl;
    cout<<"사이즈 : "<<this->size<<endl;
    cout<<"-----------------"<<endl;
    cout<<"구매 참여자"<<endl;
    cout<<"-----------------"<<endl;
    for(size_t i =0 ;i<vec2.size();i++){
        cout<<vec2[i]<<endl;
    }
    cout<<"-----------------"<<endl;

}
ostream& operator<<(ostream& out, DjhShoes& shoe){
    shoe.print2();
    return out;
}
