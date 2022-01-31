#ifndef DEFINED_Message
#define DEFINED_Message

class User;

#include <string>
#include <vector>
#include <sstream>
#include "User.hpp"

using namespace std;


class Message {
private:
    User *senderPost;
    string post;
    int id;
    vector<User*> likes;

public:
    Message(User *senderPost, string post, int id);

    int getId();
    void like(User *user);
    void unlike(User *user);

    string toString ();
};

#endif