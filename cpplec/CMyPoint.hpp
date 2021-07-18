//
//  CMyPoint.hpp
//  cpplec
//
//  Created by 하동준 on 2021/05/16.
//

#ifndef CMyPoint_hpp
#define CMyPoint_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class CMyPoint{
private:
    int x;
    int y;
public:
    CMyPoint() = default;
    ~CMyPoint() = default;
    CMyPoint(const int x, const int y);
    friend ostream& operator<<(ostream& out, CMyPoint& pt);
    bool operator<(const CMyPoint& pt);
    bool operator>(const CMyPoint& pt);

};


#endif /* CMyPoint_hpp */
