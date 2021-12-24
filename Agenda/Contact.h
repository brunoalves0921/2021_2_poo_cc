#ifndef Contact_h
#define Contact_h
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Phone.h"

class Contact{
private:
    std::string prefix = "->";
    std::string name;
public:
    std::vector<Phone> phones;
    Contact(std::string name = "") : name(name){}
    void addPhone(Phone phone);
    void removePhone(int index);
    void setName(std::string name);
    std::string getPhones();
    std::string getName();
    std::string toString();
};
#endif