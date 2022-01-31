#include "Phone.h"

bool Phone::isValid(std::string number){
    std::string valid = "0123456789().-";
    for(char c : number){
        if(valid.find(c) == std::string::npos){
            return false;
        }
    }
    return true;
}
void Phone::setId(std::string id){
    this->id = id;
}
void Phone::setNumber(std::string number){
    if(isValid(number)){
        this->number = number;
    }
}
std::string Phone::getId(){
    return id;
}
std::string Phone::getNumber(){
    return number;
}
