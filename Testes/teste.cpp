//programa para pingar um ip
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

static string host;
static string ping_again;

void ping() {
    system("clear");
    cout << "Digite o ip que deseja pingar: ";
    cin >> host;
    system(("ping " + host).c_str());
    cout << endl;
    cout << "Deseja pingar outro ip? (s/n) ";
    cin >> ping_again;
    if (ping_again == "s") {
        ping();
    }
    else
        system("exit");
}
int main() {
    cout << "Bem vindo ao pingador de ips" << endl;
    ping();
    return 0;
}