#include "photoshower.h"

photoShower::photoShower(QWidget *parent, int pid):
    QDialog(parent)
{
    resize(photoSize[pid][0],photoSize[pid][1]);
    emit(opened());
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(PC(photo,pid)).scaled(this->size())));
    this->setPalette(palette);
}

