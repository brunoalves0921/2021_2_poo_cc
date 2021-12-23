//guarda de inclusão
#ifndef Conta_H
#define Conta_H
#include <iostream>
#include <string>
#include "../Cliente.h"

class Conta {
    protected:
        float saldo = 0;
        int id;
        std::string clienteId;
        std::string tipo;
    public:
        Conta(int id, std::string clienteId, std::string tipo): id(id), clienteId(clienteId), tipo(tipo) {
        }
        virtual ~Conta() {
        }
        virtual void attMensal() = 0;
        void checkValor(float valor) {
            if (valor <= 0) {
                throw std::runtime_error("Valor invalido");
            }
        }
        virtual void sacar(float valor) {
            if (valor > saldo) {
                throw std::runtime_error("Valor insuficiente");
            }
            checkValor(valor);
            saldo -= valor;
        }
        virtual void depositar(float valor) {
            checkValor(valor);
            saldo += valor;
        }
        virtual void transferir(float valor, Conta &conta) {
            if (valor > saldo) {
                throw std::runtime_error("Saldo insuficiente");
            }
            if (conta.id == this->id) {
                throw std::runtime_error("Nao eh possivel transferir para a mesma conta");
            }
            checkValor(valor);
            this->sacar(valor);
            conta.depositar(valor);
        }
        std::string toString() {
            return "Número da conta: " + std::to_string(id) + " Tipo: " + tipo + " Saldo: " + std::to_string(saldo);
        }
        int getId() {
            return id;
        }
        float getSaldo() {
            return saldo;
        }
        std::string getClienteId() {
            return clienteId;
        }
        virtual std::string getTipo() {
            return tipo;
        }





};

#endif