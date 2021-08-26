#ifndef ZORK_H
#define ZORK_H



#include "room.h"
#include <iostream>
#include <string>
using namespace std;
class Zork
{
//private
private:
// pointers
    Room* currentRoom;
    void createRooms();
    void goRoom();
    //arrays and pointers
    Room* roomry[17];


//public
public:
    Zork();
    Zork(const Zork &obj);
    ~Zork();
    void play();
    string go(string direction);
    int text();
    Room* getRoomry(int i);
    Room* getRoom();
    string plot(string words);
    string CrtRoom();
};


#endif // ZORK_H
