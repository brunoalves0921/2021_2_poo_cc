#ifndef Agencia_H
#define Agencia_H

#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include "Cliente.h"
#include "contas/Conta.h"

class Agencia {
    private:
        std::map<std::string, Cliente*> clientes;
        std::map<int, Conta*> contas;
        int nextContaId = 1;
        Conta* getConta(int id);
        Cliente* getCliente(int id);
    public:
        //construtor
        Agencia();

        bool addCliente(Cliente* cliente);
        void sacar(int id, double valor);
        void depositar(int id, double valor);
        void transferir(int id, double valor, int idConta);
        void attMensal();
        std::string toString();


};

#endif