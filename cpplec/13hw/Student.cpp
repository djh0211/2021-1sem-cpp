//
//  Student.cpp
//  cpplec
//
//  Created by 하동준 on 2021/05/29.
//

#include "Student.hpp"
using std::endl;

Student::Student(const string& sid, const string& name, const int& score)
    :sid(sid), name(name), score(score){
    
}
ostream& operator<<(ostream& out, const Student& std){
    out<<std.sid<<", "<<std.name<<", "<<std.score<<endl;
    return out;
}
