#ifndef INHERITANCE_H
#define INHERITANCE_H

//abstract class
class inheritance{
public:
    inheritance(int houseNo);

     //Virtual function
    virtual int getHouse() = 0;
protected:

    int houseNo;
};

#endif // INHERITANCE_H
