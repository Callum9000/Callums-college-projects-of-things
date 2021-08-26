#ifndef TEXTI_H
#define TEXTI_H
#include <string>
#include "inheritance.h"
// pre processor directives
#define OBJ "Objective: find all 6 items to win"
class texti: public inheritance{
private:
 std::string addr;
public:
    texti(int houseNo, std::string addr);
    int getNo();
    std::string getAddr();

};

#endif // TEXTI_H
