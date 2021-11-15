#ifndef Pulapula_h
#define Pulapula_h

#include "Kid.h"
#include "sstream"

class Pulapula {
private:
    std::list <Kid*> fila;
    std::list <Kid*> pulapula;
public:
    bool vaziaF();
    bool vaziaP();
    Kid* remover(std::string nome);
    void arrive(Kid* k);
    std::string entrar();
    std::string sair();
    void fechar();
    std::string toString();
};
#endif