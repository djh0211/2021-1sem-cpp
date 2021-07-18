//
//  info.h
//  cpplec
//
//  Created by 하동준 on 2021/06/19.
//

#ifndef info_h
#define info_h

#include <iostream> //기본 출력함수
#include <cstdio>//c언어 라이브러리함수 c언어의 printf문등을 위해
//#include <conio.h> //getch, 등의 함수를 위해 포함
#include <string>      //string 문자열 을 사용하기위해
#include <cstdlib> //rand함수 사용을 위해
#include <time.h> //rand함수의 시드를 시간에서 받아오기위해
//#include "console_cont.h" //console컨트롤 윈도우api가져와서 함수 정의부
#include "MineSweeper.hpp"  //cell클래스
using namespace std;

//방향키 방향키는 실제로 키입력이 두번됨 224+방향
#define ARROWKEY 224
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
//엔터키
#define ENTER 13

//void setCursorView(bool visible)
//{
//    CONSOLE_CURSOR_INFO cursor = { 1, visible };
//    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);//콘솔 핸들
//}
////지금 커서의 위치를 x,y로 이동해주는 함수
//void gotoxy(int x, int y)
//{
//    COORD Pos = { x, y };
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); //커서 위치 변경
//}
////앞으로 콘솔에서 출력할 텍스트의 색,배경색을 바꿔줌
//void setColor(int color, int bgcolor)
//{
//    color &= 0xf; //비트 연산 f 남기고 다 0으로
//    bgcolor &= 0xf; //비트 연산
//    static HANDLE std_output_handle = GetStdHandle(STD_OUTPUT_HANDLE); //콘솔 핸들 가져오기
//    SetConsoleTextAttribute(std_output_handle, bgcolor << 4 | color); //윈도우핸들, bg를 왼쪽4비트 쉬프트+ color 하여 한 int변수 안에 배경,글자색정보 담기
//}
int get_num() {    //정수만을 받기 위한 함수 정수가 아닌 값을 받으면 다시 입력 받게
    int num;
    cin >> num;
    if (cin.fail()) {
        cout << "다시 입력하세요. : ";
        cin.clear();
        cin.ignore(256, '\n');
        return get_num();
    }
    return num;
}




#endif /* info_h */
