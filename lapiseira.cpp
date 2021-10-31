#include <iostream>
#include <algorithm>

struct Grafite {
    float calibre;
    std::string dureza; 
    int tamanho; 

    Grafite(float calibre = 0, std::string dureza = "", int tamanho = 0) :
        calibre{calibre}, dureza{dureza}, tamanho{tamanho} {
        }

friend std::ostream& operator<<(std::ostream& os, const Grafite& grafite) {
        os << "Calibre: " << grafite.calibre << " mm, ";
        os << "Dureza: " << grafite.dureza << ", ";
        os << "Tamanho: " << grafite.tamanho << " mm\n.";
        return os;
    }
 };
 
 struct Lapiseira {
    float calibre;
    Grafite*  grafite;
    bool temGrafite;
    Lapiseira(float calibre, Grafite* grafite = nullptr) :
        calibre{calibre}, grafite{grafite} {
    }
    bool inserirGrafite(Grafite* grafite) {
        if(this->grafite != nullptr) {
            std::cout << "Tem grafite" << "\n";
            return false;
        }
        if (grafite->calibre != this->calibre) {
            std::cout << "Calibre incompatível" << "\n";
            return false;
        }
        this->grafite = grafite;
        return true;
    }

    bool retirarGrafite() {
        if(this->grafite == nullptr) {
            std::cout << "Não tem grafite" << "\n";
            return false;
        }
        this->grafite = nullptr;
        return true;
    }

    bool temGrafite() {
        return this->grafite != nullptr;
    }

    Grafite* removerGrafite() {
        if(this->grafite == nullptr) {
            std::cout << "Não tem grafite" << "\n";
            return nullptr;
        }
        return std::exchange(this->grafite, nullptr);
    }
 };


int main() {
    Grafite grafite(10, "HC", 10);

    Lapiseira Lapiseira(0.5, &grafite);
    Lapiseira.grafite->tamanho -= 5;

    std::cout << grafite.tamanho << "\n";
    std::cout << Lapiseira.grafite->tamanho << "\n";

    return 0;
}



