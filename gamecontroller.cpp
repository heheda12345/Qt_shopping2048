#include "gamecontroller.h"
using std::vector;
using std::string;
using std::ofstream;
using std::ifstream;
using std::ios;
GameController::GameController(QWidget *parent)
                                : QDialog(parent)
{
    resize(800,500);

    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(PC(gameBase,5)).scaled(this->size())));
    this->setPalette(palette);

    btn_up=new QPushButton(this);
    btn_up->setIconSize(QSize(6*8,9*5));
    btn_up->setGeometry(QRect(81*8,58*5,6*8,9*5));
    btn_up->setFlat(true);

    btn_down=new QPushButton(this);
    btn_down->setIconSize(QSize(6*8,9*5));
    btn_down->setGeometry(QRect(81*8,78*5,6*8,9*5));
    btn_down->setFlat(true);

    btn_left=new QPushButton(this);
    btn_left->setIconSize(QSize(6*8,9*5));
    btn_left->setGeometry(QRect(74*8,67*5,6*8,9*5));
    btn_left->setFlat(true);

    btn_right=new QPushButton(this);
    btn_right->setIconSize(QSize(6*8,9*5));
    btn_right->setGeometry(QRect(87*8,68*5,6*8,9*5));
    btn_right->setFlat(true);

    btn_help=new QPushButton(this);
    btn_help->setIconSize(QSize(12*8,15*5));
    btn_help->setGeometry(QRect(70*8,13*5,12*8,15*5));
    btn_help->setFlat(true);

    btn_return=new QPushButton(this);
    btn_return->setIconSize(QSize(10*8,10*5));
    btn_return->setGeometry(QRect(86*8,10*5,10*8,10*5));
    btn_return->setFlat(true);

    btn_z=new QPushButton(this);
    btn_z->setIconSize(QSize(7*8,9*5));
    btn_z->setGeometry(QRect(2*8,3*5,7*8,9*5));
    btn_z->setFlat(true);

    btn_l=new QPushButton(this);
    btn_l->setIconSize(QSize(8*8,9*5));
    btn_l->setGeometry(QRect(60*8,86*5,8*8,9*5));
    btn_l->setFlat(true);

    btn_c=new QPushButton(this);
    btn_c->setIconSize(QSize(5*8,6*5));
    btn_c->setGeometry(QRect(91*8,55*5,5*8,6*5));
    btn_c->setFlat(true);

    win=0;
    gdie=0;
    mover=new Mover;

    connect(btn_up,&QPushButton::clicked,this,&GameController::goUp);
    connect(btn_down,&QPushButton::clicked,this,&GameController::goDown);
    connect(btn_left,&QPushButton::clicked,this,&GameController::goLeft);
    connect(btn_right,&QPushButton::clicked,this,&GameController::goRight);
    connect(btn_help,&QPushButton::clicked,this,&GameController::showHelp);
    connect(btn_return,&QPushButton::clicked,this,&GameController::goReturn);
    connect(btn_l,&QPushButton::clicked,this,&GameController::showL);
    connect(btn_z,&QPushButton::clicked,this,&GameController::showZ);
    connect(btn_c,&QPushButton::clicked,this,&GameController::showC);
    mover->newround();
    this->show();
}

GameController::~GameController()
{
    delete mover;
    delete btn_up;
    delete btn_down;
    delete btn_left;
    delete btn_right;
    delete wd;
}

void GameController::keyPressEvent(QKeyEvent *e)
{
    switch (e->key())
    {
        case Qt::Key_W : emit btn_up->clicked(); break;
        case Qt::Key_S : emit btn_down->clicked(); break;
        case Qt::Key_A : emit btn_left->clicked(); break;
        case Qt::Key_D : emit btn_right->clicked(); break;
    }
}

