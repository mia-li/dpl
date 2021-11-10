#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "layoutpage.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Initial();
    lay=new LayoutPage();
    connect(lay,SIGNAL(sendLayoutData(QString)),this,SLOT(layoutData(QString)));
    connect(lay,SIGNAL(DisplayCustomLayout(int ,int ,int ,int ,int )),this,SLOT(DisplayCustomLayout(int ,int ,int ,int ,int )));
}
void MainWindow::Initial()
{

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DisplayCustomLayout(int customlayout,int local1,int local2,int local3,int local4)
{
    QCustomPlot *cp1;
    QCustomPlot *cp2;
    QCustomPlot *cp3;
    QCustomPlot *cp4;

    if(customlayout==1)
    {
        InitCustomWidget(ui->pagec1,cp1,local1);
    }
    else if(customlayout==2)
    {
        InitCustomWidget(ui->splitterc2,cp1,local1);
        InitCustomWidget(ui->splitterc2,cp2,local2);

        ui->splitterc2->replaceWidget(0,cp1);
        ui->splitterc2->replaceWidget(1,cp2);

    }
    else if(customlayout==3)
    {
        InitCustomWidget(ui->splitterc3,cp1,local1);
        InitCustomWidget(ui->splitterc3,cp2,local2);
        ui->splitterc3->replaceWidget(0,cp1);
        ui->splitterc3->replaceWidget(1,cp2);
    }
    else if(customlayout==4)
    {
        InitCustomWidget(ui->splitterc4,cp1,local1);
        InitCustomWidget(ui->splitterc4,cp2,local2);
        InitCustomWidget(ui->splitterc4,cp3,local3);
        ui->splitterc4->replaceWidget(0,cp1);
        ui->splitterc4->replaceWidget(1,cp2);
        ui->splitterc4->replaceWidget(2,cp3);
    }
    else if(customlayout==5)
    {
        InitCustomWidget(ui->splitterc5,cp1,local1);
        InitCustomWidget(ui->splitterc5,cp2,local2);
        InitCustomWidget(ui->splitterc5,cp3,local3);
        ui->splitterc5->replaceWidget(0,cp1);
        ui->splitterc5->replaceWidget(1,cp2);
        ui->splitterc5->replaceWidget(2,cp3);
    }
    else if(customlayout==6)
    {
        InitCustomWidget(ui->splitterc6h,cp1,local1);
        InitCustomWidget(ui->splitterc6h,cp2,local2);
        InitCustomWidget(ui->splitterc6v,cp3,local3);
        ui->splitterc6h->replaceWidget(0,cp1);
        ui->splitterc6h->replaceWidget(1,cp2);
        ui->splitterc6v->replaceWidget(1,cp3);
    }
    else if(customlayout==7)
    {
        InitCustomWidget(ui->splitterc7v,cp1,local1);
        InitCustomWidget(ui->splitterc7v,cp2,local2);
        InitCustomWidget(ui->splitterc7h,cp3,local3);
        ui->splitterc7v->replaceWidget(0,cp1);
        ui->splitterc7v->replaceWidget(1,cp2);
        ui->splitterc7h->replaceWidget(1,cp3);
    }
    else if(customlayout==8)
    {
        InitCustomWidget(ui->splitterc8h,cp1,local1);
        InitCustomWidget(ui->splitterc8h,cp2,local2);
        InitCustomWidget(ui->splitterc8h,cp3,local3);
        InitCustomWidget(ui->splitterc8v,cp4,local4);
        ui->splitterc8h->replaceWidget(0,cp1);
        ui->splitterc8h->replaceWidget(1,cp2);
        ui->splitterc8h->replaceWidget(2,cp3);
        ui->splitterc8v->replaceWidget(1,cp4);
    }
    else if(customlayout==9)
    {
        InitCustomWidget(ui->splitterc9v,cp1,local1);
        InitCustomWidget(ui->splitterc9h1,cp2,local2);
        InitCustomWidget(ui->splitterc9h1,cp3,local3);
        InitCustomWidget(ui->splitterc9h2,cp4,local4);
        ui->splitterc9v->replaceWidget(0,cp1);
        ui->splitterc9h1->replaceWidget(0,cp2);
        ui->splitterc9h1->replaceWidget(1,cp3);
        ui->splitterc9h2->replaceWidget(1,cp4);
    }
    else if(customlayout==10)
    {
        InitCustomWidget(ui->splitterc10h,cp1,local1);
        InitCustomWidget(ui->splitterc10h,cp2,local2);
        InitCustomWidget(ui->splitterc10v,cp3,local3);
        InitCustomWidget(ui->splitterc10v,cp4,local4);
        ui->splitterc10h->replaceWidget(0,cp1);
        ui->splitterc10h->replaceWidget(1,cp2);
        ui->splitterc10v->replaceWidget(1,cp3);
        ui->splitterc10v->replaceWidget(2,cp4);
    }
    else if(customlayout==11)
    {
        InitCustomWidget(ui->splitterc11v,cp1,local1);
        InitCustomWidget(ui->splitterc11v,cp2,local2);
        InitCustomWidget(ui->splitterc11h,cp3,local3);
        InitCustomWidget(ui->splitterc11h,cp4,local4);

        ui->splitterc11v->replaceWidget(0,cp1);
        ui->splitterc11v->replaceWidget(1,cp2);
        ui->splitterc11h->replaceWidget(1,cp3);
        ui->splitterc11h->replaceWidget(2,cp4);
    }
    int curIndex=customlayout+20;//customlayout 1-11
    ui->stackedWidget->setCurrentIndex(curIndex);
}
void MainWindow::InitCustomWidget(QWidget* widget,QCustomPlot *&cp,int local)//在子函数中为指针分配空间，参数列表中要使用指针的引用。
{//若直接将指针作为形参，动态分配的空间会成为内存泄漏，不能达到分配空间的效果。
    if(local==1)
    {
        cp=new A2CustomPlot(widget);
    }
    else if(local==2)
    {
        cp=new BCustomPlot(widget);
    }
    else if(local>=3||local<=5)
    {
        cp=new CCustomPlot(widget);
    }
    else if(local==6)
    {
        cp=new SCustomPlot(widget);
    }
    else if(local==7)
    {
        cp=new TopcCustomPlot(widget);
    }
    else if(local==8)
    {
        //cp=new BCustomPlot(ui->pagec1);
    }
    cp->setGeometry(QRect(10, 20, 1161, 681));
}

void MainWindow::on_pushButton_2_clicked()
{
    lay->show();
}
void MainWindow::layoutData(QString type)
{
    int m_type=type.toInt();
    ui->stackedWidget->setCurrentIndex(m_type-1);
    qDebug("%d",m_type);

    //0:a2 1:a 2:b 3-5:c 6:s 7:topc
    if(m_type==2)//a2b
    {
        CursorEvent(ui->widget2a,ui->widget2b,0,2);
        CursorEvent(ui->widget2b,ui->widget2a,2,0);
    }
    else if(m_type==3)//ab
    {
        CursorEvent(ui->widget3a,ui->widget3b,1,2);
        CursorEvent(ui->widget3b,ui->widget3a,2,1);
    }
    else if(m_type==5)//sa2
    {
        CursorEvent(ui->widget5a,ui->widget5s,0,6);
        CursorEvent(ui->widget5s,ui->widget5a,6,0);

    }
    else if(m_type==6)//as
    {
        CursorEvent(ui->widget6a,ui->widget6s,1,6);
        CursorEvent(ui->widget6s,ui->widget6a,6,1);
    }
    else if(m_type==7) //abs
    {
        CursorEvent(ui->widget7a,ui->widget7s,1,6);
        CursorEvent(ui->widget7a,ui->widget7b,1,2);
        CursorEvent(ui->widget7s,ui->widget7a,6,1);
        CursorEvent(ui->widget7s,ui->widget7b,6,2);
        CursorEvent(ui->widget7b,ui->widget7a,2,1);
        CursorEvent(ui->widget7b,ui->widget7s,2,6);
    }
    else if(m_type==8)//sa2c
    {
        CursorEvent(ui->widget8a,ui->widget8s,0,6);
        CursorEvent(ui->widget8s,ui->widget8a,6,0);
        CursorEvent(ui->widget8s,ui->widget8c,6,3);
        CursorEvent(ui->widget8c,ui->widget8s,3,6);
        CursorEvent(ui->widget8c,ui->widget8a,3,0);
    }
    else if(m_type==9) //abs
    {
        CursorEvent(ui->widget9a,ui->widget9s,1,6);
        CursorEvent(ui->widget9a,ui->widget9b,1,2);
        CursorEvent(ui->widget9s,ui->widget9a,6,1);
        CursorEvent(ui->widget9s,ui->widget9b,6,2);
        CursorEvent(ui->widget9b,ui->widget9a,2,1);
        CursorEvent(ui->widget9b,ui->widget9s,2,6);
    }
    else if(m_type==10)//sa2b
    {
        CursorEvent(ui->widget10a,ui->widget10s,0,6);
        CursorEvent(ui->widget10a,ui->widget10b,0,2);
        CursorEvent(ui->widget10s,ui->widget10s,6,0);
        CursorEvent(ui->widget10s,ui->widget10b,6,2);
        CursorEvent(ui->widget10b,ui->widget10a,2,0);
        CursorEvent(ui->widget10b,ui->widget10s,2,6);

    }
    else if(m_type==11)//abcs
    {
        CursorEvent(ui->widget11a,ui->widget11s,1,6);
        CursorEvent(ui->widget11a,ui->widget11b,1,2);
        CursorEvent(ui->widget11b,ui->widget11a,2,1);
        CursorEvent(ui->widget11b,ui->widget11c,2,3);
        CursorEvent(ui->widget11b,ui->widget11s,2,6);
        CursorEvent(ui->widget11c,ui->widget11a,3,1);
        CursorEvent(ui->widget11c,ui->widget11b,3,2);
        CursorEvent(ui->widget11c,ui->widget11s,3,6);
        CursorEvent(ui->widget11s,ui->widget11a,6,1);
        CursorEvent(ui->widget11s,ui->widget11b,6,2);
        CursorEvent(ui->widget11s,ui->widget11c,6,3);
    }
    else if(m_type==12)//sa2bc
    {
        CursorEvent(ui->widget12a,ui->widget12s,0,6);
        CursorEvent(ui->widget12a,ui->widget12b,0,2);
        CursorEvent(ui->widget12b,ui->widget12a,2,0);
        CursorEvent(ui->widget12b,ui->widget12c,2,3);
        CursorEvent(ui->widget12b,ui->widget12s,2,6);
        CursorEvent(ui->widget12c,ui->widget12a,3,0);
        CursorEvent(ui->widget12c,ui->widget12b,3,2);
        CursorEvent(ui->widget12c,ui->widget12s,3,6);
        CursorEvent(ui->widget12s,ui->widget12a,6,0);
        CursorEvent(ui->widget12s,ui->widget12b,6,2);
        CursorEvent(ui->widget12s,ui->widget12c,6,3);
    }
    else if(m_type==13)//sa2bc
    {
        CursorEvent(ui->widget13a,ui->widget13s,0,6);
        CursorEvent(ui->widget13a,ui->widget13b,0,2);
        CursorEvent(ui->widget13b,ui->widget13a,2,0);
        CursorEvent(ui->widget13b,ui->widget13c,2,3);
        CursorEvent(ui->widget13b,ui->widget13s,2,6);
        CursorEvent(ui->widget13c,ui->widget13a,3,0);
        CursorEvent(ui->widget13c,ui->widget13b,3,2);
        CursorEvent(ui->widget13c,ui->widget13s,3,6);
        CursorEvent(ui->widget13s,ui->widget13a,6,0);
        CursorEvent(ui->widget13s,ui->widget13b,6,2);
        CursorEvent(ui->widget13s,ui->widget13c,6,3);

    }
    else if(m_type==14)//acs
    {
        CursorEvent(ui->widget14a,ui->widget14s,1,6);
        CursorEvent(ui->widget14c,ui->widget14a,3,1);
        CursorEvent(ui->widget14c,ui->widget14s,3,6);
        CursorEvent(ui->widget14s,ui->widget14a,6,1);
        CursorEvent(ui->widget14s,ui->widget14c,6,3);

    }
    else if(m_type==15)//sa2c
    {
        CursorEvent(ui->widget15a,ui->widget15s,0,6);
        CursorEvent(ui->widget15s,ui->widget15a,6,0);
        CursorEvent(ui->widget15s,ui->widget15c,6,3);
        CursorEvent(ui->widget15c,ui->widget15s,3,6);
        CursorEvent(ui->widget15c,ui->widget15a,3,0);
    }
    else if(m_type==16) //acstopc
    {
        CursorEvent(ui->widget16a,ui->widget16s,1,6);
        CursorEvent(ui->widget16c,ui->widget16a,3,1);
        CursorEvent(ui->widget16c,ui->widget16s,3,6);
        CursorEvent(ui->widget16c,ui->widget16topc,3,7);
        CursorEvent(ui->widget16s,ui->widget16a,6,1);
        CursorEvent(ui->widget16s,ui->widget16c,6,3);
        CursorEvent(ui->widget16topc,ui->widget16c,7,3);
        CursorEvent(ui->widget16topc,ui->widget16a,7,1);

    }
    else if(m_type==17)//sa2c1c2c3
    {
        CursorEvent(ui->widget17a,ui->widget17s,0,6);
        CursorEvent(ui->widget17s,ui->widget17a,6,0);
        CursorEvent(ui->widget17s,ui->widget17c1,6,3);
        CursorEvent(ui->widget17s,ui->widget17c2,6,4);
        CursorEvent(ui->widget17s,ui->widget17c3,6,5);
        CursorEvent(ui->widget17c1,ui->widget17a,3,0);
        CursorEvent(ui->widget17c1,ui->widget17c2,3,4);
        CursorEvent(ui->widget17c1,ui->widget17c3,3,5);
        CursorEvent(ui->widget17c1,ui->widget17s,3,6);
        CursorEvent(ui->widget17c2,ui->widget17a,4,0);
        CursorEvent(ui->widget17c2,ui->widget17c1,4,3);
        CursorEvent(ui->widget17c2,ui->widget17c3,4,5);
        CursorEvent(ui->widget17c2,ui->widget17s,4,6);
        CursorEvent(ui->widget17c3,ui->widget17a,5,0);
        CursorEvent(ui->widget17c3,ui->widget17c1,5,3);
        CursorEvent(ui->widget17c3,ui->widget17c2,5,4);
        CursorEvent(ui->widget17c3,ui->widget17s,5,6);

    }
    else if(m_type==18)//abcs
    {
        CursorEvent(ui->widget18a,ui->widget18s,1,6);
        CursorEvent(ui->widget18a,ui->widget18b,1,2);
        CursorEvent(ui->widget18b,ui->widget18a,2,1);
        CursorEvent(ui->widget18b,ui->widget18c,2,3);
        CursorEvent(ui->widget18b,ui->widget18s,2,6);
        CursorEvent(ui->widget18c,ui->widget18a,3,1);
        CursorEvent(ui->widget18c,ui->widget18b,3,2);
        CursorEvent(ui->widget18c,ui->widget18s,3,6);
        CursorEvent(ui->widget18s,ui->widget18a,6,1);
        CursorEvent(ui->widget18s,ui->widget18b,6,2);
        CursorEvent(ui->widget18s,ui->widget18c,6,3);

    }
    else if(m_type==19)//acs
    {
        CursorEvent(ui->widget19a,ui->widget19s,1,6);
        CursorEvent(ui->widget19c,ui->widget19a,3,1);
        CursorEvent(ui->widget19c,ui->widget19s,3,6);
        CursorEvent(ui->widget19s,ui->widget19a,6,1);
        CursorEvent(ui->widget19s,ui->widget19c,6,3);
    }
}
void MainWindow::CursorEvent(ThCustomPlot *sender, ThCustomPlot *receiver,int loc1,int loc2)
{
    if(loc1==0||loc1==1) // a2/a
    {
        if(loc2==2) //B
        {
            connect(sender, SIGNAL(updateY1(float)), receiver, SLOT(updateY1Event(float)));
            connect(sender, SIGNAL(updateY2(float)), receiver, SLOT(updateY2Event(float)));

        }
        if(loc2==6) //S
        {
            connect(sender, SIGNAL(updateY1), receiver, SLOT(updateY1Event));
            connect(sender, SIGNAL(updateY2), receiver, SLOT(updateY2Event));
            connect(sender, SIGNAL(SetDashLineVis), receiver, SLOT(SetDashLineVisEvent));
            connect(sender, SIGNAL(updateDash), receiver, SLOT(updateDashEvent));
            connect(sender, SIGNAL(updateDashY), receiver, SLOT(updateDashYEvent));
            connect(sender, SIGNAL(changeDashSize), receiver, SLOT(changeDashSizeEvent));
        }
    }
    else if(loc1==2) //b
    {
        if(loc2==0) //a2
        {
            connect(sender, SIGNAL(updateY1(float)), receiver, SLOT(updateX1Event(float)));
            connect(sender, SIGNAL(updateY2(float)), receiver, SLOT(updateX2Event(float)));
            connect(sender, SIGNAL(SetShortLineVis(float)), receiver, SLOT(SetShortLineVisEvent(float)));
        }
        else if(loc2==1) //a
        {
            connect(sender, SIGNAL(updateY1(float)), receiver, SLOT(updateY1Event(float)));
            connect(sender, SIGNAL(updateY2(float)), receiver, SLOT(updateY2Event(float)));
            connect(sender, SIGNAL(SetShortLineVis(float)), receiver, SLOT(SetShortLineVisEvent(float)));
        }
        else if(loc2>=3&&loc2<=5) //c
        {
            connect(sender, SIGNAL(updateX1(float)), receiver, SLOT(updateX1Event(float)));
            connect(sender, SIGNAL(updateX2(float)), receiver, SLOT(updateX2Event(float)));
            connect(sender, SIGNAL(updateX3(float)), receiver, SLOT(updateX3Event(float)));
        }
        else if(loc2==6) //S
        {
            connect(sender, SIGNAL(updateY1(float)), receiver, SLOT(updateY1Event(float)));
            connect(sender, SIGNAL(updateY2(float)), receiver, SLOT(updateY2Event(float)));
        }
    }
    else if(loc1>=3&&loc1<=5) //C
    {
        if(loc2==0||loc2==1) //a2/a
        {
            connect(sender, SIGNAL(SetShortLineVis(float)), receiver, SLOT(SetShortLineVisEvent(float)));
        }
        else if(loc2==2||loc2==7||(loc2>=3&&loc2<=5))//b/topc/c
        {
            connect(sender, SIGNAL(updateX1b(float)), receiver, SLOT(updateX1Event(float)));
            connect(sender, SIGNAL(updateX2b(float)), receiver, SLOT(updateX2Event(float)));
            connect(sender, SIGNAL(updateX3(float)), receiver, SLOT(updateX3Event(float)));
        }
        else if(loc2==6) //S
        {
            connect(sender, SIGNAL(updateX1s(float)), receiver, SLOT(updateX1Event(float)));
            connect(sender, SIGNAL(updateX2s(float)), receiver, SLOT(updateX2Event(float)));
        }
    }
    else if(loc1==6) //s
    {
        if(loc2==0) //a2
        {
            connect(sender, SIGNAL(updateY1(float)), receiver, SLOT(updateX1Event(float)));
            connect(sender, SIGNAL(updateY2(float)), receiver, SLOT(updateX2Event(float)));
            connect(sender, SIGNAL(SetShortLineVis(float)), receiver, SLOT(SetShortLineVisEvent(float)));
        }
        else if(loc2==1) //a
        {
            connect(sender, SIGNAL(updateY1(float)), receiver, SLOT(updateY1Event(float)));
            connect(sender, SIGNAL(updateY2(float)), receiver, SLOT(updateY2Event(float)));
            connect(sender, SIGNAL(SetShortLineVis(float)), receiver, SLOT(SetShortLineVisEvent(float)));
        }
        else if(loc2==2) //b
        {
            connect(sender, SIGNAL(updateY1(float)), receiver, SLOT(updateY1Event(float)));
            connect(sender, SIGNAL(updateY2(float)), receiver, SLOT(updateY2Event(float)));
        }
        else if(loc2>=3&&loc2<=5) //c
        {
            connect(sender, SIGNAL(updateY1c(float)), receiver, SLOT(updateY1Event(float)));
            connect(sender, SIGNAL(updateY2c(float)), receiver, SLOT(updateY2Event(float)));
        }
    }
    else if(loc1==7) //s
    {
        if(loc2==0||loc2==1) //a2/a
        {
            connect(sender, SIGNAL(SetShortLineVis(float)), receiver, SLOT(SetShortLineVisEvent(float)));
        }
        else if(loc2>=3&&loc2<=5) //c
        {
            connect(sender, SIGNAL(updateX1(float)), receiver, SLOT(updateX1Event(float)));
            connect(sender, SIGNAL(updateX2(float)), receiver, SLOT(updateX2Event(float)));
            connect(sender, SIGNAL(updateX3(float)), receiver, SLOT(updateX3Event(float)));
        }
    }
}

