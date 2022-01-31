#ifndef Cliente_h
#define Cliente_h

#include <iostream>
#include <map>
#include <iostream>
#include <sstream>

class Cliente {
    private: 
    std::string id;
    std::string phone;
    public:
    Cliente(std::string id, std::string phone){
        this->id = id;
        this->phone = phone;
    }
    std::string toString();
    std::string getId();
    std::string getPhone();
    void setId(std::string id);
    void setPhone(std::string phone);
};

#endif