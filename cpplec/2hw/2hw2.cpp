//
// Created by 하동준 on 2021/03/11.
//
#include "myheader/djh.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    djh::printName();
    int choice, sum=0, amer=0, latte=0;
    bool bOnLoop = true;
    while (bOnLoop)
    {
        cout<<"1) 아메리카노(100원)  2) 카페라떼(200원)  3)결제  4) 종료\n"<<setw(3)<<"선택하세요 : ";
        cin>>choice;
        switch(choice) {
            case 1: {
                cout<<"아메리카노를 주문하셨습니다."<<endl;
                amer = amer+1;
                break;
            }
            case 2: {
                cout<<"카페라떼를 주문하셨습니다."<<endl;
                latte = latte+1;
                break;
            }
            case 3: {
                sum=100*amer+200*latte;
                cout<<"===================\n"<<"   결제금액\n===================\n"<<"아메리카노 "<<amer<<"잔 "<<100*amer<<"원입니다."<<endl;
                cout<<"카페라떼 "<<latte<<"잔 "<<200*latte<<"원\n===================\n";
                cout<<"총 "<<sum<<"원\n===================\n\n결제가 완료 되었습니다."<<endl;

                bOnLoop=false;
                break;
            }
            case 4: {
                bOnLoop=false;
                break;
            }

        }

    }





}

