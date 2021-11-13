#include "Cliente.h"

Cliente::Cliente(std::string nome, std::string telefone) : nome(nome), telefone(telefone) {}

std::string Cliente::getNome() {
    return nome;
}
std::string Cliente::getTelefone() {
    return telefone;
}
std::string Cliente::toString() {
    return nome + ":" + telefone;
}