#include <stdio.h>
#include <iostream>
#include <string>
#include "Cliente.h"
#include "contas/Cp.h"
#include "contas/Cc.h"
#include "Agencia.h"

void ajuda(){
    std::cout << "                Boas vindas ao POO Bank!" << std::endl;
    std::cout << "| $addCli <Nome> : Para adicionar um cliente ao banco" << std::endl;
    std::cout << "| $remCli <Nome> : Para remover um cliente do banco" << std::endl;
    std::cout << "| $show : Para listar todos os clientes e suas contas" << std::endl;
    std::cout << "| $depositar <id> <valor> : Para depositar um valor em uma conta" << std::endl;
    std::cout << "| $sacar <id> <valor> : Para sacar um valor em uma conta" << std::endl;
    std::cout << "| $transferir <idPag> <valor> <idReceb> : Para transferir um valor de uma conta para outra" << std::endl;
    std::cout << "| $ajuda : Para exibir este menu de ajuda novamente" << std::endl;
    std::cout << "| $reload : Para recarregar o banco de dados e atualizar os dados no terminal" << std::endl;
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
            else if (str == "remCli") {
                std::string nome;
                std::cin >> nome;
                agencia.delCliente(nome);
                std::cout << "O cliente \"" << nome << "\" foi removido com sucesso!" << std::endl;
            }

            else if(str == "sacar") {
                std::string id;
                double valor;
                std::cin >> id >> valor;
                try {
                    if (valor > 0) {
                        agencia.sacar(id, valor);
                        std::cout << "Saque realizado com sucesso!" << std::endl;
                        printf("Foi retirado : R$ %.3f da conta %s\n", valor, id.c_str());
                    }
                    else {
                        std::cout << "Valor inválido! digite um número maior que \"0\"" << std::endl;
                    }
                }
                catch(std::runtime_error &e) {
                    std::cout << e.what() << std::endl;
                }
            }

            else if(str == "depositar") {
                std::string id;
                double valor;
                std::cin >> id >> valor;
                try {
                    if(valor > 0) {
                        agencia.depositar(id, valor);
                        std::cout << "Deposito realizado com sucesso!" << std::endl;
                        printf("Foi depositado : R$ %.3f na conta %s\n", valor, id.c_str());
                    }
                    else {
                        std::cout << "Valor inválido! digite um número maior que \"0\"" << std::endl;
                    }
                }
                catch(std::runtime_error &e) {
                    std::cout << e.what() << std::endl;
                }
            }

            else if(str == "transferir") {
                std::string id;
                double valor;
                std::string idTransfer;
                std::cin >> id >> valor >> idTransfer;
                try {
                    if (valor > 0) {
                        agencia.transferir(id, valor, idTransfer);
                        std::cout << "Transferência realizada com sucesso!" << std::endl;
                        printf("Foi transferido : R$ %.3f da conta %s para a conta %s\n", valor, id.c_str(), idTransfer.c_str());
                    }
                    else {
                        std::cout << "Valor inválido! digite um número maior que \"0\"" << std::endl;
                    }
                    
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
            else if (str == "reload") {
                agencia.lerArquivo();
                std::cout << "Os dados foram carregados com sucesso\nos novos saldos dos clientes são: " << std::endl;
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
