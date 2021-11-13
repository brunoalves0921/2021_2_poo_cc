#ifndef defined_Cliente_h
#define defined_Cliente_h
#include <iostream>
#include <string>


class Cliente {
    std::string nome;
    std::string telefone;

    public:
        Cliente(std::string nome, std::string telefone);
        std::string getNome();
        std::string getTelefone();
        std::string toString();
};

#endif // defined_Cliente_h
