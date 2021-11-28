#include "Phone.h"

bool Phone::isValid(std::string number){
    for(int i = 1; i < (int) number.size(); i++){
        if(!(number[i] >= '0' || number[i] <= '9' || number[i] == '.' || number[i] == '(' || number[i] == ')')){
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
