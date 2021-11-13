#include "Controlador.h"
#include "Sala.h"
#include "Cliente.h"

void Controlador::iniciar(){
    while(true) {
        std::string comando;
        std::cin >> comando;

        if (comando == "init") {
            int numeroCadeiras;
            std::cin >> numeroCadeiras;
            sala = Sala{numeroCadeiras};
        }
        else if (comando == "show") {
            std::cout << sala.toString() << std::endl;
        }
        else if (comando == "reservar") {
            std::string nome;
            std::cin >> nome;
            std::string telefone;
            std::cin >> telefone;
            int cadeira;
            std::cin >> cadeira;
            Sala::Estado estado = sala.reservar(nome, telefone, cadeira);
            switch (estado) {
                case Sala::Estado::SUCESSO:
                    std::cout << "Reserva feita com sucesso" << std::endl;
                    break;
                case Sala::Estado::CADEIRA_OCUPADA:
                    std::cout << "Cadeira ocupada" << std::endl;
                    break;
                case Sala::Estado::CADEIRA_INVALIDA:
                    std::cout << "Cadeira invalida" << std::endl;
                    break;
                case Sala::Estado::CLIENTE_EXISTE:
                    std::cout << "Cliente ja existe" << std::endl;
                    break;
            }
        }
        else if (comando == "cancelar") {
            std::string nome;
            std::cin >> nome;
            if (!sala.cancelar(nome))
                std::cout << "cliente nao esta no cinema" << std::endl;
        }
        else if (comando == "end") {
            break;
        }
        else {
            std::cout << "Comando invalido" << std::endl;
        }
    }
}