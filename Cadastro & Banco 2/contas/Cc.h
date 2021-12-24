#ifndef Cc_H
#define Cc_H

#include <iostream>
#include <string>
#include "Conta.h"

class Cc : public Conta {
    //construtor
    public:
    Cc(std::string id, std::string clienteId, double saldo = 0) : Conta(id, clienteId, "CC", saldo) {
    }
    void attMensal() override{
        saldo -= 20;
    }
};

#endif
