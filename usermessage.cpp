#include "usermessage.h"

UserMessage::UserMessage(QString s, qint32 x):
    name(s),score(x) {}

bool operator < (UserMessage &a, UserMessage &b)
{
    return a.score > b.score;
}
