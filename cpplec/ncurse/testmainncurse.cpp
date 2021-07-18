//
//  testmainncurse.cpp
//  cpplec
//
//  Created by 하동준 on 2021/06/19.
//

#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

int func1(){
    initscr();
    wprintw(stdscr, "Hello, World"); // 화면의 0행, 0열부터 Hello, World를 출력합니다.
    refresh(); // 화면에 출력하도록 합니다.
    sleep(1);
    endwin();
    return 0;
}

int main(){
    return func1();
    
    return 0;
}
