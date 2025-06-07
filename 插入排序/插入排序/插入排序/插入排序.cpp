#include<iostream>
using namespace std;
//....................... 插入排序法 .........................//


int main() {
	int a[5] = { 9, 6, 3, 5, 1 };
	for (int i = 0; i < 5; i++)
		for (int j = i; j > 0; j--) {
			if (a[j] > a[j - 1]) break;
			int temp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = temp;
		}

	for (int i : a)
		cout << i << " ";

	return 0;
}
