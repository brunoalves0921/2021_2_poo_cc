#include "Inbox.hpp"

Inbox::Inbox(User* user) : user(user) {}


vector<Message*> Inbox::getAll() {
    vector<Message*> all;
    for (auto it = allMessages.begin(); it != allMessages.end(); it++) {
        all.push_back(it->second);
    }
    return all;
}

vector<Message*> Inbox::getUnread() {
    vector<Message*> unread;
    for (auto it = unreadMessages.begin(); it != unreadMessages.end(); it++) {
        unread.push_back(it->second);
    }
    return unread;
}

Message* Inbox::getTweet(int id) {
    return allMessages[id];
}

void Inbox::addMessage(Message* message) {
    allMessages[message->getId()] = message;
    unreadMessages[message->getId()] = message;
}

void Inbox::readMessage(Message* message) {
    unreadMessages.erase(message->getId());
}

string Inbox::toString() {
    stringstream ss;
    ss << "Inbox of " << user->getName() << ": " << endl;
    for (auto it = allMessages.begin(); it != allMessages.end(); it++) {
        ss << it->second->toString() << endl;
    }
    return ss.str();
}
