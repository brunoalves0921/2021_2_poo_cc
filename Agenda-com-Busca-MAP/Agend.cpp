#include "Agend.h"  // include the header file
#include "Phone.h"
#include <iostream>

bool Agend::addContact(Contact& contact) {
    Contact* newContact = contacts[contact.getName()];
    if (newContact == nullptr) {
        contacts[contact.getName()] = &contact;
        return true;
    }
    return false;
}
bool Agend::removeContact(std::string name) {
    return contacts.erase(name);
}
std::string Agend::toString() {
    std::stringstream ss;
    ss << "Agenda: " << std::endl;
    for (auto it = contacts.begin(); it != contacts.end(); it++) {
        ss << it->second->toString() << std::endl;
    }
    return ss.str();
}
Contact* Agend::getContact(std::string name) {
    return contacts[name];
}
Contact* Agend::getFirstContact() {
    return contacts.begin()->second;
}
int Agend::size() {
    return contacts.size();
}
void Agend::search(std::string pattern) {
    std::cout << "Searching for " << pattern << "..." << std::endl;
    //procurando nomes e telefones
    bool found = false;
    for (auto& c : contacts) {
        if (c.first.find(pattern) != std::string::npos || c.second->getPhones().find(pattern) != std::string::npos) {
            std::cout << c.second->toString() << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "Resultado não encontrado." << std::endl;
    }
}



