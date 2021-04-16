#ifndef ZORK_H
#define ZORK_H



#include "room.h"
#include <iostream>
#include <string>
using namespace std;
class Zork
{
private:

    Room* currentRoom;
    void createRooms();

    void goRoom();

    Room* roomry[17];



public:
    Zork();
    void play();
    string go(string direction);
    int text();
    Room* getRoomry(int i);
    Room* getRoom();
    string plot(string words);

};


#endif // ZORK_H
