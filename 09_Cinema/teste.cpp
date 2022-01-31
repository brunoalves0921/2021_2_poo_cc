#include <map>
#include <string>
#include <iostream>


int main () {

    std::map<int, std::string> mapa;
    mapa[1] = "um";
    mapa[2] = "dois";
    if (mapa[1] != "") {
        std::cout << "ja existe" << std::endl;
    }
    if (mapa[3] == "") {
        std::cout << "nao existe" << std::endl;
    }

    return 0;   
}