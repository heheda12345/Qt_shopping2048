#ifndef USERMESSAGE_H
#define USERMESSAGE_H
#include<string>
#include<QString>
#include<iostream>
using std::string;
using std::istream;
using std::ostream;

class UserMessage
{
friend bool operator < (UserMessage &a, UserMessage &b);
public:
    UserMessage() = default;
    UserMessage(QString s, qint32 x);
    QString name;
    qint32 score;
};


#endif // USERMESSAGE_H
