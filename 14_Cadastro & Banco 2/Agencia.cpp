#include "Agencia.h"
#include "Cliente.h"
#include "contas/Cc.h"
#include "contas/Cp.h"

Agencia::Agencia() {
    srand(time(NULL));
    lerArquivo();
}
std::string Agencia::genValidId() {
    const std::string validChar = "1234567890";
    std::stringstream ss;
    do {
        ss.clear();
        for (int i = 0; i < 5; i++) {
            ss << validChar[rand() % validChar.length()];
        }
        ss << "-" << validChar[rand() % validChar.length()];
    } while (contas.find(ss.str()) != contas.end());
    return ss.str();
}
void Agencia::salvarArquivo() {
    std::ofstream f;
    f.open("agencia.txt");
    for (const auto &[id, conta] : contas) {
        f << conta->getClienteId() << " " << conta->getId() << " " << conta->getTipo() << " " << conta->getSaldo() << "\n";
    }
    f.close();
}
void Agencia::lerArquivo() {
    std::ifstream f;
    f.open("agencia.txt");
    std::string clienteId, id, tipo;
    double saldo;
    Conta* conta;
    Cliente* cliente;
    while (f >> clienteId >> id >> tipo >> saldo) {
        if (tipo == "CP") {
            conta = new Cp(id, clienteId, saldo);
        } else {
            conta = new Cc(id, clienteId, saldo);
        }
        if (clientes.find(clienteId) == clientes.end()) {
            cliente = new Cliente(clienteId);
            clientes[clienteId] = cliente;
        }
        else {
            cliente = clientes[clienteId];
        }
        cliente->addConta(conta);
        contas[id] = conta;
    }
    f.close();
}
Conta* Agencia::getConta(std::string id) {
    return contas[id];
}

void Agencia::addCliente(Cliente* cliente) {
    if (clientes.find(cliente->getClienteId()) == clientes.end()) {
        clientes[cliente->getClienteId()] = cliente;
        Cc *conta1 = new Cc(genValidId(), cliente->getClienteId());
        contas[conta1->getId()] = conta1;
        Cp *conta2 = new Cp(genValidId(), cliente->getClienteId());
        contas[conta2->getId()] = conta2;
        cliente->addConta(conta1);
        cliente->addConta(conta2);
        salvarArquivo();
    }
    else {
        throw std::runtime_error("Cliente ja existe");
    }
}
void Agencia::delCliente(std::string clienteId) {
    if (clientes.find(clienteId) != clientes.end()) {
        Cliente* cliente = clientes[clienteId];
        for (Conta* conta : cliente->getContas()) {
            cliente->delConta(conta->getId());
            delConta(conta->getId());
        }
        clientes.erase(clienteId);
        salvarArquivo();
    }
    else {
        throw std::runtime_error("Cliente nao encontrado");
    }
}
void Agencia::delConta(std::string id) {
    if (contas.find(id) != contas.end()) {
        contas.erase(id);
    }
    else {
        throw std::runtime_error("Conta nao encontrada");
    }
}

void Agencia::sacar(std::string id, double valor) {
    Conta* conta = getConta(id);
    if (conta != nullptr) {
        conta->sacar(valor);
        salvarArquivo();
    }
    else {
        throw std::runtime_error("Conta não encontrada");
    }
}

void Agencia::depositar(std::string id, double valor) {
    Conta* conta = getConta(id);
    if (conta != nullptr) {
        conta->depositar(valor);
        salvarArquivo();
    }
    else {
        throw std::runtime_error("Conta não encontrada");
    }
}

void Agencia::transferir(std::string idRec, double valor,std::string idPag) {
    Conta* contaPag = getConta(idRec);
    Conta* contaRec = getConta(idPag);

    if (contaPag != nullptr && contaRec != nullptr) {
        contaPag->transferir(valor, *contaRec);
        salvarArquivo();
    }
    else {
        throw std::runtime_error("Conta não encontrada");
    }
}

void Agencia::attMensal() {
    if (contas.size() > 0) {
        for (auto it = contas.begin(); it != contas.end(); it++) {
            it->second->attMensal();
        }
        salvarArquivo();
    }
    else {
        throw std::runtime_error("Nenhuma conta cadastrada");
    }
}

std::string Agencia::toString() {    
    if (contas.size() > 0) {
        std::stringstream ss;
        for (auto it = clientes.begin(); it != clientes.end(); it++) {
            std::string saldoFormatado = it->second->toString();
            std::replace (saldoFormatado.begin(), saldoFormatado.end(), '.', ',');
            ss << saldoFormatado << "\n";
        }
        return ss.str();
    }
    else {
        throw std::runtime_error("Nenhuma conta cadastrada");
    }
}

