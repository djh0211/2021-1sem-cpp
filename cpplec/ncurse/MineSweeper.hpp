//
//  MineSweeper.hpp
//  cpplec
//
//  Created by 하동준 on 2021/06/19.
//

#ifndef MineSweeper_hpp
#define MineSweeper_hpp

#include <stdio.h>
#include "info.h"

class MineSweeper{
    bool isChecked; bool isBoom; bool isHide;
    int nearBomb;
    static int count;
public:
    MineSweeper();
    ~MineSweeper();
    MineSweeper** init(int& row, int& col);
    void hideBombs(MineSweeper** (&map), const int& row, const int& col, int& bomb_num);
    void start();
};

#endif /* MineSweeper_hpp */
