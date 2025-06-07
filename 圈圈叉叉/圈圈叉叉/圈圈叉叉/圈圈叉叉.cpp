#include<iostream>
#include<ctime>
using namespace std;
// ......................... 圈圈叉叉遊戲 ..........................//


int game[3][3] = { 0 }, player, computer;
int condition[2][3] = { {1, 5, 9}, {3, 5, 7} };
string emoji[8] = { "□", "○", "", "", "", "", "", "△"};
void print();
void input(int& target, bool fromPlayer);
void onUpdated(bool fromPlayer);
bool isContain(int num), isGameOver(), isDraw();

int main() {
	srand(time(0));
	cout << "Game start" << endl;
	print();

	do {
		if (isDraw()) { cout << "平手!!"; exit(0); }
		cout << "輸入一個1 ~ 9的數字(0 -> 跳出遊戲)\t";
		input(player, true);
		input(computer, false);
	} while (!isGameOver());
	cout << "遊戲結束" << endl;

	return 0;
}

bool isContain(int num) {
	if (game[num / 3][num % 3 - 1] != 0)
		return true;

	return false;
}

bool isGameOver() {
	for (int i = 0; i < 3; i++)
		if (game[i][0] + game[i][1] + game[i][2] == 3)
			return true;
		else if (game[i][0] + game[i][1] + game[i][2] == 21)
			return true;
	for (int i = 0; i < 3; i++)
		if (game[0][i] + game[1][i] + game[2][i] == 3)
			return true;
		else if (game[0][i] + game[1][i] + game[2][i] == 21)
			return true;
	for (int i = 0; i < 2; i++) {
		int prev = game[i][0];
		for (int j = 0; j < 3; j++) {
			if (game[condition[i][j] / 3][condition[i][j] % 3 - 1] == prev
				&& prev != 0
				&& j == 2
				) return true;
			prev = game[condition[i][j] / 3][condition[i][j] % 3 - 1];
		}
	}


	return false;
}

bool isDraw() {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (game[i][j] == 0)
				return false;
	return true;
}


void print() {
	for (int i = 0; i < 3; i++) {
		cout << endl;
		for (int j = 0; j < 3; j++)
			cout << emoji[game[i][j]];
	}
	cout << endl;
}

void input(int& target, bool fromPlayer) {
	if (!fromPlayer) {
		do {
			target = rand() % 10;
		} while (isContain(target) || target == 0);

		onUpdated(fromPlayer);
		return;
	}

	do {
		cin >> target;
		if (target == 0)
			exit(0);
		if (isContain(target))
			cout << "輸入已被標記的格子, 請在試一次!" << endl;
	} while (isContain(target));

	onUpdated(fromPlayer);
}

void onUpdated(bool fromPlayer) {
	cout << "----- 當前遊戲: -----" << endl;
	if (!fromPlayer)
		game[computer / 3][computer % 3 - 1] = 7;
	else
		game[player / 3][player % 3 - 1] = 1;

	print();
}
