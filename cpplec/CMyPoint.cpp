//
//  CMyPoint.cpp
//  cpplec
//
//  Created by 하동준 on 2021/05/16.
//

#include "CMyPoint.hpp"

using namespace std;

CMyPoint::CMyPoint(const int x, const int y)
:x(x), y(y){
    
}

ostream& operator<<(ostream& out, CMyPoint& pt){
    out<<pt.x<<", "<<pt.y<<endl;
    return out;
}

bool CMyPoint::operator<(const CMyPoint& pt){
    return x<pt.x;
}

bool CMyPoint::operator>(const CMyPoint& pt){
    return x>pt.x;
}
