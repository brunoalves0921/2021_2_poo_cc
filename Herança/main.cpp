#include <iostream>

//erança entre automóveis

class Automovel {
protected:
    int velocidade = 0;
    int combustivel = 0;
    bool ligado = false;
public:
    virtual void acelerar() = 0;
    virtual void frear() = 0;
    virtual void abastecer() {
        combustivel += 10;
        std::cout << "Foi adicionado 10 litros ao tank" << std::endl;
        if (combustivel > 100) {
            combustivel = 100;
            std::cout << "Tank cheio!" << std::endl;
        }
    }
    void ligar() {
        if (!ligado) {
            ligado = true;
            std::cout << "Ligando..." << std::endl;
        }
        else {
            std::cout << "O automóvel já está ligado" << std::endl;
        }
    }
    void desligar() {
        if (ligado) {
            ligado = false;
        }
        else {
            std::cout << "O automóvel já está desligado" << std::endl;
        }
    }
    void setVelocidade(int velocidade) {
        this->velocidade = velocidade;
    }
    int getVelocidade() {
        return velocidade;
    }
    void setCombustivel(int combustivel) {
        this->combustivel = combustivel;
    }
    int getCombustivel() {
        return combustivel;
    }
    bool isLigado() {
        return ligado;
    }
};
//veiculos terrestres
class Terrestre : public Automovel {
public:
    void acelerar() {
        if (isLigado() && getCombustivel() > 0) {
            velocidade += 10;
        }
        else {
            std::cout << "O automóvel não está ligado" << std::endl;
        }
    }
    void frear() {
        if (isLigado() && velocidade > 0) {
            velocidade -= 10;
        }
        else if (isLigado() && velocidade == 0) {
            std::cout << "O automóvel já está parado" << std::endl;
        }
        else {
            std::cout << "O automóvel não está ligado" << std::endl;
        }
    }
};
class Carro : public Terrestre {
public:
    void buzinar() {
        if (isLigado()) {
            std::cout << "Peeeeem!" << std::endl;
        }
        else {
            std::cout << "O automóvel não está ligado" << std::endl;
        }
    }
    void acelerar() override{
        if (isLigado() && getCombustivel() > 0 && getVelocidade() < 120) {
            velocidade += 20;
            combustivel -= 10;
            std::cout << "O carro está a: " << velocidade << " Km/h."<< std::endl;
            if (velocidade > 120) {
                velocidade = 120;
                std::cout << "O carro está a: " << velocidade << " Km/h e está na velocidade máxima!!" << std::endl;
            }
        }
        else if (getVelocidade() == 120) {
            std::cout << "O carro está a: " << velocidade << " Km/h e está na velocidade máxima!!" << std::endl;
        }
        else if (getCombustivel() == 0) {
            std::cout << "O carro não tem combustível" << std::endl;
            while (getVelocidade() > 0) {
                velocidade -= 10;
                std::cout << "O carro está a: " << velocidade << " Km/h." << std::endl;
            }
        }
        else {
            std::cout << "O automóvel não está ligado" << std::endl;
        }
    }
    void frear() override {
        if (isLigado() && velocidade > 0) {
            velocidade -= 20;
        }
        else if (isLigado() && velocidade == 0) {
            std::cout << "O automóvel já está parado" << std::endl;
        }
        else {
            std::cout << "O automóvel não está ligado" << std::endl;
        }
    }
};
//veiculos aéreos
class Aereo : public Automovel {
    protected:
        int altitude = 0;
    public:
        virtual void voar() {
            if (isLigado() && getCombustivel() > 0) {
                velocidade += 10;
            }
            else {
                std::cout << "O automóvel não está ligado" << std::endl;
            }
        }
        void frear() {
            if (isLigado() && velocidade > 0) {
                velocidade -= 10;
            }
            else if (isLigado() && velocidade == 0) {
                std::cout << "O automóvel já está parado" << std::endl;
            }
            else {
                std::cout << "O automóvel não está ligado" << std::endl;
            }
        }
        bool isVooando() {
            if (altitude > 0) {
                return true;
            }
            else {
                return false;
            }
        }
        void setAltitude(int altitude) {
            this->altitude = altitude;
        }
        int getAltitude() {
            return altitude;
        }
};
class Aviao : public Aereo {
    public:
        void acelerar() override {
            if (isLigado() && getCombustivel() > 0) {
                velocidade += 50;
                if( velocidade <= 200)
                    std::cout << "O avião está a: " << velocidade << " Km/h." << std::endl;
                combustivel -= 50;
                if (velocidade > 200) {
                    isVooando();
                    altitude += 100;
                    std::cout << "O avião está a: " << velocidade << " Km/h e está a:"<< altitude << " m de altura"<< std::endl;
                }
            }
            else if (isLigado() && getCombustivel() == 0) {
                std::cout << "O avião não tem  mais combustível" << std::endl;
                while (getAltitude() > 0 && isVooando()) {
                    altitude -= 50;
                    velocidade += 50;
                    if (altitude <= 0) {
                        std::cout << "O avião caiu!" << std::endl;
                    }
                    else {
                        std::cout << "O avião está a: " << altitude << " metros e está a:" << velocidade << "Km/h." << std::endl;
                    }
                }
            }
            else {
                std::cout << "O avião não está ligado" << std::endl;
            }
        }
        void abastecer() override{
            combustivel += 100;
            std::cout << "O avião está com " << combustivel << " litros de combustível." << std::endl;
            if (combustivel > 1000) {
                combustivel = 1000;
                std::cout << "O avião já está com o tank cheio!" << std::endl;
            }
        }
        
};
    





int main () {

    Carro carro;
    carro.ligar();
    carro.buzinar();
    carro.abastecer();
    carro.abastecer();
    carro.abastecer();
    carro.acelerar();
    carro.acelerar();
    carro.acelerar();
    carro.acelerar();
    carro.acelerar();
    carro.acelerar();
    carro.acelerar();
    carro.acelerar();
    Aviao aviao;
    aviao.ligar();
    aviao.abastecer();
    aviao.abastecer();
    aviao.abastecer();
    aviao.abastecer();
    aviao.acelerar();
    aviao.acelerar();
    aviao.acelerar();
    aviao.acelerar();
    aviao.acelerar();
    aviao.acelerar();
    aviao.acelerar();
    aviao.acelerar();
    aviao.acelerar();
    
    return 0;
}