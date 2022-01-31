#ifndef Phone_h
#define Phone_h
#include <string>
#include <sstream>

class Phone{
private:
    std::string id;
    std::string number;
public:
    Phone(std::string id = "", std::string number = "") : id(id), number(number){}
    bool isValid(std::string number);
    void setId(std::string id);
    void setNumber(std::string number);
    std::string getId();
    std::string getNumber();
    std::string toString();
};

#endif