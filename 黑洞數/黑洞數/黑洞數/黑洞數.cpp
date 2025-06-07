#include<iostream>
using namespace std;
//........................ 黑洞數 ...........................//

int a[4] = {};
int input, origin, _max, _min, dif;
void toArray(int a[4], int n);
void sort(int a[4], bool type); // false -> 1...5 // true -> 5...1
void swap(int& n1, int& n2);
int toNum(int a[4]);

int main() {
	cout << "輸入4位數字 ->" << endl;
	cin >> input;
	toArray(a, input);
	do {
		origin = toNum(a);
		sort(a, true);
		_max = toNum(a);
		sort(a, false);
		_min = toNum(a);
		dif = _max - _min;
		toArray(a, dif);
	} while (_max - _min != origin);
	cout << "黑洞數 -> " << origin << endl;

	return 0;
}

void toArray(int a[4], int n) {
	for (int i = 3; i >= 0; i--) {
		a[i] = n % 10;
		n = n / 10;
	}
}

void sort(int a[4], bool type) {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 3; j++)
			if (type)
				if (a[j] < a[j + 1])
					swap(a[j], a[j + 1]);
				else
					continue;
			else
				if (a[j] > a[j + 1])
					swap(a[j], a[j + 1]);
				else
					continue;
}

void swap(int& n1, int& n2) {
	int temp = n1;
	n1 = n2;
	n2 = temp;
}

int toNum(int a[4]) {
	int n = 0;
	for (int i = 0; i < 4; i++) {
		n = n + a[i];
		if (i != 3)
			n = n * 10;
	}

	return n;
}

