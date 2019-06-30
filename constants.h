#ifndef CONSTANTS
#define CONSTANTS
#include <QString>
const int WIDTH = 200;
const int HEIGHT = 220;
const int PICTURES = 11;
const int GS = 4;
const int MUL = 25;
const int PAGE_X = 32;
const int PAGE_Y = 18;
const int PHOTO = 10;
const int winnerPoint = 11;//2048->11

const QString name[8] = {
    "酸爽酷劲难挡",
    "还想再睡五十年",
    "你这个小坏坏",
    "社会老管",
    "纳尼",
    "快看这儿有个傻妞",
    "窒息",
    "原来刁民是你"
};

const int photoSize[8][2] =
{
    800,500,
    800,500,
    800,500,
    800,500,
    800,500,
    800,500,
    800,500,
    800,500
};
enum Now_situation
{
    ended,started,
};

enum MoveQuality
{
    success,fail,dead,
};

enum PicName
{
    gameBase,block,photo,
};

#endif // CONSTANTS

