#include "Sala.h"
#include "Cliente.h"

std::string Sala::reservar(Cliente cliente, std::string pos){
    if (cadeiras.find(pos) != cadeiras.end()){
        return "Esta posição já está ocupada";
    }
    else{
        cadeiras.insert(std::pair<std::string, Cliente> (pos, cliente));
        return "Reserva realizada com sucesso";
    }
}
bool Sala::cancelar(std::string id){
    for(auto it = cadeiras.begin(); it != cadeiras.end(); it++){
        if(it->second.getId() == id){
            cadeiras.erase(it);
            return true;
        }
    }
    return false;
}
void Sala::setCapacidade(int capacidade){
    this->capacidade = capacidade;
}
void Sala::toString(){
    std::stringstream ss;
    ss << "[";
    for(int i=0; i<this->capacidade; i++){
        if(cadeiras.find(std::to_string(i)) != cadeiras.end()){
            ss <<  cadeiras.find(std::to_string(i))->second.toString();
        
        }else{
            ss << " - ";
        }
    }
    ss << "]" << std::endl;
    std::cout << ss.str();
    }