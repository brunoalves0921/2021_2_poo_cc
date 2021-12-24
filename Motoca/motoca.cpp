#include <iostream>
#include <sstream>
#include <vector>

struct Pessoa {
    std::string nome;
    int idade;

    Pessoa(std::string nome = "", int idade = 0) {
        this->nome = nome;
        this->idade = idade;
    }

    friend std::ostream& operator<<(std::ostream& os, const Pessoa& pessoa) {
        os << "Nome: " << pessoa.nome << " Idade: " << pessoa.idade;
        return os;
    }
};

struct Moto {
    Pessoa * pessoa;
    int tempo;
    int potencia;
    Moto(int pot):
        pessoa{nullptr}, tempo {0}, potencia{pot} {
    }

    bool inserirPessoa(Pessoa * p) {
        if (this->pessoa != nullptr) {
          std::cout << "Moto tem gente" << "\n";
          return false;
        }
        this->pessoa = p;
        return true;
    }

    std::string buzinar() {
      return "P" + std::string(this->potencia, 'e') + "m";
    }

    Pessoa * removerPessoa() {
        Pessoa * p = this->pessoa;
        this->pessoa = nullptr;
        return p;
    }

    void comprarTempo(int tempo) {
        this->tempo += tempo;
    }

    bool dirigir(int tempo) {
        if(this->pessoa == nullptr) {
            std::cout << "Nao tem gente para dirigir" << "\n";
            return false;
        }
        if(tempo > this->tempo) {
            std::cout << "So conseguiu dirigir " << this->tempo << "minutos\n";
            this->tempo = 0;
            return true;
        }
        std::cout << "Conseguiu dirigir " << this->tempo << "minutos\n";
        this->tempo = tempo;
    }

    friend std::ostream& operator<<(std::ostream& os, const Moto& m) {
        os << "Tempo: " << m.tempo << " Potencia: " << m.potencia;
        os << "[" << (m.pessoa == nullptr ? "null" : m.pessoa->nome) << "]";
        return os;
    }
};

int main() {
  Moto motoca(1);
  std::vector<Moto *> motos;
  std::vector<Pessoa *> pessoas;

  Pessoa *p = new Pessoa("Joao", 10);
  pessoas.push_back(p);
  p = new Pessoa("Maria", 8);
  pessoas.push_back(p);
  p = new Pessoa("Pedro", 12);
  pessoas.push_back(p);

  Moto *m = new Moto(1);
  motos.push_back(m);
  m = new Moto(2);
  motos.push_back(m);
  m = new Moto(3);
  motos.push_back(m);

  while(true) {
      std::string line;
      std::getline(std::cin, line);
      std::istringstream iss(line);
      std::string cmd;
      iss >> cmd;
      std::cout << "Comando: " << cmd << "\n";
      
      if (cmd == "end")
          break;
      if (cmd == "init") {
          int pot = 0;
          iss >> pot;
          motoca = Moto(pot);
      }
      else if (cmd == "show") {
          std::cout << motoca << "\n";
      }
      else if (cmd == "inserir") {
          for (unsigned int i = 0; i < pessoas.size(); i++) {
              std::cout << "["<< i << "] " << *pessoas[i] << "\n";
          }
          for (unsigned int i = 0; i < motos.size(); i++) {
              std::cout << "["<< i << "] " << *motos[i] << "\n";
          }
          int indice = 0; 
          std::cin >> indice;//pegando indice pra pessoa
          Pessoa * pessoa = pessoas[indice];
          std::cin >> indice;//pegando indice pra moto
          Moto * moto = motos[indice];
          if(!moto->inserirPessoa(pessoa))
              std::cout << "A moto está ocupada!\n";
      }
      else if (cmd == "buzinar") {
          std::cout << motoca.buzinar() << "\n";
      }
      else if (cmd == "comprar") {
          int tempo = 0;
          iss >> tempo;
          motoca.comprarTempo(tempo);
      }
      else if (cmd == "retirar") {
          Pessoa * pessoa = motoca.removerPessoa();
          if (pessoa != nullptr) {
              std::cout << "Retirou " << *pessoa << "\n";
              delete pessoa;
          }
      }
      else {
          std::cout << "Comando invalido" << "\n";
      }
   }
}