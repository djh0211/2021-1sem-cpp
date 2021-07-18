//
//  DjhVehicle.cpp
//  cpplec
//
//  Created by 하동준 on 2021/06/16.
//

#include "DjhVehicle.hpp"
#include "DjhItems.hpp"

DjhVehicle::~DjhVehicle(){
    
}
DjhVehicle::DjhVehicle(string num, string type, int quantity, int price, string company, string model, int capacity ):DjhItems(company, type, quantity, price){
    this->company = company;
    this->model = model;
    this->capacity = capacity;
    
    cout<<this->company<<this->model<<this->type;
    
}
void DjhVehicle::buy(string consumer){
    this->vec1.push_back(consumer);
}
void DjhVehicle::print1(){
    cout<<"-----------------"<<endl;
    cout<<"등록번호 : "<<this->num<<endl;
    cout<<"제품유형 : "<<this->type<<endl;
    cout<<"제품 개수 : "<<this->quantity<<endl;
    cout<<"가격 : "<<this->price<<endl;
    cout<<"-----------------"<<endl;
    cout<<"제조회사 : "<<this->company<<endl;
    cout<<"차량모델 : "<<this->model<<endl;
    cout<<"배기용량(cc) : "<<this->capacity<<endl;
    cout<<"-----------------"<<endl;
    cout<<"구매 참여자"<<endl;
    cout<<"-----------------"<<endl;
    for(size_t i =0 ;i<vec1.size();i++){
        cout<<vec1[i]<<endl;
    }
    cout<<"-----------------"<<endl;

}
ostream& operator<<(ostream& out, DjhVehicle& vehicle){
    vehicle.print1();
    return out;
}

