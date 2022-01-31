#include <iostream>
#include <map>
#include <vector>
#include <sstream>
 
//aluno.hpp
class Disciplina;
class Aluno {
    std::string nome;
    std::map<std::string, Disciplina*> disciplinas;
public:
    Aluno(std::string nome) : nome(nome) {}
    void addDisciplina(Disciplina * disciplina);
    void rmDisciplina(std::string nome);
 
    std::string getNome(){return nome; }
    friend std::ostream& operator<<(std::ostream& os, const Aluno& aluno);
};
 
//disciplina.hpp
//include <aluno.hpp>
class Disciplina {
    std::string nome;
    std::map<std::string, Aluno*> alunos;
public:
    Disciplina(std::string nome) : nome(nome) {}
    void addAluno(Aluno * aluno);
    void rmAluno(std::string nome);
    std::string getNome(){return nome;}
    friend std::ostream& operator<<(std::ostream& os, const Disciplina& disciplina);
};
 
 
 
 
//aluno.cpp
//include disciplina.hpp
void Aluno::addDisciplina(Disciplina * disciplina) {
    auto key = disciplina->getNome();
    if(disciplinas.find(key) != disciplinas.end())
        return;
    this->disciplinas[key] = disciplina;
    disciplina->addAluno(this);
}
void Aluno::rmDisciplina(std::string nome) {
    auto key = nome;
    if(disciplinas.find(key) == disciplinas.end())
        return;
    this->disciplinas[key]->rmAluno(this->nome);
    this->disciplinas.erase(key);
}
 
std::ostream& operator<<(std::ostream& os, const Aluno& aluno) {
    os << "Aluno: " << aluno.nome << std::endl;
    for(auto& [key, value] : aluno.disciplinas)
        os << " " << value->getNome();
    return os;
}
 
//disciplina.cpp
void Disciplina::addAluno(Aluno * aluno) {
    auto key = aluno->getNome();
    if(alunos.find(key) != alunos.end())
        return;
    this->alunos[key] = aluno;
    aluno->addDisciplina(this);
}
void Disciplina::rmAluno(std::string nome) {
    auto key = nome;
    if(alunos.find(key) == alunos.end())
        return;
    this->alunos[key]->rmDisciplina(this->nome);
    this->alunos.erase(key);
}
 
std::ostream& operator<<(std::ostream& os, const Disciplina& disciplina) {
    os << "Disciplina: " << disciplina.nome << std::endl;
    for(auto& [key, value] : disciplina.alunos)
        os << " " << value->getNome();
    return os;
}
 
int main() {
    Aluno joao("Joao");
    Aluno maria("Maria");
    Aluno pedro("Pedro");
 
    Disciplina kungfu("KungFu");
    Disciplina redacao("Redacao");
 
    joao.addDisciplina(&kungfu);
    maria.addDisciplina(&kungfu);
    maria.addDisciplina(&redacao);
    pedro.addDisciplina(&redacao);
 
    std::cout << joao << std::endl;
    std::cout << maria << std::endl;
    std::cout << pedro << std::endl;
 
    std::cout << kungfu << std::endl;
    std::cout << redacao << std::endl;

    joao.rmDisciplina("KungFu");
    maria.rmDisciplina("KungFu");
    redacao.rmAluno("Maria");

    std::cout << joao << std::endl;
    std::cout << maria << std::endl;

    return 0;
}