//
//  Student.hpp
//  cpplec
//
//  Created by 하동준 on 2021/05/19.
//

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>
#include <string>
#include <iostream>


class Student{
private:
    std::string name;
    int score;
public:
    Student() = delete;
    ~Student(){};
    Student(const std::string& name, const int& score): name(name), score(score){};
    std::string getName() const{
        return name;
    };
    int getScore() const{
        return score;
    };
    
    friend std::ostream& operator<<(std::ostream& out, Student& pt){
        out<<pt.name<<", "<<pt.score;
        return out;
    };
    
    friend bool operator == (const Student& pt1, const char* pt2){
        return pt1.name == pt2;
    };
    
    friend bool operator == (const Student& pt1, const Student& pt2){
        if (pt1.name==pt2.name and pt1.score == pt2.score) {
            return true;
        }
        else
            return false;
    };
    
};




#endif /* Student_hpp */
