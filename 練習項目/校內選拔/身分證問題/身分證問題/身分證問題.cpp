#include<iostream>
using namespace std;

int to(char c);
int first(char c);

char userId[10];
int m = 8, total = 0;
int main() {
	cout << "輸入身分證號\n";
	for (int i = 0; i < 10; i++)
		cin >> userId[i];

	total = total + first(userId[0]);
	total = total + to(userId[9]);

	for (int i = 1; i < 9; i++) {
		total = total + to(userId[i]) * m;
		m--;
	}
	
	cout << (total % 10 == 0 ? "正常" : "不正常") << endl;

	return 0;
}

int to(char c) {
	switch (c) {
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		default: return 0;
	}
}
int first(char c) {
	char clist[] = {
		'A', 'B', 'C', 'D',
		'E', 'F', 'G', 'H',
		'J', 'K', 'L', 'M',
		'N', 'O', 'P', 'Q',
		'R', 'S', 'T', 'U',
		'V', 'W', 'X', 'Y',
		'Z', 'I'
	};
	int vlist[] = {
		10, 11, 12, 13,
		14, 15, 16, 17, 
		18, 19, 20, 21,
		22, 35, 23, 24,
		25, 26, 27, 28,
		29, 32, 30, 31,
		33, 34
	};

	
	for (int i = 0; i < 26; i++)
		if (c == clist[i]) return vlist[i] % 10 * 9 + vlist[i] / 10;
			
}