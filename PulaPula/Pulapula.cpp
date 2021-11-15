#include "Pulapula.h"

bool Pulapula::vaziaF() {
    if (fila.empty()) {
        return true;
    }
    return false;
}
bool Pulapula::vaziaP() {
    if (pulapula.empty()) {
        return true;
    }
    return false;
}
Kid* Pulapula::remover(std::string nome) { 
    
    for (std::list<Kid*>::iterator it = fila.begin(); it != fila.end(); it++) {
        if ((*it)->getNome() == nome) {
            Kid* k = *it;
            fila.erase(it);
            return k;
        }
    }
    for (std::list<Kid*>::iterator it = pulapula.begin(); it != pulapula.end(); it++) {
        if ((*it)->getNome() == nome) {
            Kid* k = *it;
            pulapula.erase(it);
            return k;
        }
    }
    return nullptr;
}
void Pulapula::arrive(Kid* k) {
    fila.push_back(k);
}
std::string Pulapula::entrar() {
    std::stringstream ss;
    if (vaziaF()) {
        ss << "ERROR: Nao tem ninguem na fila\n";
    }
    else {
        this->pulapula.push_back(*(this->fila.begin()));
        this->fila.pop_front();
        ss << "Kid " << pulapula.back()->getNome() << " entrou na fila\n";
    }
    return ss.str();
}
std::string Pulapula::sair() {
    if (vaziaP()) {
        std::stringstream ss;
        ss << "ERROR: Nao tem ninguem no pula pula\n";
        return ss.str();
    }
    else {
        this->fila.push_back(*(this->pulapula.begin()));
        this->pulapula.pop_front();
        std::stringstream ss;
        ss << "Kid " << fila.back()->getNome() << " saiu do Pula-Pula\n";
        return ss.str();
    }
}
void Pulapula::fechar() {
    fila.clear();
    pulapula.clear();
}
std::string Pulapula::toString() {
    std::stringstream ss;
    ss << "Fila: [ ";
    for (std::list<Kid*>::reverse_iterator it = fila.rbegin(); it != fila.rend(); it++) {
        ss << (*it)->toString() << " ";
    }
    ss << "] PulaPula: [ "; 
    for (std::list<Kid*>::reverse_iterator it = pulapula.rbegin(); it != pulapula.rend(); it++) {
        ss << (*it)->toString() << " ";
    }
    ss << "]\n";
    return ss.str();
}
