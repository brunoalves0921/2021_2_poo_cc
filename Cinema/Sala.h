#ifndef defined_Sala_h
#define defined_Sala_h
#include <iostream>
#include <string>
#include <vector>
#include "Cliente.h"
#include <sstream>

class Sala {
    private:
        std::vector<Cliente*> cadeiras;

    public:
        enum Estado {
            CADEIRA_OCUPADA,
            CADEIRA_INVALIDA,
            CLIENTE_EXISTE,
            SUCESSO,
        };
        Sala(int capacidade = 0);
        ~Sala();
        Estado reservar(std::string nome, std::string telefone, int cadeira);
        bool cancelar(std::string nome);
        std::string toString();
};

#endif // defined_Sala_h