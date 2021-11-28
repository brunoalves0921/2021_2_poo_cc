#ifndef Agend_h
#define Agend_h

#include <vector>
#include <string>
#include <sstream>
#include <memory>
#include "Contact.h"

class Agend {
private:
    std::vector<std::shared_ptr<Contact>> contacts;
public:
    std::vector<std::shared_ptr<Contact>>& getContacts();
    bool addContact(Contact& contact);
    bool removeContact(std::string);
    Contact* getContact(std::string);
    std::string toString();
    void search(std::string);
};
#endif
