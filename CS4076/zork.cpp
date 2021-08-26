#include "zork.h"

Zork::Zork()
{
    createRooms();

}


void Zork::createRooms()  {
    //Pointers
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *m, *n, *o, *p;

    a = new Room("door");
    b = new Room("entrance");
    c = new Room("bathroom");
    d = new Room("DiningRoom");
    d->addItem(new Item("kkey"));
    e = new Room("lib");
    e->addItem(new Item("book"));
    f = new Room("2ndFloor");
    g = new Room("kitchen");
    h = new Room("celllar");
    i = new Room("base");
    i->addItem(new Item("dmd"));
    j = new Room("study");
    k = new Room("attic");
    k->addItem(new Item("gold"));
    l = new Room("master");
    m = new Room("smallBed");
    n = new Room("balconey");
    n->addItem(new Item("pot"));
    o = new Room("enSuite");
    p = new Room("cupboard");
    p->addItem(new Item("map"));


//             (N, E, S, W)
    a->setExits(b, NULL, NULL, NULL);
    b->setExits(f, e, a, d);
    c->setExits(NULL, NULL, d, NULL);
    d->setExits(c, b, g, NULL);
    e->setExits(NULL, NULL, NULL, b);
    f->setExits(l, j, b, m);
    g->setExits(d, NULL, NULL, h);
    h->setExits(i, g, NULL, NULL);
    i->setExits(NULL, NULL, h, NULL);
    j->setExits(k, NULL, NULL, f);
    k->setExits(NULL, NULL, j, NULL);
    l->setExits(NULL, o, f, p);
    m->setExits(NULL, f, NULL, n);
    n->setExits(NULL, m, NULL, NULL);
    o->setExits(NULL, NULL, NULL, l);
    p->setExits(NULL, l, NULL, NULL);
    //array
    roomry[0] = a;
    roomry[1] = b;
    roomry[2] = c;
    roomry[3] = d;
    roomry[4] = e;
    roomry[5] = f;
    roomry[6] = g;
    roomry[7] = h;
    roomry[9] = i;
    roomry[10] = j;
    roomry[11] = k;
    roomry[12] = l;
    roomry[13] = m;
    roomry[14] = n;
    roomry[15] = o;
    roomry[16] = p;

        currentRoom = a;

}

//copy constructor
Zork::Zork(const Zork &obj){
    currentRoom = new Room;
    *currentRoom = *obj.currentRoom;
}
//destructor
Zork::~Zork(){
    delete currentRoom;
    delete roomry[17];
}
string Zork::go(string direction) {
    //Make the direction lowercase
    //transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
    //Move to the next room
    Room* nextRoom = currentRoom->nextRoom(direction);
    if( nextRoom == NULL){
        return("there isn't an exit");
    }
    else
    {
        currentRoom = nextRoom;
        return currentRoom->longDescription();
    }
}

Room* Zork::getRoomry(int i){
    return roomry[i];
}
Room* Zork::getRoom(){
    return currentRoom;
}

//string Zork::plot(string words){
//    return "hello world";
//}
