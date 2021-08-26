#ifndef TEXT_H
#define TEXT_H
#include <string>
#include <iostream>
#include "texti.h"
using namespace std;

class Text
{
private:
    string cdate;
    string ending;
    int Day, Month;
    //bit structure
    struct date1{
        unsigned int m;
        unsigned int y;
    } ;
    texti* thing;
public:
    int getDay();
    int getMonth();
    Text(int d = 0, int m = 0);
    // operator overloading
    Text operator + (Text &obj);

    string change();
    string date();
    string obj();
    string end();
    string house();
};


template<typename A> A myMax(A x, A y){
    return(x > y)? x:y;
}
#endif // TEXT_H
