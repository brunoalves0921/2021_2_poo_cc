#include "Phone.h"
#include "Contact.h"
#include "Agend.h"
#include <iostream>
#include <algorithm>

void ajuda(){
    std::cout << "                Boas vindas à POO Agenda!" << std::endl;
    std::cout << "| $add <Nome> <Operadora> <Numero> : Para adicionar um telefone" << std::endl;
    std::cout << "| $remover <Nome> <Index> : Para remover um telefone" << std::endl;
    std::cout << "| $show : Para listar os telefones" << std::endl;
    std::cout << "| $find <Letra, número ou nome> : Para pesquisar nos contatos algo relacionado" << std::endl;
    std::cout << "| $list : Para mostrar a lista com os nomes dos contatos cadastrados" << std::endl;
    std::cout << "| $ajuda : Para exibir este menu de ajuda novamente" << std::endl;
    std::cout << "| $end : Para sair" << std::endl;
}
int main () {
    Contact* currentContact = nullptr;
    Agend agenda;
    Phone f;
    ajuda();
    while(true){
        std::string str;
        std::cin >> str;
        if(str == "add") {
            std::string name;
            std::string id;
            std::string number;
            std::cin >> name >> id >> number;
            Contact* aux = new Contact(name);
            if(f.isValid(number)) {
                if (agenda.addContact(*aux)) {
                    currentContact = aux;
                }
                else {
                    currentContact = agenda.getContact(name);
                }
                f = Phone(id, number);
                if (currentContact->addPhone(f)) {
                    std::cout << "Telefone adicionado com sucesso!" << std::endl;
                }
                else {
                    std::cout << "Telefone já existente!" << std::endl;
                }
                std::cout << currentContact->toString() << std::endl;
            }
            else {
                std::cout << "Número inválido" << std::endl;
            }
        }
        else if (str != "end" && currentContact == nullptr) {
            std::cout << "Agenda está vazia, por favor ultilize o comando add <Name> <Operadora> <Número> primeiro" << std::endl;
        }
        else if (str == "remover") {
            std::string name;
            Contact* aux;
            int indice;
            std::cin >> name >> indice;
            aux = agenda.getContact(name);
            if (aux != nullptr) {
                currentContact = aux;
                currentContact->removePhone(indice);
                std::cout << currentContact->toString() << std::endl;
            }
            else {
                std::cout << "Contato não encontrado" << std::endl;
            }
        }
        else if (str == "delete") { 
            std::string nome;
            std::cin >> nome;
            agenda.removeContact(nome);
            if (agenda.size() == 0) {
                currentContact = nullptr;
                std::cout << "Agenda está vazia!" << std::endl;
            }
            else {
                currentContact = agenda.getFirstContact();
                std::cout << "Contato deletado!" << std::endl;
            }
        }
        else if (str == "show") {
            std::cout << currentContact->toString() << std::endl;
        }
        else if (str == "list") {
            std::cout << agenda.toString();
        }
        else if (str == "find") {
            std::string find;
            std::cin >> find;
            agenda.search(find);
        }
        else if (str == "ajuda") {
            ajuda();
        }
        else if (str == "end") {
            break;
        }
        else {
            std::cout << "Comando invalido!" << std::endl;
        }
    }
    return 0;
}
