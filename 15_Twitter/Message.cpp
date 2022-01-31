#include "Message.hpp"

Message::Message(User *senderPost, string post, int id) : senderPost(senderPost), post(post), id(id) { }


int Message::getId() {
    return id;
}

void Message::like(User *user) {
    for(User *it: likes) if (it == user) throw "O Usuario " + user->getName() + " ja curtiu esse post!";
    likes.push_back(user);
}

void Message::unlike(User *user) {
    for(unsigned int i = 0; i < likes.size(); i++) if (likes[i] == user) likes.erase(likes.begin() + i);
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
    return ss.str();
}
