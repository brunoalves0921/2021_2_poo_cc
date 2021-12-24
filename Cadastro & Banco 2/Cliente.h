//guarda de inclusão
#ifndef Cliente_H
#define Cliente_H
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include "contas/Conta.h"

class Cliente {
    private:
    std::string clienteId;
    std::map<std::string, Conta*> contas;
    public:
    Cliente(std::string clienteId);

    void addConta(Conta* conta);
    void delConta(std::string id);
    std::string toString();
    std::string getClienteId();
    std::vector<Conta*> getContas();
    Conta* getConta(std::string id);
};

#endif