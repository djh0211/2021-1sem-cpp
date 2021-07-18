//
//  txt_read.hpp
//  cpplec
//
//  Created by 하동준 on 2021/04/09.
//

#ifndef txt_read_hpp
#define txt_read_hpp

#include <stdio.h>
#include <string>

using namespace std;

class txt_read{
public:
    string* name;
    string* rc;
    string address;
    int movie_num;
    void getinfo();
    txt_read()=delete;
    txt_read(const std::string&);
    txt_read(const txt_read &);
    txt_read(txt_read &&) noexcept;
    ~txt_read();
};



#endif /* txt_read_hpp */
