//
//  StackCalc.hpp
//  cpplec
//
//  Created by 하동준 on 2021/05/29.
//

#ifndef StackCalc_hpp
#define StackCalc_hpp

#include <stdio.h>
#include <stack>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class StackCalc{
private:
    string input;
    vector<string> inputsplit;
    stack<double> st;
public:
    StackCalc();
    StackCalc(string input);
    ~StackCalc();
    vector<string> split(string str, char delimiter);
    void changeInput(string input);
    void printResult();
};



#endif /* StackCalc_hpp */
