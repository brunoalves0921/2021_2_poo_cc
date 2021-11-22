#include "Phone.h"
#include "Contact.h"
#include <iostream>
void ajuda(){
    std::cout << "         Boas vindas à POO Agenda!" << std::endl;
    std::cout << "| $init <Nome> : Para inicializar a agenda" << std::endl;
    std::cout << "| $add <Operadora> <Numero> : Para adicionar um telefone" << std::endl;
    std::cout << "| $remover <Index> : Para remover um telefone" << std::endl;
    std::cout << "| $show : Para listar os telefones" << std::endl;
    std::cout << "| $end : Para sair" << std::endl;
    std::cout << "| $ajuda : Para exibir este menu de ajuda novamente" << std::endl;
}
int main () {
    Contact c;
    Phone f;
    ajuda();
    while(true){
        std::string str;
        std::cin >> str;
        if(str == "init") {
            std::string name;
            std::cin >> name;
            c = Contact(name);
            std::cout << c.toString() << std::endl;

        }
        else if(str == "add") {
            std::string id;
            std::string number;
            std::cin >> id >> number;
            if(f.isValid(number)) {
                f = Phone(id, number);
                c.addPhone(f);
                std::cout << c.toString() << std::endl;
            }
            else {
                std::cout << "Numero invalido" << std::endl;
            }
        }
        else if(str == "remover") {
            int indice;
            std::cin >> indice;
            c.removePhone(indice);
            std::cout << c.toString() << std::endl;
        }
        else if(str == "show") {
            std::cout << c.toString() << std::endl;
        }
        else if(str == "end") {
            break;
        }
        else if(str == "ajuda") {
            ajuda();
        }
        else {
            std::cout << "Comando invalido" << std::endl;
        }
    }
    return 0;
}
