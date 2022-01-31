#ifndef DEFINED_Twitter
#define DEFINED_Twitter

#include <string>
#include <vector>
#include <map>
#include <sstream>
#include "User.hpp"
#include "Message.hpp"

using namespace std;


class Twitter {
private:
    map<string, User*> users;
    map<int, Message*> tweets;
    int nextTweetId;
public:  
    Twitter();

    void addUser(string name);
    void sendTweet(string name, string post);
    void like(string name, int id);
    void unlike(string name, int id);
    User* getUser(string name);

    string getTimeline(string name);
    std::string toString();
};

#endif