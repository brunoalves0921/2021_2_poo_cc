#ifndef Agencia_H
#define Agencia_H

#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <time.h>
#include <stdio.h>
#include <algorithm>
#include <fstream>
#include "Cliente.h"
#include "contas/Conta.h"

class Agencia {
    private:
        std::map<std::string, Cliente*> clientes;
        std::map<std::string, Conta*> contas;
        std::string genValidId();
        Conta* getConta(std::string id);
    public:
        Agencia();
        void addCliente(Cliente* cliente);
        void delCliente(std::string clienteId);
        void lerArquivo();
        void salvarArquivo();
        void delConta(std::string id);
        void sacar(std::string id, double valor);
        void depositar(std::string id, double valor);
        void transferir(std::string idPag, double valor, std::string idRec);
        void attMensal();
        std::string toString();


};

#endif