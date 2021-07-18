//
//  MovieManager.hpp
//  cpplec
//
//  Created by 하동준 on 2021/04/09.
//

#ifndef MovieManager_hpp
#define MovieManager_hpp

#include <stdio.h>
#include "Movie.hpp"
#include "txt_read.hpp"

class MovieManager{
private:
    int count=0;
    Movie** movieList;
    string f_adress;
public:
    void makeArray();
    void showArray(int);
    void func1(const string&);
    MovieManager()=delete;
    MovieManager(const string&);
    MovieManager(const MovieManager&);
    MovieManager(MovieManager&&) noexcept;
    ~MovieManager();
    void startmenu();
    void make_reservation(int);
    void cancel_reservation(int);
    void print_reservation(int);
    string getf_adress();
    void showArray2(int , int , int , Movie);





};

#endif /* MovieManager_hpp */
