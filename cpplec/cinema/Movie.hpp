//
//  Movie.hpp
//  cpplec
//
//  Created by 하동준 on 2021/04/09.
//

#ifndef Movie_hpp
#define Movie_hpp

#include <stdio.h>
#include <string>
#include "txt_read.hpp"

using namespace std;

class Movie{
private:
    string m_name;
    int m_row;
    int m_col;
    int limit;
    int reserve=0;
    int** seats;
    int** reservationnum;
public:
    Movie()=delete;
    Movie(int, txt_read);
    Movie(const Movie&);
    Movie(Movie&&) noexcept;
    ~Movie();
    int getcol();
    int getrow();
    int getlimit();
    int getreserve();
    string getname();
    int** getseats();
    int** getreservationnum();
    void plusreserve();
    void minusreserve();

    
};

#endif /* Movie_hpp */
