//
//  ArrayDataSmart.hpp
//  cpplec
//
//  Created by 하동준 on 2021/05/11.
//

#ifndef ArrayDataSmart_hpp
#define ArrayDataSmart_hpp

#include <stdio.h>
#include "ArrayData.hpp"
class ArrayDataSmart :
    public ArrayData
{
private:
    //unique_ptr<double[]> backdata;
    double* backdata = nullptr;
    int usedB;
public:
    ArrayDataSmart();
    ArrayDataSmart(ArrayDataSmart& arr);
    ArrayDataSmart(ArrayDataSmart&& arr)noexcept;
    ArrayDataSmart(const int& capacity, const int& used = 0);
    ~ArrayDataSmart();
    void backup();
    void restore();
    ArrayDataSmart& operator=(const ArrayDataSmart& rhs);
    ArrayDataSmart& operator=(ArrayDataSmart&& rhs) noexcept;
};





#endif /* ArrayDataSmart_hpp */
