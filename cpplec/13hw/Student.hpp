//
//  Student.hpp
//  cpplec
//
//  Created by 하동준 on 2021/05/29.
//

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>
#include <string>
#include <iostream>

using std::string;
using std::ostream;

class Student{
private:
    string sid;
    string name;
    int score;
public:
    Student()=default;
    ~Student()=default;
    Student(const string& sid, const string& name, const int& score);
    friend ostream& operator<<(ostream& out, const Student& std);
};


#endif /* Student_hpp */
