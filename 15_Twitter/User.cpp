#include "User.hpp"


User::User(string name) : name(name), inbox(new Inbox(this)) {}


string User::getName() {
    return name;
}

Inbox *User::getInbox() {
    return inbox;
}

void User::like(Message *message) {
    message->like(this);
}

void User::unlike(Message *message) {
    message->unlike(this);
}

void User::follow(User *user) {
    if (following[user->getName()] != NULL) {
        throw "Usuário já está seguindo " + user->getName();
    }
    following[user->getName()] = user;
    user->followers[name] = this;
}

void User::unfollow(User *user) {
    if (following[user->getName()] == NULL) {
        throw "Você não está seguindo " + user->getName();
    }
    getInbox()->removeMessagesFrom(user);
    following.erase(user->getName());
    user->followers.erase(name);
}

void User::unfollowAll() {
    for (auto it = following.begin(); it != following.end(); it++) {
        it->second->followers.erase(name);
    }
    following.clear();
}

void User::rejectAll() {
    for (auto it = followers.begin(); it != followers.end(); it++) {
        it->second->unfollow(this);
    }
    followers.clear();
}

void User::tweetar(Message *message) {
    inbox->addMessage(message);
    for(auto it = followers.begin(); it != followers.end(); it++) {
        it->second->getInbox()->addMessage(message);
    }
}

void User::retweet(Message *message, Message *rt) {
    tweetar(rt);
    rt->setRt(message);
}

string User::toString() {
    bool firstCase = true;
    stringstream ss;
    ss << "Nome: " << name << "\n\tSeguindo:   [";
    for (auto it = following.begin(); it != following.end(); it++) {
        if (firstCase) {
            ss << it->first;
            firstCase = false;
        } else {
            ss << ", " << it->first;
        }
    };
    ss << "]\n\tSeguidores: [";
    firstCase = true;
    for (auto it = followers.begin(); it != followers.end(); it++) {
        if(firstCase) {
            ss << it->first;
            firstCase = false;
        } else {
            ss << ", " << it->first;
        }
    }
    ss << "]\n";
    return ss.str();
}
