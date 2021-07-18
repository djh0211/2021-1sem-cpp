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
				cout << (seats[i][j] ? "��" : "��") << '\t';
			}
			cout << "\n\n";
		}
		cout << "�¼� �Է� (ex==> A1) : ";
		char x, y;
		cin >> x >> y;
		if (0 <= (x - 'A') && (x - 'A') <= 3 && 0 <= (y - '1') && (y - '1') <= 3) {
			if (seats[x - 'A'][y - '1']) {
				cout << " �̹� ����� �ڸ��Դϴ�.\n";
			}
			else {
				seats[x - 'A'][y - '1'] = true;
				cout << "������ �Ϸ�Ǿ����ϴ�\n";
			}
			
			cout << "��� �����Ͻ÷��� y �� �ߴ��Ͻ÷��� �� �� �ٸ� ���ڸ� �Է��Ͻÿ� : ";
			system("pause");
			cin >> a;
			if (a == 'y')
				condition = true;
			else condition = false;
		}
		else
		{
			cout << "���� �¼��Դϴ�" << endl;
			cout << "��� �����Ͻ÷��� y �� �ߴ��Ͻ÷��� �� �� �ٸ� ���ڸ� �Է��Ͻÿ� : ";
			system("pause");
			cin >> a;
			if (a == 'y')
				condition = true;
			else condition = false;
			
		}
			
		
	}

	return 0;
}