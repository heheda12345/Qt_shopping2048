#include<picturepath.h>

QString PC(PicName t,int id)
{
    switch (t)
    {
        case gameBase:
            return "://s//"+QString::number(id);
            break;
        case block:
            return "://p//"+QString::number(id);
            break;
        case photo:
            return "://h//"+QString::number(id);
            break;
    }
    return "";
}
