#ifndef PLAYER_H_
#define PLAYER_H_
#include "zork.h"
#include "item.h"
#include <string>
using namespace std;
#include <vector>
using std::vector;


class Player {
private:
    string description;
     vector < Item > itemsInPlayer;
public:
    void addItem(Item &item);
    void addItem(Item *item);
    vector <Item> getItems();
    Player(string description);
    string shortDescription();
    string longDescription();

};

#endif /*PLAYER_H_*/
