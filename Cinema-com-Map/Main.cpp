#include "Cliente.h"
#include "Sala.h"

int main () {
    Sala sala;
    while(true){
        std::string cmd;
        std::getline(std::cin, cmd);
        std::stringstream ss(cmd);
        std::string op;
        ss >> op;
        if(op == "sair") {
            break;
        }
        else if(op == "init") {
            int capacidade;
            ss >> capacidade;
            sala.setCapacidade(capacidade);
            std::cout << "Sala inicializada com sucesso" << std::endl;
        }
        else if (op == "reservar") {
            std::string id, phone, pos;
            ss >> id >> phone >> pos;
            Cliente cliente(id, phone);
            ss << sala.reservar(cliente, pos) << std::endl;
        }
        else if (op == "cancelar") {
            std::string id;
            ss >> id;
            if (sala.cancelar(id) == true) {
                std::cout << "Reserva cancelada com sucesso" << std::endl;
            }
            else {
                std::cout << "Reserva nao encontrada" << std::endl;
            }
        }
        else if (op == "show") {
            sala.toString();
        }
        else {
            std::cout << "Comando invalido" << std::endl;
        }
    }
}