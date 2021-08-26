#include "text.h"

Text::Text(int dth, int t) :thing()
{

  Day = dth;
  Month = t;
}

int Text::getDay(){
    return Day;
}

int Text::getMonth(){
    return Month;
}
//operator overloading
Text Text::operator + (Text &obj){
    Text result;
    result.Day = Day - obj.getDay();
    result.Month = Month - obj.getMonth();
    return result;
}
string Text::change(){
    Text today(12, 12), Death(4, 9);
    Text c3 = today + Death;
      return to_string(c3.Day) + " days " + to_string(c3.Month) + " months since inheriting the house, should collect the rest of his things.";
}

string Text::date(){
  //bit Structure
struct date1 d8 = {12, 1997};
cdate = ("Date: " + to_string(myMax<int>(3, 12)) + "/" + to_string(d8.m)+ "/" + to_string(d8.y));
    return cdate;

}


string Text::obj(){
    return OBJ;
}

string Text::end(){
ending = "I found all Grandpa's things time to go home";
return ending;
}
string Text::house(){
 thing->getAddr();
 return 0;
}

