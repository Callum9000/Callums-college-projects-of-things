#include "player.h"

Player::Player(string description) {
    this->description = description;
}
void Player::addItem(Item &item) {
    itemsInPlayer.push_back(item);
}
void Player::addItem(Item *item) {
    itemsInPlayer.push_back(*item);
    delete item;
}

vector <Item> Player::getItems(){
    return itemsInPlayer;
}
string Player::longDescription()
{
  string ret = this->description;
  ret += "\n Item list:\n";
  for (vector<Item>::iterator i = itemsInPlayer.begin(); i != itemsInPlayer.end(); i++){
    ret += "\t"+ (*i).getLongDescription() + "\n";

  }
  return ret;
}
