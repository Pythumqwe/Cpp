#include<iostream>
#include"Drone.h";
using namespace std;
//.......................無人機操控(優化)......................//

Drone drones[100] = { Drone() };

int amount;
void input();

int main() {
    input();
    
    for (int i = 0; i < amount; i++) {
        drones[i].excute();
        if (drones[i].isDestroyed()) continue;

        for (int j = i + 1; i < amount; i++) {
            drones[j].onTagged(drones[i].x, drones[i].y);
        }
    }

    for (int i = 0; i < amount; i++)
        drones[i].print();

    return 0;
}

void input() {
    int maxX, maxY, x, y;
    char dire;
    char command[100];

    cin >> amount;
    for (int i = 0; i < amount; i++) {
        if (i == 0) cin >> maxX >> maxY;
        cin >> x >> y >> dire;
        cin >> command;

        drones[i] = Drone(x, y, maxX, maxY, dire, command);
    }
}