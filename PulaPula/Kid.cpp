#include "Kid.h"
void Kid::setNome(std::string nome) {
    this->nome = nome;
}
void Kid::setIdade(int idade) {
    this->idade = idade;
}

std::string Kid::getNome() {
    return nome;
}
int Kid::getIdade() {
    return idade;
}

std::string Kid::toString() {
    std::stringstream ss;
    ss << nome << ":" << idade;
    return ss.str();
}
