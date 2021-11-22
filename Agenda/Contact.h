#ifndef Contact_h
#define Contact_h
#include <string>
#include <sstream>
#include <vector>
#include "Phone.h"

class Contact{
private:
    std::string prefix = "->";
    std::vector<Phone> phones;
    std::string name;
public:
    Contact(std::string name = "") : name(name){}
    void addPhone(Phone phone);
    void removePhone(int index);
    void setName(std::string name);
    std::string getName();
    std::string toString();
};
#endif