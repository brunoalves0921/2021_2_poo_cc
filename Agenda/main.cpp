#include "Phone.h"
#include "Contact.h"
#include "Agend.h"
#include <iostream>
void ajuda(){
    std::cout << "         Boas vindas à POO Agenda!" << std::endl;
    std::cout << "| $init <Nome> : Para inicializar a agenda" << std::endl;
    std::cout << "| $add <Operadora> <Numero> : Para adicionar um telefone" << std::endl;
    std::cout << "| $remover <Index> : Para remover um telefone" << std::endl;
    std::cout << "| $show : Para listar os telefones" << std::endl;
    std::cout << "| $end : Para sair" << std::endl;
    std::cout << "| $select <Nome>: Para selecionar qual contato deseja modificar" << std::endl;
    std::cout << "| $list : Para mostrar a lista com os nomes dos contatos cadastrados" << std::endl;
    std::cout << "| $ajuda : Para exibir este menu de ajuda novamente" << std::endl;
}
int main () {
    Contact* currentContact = nullptr;
    Agend agenda;
    Phone f;
    ajuda();
    while(true){
        std::string str;
        std::cin >> str;
        if(str == "init") {
            std::string name;
            std::cin >> name;
            currentContact = new Contact(name);
            agenda.addContact(*currentContact);
            std::cout << currentContact->toString() << std::endl;
        }
        else if (str != "end" && currentContact == nullptr) {
            std::cout << "Agenda está vazia, por favor ultilize o comando init <Name> primeiro" << std::endl;
        }
        else if(str == "add") {
            std::string id;
            std::string number;
            std::cin >> id >> number;
            if(f.isValid(number)) {
                f = Phone(id, number);
                currentContact->addPhone(f);
                std::cout << currentContact->toString() << std::endl;
            }
            else {
                std::cout << "Numero invalido" << std::endl;
            }
        }
        else if(str == "select") {
            std::string nome;
            std::cin >> nome;
            if (nome == currentContact->getName()) {
                std::cout << "Contato já estava selecionado!" << std::endl;
            }
            else {
                Contact* aux = agenda.getContact(nome);
                if (aux != nullptr) {
                    currentContact = aux;
                    std::cout << "Contato selecionado!" << std::endl;
                }
                else {
                    std::cout << "Contato não encontrado!" << std::endl;
                }
            }
        }
        else if (str == "remover") {
            int indice;
            std::cin >> indice;
            currentContact->removePhone(indice);
            std::cout << currentContact->toString() << std::endl;
        }
        else if (str == "delete") {
            std::string nome;
            std::cin >> nome;
            agenda.removeContact(nome);
            if (agenda.getContacts().size() == 0) {
                currentContact = nullptr;
            }
            else {
                currentContact = &*agenda.getContacts()[0];
            }
        }
        else if (str == "show") {
            std::cout << currentContact->toString() << std::endl;
        }
        else if (str == "list") {
            std::cout << agenda.toString();
        }
        else if (str == "ajuda") {
            ajuda();
        }
        else if (str == "end") {
            break;
        }
        else if (str == "ajuda") {
            ajuda();
        }
        else {
            std::cout << "Comando invalido" << std::endl;
        }
    }
    return 0;
}
