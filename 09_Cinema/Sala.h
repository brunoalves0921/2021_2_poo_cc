#ifndef defined_Sala_h
#define defined_Sala_h
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include "Cliente.h"

class Sala {
    private:
        std::map<int, Cliente*> cadeiras;
    public:
        enum Estado {
            CADEIRA_OCUPADA,
            CADEIRA_INVALIDA,
            CLIENTE_EXISTE,
            SUCESSO,
        };
        Estado reservar(std::string nome, std::string telefone, int cadeira);
        bool cancelar(std::string nome);
        std::string toString();
};

#endif // defined_Sala_h