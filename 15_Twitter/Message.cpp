#include "Message.hpp"

Message::Message(User *senderPost, string post, int id) : senderPost(senderPost), post(post), id(id) {
    rt = nullptr;
}


int Message::getId() {
    return id;
}

void Message::like(User *user) {
    for(User *it: likes) if (it == user) throw "O Usuario " + user->getName() + " ja curtiu esse post!";
    likes.push_back(user);
}

void Message::unlike(User *user) {
    bool found = false;
    for (User *it: likes) {
        if (it == user) {
            found = true;
            for(unsigned int i = 0; i < likes.size(); i++) if (likes[i] == user) likes.erase(likes.begin() + i);
        }
    }
    if (!found) throw "O Usuario " + user->getName() + " nao curtiu esse post!";
   
}

void Message::setRt(Message *message) {
    rt = message;
}

void Message::setDeleted() {
    deleted = true;
}

bool Message::isDeleted() {
    return deleted;
}


string Message::toString() {
    stringstream ss;
    ss << id << ":" << senderPost->getName() << " (" << post << ") ";
    if (likes.size() > 0) {
        ss << "[" << likes[0]->getName();
        for (unsigned int i = 1; i < likes.size(); i++) {
            ss << ", " << likes[i]->getName();
        }
        ss << "]";
    }
    if (rt != nullptr) {
        ss << "\n\t" << rt->toString();
    }
    return ss.str();
}
