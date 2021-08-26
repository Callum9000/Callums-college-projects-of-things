#include "texti.h"
//inheritance & object construction sequence as it is inheritaing an abstract class that has to be called.
texti::texti(int houseNo, std::string addr) : inheritance(houseNo)
{
    this->addr = addr;

}
int texti::getNo(){
    return houseNo ;
}

std::string texti::getAddr(){
    return addr;
}
