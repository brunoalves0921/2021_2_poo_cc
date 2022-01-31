#include "Contact.h"

bool Contact::addPhone(Phone phone) {
    //verify if the phone is already in the list
    for (Phone &p : phones) {
        if (p.getNumber() == phone.getNumber()) {
            return false;
        }
    }
    phones.push_back(phone);
    return true;
}
void Contact::removePhone(int index) {
    phones.erase(phones.begin() + index);
}
std::string Contact::toString() {
    std::stringstream ss;
    ss << prefix << " " << name << std::endl;
    for(int i = 0; i < (int) phones.size(); i++) {
        ss << i << " - "<< "[" << phones[i].getId() << " : " << phones[i].getNumber() << "]" << std::endl;
    }
    return ss.str();
}
std::string Contact::getName() {
    return name;
}
std::string Contact::getPhones() {
    std::stringstream ss;
    for(int i = 0; i < (int) phones.size(); i++) {
        ss << phones[i].getNumber() << " ";
    }
    return ss.str();
}
void Contact::setName(std::string name) {
    this->name = name;
}