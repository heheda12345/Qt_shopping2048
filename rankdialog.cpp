#include "rankdialog.h"

rankDialog::rankDialog(QWidget *parent) : QDialog(parent)
{
    print();
}
rankDialog::~rankDialog()
{
}

rankDialog::rankDialog(QWidget *parent, UserMessage &vec)
    :QDialog(parent)
{
    add(vec);
    print();
}

void rankDialog::add(UserMessage mes)
{
    vector<UserMessage> vec;
    vec.push_back(mes);
    QFile file("file.dat");
    qint32 n;
    if (file.open(QIODevice::ReadOnly))
    {
        QDataStream in(&file);
        in >> n;
        for (int i=1; i<=n; i++)
        {
            in >> mes.name >> mes.score;
            vec.push_back(mes);
        }
        file.close();
    }
    sort(vec.begin(),vec.end());
    n = vec.size();
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    n=std::min(n,qint32(10));
    out << n;
    for (int i=0; i<n; i++)
    {
        out << vec[i].name << vec[i].score;
        qDebug() << vec[i].name << vec[i].score;
    }
    file.close();
}

void rankDialog::print()
{
    QFile file("file.dat");
    qint32 n=0;
    vector<UserMessage> vec;
    UserMessage mes;
    if (file.open(QIODevice::ReadOnly))
    {
        vec.push_back(UserMessage(QString("zc"),2147483647));
        vec.push_back(UserMessage(QString("lhw"),741741741));
        QDataStream in(&file);
        in >> n;
        qDebug() << n;
        for (int i=1; i<=n; i++)
        {
            in >> mes.name >> mes.score;
            qDebug() << mes.name << mes.score;
            vec.push_back(mes);
        }
        file.close();
    }

    resize(800,500);
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(PC(gameBase,6)).scaled(this->size())));
    this->setPalette(palette);
    //QScrollArea *s = new QScrollArea(this);
    //s->setGeometry(200,100,400,250);

    grid = new QGridLayout(this);
    lab1.resize(10);
    lab2.resize(10);
    QFont ft;
    ft.setPointSize(20);
    head1 = new QLabel("昵称",this);
    head2 = new QLabel("成绩",this);
    head1->setFont(ft);
    head2->setFont(ft);
    grid->addWidget(head1,3,1);
    grid->addWidget(head2,3,2);
    int m=vec.size();
    if (m>10) m=10;
    //m=10;
    e1=new QLabel("",this);
    e2=new QLabel("",this);
    e3=new QLabel("",this);
    grid->addWidget(e1,0,0);
    grid->addWidget(e2,1,3);
    grid->addWidget(e3,2,0);
    for (int i=0; i<m; i++)
    {
        lab1[i] = new QLabel(vec[i].name, this);
        lab2[i] = new QLabel(QString::fromStdString(std::to_string(vec[i].score)), this);
        lab1[i]->setFont(ft);
        lab2[i]->setFont(ft);
        grid->addWidget(lab1[i],i+4,1);
        grid->addWidget(lab2[i],i+4,2);
    }
    for (int i=m;i<10;i++)
    {
        lab1[i] = new QLabel("",this);
        lab2[i] = new QLabel("",this);
        grid->addWidget(lab1[i],i+4,1);
        grid->addWidget(lab2[i],i+4,2);
    }
    grid->setGeometry(QRect(200,100,400,250));
    btn_return=new QPushButton(this);
    btn_return->setIconSize(QSize(10*8,10*5));
    btn_return->setGeometry(QRect(86*8,10*5,10*8,10*5));
    btn_return->setFlat(true);
    connect(btn_return,&QPushButton::clicked,this,&rankDialog::goReturn);
}

void rankDialog::goReturn()
{
    e=new QCloseEvent();
    QCoreApplication::sendEvent(this,e);
}
