//
//  MineSweeper.cpp
//  cpplec
//
//  Created by 하동준 on 2021/06/19.
//

#include "MineSweeper.hpp"
#include "info.h"


MineSweeper::MineSweeper():isChecked(false),isBoom(false),isHide(true),nearBomb(0){
    
}
MineSweeper::~MineSweeper(){
    
}
MineSweeper** MineSweeper::init(int& row, int& col){
    cout<<"지뢰찾기의 사이즈를 입력하세요 ex. 가로 세로"<<endl;
    col = get_num();
    row = get_num();
    MineSweeper** map = new MineSweeper*[row];
    for (int i=0; i<col; i++) {
        map[i] = new MineSweeper[col];
    }
    return map;
}
void MineSweeper::hideBombs(MineSweeper** (&map), const int& row, const int& col, int& bomb_num){
    cout<<"지뢰의 총 개수를 입력하세요"<<endl;
    bomb_num = get_num();
    while (bomb_num >= row*col) {
        cout<<"지뢰개수는 지뢰찾기 칸 수보다 작아야합니다. 다시 입력하세요."<<endl;
        bomb_num = get_num();
    }
    for (int i = 0; i<bomb_num; i++) {
        int temp_row = rand() % row;
        int temp_col = rand() % col;
        
        if (map[temp_row][temp_col].isBoom == true) {
            i--;
            continue;
        }
        else{
            map[temp_row][temp_col].isBoom = true;
            if (temp_row > 0) {
                map[temp_row-1][temp_col].nearBomb++;
                if (temp_col>0) {
                    map[temp_row-1][temp_col-1].nearBomb++;
                }
                if (temp_col<col-1) {
                    map[temp_row-1][temp_col+1].nearBomb++;
                }
                if (temp_row < row - 1) {
                    map[temp_row + 1][temp_col].nearBomb++;
                    if (temp_col > 0) map[temp_row +1][temp_col - 1].nearBomb++;
                    if (temp_col < col - 1) map[temp_row + 1][temp_col + 1].nearBomb++;
                }
                if (temp_col > 0) map[temp_row][temp_col - 1].nearBomb++;
                if (temp_col < col - 1) map[temp_row][temp_col + 1].nearBomb++;
                
            }
        }
    }
}
void MineSweeper::start(){
    MineSweeper** map;
    int row, col, bomb_num;
    count = 0;
    int here_x = 0;
    int here_y = 0;
    map = init(row, col);
    hideBombs(map, row, col, bomb_num);
//    setCursorView(false);
    while (count + bomb_num) {
        <#statements#>
    }
}



