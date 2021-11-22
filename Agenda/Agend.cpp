#include "Agend.h"  // include the header file

std::vector<std::shared_ptr<Contact>>& Agend::getContacts() {
    return contacts;
}
bool Agend::addContact(Contact& contact) {
    if (getContact(contact.getName()) != nullptr) {
        return false;
    }
    contacts.push_back(std::shared_ptr<Contact>{&contact});
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


