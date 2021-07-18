//
//  moviemain.cpp
//  cpplec
//
//  Created by 하동준 on 2021/04/09.
//

#include <stdio.h>
#include "Movie.hpp"
#include "MovieManager.hpp"
#include "txt_read.hpp"
#include "djh.h"

int main(){
    djh::printName();
    MovieManager a("/Users/hadongjun/xcode save/cpplec/cpplec/cinema/movie.txt");
    a.startmenu();
    
    return 0;
}
