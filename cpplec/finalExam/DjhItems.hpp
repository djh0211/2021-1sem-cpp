//
//  DjhItems.hpp
//  cpplec
//
//  Created by 하동준 on 2021/06/16.
//

#ifndef DjhItems_hpp
#define DjhItems_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class DjhItems{
protected:
    string num;
    string type;
    int quantity;
    int price;
public:
    virtual ~DjhItems(){};
    DjhItems(string num, string type, int quantity, int price);
};


#endif /* DjhItems_hpp */
