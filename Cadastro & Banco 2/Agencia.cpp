#include "Agencia.h"
#include "Cliente.h"
#include "contas/Cc.h"
#include "contas/Cp.h"

Agencia::Agencia() {
    // TODO Auto-generated constructor stub

}
Conta* Agencia::getConta(int id) {
    return contas[id];
}

bool Agencia::addCliente(Cliente* cliente) {
    if (clientes.find(cliente->getClienteId()) == clientes.end()) {
        clientes[cliente->getClienteId()] = cliente;
        Cc *conta1 = new Cc(nextContaId++, cliente->getClienteId());
        Cp *conta2 = new Cp(nextContaId++, cliente->getClienteId());
        cliente->addConta(conta1);
        cliente->addConta(conta2);
        contas[conta1->getId()] = conta1;
        contas[conta2->getId()] = conta2;
        return true;
    }
    return false;
}

void Agencia::sacar(int id, double valor) {
    Conta* conta = getConta(id);
    if (conta != nullptr) {
        conta->sacar(valor);
    }
    else {
        throw std::runtime_error("Conta não encontrada");
    }
}

void Agencia::depositar(int id, double valor) {
    Conta* conta = getConta(id);
    if (conta != nullptr) {
        conta->depositar(valor);
    }
    else {
        throw std::runtime_error("Conta não encontrada");
    }
}

void Agencia::transferir(int idRec, double valor, int idPag) {
    Conta* contaPag = getConta(idRec);
    Conta* contaRec = getConta(idPag);

    if (contaPag != nullptr && contaRec != nullptr) {
        contaPag->transferir(valor, *contaRec);
    }
    else {
        throw std::runtime_error("Conta não encontrada");
    }
}

void Agencia::attMensal() {
    for (auto it = contas.begin(); it != contas.end(); it++) {
        it->second->attMensal();
    }
}

std::string Agencia::toString() {
    std::string str = "";
    for (auto it = clientes.begin(); it != clientes.end(); it++) {
        str += it->second->toString() + "\n";
    }
    return str;
}

