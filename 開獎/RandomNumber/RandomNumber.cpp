#include<iostream>
#include<ctime>
using namespace std;
//........................ 開獎 ...........................//

int num[5] = {};
double average[3] = {0, 0, 0};
bool contain(int n, int index);
void print();
int main() {
	srand(time(0));
	for (int i = 0; i < 5; i++) {
		do {
			num[i] = rand() % 40;
		} while (num[i] == 0 || contain(num[i], i));
		cout << "第" << i + 1 << "個開獎號碼 -> " << num[i] << endl;
	}
	cout << "排序前 -> ";
	print();
	// sort //
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 4; j++)
			if (num[j] > num[j + 1]) {
				int temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
	cout << endl << "排序後 -> ";
	print();
	cout << endl;
	// get average
	for (int i : num)
		average[0] += i;
	cout << "平均 -> " << average[0] / 5 << endl;


	return 0;
}

bool contain(int n, int index) {
	for (int i = 0; i < index; i++)
		if (n == num[i])
			return true;
	return false;
}
void print() {
	for (int i : num)
		cout << i << " ";
}

