#include <iostream>
#include <string>
#include <ctime>
#include "djh.h"
using namespace std;
int main() {
	

	constexpr int ROW = 6;
	constexpr int COL = 4;
	bool seats[ROW][COL]{};
	char a = 'y';
	bool condition = true;
	while (condition == true) {
		
		system("CLS");
		djh::printName();
		for (int i = 0; i < COL; i++)
			cout << '\t' << i + 1;
		cout << "\n\n";
		for (int i = 0; i < ROW; i++) {
			cout << static_cast<char>('A' + i) << '\t';
			for (int j = 0; j < COL; j++) {
				cout << (seats[i][j] ? "●" : "○") << '\t';
			}
			cout << "\n\n";
		}
		cout << "좌석 입력 (ex==> A1) : ";
		char x, y;
		cin >> x >> y;
		if (0 <= (x - 'A') && (x - 'A') <= 3 && 0 <= (y - '1') && (y - '1') <= 3) {
			if (seats[x - 'A'][y - '1']) {
				cout << " 이미 예약된 자리입니다.\n";
			}
			else {
				seats[x - 'A'][y - '1'] = true;
				cout << "예약이 완료되었습니다\n";
			}
			
			cout << "계속 예약하시려면 y 를 중단하시려면 그 외 다른 문자를 입력하시오 : ";
			system("pause");
			cin >> a;
			if (a == 'y')
				condition = true;
			else condition = false;
		}
		else
		{
			cout << "없는 좌석입니다" << endl;
			cout << "계속 예약하시려면 y 를 중단하시려면 그 외 다른 문자를 입력하시오 : ";
			system("pause");
			cin >> a;
			if (a == 'y')
				condition = true;
			else condition = false;
			
		}
			
		
	}

	return 0;
}