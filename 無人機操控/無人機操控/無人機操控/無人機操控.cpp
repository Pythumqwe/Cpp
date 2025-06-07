#include<iostream>
#include<cmath>
#include<fstream>
#include<string>
using namespace std;
//.......................無人機..........................//

class Drone {
	int indexOf() {
		for (int i = 0; i < 4; i++)
			if (list[i] == dire)
				return i;
		return 0;
	}
public:
	int x;
	int y;
	int maxX;
	int maxY;
	int previous[2] = { x, y };
	int pos[100][2] = {};
	int destroyedDrone = 0;
	char command[100];
	char dire;
	bool isDestroyed = false;

	char list[4] = { 'n', 'e', 's', 'w' };

	Drone(int x, int y, int maxX, int maxY, char dire, char command[100]) {
		this->x = x;
		this->y = y;
		this->maxX = maxX;
		this->maxY = maxY;
		this->dire = dire;
		strcpy_s(this->command, 100, command);
	}
	Drone() : x(0), y(0), maxX(0), maxY(0), dire('a'), command() {}; // 預設建構式

	void turn(int dire) {
		if (isDestroyed) return;
		int next = (indexOf() + dire + 4) % 4;
		this->dire = list[next];
	}
	void tag(int x, int y) {
		this->pos[destroyedDrone][0] = x;
		this->pos[destroyedDrone][1] = y;
		destroyedDrone = destroyedDrone + 1;
	}
	bool isPos() {
		for (int i = 0; i < destroyedDrone; i++)
			if (x != pos[i][0] && y != pos[i][1]) continue;
			else return true;

		return false;
	}
	void forword() {
		if (isDestroyed) return;
		if (x > maxX || y > maxY) {
			if (isPos()) return;

			isDestroyed = true;
			return;
		}

		previous[0] = x;
		previous[1] = y;
		switch (dire) {
			case 'n':
				y = y + 1;
				break;
			case 'e':
				x = x + 1;
				break;
			case 's':
				y = y - 1;
				break;
			default:
				x = x - 1;
				break;
		}
	}
	void action() {
		for (char cmd : command) {
			if (!cmd) return;
			if (cmd == 'L') turn(-1);
			if (cmd == 'R') turn(1);
			if (cmd == 'F') forword();
		}
	}
	void print() {
		if (isDestroyed) {
			cout << previous[0] << " " << previous[1] << " " << dire;
			cout << (isDestroyed ? "Destroyed\t" : "\t");
			return;
		}

		cout << "x: " << x << endl;
		cout << "y: " << y << endl;
		cout << "dire: " << dire << " ";
		cout << (isDestroyed ? "Destroyed\t" : "\t");
	}

};
void input(fstream& stream);
void output(ofstream& writer);
void getLength(ifstream& reader);

Drone spawn(ifstream& reader);
Drone drones[100];

int amount, maxX, maxY, x, y, destroyed;
char dire, command[100];

int main() {
	fstream stream;
	ifstream reader;
	ofstream writer;

	input(stream);
	getLength(reader);

	cout << endl << endl;
	for (int i = 0; i < amount; i++) {
		drones[i] = spawn(reader);
		drones[i].action();
		if (!drones[i].isDestroyed) continue;
		for (int j = i + 1; j < amount; j++)
			drones[j].tag(drones[i].x, drones[i].y);
	}
	reader.close();
	output(writer);

	for (int i = 0; i < amount; i++)
		drones[i].print();


	return 0;
}

void input(fstream& stream) {
	stream.open("d:input.txt", ios::out);
	if (stream.fail())
		return;

	cin >> amount;
	stream << amount << endl;

	for (int i = 0; i < amount; i++) {
		cin >> maxX >> maxY;
		stream << maxX << " " << maxY << endl;
		cin >> x >> y >> dire;
		stream << x << " " << y << " " << dire << endl;
		cin >> command;
		stream << command << endl;
	}

	stream.close();
}
void output(ofstream& writer) {
	writer.open("d:output.txt", ios::out);
	if (writer.fail())
		return;

	for (int i = 0; i < amount; i++)
		if (drones[i].isDestroyed)
			writer << drones[i].previous[0] << " " << drones[i].previous[1] << " " << drones[i].dire << (drones[i].isDestroyed ? " Destroyed" : "\n");
		else
			writer << drones[i].x << " " << drones[i].y << " " << drones[i].dire << (drones[i].isDestroyed ? " Destroyed" : "\n");

	writer.close();
}
void getLength(ifstream& reader) {
	reader.open("d:input.txt", ios::in);
	reader >> amount;
}

Drone spawn(ifstream& reader) {
	if (reader.fail() || !reader)
		return Drone(0, 0, 0, 0, 'a', command);

	reader >> maxX >> maxY;
	reader >> x >> y >> dire;
	reader >> command;

	return Drone(x, y, maxX, maxY, dire, command);
}