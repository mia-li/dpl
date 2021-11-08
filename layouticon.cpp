#include "layouticon.h"

int LayoutIcon::layoutNum=0;
LayoutIcon::LayoutIcon(int customlayout,QWidget *widgetparent,int lo1,int lo2,int lo3,int lo4,QObject *parent) : QObject(parent),
    m_customlayout(customlayout),
    m_widget(widgetparent),
    local1(lo1),
    local2(lo2),
    local3(lo3),
    local4(lo4)
{

    //index=layoutNum;
    rb= new QRadioButton(m_widget);
    //rb->setObjectName(QString("radioButtonp%1").arg(index));
//    Point=QRect(lx+240*(index%4), ly+130*(index/4), 121, 111);
//    rb->setGeometry(Point);
    rb->setAutoFillBackground(false);

    //layoutNum++;

    QString ima=QString("background-image:url(:/image/pics/s%1b.png)").arg(m_customlayout);
    ima.append(";background-repeat:no-repeat;background-position:right center;");
    rb->setStyleSheet(ima);
    rb->setText(QString());

    l1=new QLabel(m_widget);
    t1=IndToString(local1);
    //l1->setObjectName(QString("labelp%1").arg(index));
    l1->setText(t1);

    if(m_customlayout>=2)
    {
        l2=new QLabel(m_widget);
        t2=IndToString(local2);
        //l2->setObjectName(QString("labelp%1").arg(index));
        l2->setText(t2);
    }
    if(m_customlayout>=4)
    {
        l3=new QLabel(m_widget);
        t3=IndToString(local3);
        //l3->setObjectName(QString("labelp%1").arg(index));
        l3->setText(t3);
    }
    if(m_customlayout>=8)
    {
        l4=new QLabel(m_widget);
        t4=IndToString(local4);
        //l4->setObjectName(QString("labelp%1").arg(index));
        l4->setText(t4);
    }

    Paint();

}
QString LayoutIcon::IndToString(int index)
{
    if(index==1)
        return "A";
    else if(index==2)
        return "B";
    else if(index==3)
        return "C1";
    else if(index==4)
        return "C2";
    else if(index==5)
        return "C3";
    else if(index==6)
        return "S";
    else if(index==7)
        return "TopC";
    else if(index==8)
        return "Pa3D";
}
void LayoutIcon::Delete()
{
    if(rb)
    {
        delete rb;
        delete l1;
        if(m_customlayout>=2)
            delete l2;
        if(m_customlayout>=4)
            delete l3;
        if(m_customlayout>=8)
            delete l4;
    }
}
void LayoutIcon::UpdateIndex(int inx)
{
    index=inx;
    Point=QRect(lx+240*(index%4), ly+130*(index/4), 121, 111);
    rb->setGeometry(Point);
    Paint();
}
void LayoutIcon::Paint()
{
    if(m_customlayout==1)
    {
        QFont font3;
        if(t1=="A"||t1=="B"||t1=="S")
        {
            l1->setGeometry(QRect(Point.x()+55,Point.y()+30,51,51));
            font3.setPointSize(24);
        }
        else if(t1=="C1"||t1=="C2"||t1=="C3")
        {
            l1->setGeometry(QRect(Point.x()+55,Point.y()+30,51,51));
            font3.setPointSize(16);
        }
        else if(t1=="TopC"||t1=="Pa3D")
        {
            l1->setGeometry(QRect(Point.x()+50,Point.y()+30,51,51));
            font3.setPointSize(12);
        }
        font3.setFamily(QString::fromUtf8("Arial Rounded MT Bold"));
        font3.setBold(false);
        font3.setWeight(50);
        l1->setFont(font3);
        l1->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));
        l1->raise();
    }
    else if(m_customlayout==2)
    {
        QFont font1;
        if(t1=="A"||t1=="B"||t1=="S")
        {
            l1->setGeometry(QRect(Point.x()+65,Point.y()+10,51,51));
            font1.setPointSize(16);
        }
        else if(t1=="C1"||t1=="C2"||t1=="C3")
        {
            l1->setGeometry(QRect(Point.x()+55,Point.y()+10,51,51));
            font1.setPointSize(16);
        }
        else if(t1=="TopC"||t1=="Pa3D")
        {
            l1->setGeometry(QRect(Point.x()+50,Point.y()+10,51,51));
            font1.setPointSize(12);
        }
        font1.setFamily(QString::fromUtf8("Arial Rounded MT Bold"));
        font1.setBold(false);
        font1.setWeight(50);
        l1->setFont(font1);
        l1->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));
        l1->raise();

        QFont font2;
        if(t2=="A"||t2=="B"||t2=="S")
        {
            l2->setGeometry(QRect(Point.x()+65,Point.y()+50,51,51));
            font2.setPointSize(16);
        }
        else if(t2=="C1"||t2=="C2"||t2=="C3")
        {
            l2->setGeometry(QRect(Point.x()+55,Point.y()+50,51,51));
            font2.setPointSize(16);
        }
        else if(t2=="TopC"||t2=="Pa3D")
        {
            l2->setGeometry(QRect(Point.x()+50,Point.y()+50,51,51));
            font2.setPointSize(12);
        }
        font2.setFamily(QString::fromUtf8("Arial Rounded MT Bold"));
        font2.setBold(false);
        font2.setWeight(50);
        l2->setFont(font2);
        l2->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));
        l2->raise();

    }
    else if(m_customlayout==3)
    {
        QFont font1;
        if(t1=="A"||t1=="B"||t1=="S")
        {
            l1->setGeometry(QRect(Point.x()+40,Point.y()+30,51,51));
            font1.setPointSize(16);
        }
        else if(t1=="C1"||t1=="C2"||t1=="C3")
        {
            l1->setGeometry(QRect(Point.x()+35,Point.y()+30,51,51));
            font1.setPointSize(16);
        }
        else if(t1=="TopC"||t1=="Pa3D")
        {
            l1->setGeometry(QRect(Point.x()+32,Point.y()+30,51,51));
            font1.setPointSize(9);
        }
        font1.setFamily(QString::fromUtf8("Arial Rounded MT Bold"));
        font1.setBold(false);
        font1.setWeight(50);
        l1->setText(t1);
        l1->setFont(font1);
        l1->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));
        l1->raise();

        QFont font2;
        if(t2=="A"||t2=="B"||t2=="S")
        {
            l2->setGeometry(QRect(Point.x()+80,Point.y()+30,51,51));
            font2.setPointSize(16);
        }
        else if(t2=="C1"||t2=="C2"||t2=="C3")
        {
            l2->setGeometry(QRect(Point.x()+80,Point.y()+30,51,51));
            font2.setPointSize(16);
        }
        else if(t2=="TopC"||t2=="Pa3D")
        {
            l2->setGeometry(QRect(Point.x()+75,Point.y()+30,51,51));
            font2.setPointSize(9);
        }
        font2.setFamily(QString::fromUtf8("Arial Rounded MT Bold"));
        font2.setBold(false);
        font2.setWeight(50);
        l2->setText(t2);
        l2->setFont(font2);
        l2->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));
        l2->raise();

    }
    else if(m_customlayout==4)
    {
        QFont font1;
        if(t1=="A"||t1=="B"||t1=="S")
        {
            l1->setGeometry(QRect(Point.x()+34,Point.y()+30,51,51));
            font1.setPointSize(14);
        }
        else if(t1=="C1"||t1=="C2"||t1=="C3")
        {
            l1->setGeometry(QRect(Point.x()+32,Point.y()+30,51,51));
            font1.setPointSize(10);
        }
        else if(t1=="TopC"||t1=="Pa3D")
        {
            l1->setGeometry(QRect(Point.x()+32,Point.y()+30,51,51));
            font1.setPointSize(6);
        }
        font1.setFamily(QString::fromUtf8("Arial Rounded MT Bold"));
        font1.setBold(false);
        font1.setWeight(50);
        l1->setText(t1);
        l1->setFont(font1);
        l1->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));
        l1->raise();

        QFont font2;
        if(t2=="A"||t2=="B"||t2=="S")
        {
            l2->setGeometry(QRect(Point.x()+62,Point.y()+30,51,51));
            font2.setPointSize(14);
        }
        else if(t2=="C1"||t2=="C2"||t2=="C3")
        {
            l2->setGeometry(QRect(Point.x()+60,Point.y()+30,51,51));
            font2.setPointSize(10);
        }
        else if(t2=="TopC"||t2=="Pa3D")
        {
            l2->setGeometry(QRect(Point.x()+59,Point.y()+30,51,51));
            font2.setPointSize(6);
        }
        font2.setFamily(QString::fromUtf8("Arial Rounded MT Bold"));
        font2.setBold(false);
        font2.setWeight(50);
        l2->setText(t2);
        l2->setFont(font2);
        l2->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));
        l2->raise();

        QFont font3;
        if(t3=="A"||t3=="B"||t3=="S")
        {
            l3->setGeometry(QRect(Point.x()+91,Point.y()+30,51,51));
            font3.setPointSize(14);
        }
        else if(t3=="C1"||t3=="C2"||t3=="C3")
        {
            l3->setGeometry(QRect(Point.x()+89,Point.y()+30,51,51));
            font3.setPointSize(10);
        }
        else if(t3=="TopC"||t3=="Pa3D")
        {
            l3->setGeometry(QRect(Point.x()+87,Point.y()+30,51,51));
            font3.setPointSize(6);
        }
        font3.setFamily(QString::fromUtf8("Arial Rounded MT Bold"));
        font3.setBold(false);
        font3.setWeight(50);
        l3->setText(t3);
        l3->setFont(font3);
        l3->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));
        l3->raise();
    }
    else if(m_customlayout==5)
    {
        QFont font1;
        if(t1=="A"||t1=="B"||t1=="S")
        {
            l1->setGeometry(QRect(Point.x()+60,Point.y()+5,51,51));
            font1.setPointSize(16);
        }
        else if(t1=="C1"||t1=="C2"||t1=="C3")
        {
            l1->setGeometry(QRect(Point.x()+55,Point.y()+5,51,51));
            font1.setPointSize(14);
        }
        else if(t1=="TopC"||t1=="Pa3D")
        {
            l1->setGeometry(QRect(Point.x()+50,Point.y()+5,51,51));
            font1.setPointSize(10);
        }
        font1.setFamily(QString::fromUtf8("Arial Rounded MT Bold"));
        font1.setBold(false);
        font1.setWeight(50);
        l1->setText(t1);
        l1->setFont(font1);
        l1->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));
        l1->raise();

        QFont font2;
        if(t2=="A"||t2=="B"||t2=="S")
        {
            l2->setGeometry(QRect(Point.x()+60,Point.y()+29,51,51));
            font2.setPointSize(16);
        }
        else if(t2=="C1"||t2=="C2"||t2=="C3")
        {
            l2->setGeometry(QRect(Point.x()+55,Point.y()+29,51,51));
            font2.setPointSize(14);
        }
        else if(t2=="TopC"||t2=="Pa3D")
        {
            l2->setGeometry(QRect(Point.x()+50,Point.y()+29,51,51));
            font2.setPointSize(10);
        }
        font2.setFamily(QString::fromUtf8("Arial Rounded MT Bold"));
        font2.setBold(false);
        font2.setWeight(50);
        l2->setText(t2);
        l2->setFont(font2);
        l2->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));
        l2->raise();

        QFont font3;
        if(t3=="A"||t3=="B"||t3=="S")
        {
            l3->setGeometry(QRect(Point.x()+60,Point.y()+57,51,51));
            font3.setPointSize(16);
        }
        else if(t3=="C1"||t3=="C2"||t3=="C3")
        {
            l3->setGeometry(QRect(Point.x()+55,Point.y()+57,51,51));
            font3.setPointSize(14);
        }
        else if(t3=="TopC"||t3=="Pa3D")
        {
            l3->setGeometry(QRect(Point.x()+50,Point.y()+57,51,51));
            font3.setPointSize(10);
        }
        font3.setFamily(QString::fromUtf8("Arial Rounded MT Bold"));
        font3.setBold(false);
        font3.setWeight(50);
        l3->setText(t3);
        l3->setFont(font3);
        l3->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));
        l3->raise();
    }
    else if(m_customlayout==6)
    {
        QFont font1;
        if(t1=="A"||t1=="B"||t1=="S")
        {
            l1->setGeometry(QRect(Point.x()+47,Point.y()+10,51,51));
            font1.setPointSize(16);
        }
        else if(t1=="C1"||t1=="C2"||t1=="C3")
        {
            l1->setGeometry(QRect(Point.x()+40,Point.y()+10,51,51));
            font1.setPointSize(16);
        }
        else if(t1=="TopC"||t1=="Pa3D")
        {
            l1->setGeometry(QRect(Point.x()+32,Point.y()+10,51,51));
            font1.setPointSize(11);
        }
        font1.setFamily(QString::fromUtf8("Arial Rounded MT Bold"));
        font1.setBold(false);
        font1.setWeight(50);
        l1->setFont(font1);
        l1->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));
        l1->raise();

        QFont font2;
        if(t2=="A"||t2=="B"||t2=="S")
        {
            l2->setGeometry(QRect(Point.x()+50,Point.y()+50,51,51));
            font2.setPointSize(16);
        }
        else if(t2=="C1"||t2=="C2"||t2=="C3")
        {
            l2->setGeometry(QRect(Point.x()+45,Point.y()+50,51,51));
            font2.setPointSize(16);
        }
        else if(t2=="TopC"||t2=="Pa3D")
        {
            l2->setGeometry(QRect(Point.x()+32,Point.y()+50,51,51));
            font2.setPointSize(11);
        }
        font2.setFamily(QString::fromUtf8("Arial Rounded MT Bold"));
        font2.setBold(false);
        font2.setWeight(50);
        l2->setFont(font2);
        l2->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));
        l2->raise();

        QFont font3;
        if(t3=="A"||t3=="B"||t3=="S")
        {
            l3->setGeometry(QRect(Point.x()+87,Point.y()+30,51,51));
            font3.setPointSize(16);
        }
        else if(t3=="C1"||t3=="C2"||t3=="C3")
        {
            l3->setGeometry(QRect(Point.x()+81,Point.y()+30,51,51));
            font3.setPointSize(14);
        }
        else if(t3=="TopC"||t3=="Pa3D")
        {
            l3->setGeometry(QRect(Point.x()+82,Point.y()+30,51,51));
            font3.setPointSize(7);
        }
        font3.setFamily(QString::fromUtf8("Arial Rounded MT Bold"));
        font3.setBold(false);
        font3.setWeight(50);
        l3->setFont(font3);
        l3->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));
        l3->raise();
    }
    else if(m_customlayout==7)
    {
        QFont font1;
        if(t1=="A"||t1=="B"||t1=="S")
        {
            l1->setGeometry(QRect(Point.x()+45,Point.y()+15,51,51));
            font1.setPointSize(16);
        }
        else if(t1=="C1"||t1=="C2"||t1=="C3")
        {
            l1->setGeometry(QRect(Point.x()+37,Point.y()+15,51,51));
            font1.setPointSize(16);
        }
        else if(t1=="TopC"||t1=="Pa3D")
        {
            l1->setGeometry(QRect(Point.x()+35,Point.y()+10,51,51));
            font1.setPointSize(7);
        }
        font1.setFamily(QString::fromUtf8("Arial Rounded MT Bold"));
        font1.setBold(false);
        font1.setWeight(50);
        l1->setFont(font1);
        l1->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));
        l1->raise();

        QFont font2;
        if(t2=="A"||t2=="B"||t2=="S")
        {
            l2->setGeometry(QRect(Point.x()+85,Point.y()+15,51,51));
            font2.setPointSize(16);
        }
        else if(t2=="C1"||t2=="C2"||t2=="C3")
        {
            l2->setGeometry(QRect(Point.x()+80,Point.y()+15,51,51));
            font2.setPointSize(16);
        }
        else if(t2=="TopC"||t2=="Pa3D")
        {
            l2->setGeometry(QRect(Point.x()+80,Point.y()+10,51,51));
            font2.setPointSize(7);
        }
        font2.setFamily(QString::fromUtf8("Arial Rounded MT Bold"));
        font2.setBold(false);
        font2.setWeight(50);
        l2->setFont(font2);
        l2->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));
        l2->raise();

        QFont font3;
        if(t3=="A"||t3=="B"||t3=="S")
        {
            l3->setGeometry(QRect(Point.x()+60,Point.y()+50,51,51));
            font3.setPointSize(16);
        }
        else if(t3=="C1"||t3=="C2"||t3=="C3")
        {
            l3->setGeometry(QRect(Point.x()+55,Point.y()+50,51,51));
            font3.setPointSize(16);
        }
        else if(t3=="TopC"||t3=="Pa3D")
        {
            l3->setGeometry(QRect(Point.x()+50,Point.y()+50,51,51));
            font3.setPointSize(11);
        }
        font3.setFamily(QString::fromUtf8("Arial Rounded MT Bold"));
        font3.setBold(false);
        font3.setWeight(50);
        l3->setFont(font3);
        l3->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));
        l3->raise();
    }
    else if(m_customlayout==8)
    {
        QFont font1;
        if(t1=="A"||t1=="B"||t1=="S")
        {
            l1->setGeometry(QRect(Point.x()+45,Point.y()+3,51,51));
            font1.setPointSize(16);
        }
        else if(t1=="C1"||t1=="C2"||t1=="C3")
        {
            l1->setGeometry(QRect(Point.x()+45,Point.y()+5,51,51));
            font1.setPointSize(14);
        }
        else if(t1=="TopC"||t1=="Pa3D")
        {
            l1->setGeometry(QRect(Point.x()+40,Point.y()+5,51,51));
            font1.setPointSize(7);
        }
        font1.setFamily(QString::fromUtf8("Arial Rounded MT Bold"));
        font1.setBold(false);
        font1.setWeight(50);
        l1->setFont(font1);
        l1->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));
        l1->raise();

        QFont font2;
        if(t2=="A"||t2=="B"||t2=="S")
        {
            l2->setGeometry(QRect(Point.x()+45,Point.y()+29,51,51));
            font2.setPointSize(16);
        }
        else if(t2=="C1"||t2=="C2"||t2=="C3")
        {
            l2->setGeometry(QRect(Point.x()+45,Point.y()+29,51,51));
            font2.setPointSize(14);
        }
        else if(t2=="TopC"||t2=="Pa3D")
        {
            l2->setGeometry(QRect(Point.x()+40,Point.y()+29,51,51));
            font2.setPointSize(7);
        }
        font2.setFamily(QString::fromUtf8("Arial Rounded MT Bold"));
        font2.setBold(false);
        font2.setWeight(50);
        l2->setFont(font2);
        l2->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));
        l2->raise();

        QFont font3;
        if(t3=="A"||t3=="B"||t3=="S")
        {
            l3->setGeometry(QRect(Point.x()+45,Point.y()+57,51,51));
            font3.setPointSize(16);
        }
        else if(t3=="C1"||t3=="C2"||t3=="C3")
        {
            l3->setGeometry(QRect(Point.x()+45,Point.y()+57,51,51));
            font3.setPointSize(14);
        }
        else if(t3=="TopC"||t3=="Pa3D")
        {
            l3->setGeometry(QRect(Point.x()+40,Point.y()+57,51,51));
            font3.setPointSize(7);
        }
        font3.setFamily(QString::fromUtf8("Arial Rounded MT Bold"));
        font3.setBold(false);
        font3.setWeight(50);
        l3->setFont(font3);
        l3->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));
        l3->raise();

        QFont font4;
        if(t4=="A"||t4=="B"||t4=="S")
        {
            l4->setGeometry(QRect(Point.x()+87,Point.y()+30,51,51));
            font4.setPointSize(16);
        }
        else if(t4=="C1"||t4=="C2"||t4=="C3")
        {
            l4->setGeometry(QRect(Point.x()+82,Point.y()+30,51,51));
            font4.setPointSize(14);
        }
        else if(t4=="TopC"||t4=="Pa3D")
        {
            l4->setGeometry(QRect(Point.x()+82,Point.y()+30,51,51));
            font4.setPointSize(7);
        }
        font4.setFamily(QString::fromUtf8("Arial Rounded MT Bold"));
        font4.setBold(false);
        font4.setWeight(50);
        l4->setFont(font4);
        l4->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));
        l4->raise();
    }
    else if(m_customlayout==9)
    {
        QFont font1;
        if(t1=="A"||t1=="B"||t1=="S")
        {
            l1->setGeometry(QRect(Point.x()+40,Point.y()+15,51,51));
            font1.setPointSize(16);
        }
        else if(t1=="C1"||t1=="C2"||t1=="C3")
        {
            l1->setGeometry(QRect(Point.x()+35,Point.y()+15,51,51));
            font1.setPointSize(12);
        }
        else if(t1=="TopC"||t1=="Pa3D")
        {
            l1->setGeometry(QRect(Point.x()+35,Point.y()+15,51,51));
            font1.setPointSize(5);
        }
        font1.setFamily(QString::fromUtf8("Arial Rounded MT Bold"));
        font1.setBold(false);
        font1.setWeight(50);
        l1->setFont(font1);
        l1->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));
        l1->raise();

        QFont font2;
        if(t2=="A"||t2=="B"||t2=="S")
        {
            l2->setGeometry(QRect(Point.x()+85,Point.y()+2,51,51));
            font2.setPointSize(16);
        }
        else if(t2=="C1"||t2=="C2"||t2=="C3")
        {
            l2->setGeometry(QRect(Point.x()+78,Point.y()+3,51,51));
            font2.setPointSize(14);
        }
        else if(t2=="TopC"||t2=="Pa3D")
        {
            l2->setGeometry(QRect(Point.x()+78,Point.y()+3,51,51));
            font2.setPointSize(7);
        }
        font2.setFamily(QString::fromUtf8("Arial Rounded MT Bold"));
        font2.setBold(false);
        font2.setWeight(50);
        l2->setFont(font2);
        l2->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));
        l2->raise();

        QFont font3;
        if(t3=="A"||t3=="B"||t3=="S")
        {
            l3->setGeometry(QRect(Point.x()+85,Point.y()+29,51,51));
            font3.setPointSize(16);
        }
        else if(t3=="C1"||t3=="C2"||t3=="C3")
        {
            l3->setGeometry(QRect(Point.x()+78,Point.y()+29,51,51));
            font3.setPointSize(14);
        }
        else if(t3=="TopC"||t3=="Pa3D")
        {
            l3->setGeometry(QRect(Point.x()+78,Point.y()+29,51,51));
            font3.setPointSize(7);
        }
        font3.setFamily(QString::fromUtf8("Arial Rounded MT Bold"));
        font3.setBold(false);
        font3.setWeight(50);
        l3->setFont(font3);
        l3->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));
        l3->raise();

        QFont font4;
        if(t4=="A"||t4=="B"||t4=="S")
        {
            l4->setGeometry(QRect(Point.x()+60,Point.y()+57,51,51));
            font4.setPointSize(16);
        }
        else if(t4=="C1"||t4=="C2"||t4=="C3")
        {
            l4->setGeometry(QRect(Point.x()+55,Point.y()+57,51,51));
            font4.setPointSize(14);
        }
        else if(t4=="TopC"||t4=="Pa3D")
        {
            l4->setGeometry(QRect(Point.x()+50,Point.y()+57,51,51));
            font4.setPointSize(10);
        }
        font4.setFamily(QString::fromUtf8("Arial Rounded MT Bold"));
        font4.setBold(false);
        font4.setWeight(50);
        l4->setFont(font4);
        l4->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));
        l4->raise();

    }
    else if(m_customlayout==10)
    {
        QFont font1;
        if(t1=="A"||t1=="B"||t1=="S")
        {
            l1->setGeometry(QRect(Point.x()+37,Point.y()+8,51,51));
            font1.setPointSize(14);
        }
        else if(t1=="C1"||t1=="C2"||t1=="C3")
        {
            l1->setGeometry(QRect(Point.x()+35,Point.y()+8,51,51));
            font1.setPointSize(10);
        }
        else if(t1=="TopC"||t1=="Pa3D")
        {
            l1->setGeometry(QRect(Point.x()+32,Point.y()+8,51,51));
            font1.setPointSize(6);
        }
        font1.setFamily(QString::fromUtf8("Arial Rounded MT Bold"));
        font1.setBold(false);
        font1.setWeight(50);
        l1->setFont(font1);
        l1->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));
        l1->raise();

        QFont font2;
        if(t2=="A"||t2=="B"||t2=="S")
        {
            l2->setGeometry(QRect(Point.x()+37,Point.y()+50,51,51));
            font2.setPointSize(14);
        }
        else if(t2=="C1"||t2=="C2"||t2=="C3")
        {
            l2->setGeometry(QRect(Point.x()+35,Point.y()+50,51,51));
            font2.setPointSize(10);
        }
        else if(t2=="TopC"||t2=="Pa3D")
        {
            l2->setGeometry(QRect(Point.x()+32,Point.y()+50,51,51));
            font2.setPointSize(6);
        }
        font2.setFamily(QString::fromUtf8("Arial Rounded MT Bold"));
        font2.setBold(false);
        font2.setWeight(50);
        l2->setFont(font2);
        l2->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));
        l2->raise();

        QFont font3;
        if(t3=="A"||t3=="B"||t3=="S")
        {
            l3->setGeometry(QRect(Point.x()+65,Point.y()+30,51,51));
            font3.setPointSize(14);
        }
        else if(t3=="C1"||t3=="C2"||t3=="C3")
        {
            l3->setGeometry(QRect(Point.x()+65,Point.y()+30,51,51));
            font3.setPointSize(9);
        }
        else if(t3=="TopC"||t3=="Pa3D")
        {
            l3->setGeometry(QRect(Point.x()+65,Point.y()+30,51,51));
            font3.setPointSize(5);
        }
        font3.setFamily(QString::fromUtf8("Arial Rounded MT Bold"));
        font3.setBold(false);
        font3.setWeight(50);
        l3->setFont(font3);
        l3->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));
        l3->raise();

        QFont font4;
        if(t4=="A"||t4=="B"||t4=="S")
        {
            l4->setGeometry(QRect(Point.x()+92,Point.y()+30,51,51));
            font4.setPointSize(14);
        }
        else if(t4=="C1"||t4=="C2"||t4=="C3")
        {
            l4->setGeometry(QRect(Point.x()+92,Point.y()+30,51,51));
            font4.setPointSize(9);
        }
        else if(t4=="TopC"||t4=="Pa3D")
        {
            l4->setGeometry(QRect(Point.x()+92,Point.y()+30,51,51));
            font4.setPointSize(5);
        }
        font4.setFamily(QString::fromUtf8("Arial Rounded MT Bold"));
        font4.setBold(false);
        font4.setWeight(50);
        l4->setFont(font4);
        l4->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));
        l4->raise();
    }
    else if(m_customlayout==11)
    {
        QFont font1;
        if(t1=="A"||t1=="B"||t1=="S")
        {
            l1->setGeometry(QRect(Point.x()+40,Point.y()+3,51,51));
            font1.setPointSize(16);
        }
        else if(t1=="C1"||t1=="C2"||t1=="C3")
        {
            l1->setGeometry(QRect(Point.x()+35,Point.y()+3,51,51));
            font1.setPointSize(14);
        }
        else if(t1=="TopC"||t1=="Pa3D")
        {
            l1->setGeometry(QRect(Point.x()+35,Point.y()+3,51,51));
            font1.setPointSize(7);
        }
        font1.setFamily(QString::fromUtf8("Arial Rounded MT Bold"));
        font1.setBold(false);
        font1.setWeight(50);
        l1->setFont(font1);
        l1->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));
        l1->raise();

        QFont font2;
        if(t2=="A"||t2=="B"||t2=="S")
        {
            l2->setGeometry(QRect(Point.x()+85,Point.y()+3,51,51));
            font2.setPointSize(16);
        }
        else if(t2=="C1"||t2=="C2"||t2=="C3")
        {
            l2->setGeometry(QRect(Point.x()+80,Point.y()+3,51,51));
            font2.setPointSize(14);
        }
        else if(t2=="TopC"||t2=="Pa3D")
        {
            l2->setGeometry(QRect(Point.x()+78,Point.y()+3,51,51));
            font2.setPointSize(7);
        }
        font2.setFamily(QString::fromUtf8("Arial Rounded MT Bold"));
        font2.setBold(false);
        font2.setWeight(50);
        l2->setFont(font2);
        l2->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));
        l2->raise();

        QFont font3;
        if(t3=="A"||t3=="B"||t3=="S")
        {
            l3->setGeometry(QRect(Point.x()+60,Point.y()+29,51,51));
            font3.setPointSize(16);
        }
        else if(t3=="C1"||t3=="C2"||t3=="C3")
        {
            l3->setGeometry(QRect(Point.x()+55,Point.y()+29,51,51));
            font3.setPointSize(14);
        }
        else if(t3=="TopC"||t3=="Pa3D")
        {
            l3->setGeometry(QRect(Point.x()+50,Point.y()+29,51,51));
            font3.setPointSize(10);
        }
        font3.setFamily(QString::fromUtf8("Arial Rounded MT Bold"));
        font3.setBold(false);
        font3.setWeight(50);
        l3->setFont(font3);
        l3->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));
        l3->raise();

        QFont font4;
        if(t4=="A"||t4=="B"||t4=="S")
        {
            l4->setGeometry(QRect(Point.x()+60,Point.y()+57,51,51));
            font4.setPointSize(16);
        }
        else if(t4=="C1"||t4=="C2"||t4=="C4")
        {
            l4->setGeometry(QRect(Point.x()+55,Point.y()+57,51,51));
            font4.setPointSize(14);
        }
        else if(t4=="TopC"||t4=="Pa4D")
        {
            l4->setGeometry(QRect(Point.x()+50,Point.y()+57,51,51));
            font4.setPointSize(10);
        }
        font4.setFamily(QString::fromUtf8("Arial Rounded MT Bold"));
        font4.setBold(false);
        font4.setWeight(50);
        l4->setFont(font4);
        l4->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));
        l4->raise();
    }
}
