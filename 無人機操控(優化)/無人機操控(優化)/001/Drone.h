#pragma once
class Drone {
	int maxX;
	int maxY;
	char dire;
	char command[100];
	bool isAlive;


	int count;
	int tagged[100][2];
	int prev[2] = { x, y };
	char direList[4] = {'n', 'e', 's', 'w'};
public:
	int x;
	int y;

	Drone(int x, int y, int maxX, int maxY, char dire, char command[100]);
	Drone();

	int indexOf();
	bool isTagged();
	bool isDestroyed();
	void turn(int i);
	void print();
	void forward();
	void onTagged(int x, int y);
	void excute();
};