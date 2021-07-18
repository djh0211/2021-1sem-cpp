//
//  Calcmain.cpp
//  cpplec
//
//  Created by 하동준 on 2021/05/29.
//

#include <stdio.h>
#include <stack>
#include <string>
#include <iostream>
#include "StackCalc.hpp"
#include "djh.h"

using namespace std;

int main(){
    djh::printName();
    
    StackCalc expression("3 20 6 * +");//첫번째 식
    expression.changeInput("3 20 6 * 2 * + 20 +");//두번째식
    expression.changeInput("6 3 /");
    expression.changeInput("5 2 -");
}
