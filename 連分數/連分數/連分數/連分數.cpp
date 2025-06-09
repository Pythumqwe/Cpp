#include<iostream>
using namespace std;
//........................ 連分數 ...........................//


int num[100], p = 0, c = 0, l;

void function(int& p, int& c, int i);
void swap();

int main() {
	cout << "輸入資料數:" << endl;
	cin >> l;
	cout << "輸入資料:" << endl;
	for (int i = 0; i < l; i++)
		cin >> num[i];
	function(p, c, l - 1);
	cout << c << " / " << p;

	return 0;
}

void function(int& p, int& c, int i) {
	if (i == l - 1) {
		p = num[i];
		c = 1;
		function(p, c, i - 1);
		return;
	}
	if (i != 0) {
		c = num[i] * p + c;
		swap();
		function(p, c, i - 1);
	}
	else {
		c = num[i] * p + c;
	}
}

void swap() {
	int temp = p;
	p = c;
	c = temp;
}
