#include<iostream>
using namespace std;

int num[5];
int main() {
	cout << "輸入5個數字\n";
	for (int i = 0; i < 5; i++)
		cin >> num[i];

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 4 - i; j++)
			if (num[j] > num[j + 1]) {
				int temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}

	for (int i : num)
		cout << i << " ";
	cout << endl;

	return 0;
}