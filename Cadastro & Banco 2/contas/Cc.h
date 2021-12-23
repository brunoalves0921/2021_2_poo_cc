#ifndef Cc_H
#define Cc_H

#include <iostream>
#include <string>
#include "Conta.h"

class Cc : public Conta {
    //construtor
    public:
    Cc(int id, std::string clienteId) : Conta(id, clienteId, "CC") {
    }
    void attMensal() override{
        saldo -= 20;
    }
};

#endif
