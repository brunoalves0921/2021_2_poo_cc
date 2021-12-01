#ifndef Agend_h
#define Agend_h

#include <vector>
#include <string>
#include <sstream>
#include <memory>
#include <iostream>
#include <map>
#include "Contact.h"

class Agend {
private:
    std::map<std::string, Contact*> contacts;
public:
    bool addContact(Contact& contact);
    bool removeContact(std::string);
    void search(std::string);
    Contact* getFirstContact();
    int size();
    std::string toString();
    Contact* getContact(std::string);
};
#endif
