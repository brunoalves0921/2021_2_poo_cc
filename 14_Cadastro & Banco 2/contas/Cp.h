//guarda de inclusão
#ifndef Cp_H
#define Cp_H

#include <iostream>
#include <string>
#include "Conta.h"

class Cp : public Conta {
    //construtor
    public:
    Cp(std::string id, std::string clienteId, double saldo = 0) : Conta(id, clienteId, "CP", saldo) {
    }

    void attMensal() override {
        saldo *= 1.01;
    }
};

#endif