#include<iostream>
#include<fstream>
using namespace std;

char t[100];
int main() {
	ofstream output;
	ifstream input;

	input.open("d:input.txt", ios::in);
	if (input.fail())
		return 1;

	while (!input.eof()) {
		input >> t;
		cout << t << endl;
	}
	input.close();

	return 0;
}

