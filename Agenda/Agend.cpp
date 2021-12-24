#include "Agend.h"  // include the header file
#include <iostream>

std::vector<std::shared_ptr<Contact>>& Agend::getContacts() {
    return contacts;
}
bool Agend::addContact(Contact& contact) {
    Contact* newContact = getContact(contact.getName());
    if (newContact != nullptr) {
        return false;
    }
    contacts.push_back(std::shared_ptr<Contact>{&contact});
    for (int i = contacts.size() - 2; i >= 0; i--) {
        if (contacts[i]->getName() > contacts[i + 1]->getName()) {
            std::swap(contacts[i], contacts[i + 1]);
        
        }
    }
    return true;
}
bool Agend::removeContact(std::string name) {
    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if ((*it)->getName() == name) {
            contacts.erase(it);
            return true;
        }
    }
    return false;
}
Contact* Agend::getContact(std::string name) {
    for (auto& c : contacts) {
        if (c->getName() == name) {
            return &*c;
        }
    }
    return nullptr;
}
std::string Agend::toString() {
    std::stringstream ss;
    ss << "Agenda: " << std::endl;
    for (auto& c : contacts) {
        ss << c->toString() << std::endl;
    }
    return ss.str();
}
// string pattern 
void Agend::search(std::string pattern) {
    std::cout << "Searching for " << pattern << "..." << std::endl;
    //procurando nomes e telefones
    bool found = false;
    for (auto& c : contacts) {
        if (c->getName().find(pattern) != std::string::npos || c->getPhones().find(pattern) != std::string::npos) {
            std::cout << c->toString() << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "Resultado não encontrado." << std::endl;
    }
}


