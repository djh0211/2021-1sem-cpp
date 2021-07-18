//
//  StackCalc.cpp
//  cpplec
//
//  Created by 하동준 on 2021/05/29.
//

#include "StackCalc.hpp"
#include <sstream>
#include <stdio.h>
#include <stack>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<string> StackCalc::split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}

StackCalc::StackCalc(){
    
}

StackCalc::~StackCalc(){
    cout<<"소멸자 실행"<<endl;
}

StackCalc::StackCalc(string input)
    :input(input)
{
    printResult();
    
    
}

void StackCalc::printResult(){
    inputsplit = split(input, ' ');
    for(auto it = inputsplit.begin(); it!= inputsplit.end(); it++){
//        cout << *it << " ";
        if (*it == "+") {
            double temp1 = st.top();
            st.pop();
            double temp2 = st.top();
            st.pop();
            double temp = temp2+temp1;
            st.push(temp);
            
        }
        else if (*it == "*") {
            double temp1 = st.top();
            st.pop();
            double temp2 = st.top();
            st.pop();
            double temp = temp2*temp1;
            st.push(temp);
            
        }
        else if (*it == "/") {
            double temp1 = st.top();
            st.pop();
            double temp2 = st.top();
            st.pop();
            double temp = temp2/temp1;
            st.push(temp);
            
        }
        else if (*it == "-") {
            double temp1 = st.top();
            st.pop();
            double temp2 = st.top();
            st.pop();
            double temp = temp2-temp1;
            st.push(temp);
            
        }
        else{
            st.push(stod(*it));
        }
        
    }
    cout<<"결과값 : "<<st.top()<<endl;
    st.pop();
    if(st.empty()){
        cout<<"스택을 비웠습니다."<<endl;
    }
}

void StackCalc::changeInput(string input){
    this -> input = input;
    printResult();
    
    
}
