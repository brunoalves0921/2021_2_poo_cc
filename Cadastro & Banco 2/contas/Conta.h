//guarda de inclusão
#ifndef Conta_H
#define Conta_H
#include <iostream>
#include <string>
#include <cstdio>
#include "../Cliente.h"

class Conta {
    protected:
        std::string id;
        std::string clienteId;
        std::string tipo;
        double saldo;
    public:
        Conta(std::string id, std::string clienteId, std::string tipo, double saldo): id(id), clienteId(clienteId), tipo(tipo), saldo(saldo) {
        }
        virtual ~Conta() {
        }
        virtual void attMensal() = 0;
        void checkValor(double valor) {
            if (valor < 0) {
                throw std::runtime_error("Valor invalido");
            }
        }

        virtual void sacar(double valor) {
            if (valor > saldo) {
                throw std::runtime_error("Saldo insuficiente");
            }
            checkValor(valor);
            saldo -= valor;
        }
        virtual void depositar(double valor) {
            checkValor(valor);
            saldo += valor;
        }
        virtual void transferir(double valor, Conta &conta) {
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
            std::stringstream ss;
            std::string saldoStr(20, '\0');
            auto newSize = sprintf(saldoStr.data(), "%.3f", saldo+0);
            saldoStr.resize(newSize);
            ss << "Número da conta: " << id << " Tipo: " << tipo << " Saldo: R$" << saldoStr;
            return ss.str();
        }
        std::string getId() {
            return id;
        }
        double getSaldo() {
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