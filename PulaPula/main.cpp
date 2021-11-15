#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include <sstream>
#include <string>
#include "Pulapula.h"
#include "Kid.h"

int main() {
    std::shared_ptr<Pulapula> Trampoline (new Pulapula ());

    while (true) {
        std::string comando = ""; 
        std::cin >> comando;

        if (comando == "arrive") { 
            
            Kid* auxiliar = new Kid();
            std::string nome;
            int idade;
            std::cin >> nome;
            std::cin >> idade;

            auxiliar->setNome(nome);
            auxiliar->setIdade(idade);

            Trampoline->arrive(auxiliar);
            std::cout << Trampoline->toString();
        } 
        else if (comando == "entrar") {
            Trampoline->entrar();
            std::cout << Trampoline->toString();
        }
        else if (comando == "sair") {
            Trampoline->sair();
            std::cout << Trampoline->toString();
        }
        else if (comando == "show") {
            std::cout << Trampoline->toString();
        }
        else if (comando == "remover") {
            std::string nome;
            std::cin >> nome;
            Kid* removido = Trampoline->remover(nome);
            if (removido != nullptr) {
                std::cout << "Removido: " << removido->getNome() << std::endl;
                delete removido;
            }
            else {
                std::cout << "Nao encontrado" << std::endl;
            }
            std::cout << Trampoline->toString();
            
        }
        else if (comando == "fechar") {
            Trampoline->fechar();
            std::cout << Trampoline->toString();
        }
        else if (comando == "end")
            break;
        else 
            std::cout << "fail: comando invalido\n";
    }
    return 0;
}