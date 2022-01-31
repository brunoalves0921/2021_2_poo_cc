#include "Twitter.hpp"

Twitter::Twitter(): nextTweetId(0) { }


void Twitter::addUser(string name) {
    if (users[name] != NULL) {
        throw "Usuario ja existe";
    }
    users[name] = new User(name);
}

void Twitter::sendTweet(string name, string post) {
    User *user = users[name];
    if (user == NULL) {
        throw "Usuario nao existe";
    }
    Message *message = new Message(user, post, nextTweetId);
    tweets[nextTweetId] = message;
    user->tweetar(message);
    nextTweetId++;
}

void Twitter::like(string name, int id) {
    User *user = users[name];
    if (user == NULL) {
        throw "Usuario nao existe: " + name;
    }
    Message *message = tweets[id];
    if (message == NULL) {
        throw "Mensagem nao existe: " + to_string(id);
    }
    user->like(message);
}

void Twitter::unlike(string name, int id) {
    User *user = users[name];
    if (user == NULL) {
        throw "Usuario nao existe: " + name;
    }
    Message *message = tweets[id];
    if (message == NULL) {
        throw "Mensagem nao existe: " + to_string(id);
    }
    user->unlike(message);
}

User *Twitter::getUser(string name) {
    return users[name];
}

string Twitter::getTimeline(string name) {
    User *user = users[name];
    if (user == NULL) {
        throw "Usuario nao existe: " + name;
    }
    stringstream ss;
    ss << "Timeline of " << user->getName() << ": " << endl;
    vector<Message*> all = user->getInbox()->getAll();
    for (auto msg : all) {
        ss << msg->toString() << endl;
        user->getInbox()->readMessage(msg);
    }
    return ss.str();
}

string Twitter::toString() {
    stringstream ss;
    for (auto it = users.begin(); it != users.end(); it++) {
        ss << it->second->toString();
    }
    return ss.str();
}
