#include "Sala.h"

Sala::Sala(int capacidade) {
    cadeiras = std::vector<Cliente*>(capacidade);
    for (int i = 0; i < capacidade; i++) {
        cadeiras[i] = nullptr;
    }
}

Sala::Estado Sala::reservar(std::string nome, std::string telefone, int cadeira) {
    if (cadeira < 0 || cadeira >= (int) cadeiras.size()) {
        return Estado::CADEIRA_INVALIDA;
    }
    if (cadeiras[cadeira] != nullptr) {
        return Estado::CADEIRA_OCUPADA;
    }
    for (Cliente *cliente : cadeiras) {
        if (cliente != nullptr && cliente->getNome() == nome) {
            return Estado::CLIENTE_EXISTE;
        }
    }
    cadeiras[cadeira] = new Cliente(nome, telefone);
    return Estado::SUCESSO;
}
bool Sala::cancelar(std::string nome) {
    for (Cliente *cliente : cadeiras) {
        if (cliente != nullptr && cliente->getNome() == nome) {
            delete cliente;
            cliente = nullptr;
        }
    }
    return false;
}
std::string Sala::toString() {
    std::stringstream ss;
    ss << "[";
    for (Cliente *cliente : cadeiras) {
        ss << " ";
        if (cliente != nullptr) {
            ss << cliente->toString();
        }
        else {
            ss << "-";
        }
    }
    ss << " ]";
    return ss.str();
}
