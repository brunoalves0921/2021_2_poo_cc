#include "Cliente.h"
#include "contas/Conta.h"


Cliente::Cliente(std::string clienteId) {
    this->clienteId = clienteId;
}

void Cliente::addConta(Conta* conta) {
    contas[conta->getId()] = conta;
}
void Cliente::delConta(std::string id) {
    contas.erase(id);
}
std::vector<Conta*> Cliente::getContas() {
    std::vector<Conta*> contas;
    for (const auto &[key, value] : this->contas) {
        contas.push_back(value);
    }
    return contas;
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

Conta* Cliente::getConta(std::string id) {
    auto it = contas.find(id);
    if (it != contas.end()) {
        return it->second;
    }
    return nullptr;
}

