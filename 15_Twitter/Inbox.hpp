#ifndef DEFINED_Inbox
#define DEFINED_Inbox

class User;
class Message;

#include <string>
#include <vector>
#include <map>
#include <sstream>
#include "User.hpp"
#include "Message.hpp"

using namespace std;


class Inbox {
private:
    map<int, Message*> allMessages;
    map<int, Message*> unreadMessages;
    User* user; 
public:
    Inbox(User* user);

    vector<Message*> getAll();
    vector<Message*> getUnread();
    Message* getTweet(int id);
    void addMessage(Message* message);
    void readMessage(Message* message);

    string toString ();
};

#endif