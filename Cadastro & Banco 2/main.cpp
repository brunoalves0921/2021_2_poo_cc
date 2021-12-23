#include "Cliente.h"
#include "contas/Cp.h"
#include "contas/Cc.h"
#include "Agencia.h"
#include <iostream>
#include <string>

void ajuda(){
    std::cout << "                Boas vindas ao POO Bank!" << std::endl;
    std::cout << "| $addCli <Nome> : Para adicionar um cliente ao banco" << std::endl;
    std::cout << "| $show : Para listar todos os clientes e suas contas" << std::endl;
    std::cout << "| $depositar <id> <valor> : Para depositar um valor em uma conta" << std::endl;
    std::cout << "| $sacar <id> <valor> : Para sacar um valor em uma conta" << std::endl;
    std::cout << "| $transferir <idPagador> <valor> <idReceb> : Para transferir um valor de uma conta para outra" << std::endl;
    std::cout << "| $ajuda : Para exibir este menu de ajuda novamente" << std::endl;
    std::cout << "| $exit : Para sair" << std::endl;
}
int main () {

    Agencia agencia;
    ajuda();
    while(true){
        std::string str;
        std::cin >> str;
        try {
            if(str == "addCli") {
                std::string nome;
                std::cin >> nome;
                Cliente& cliente = *new Cliente(nome);
                agencia.addCliente(&cliente);
                std::cout << "Cliente adicionado com sucesso!" << std::endl;
                std::cout << cliente.toString();
            }

            else if(str == "sacar") {
                int id;
                double valor;
                std::cin >> id >> valor;
                try {
                    agencia.sacar(id, valor);
                    std::cout << "Foi retirado : " << valor << "R$ da conta: " << id << std::endl;
                }
                catch(std::runtime_error &e) {
                    std::cout << e.what() << std::endl;
                }
            }

            else if(str == "depositar") {
                int id;
                double valor;
                std::cin >> id >> valor;
                try {
                    agencia.depositar(id, valor);
                    std::cout << "Foi depositado: " << valor << "R$ na conta: " << id << std::endl;
                }
                catch(std::runtime_error &e) {
                    std::cout << e.what() << std::endl;
                }
            }

            else if(str == "transferir") {
                int id;
                double valor;
                int idTransfer;
                std::cin >> id >> valor >> idTransfer;
                try {
                    agencia.transferir(id, valor, idTransfer);
                    std::cout << "Foi transferido: " << valor << "R$ da conta: " << id << " para a conta: " << idTransfer << std::endl;
                }
                catch(std::runtime_error &e) {
                    std::cout << e.what() << std::endl;
                }
            }

            else if(str == "attmensal") {
                agencia.attMensal();
                std::cout << "As taxas mensais foram atualizadas com sucesso\n os novos saldos dos clientes são: " << std::endl;
                std::cout << agencia.toString();
            }

            else if(str == "show") {
                std::cout << agencia.toString();
            }

            else if (str == "ajuda") {
                ajuda();
            }

            else if (str == "exit") {
                break;
            }

            else {
                throw std::runtime_error("Comando invalido");
            }
        }
        catch(std::runtime_error &e) {
            std::cout << e.what() << std::endl;
        }
    }

    return 0;
}
