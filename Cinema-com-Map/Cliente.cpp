#include "Cliente.h"

std::string Cliente::toString() {
    std::stringstream ss;
    ss << " " << id << " : " << phone << " ";
    return ss.str();
} 
std::string Cliente::getId() {
    return id;
}
std::string Cliente::getPhone() {
    return phone;
}
void Cliente::setId(std::string id) {
    this->id = id;
}
void Cliente::setPhone(std::string phone) {
    this->phone = phone;
}
