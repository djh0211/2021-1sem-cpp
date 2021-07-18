//
//  DjhVehicle.hpp
//  cpplec
//
//  Created by 하동준 on 2021/06/16.
//

#ifndef DjhVehicle_hpp
#define DjhVehicle_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "DjhItems.hpp"
#include <vector>

using namespace std;

class DjhVehicle:DjhItems{
private:
    string company;
    string model;
    int capacity;
    vector<string> vec1;
public:
    ~DjhVehicle();
    DjhVehicle(string num, string type, int quantity, int price, string company, string model, int capacity);
    void buy(string consumer);
    void print1();

};
ostream& operator<<(ostream& out, DjhVehicle& vehicle);



#endif /* DjhVehicle_hpp */
