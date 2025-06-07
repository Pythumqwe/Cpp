#include<iostream>
#include"Drone.h"
using namespace std;

Drone::Drone(int x, int y, int maxX, int maxY, char dire, char command[100]) {
	this->x = x;
	this->y = y;
	this->maxX = maxX;
	this->maxY = maxY;
	this->dire = dire;
	this->isAlive = true;
	strcpy_s(this->command, command);

	this->count = 0;
}
Drone::Drone() : x(0), y(0), maxX(0), maxY(0), dire('n') {};

int Drone::indexOf() {
	for (int i = 0; i < 4; i++)
		if (dire == direList[i]) return i;
	return 0;
}

bool Drone::isTagged() {
	for (int i = 0; i < count; i++)
		if (x == tagged[i][0] && y == tagged[i][1])
			return true;
	return false;
}

bool Drone::isDestroyed() {
	return isAlive;
}

void Drone::print() {
	cout << x << " " << y << " " << dire << " " << (isAlive ? "\n" : "Destroyed\n");
}

void Drone::turn(int i) {
	if (!isAlive) return;
	int next = (indexOf() + i + 4) % 4;
	dire = direList[next];
}

void Drone::forward() {
	if (!isAlive) return;
	if (x > maxX || y > maxY) {
		if (isTagged()) return;

		x = prev[0]; y = prev[1];
		isAlive = false;
		return;
	}
	prev[0] = x;
	prev[1] = y;

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
	};
}

void Drone::onTagged(int x, int y) {
	tagged[count][0] = x;
	tagged[count][1] = y;
	count++;
}

void Drone::excute() {
	for (char cmd : command) {
		if (!cmd) return;
		if (cmd == 'F') forward();
		if (cmd == 'L') turn(-1);
		if (cmd == 'R') turn(1);
	}
}