#ifndef DEFINED_User
#define DEFINED_User

class Inbox;

#include <string>
#include <vector>
#include <map>
#include <sstream>
#include "Inbox.hpp"

using namespace std;

class User {
private:
    string name;
    Inbox *inbox;
    map<string, User*> followers, following;
public:
    User(string name);

    string getName();
    Inbox *getInbox();

    void like(Message* message);
    void unlike(Message* message);
    void follow(User *user);
    void unfollow(User *user);
    void unfollowAll();
    void rejectAll();
    void tweetar(Message *message);
    void retweet(Message *message, Message *comment);

    string toString();
};

#endif