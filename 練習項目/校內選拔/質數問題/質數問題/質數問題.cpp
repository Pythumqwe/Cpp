#include<iostream>
using namespace std;

bool isPrime(int n);

int a, b, l = 0;
int main() {
	cout << "輸入兩個數\n";
	cin >> a >> b;

	for (int i = a; i <= b; i++)
		if (isPrime(i)) l++;

	cout << l << "個質數\n";

	return 0;
}

bool isPrime(int n) {
	if (n == 1) return false;

	for (int i = 2; i < n; i++)
		if (n % i == 0) return false;
	return true;
}