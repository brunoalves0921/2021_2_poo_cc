#ifndef Sala_h
#define Sala_h

#include <iostream>
#include <map>
#include <iostream>
#include <sstream>
#include "Cliente.h"

class Sala {
    private:
    int capacidade;
    std::map<std::string, Cliente> cadeiras;
    public:
    Sala(int capacidade = 0){
        this->capacidade = capacidade;
    }
    std::string reservar(Cliente cliente, std::string pos);
    bool cancelar(std::string id);
    void setCapacidade(int capacidade);
    void toString();
};

#endif