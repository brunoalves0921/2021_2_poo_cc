#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

class User;
class Message;  


#include "User.hpp"
#include "Message.hpp"
#include "Inbox.hpp"
#include "Twitter.hpp"

using namespace std;

void ajuda(){
    std::cout << "                Boas vindas ao POO Tweet!" << std::endl;
    std::cout << "| $add <Nome> : Para adicionar uma pessoa ao Twitter" << std::endl;
    std::cout << "| $show : Para listar todos os usuários" << std::endl;
    std::cout << "| $follow <Seguidor> <Seguido> : Para fazer um usuário seguir o outro" << std::endl;
    std::cout << "| $unfollow <Seguidor> <Seguido> : Para fazer um usuário deixar de seguir o outro" << std::endl;
    std::cout << "| $timeline <Usuário> : Para ver a timeline de um usuário" << std::endl;
    std::cout << "| $tweetar <Usuário> <Mensagem> : Para fazer um tweet" << std::endl;
    std::cout << "| $like <Usuário> <Tweet> : Para dar like em um tweet" << std::endl;
    std::cout << "| $unlike <Usuário> <Tweet> : Para dar unlike em um tweet" << std::endl;
    std::cout << "| $ajuda : Para exibir este menu de ajuda novamente" << std::endl;
    std::cout << "| $exit : Para sair" << std::endl;
}

int main() {
    Twitter twitter;
    string command;
    ajuda();
    while(true) {
        try {
            cin >> command;
            if (command == "add") {
                string name;
                cin >> name;
                twitter.addUser(name);
                cout << "Usuário adicionado: " << name << endl;
            }
            else if(command == "follow") {
                string seguidor, seguido;
                cin >> seguidor >> seguido;
                twitter.getUser(seguidor)->follow(twitter.getUser(seguido));
                cout << "O usuário " << seguidor << " começou a seguir " << seguido << endl;
            }
            else if(command == "ajuda") {
                ajuda();
            }
            else if(command == "unfollow") {
                string seguidor, seguido;
                cin >> seguidor >> seguido;
                twitter.getUser(seguidor)->unfollow(twitter.getUser(seguido));
                cout << "O usuário " << seguidor << " deixou de seguir " << seguido << endl;
            }
            else if(command == "tweetar") {
                string name, post;
                cin >> name;
                getline(cin, post);
                post = post.substr(1);
                twitter.sendTweet(name, post);
                cout << "O usuário " << name << " tweetou: " << post << endl;
            }
            else if(command == "like") {
                string name;
                int id;
                cin >> name >> id;
                twitter.like(name, id);
                cout << "O usuário " << name << " curtiu o tweet " << id << endl;
            }
            else if(command == "unlike") {
                string name;
                int id;
                cin >> name >> id;
                twitter.unlike(name, id);
                cout << "O usuário " << name << " descurtiu o tweet " << id << endl;
            }
            else if(command == "timeline") {
                string name;
                cin >> name;
                cout << twitter.getTimeline(name) << endl;
            }
            else if(command == "show") {
                cout << twitter.toString() << endl;
            }
            else if(command == "exit") {
                cout << "Encerrando o Twitter\n";
                break;
            }
            else {
                cout << "Comando invalido" << endl;
            }
        } catch (const string &ex) {
            cerr << "Erro: " << ex << endl;
        }
    }

    return 0;
}