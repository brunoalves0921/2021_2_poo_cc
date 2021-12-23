//guarda de inclusão
#ifndef Cliente_H
#define Cliente_H
#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include "contas/Conta.h"

class Cliente {
    private:
    std::string clienteId;
    std::map<int, Conta*> contas;
    public:
    Cliente(std::string clienteId);

    void addConta(Conta* conta);
    std::string toString();
    std::string getClienteId();
    Conta* getConta(int id);
};

#endif