void GameController::paintEvent(QPaintEvent *)
{
    for (int i=0;i<GS;i++)
    {
        qDebug() << mover->q(i,0) << ' ' << mover->q(i,1) << ' '
                 << mover->q(i,2) << ' ' << mover->q(i,3) << ' ';
     }
    qDebug() << "________________" << endl;
    QPainter painter(this);
    int rpx=27,rpy=29,rlx=123,rly=104;
    for (int i=0;i<GS;i++)
        for (int j=0;j<GS;j++)
        {
            int now=mover->q(i,j);
            if (now>PICTURES) now=233;
            painter.drawImage(rpx+rlx*j,rpy+rly*i,QImage(PC(block,now)).scaled(QSize(rlx,rly)));
            painter.drawText(rpx+rlx*j,rpy+rly*i,rlx,rly,Qt::AlignHCenter,QString::number(1<<now));
        //need change
        }
//    for (int i=1;i<GS;i++)
//        painter.drawLine(rpx+rlx*i,rpy,rpx+rlx*i,rpy+rly*GS);
//    for (int i=1;i<GS;i++)
//        painter.drawLine(rpx,rpy+rly*i,rpx+rlx*GS,rpy+rly*i);
    painter.drawImage(0,0,QImage(PC(gameBase,5)).scaled(QSize(800,500)));
    //painter.drawText(5*MUL,5*MUL,4*MUL,2*MUL,Qt::AlignHCenter,"WOW"+QString::number(mover->qMark()));
    checkWin();
}

void GameController::checkWin()
{
    if (win) return;
    for (int i=0; i<GS; i++)
        for (int j=0; j<GS; j++)
            if (mover->q(i,j)==winnerPoint)
            {
                win=1;
                wd=new winnerDialog(this);
                wd->exec();
            }
}

void GameController::newround()
{
    if (mover->newround()== dead)
    {
        emit(die());
        gdie=1;
        QMessageBox::information(this,"哈哈哈","还是太嫩～");
        emit(btn_return->clicked());
    }
    else
        this -> update();
}

void GameController::scoreStore()
{
    if (QMessageBox::Yes ==
        QMessageBox::question(this,"保存","你想名垂青史吗？",QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes))
    {
        sd = new ScoreDialog(this);
        connect(sd,&ScoreDialog::name,this,&GameController::saveName);
        sd->exec();
    }
}

void GameController::saveName(QString name)
{
    e = new QCloseEvent;
    QCoreApplication::sendEvent(sd,e);
    int s=mover->qMark();
    UserMessage mes(name,qint32(s));
    rankDialog *r=new rankDialog(this,mes);
    r->exec();
}

void GameController::goUp()
{
    mover->moveUp();
    newround();
}

void GameController::goDown()
{
    mover->moveDown();
    newround();
}

void GameController::goLeft()
{
    mover->moveLeft();
    newround();
}

void GameController::goRight()
{
    mover->moveRight();
    newround();
}

void GameController::showHelp()
{
    while (1)
        {
            if (QMessageBox::Yes ==
                QMessageBox::question(this,
                                      tr("确认"),
                                      tr("是否确定需要帮助"),
                                      QMessageBox::Yes | QMessageBox::No,
                                      QMessageBox::Yes)
                )
            {
                hd = new Helpdialog;
                hd->exec();
                break;
            }
            else
            {
                QMessageBox::information(this,tr("帮助"),tr("小朋友不是需要帮助吗？"));
            }
        }
}

void GameController::goReturn()
{
    e=new QCloseEvent();
    QCoreApplication::sendEvent(this,e);

}
void GameController::closeEvent(QCloseEvent *event)
{
    if (gdie||QMessageBox::Yes ==
        QMessageBox::question(this,"确认","你竟然敢玩够这个游戏？",
            QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes))
    {
        scoreStore();
        QDialog::closeEvent(event);
    }
    else
    {
        event->ignore();
    }
}

void GameController::showL()
{
    while (1)
    {
        if (QMessageBox::Yes ==
            QMessageBox::question(this,
                                  tr("A simple question"),
                                  tr("慧文是否英明神武"),
                                  QMessageBox::Yes | QMessageBox::No,
                                  QMessageBox::Yes))
        {
            QMessageBox::information(this, tr("Hmmm..."), tr("乖～"));
            break;
        } else {
            QMessageBox::information(this, tr("Hmmm..."), tr("又逆反？"));
        }
    }
}

void GameController::showZ()
{
    while (1)
    {
        if (QMessageBox::Yes ==
            QMessageBox::question(this,
                                  tr("A simple question"),
                                  tr("晨神帅不帅？"),
                                  QMessageBox::Yes | QMessageBox::No,
                                  QMessageBox::Yes))
        {
            QMessageBox::information(this, tr("Hmmm..."), tr("I'm glad to hear that!"));
            break;
        } else {
            QMessageBox::information(this, tr("Hmmm..."), tr("你干什么吃的你！"));
        }
    }
}

void GameController::showC()
{
    cd = new ChooseDialog(this);
    while (!cd->exit_press())
        cd->exec();
}
