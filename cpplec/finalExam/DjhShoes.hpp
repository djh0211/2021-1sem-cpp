//
//  DjhShoes.hpp
//  cpplec
//
//  Created by 하동준 on 2021/06/16.
//

#ifndef DjhShoes_hpp
#define DjhShoes_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "DjhItems.hpp"
#include <vector>

using namespace std;

class DjhShoes:DjhItems{
private:
    string sex;
    string shoeType;
    int size;
    vector<string> vec2;

public:
    DjhShoes(string num, string type, int quantity, int price, string sex, string shoeType, int size);
    ~DjhShoes();
    void buy(string consumer);
    void print2();

};
ostream& operator<<(ostream& out, DjhShoes& shoe);


#endif /* DjhShoes_hpp */
