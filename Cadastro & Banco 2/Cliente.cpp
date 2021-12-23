#include "Cliente.h"
#include "contas/Conta.h"


Cliente::Cliente(std::string clienteId) {
    this->clienteId = clienteId;
}

void Cliente::addConta(Conta* conta) {
    contas[conta->getId()] = conta;
}

std::string Cliente::toString() {
    std::stringstream ss;
    ss << "Cliente: " << clienteId << "\n";
    for (const auto &[key, value] : contas) {
        ss << value->toString() << "\n";
    }
    return ss.str();
}

std::string Cliente::getClienteId() {
    return clienteId;
}

Conta* Cliente::getConta(int id) {
    auto it = contas.find(id);
    if (it != contas.end()) {
        return it->second;
    }
    return nullptr;
}

