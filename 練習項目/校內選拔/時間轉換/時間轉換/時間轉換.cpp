#include<iostream>
using namespace std;

int _sec, _hour, _min;
int main() {
	cout << "輸入秒數" << endl;
	cin >> _sec;

	_min = (_sec / 60) % 60;
	_hour = _sec / 60 / 60;

	cout << _hour << "小時 " << _min << "分鐘 " << _sec % 60 << "秒\n";

	return 0;
}