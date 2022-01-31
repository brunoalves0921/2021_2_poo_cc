#ifndef Kid_H
#define Kid_H

#include <string>
#include <sstream>
#include <list>
#include <string>

class Kid {
private:
    std::string nome;
    int idade;    
public:
    Kid(std::string nome = "", int idade = 0) : nome{nome}, idade{idade} {}
    void setNome(std::string nome);
    void setIdade(int idade);
    std::string getNome();
    int getIdade();
    std::string toString();
};
#endif
