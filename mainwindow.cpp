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
   // ui->pushButton_2->setVisible(false);
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

//        if(local1==1)
//        {
//            cp1=new ACustomPlot(ui->splitterc2);
//        }
//        else if(local1==2)
//        {
//            cp1=new BCustomPlot(ui->splitterc2);
//        }
//        else if(local1>=3||local1<=5)
//        {
//            cp1=new CCustomPlot(ui->splitterc2);
//        }
//        else if(local1==6)
//        {
//            cp1=new SCustomPlot(ui->splitterc2);
//        }
//        else if(local1==7)
//        {
//            cp1=new TopcCustomPlot(ui->splitterc2);
//        }
//        else if(local1==8)
//        {
//            //cp=new BCustomPlot(ui->pagec1);
//        }

//        if(local2==1)
//        {
//            cp2=new ACustomPlot(ui->splitterc2);
//        }
//        else if(local2==2)
//        {
//            cp2=new BCustomPlot(ui->splitterc2);
//        }
//        else if(local2>=3||local2<=5)
//        {
//            cp2=new CCustomPlot(ui->splitterc2);
//        }
//        else if(local2==6)
//        {
//            cp2=new SCustomPlot(ui->splitterc2);
//        }
//        else if(local2==7)
//        {
//            cp2=new TopcCustomPlot(ui->splitterc2);
//        }
//        else if(local2==8)
//        {
//            //cp=new BCustomPlot(ui->pagec1);
//        }

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
       // ui->splitterc6h->replaceWidget(1,cp2);
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
        cp=new ACustomPlot(widget);
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

int num=0;

void MainWindow::on_pushButton_clicked()
{
    if(num>18)
    {
        num=0;
    }
    ui->stackedWidget->setCurrentIndex(num);
    num++;

    QWidget *curWidget=ui->stackedWidget->currentWidget();
    if(curWidget==ui->page2)//a2b
    {
        connect(ui->widget2a, &A2CustomPlot::updateY1, (ui->widget2b), &BCustomPlot::updateY1Event);
        connect(ui->widget2a, &A2CustomPlot::updateY2, (ui->widget2b), &BCustomPlot::updateY2Event);
        connect(ui->widget2b, &BCustomPlot::updateY1, (ui->widget2a), &A2CustomPlot::updateX1Event);
        connect(ui->widget2b, &BCustomPlot::updateY2, (ui->widget2a), &A2CustomPlot::updateX2Event);

    }
    else if(curWidget==ui->page3)
    {
        connect(ui->widget3a, &ACustomPlot::updateY1, (ui->widget3b), &BCustomPlot::updateY1Event);
        connect(ui->widget3a, &ACustomPlot::updateY2, (ui->widget3b), &BCustomPlot::updateY2Event);
        connect(ui->widget3b, &BCustomPlot::updateY1, (ui->widget3a), &ACustomPlot::updateY1Event);
        connect(ui->widget3b, &BCustomPlot::updateY2, (ui->widget3a), &ACustomPlot::updateY2Event);
    }
    else if(curWidget==ui->page5)//sa2
    {
        connect(ui->widget5a, &A2CustomPlot::updateY1, (ui->widget5s), &SCustomPlot::updateY1Event);
        connect(ui->widget5a, &A2CustomPlot::updateY2, (ui->widget5s), &SCustomPlot::updateY2Event);
        connect(ui->widget5a, &A2CustomPlot::SetDashLineVis, (ui->widget5s), &SCustomPlot::SetDashLineVisEvent);
        connect(ui->widget5a, &A2CustomPlot::updateDash, (ui->widget5s), &SCustomPlot::updateDashEvent);
        connect(ui->widget5a, &A2CustomPlot::updateDashY, (ui->widget5s), &SCustomPlot::updateDashYEvent);
        connect(ui->widget5a, &A2CustomPlot::changeDashSize, (ui->widget5s), &SCustomPlot::changeDashSizeEvent);

        connect(ui->widget5s, &SCustomPlot::updateY1, (ui->widget5a), &A2CustomPlot::updateX1Event);
        connect(ui->widget5s, &SCustomPlot::updateY2, (ui->widget5a), &A2CustomPlot::updateX2Event);
        connect(ui->widget5s, &SCustomPlot::SetShortLineVis, (ui->widget5a), &A2CustomPlot::SetShortLineVisEvent);

    }
    else if(curWidget==ui->page6)
    {
        connect(ui->widget6a, &ACustomPlot::updateY1, (ui->widget6s), &SCustomPlot::updateY1Event);
        connect(ui->widget6a, &ACustomPlot::updateY2, (ui->widget6s), &SCustomPlot::updateY2Event);
        connect(ui->widget6a, &ACustomPlot::SetDashLineVis, (ui->widget6s), &SCustomPlot::SetDashLineVisEvent);
        connect(ui->widget6a, &ACustomPlot::updateDash, (ui->widget6s), &SCustomPlot::updateDashEvent);
        connect(ui->widget6a, &ACustomPlot::updateDashY, (ui->widget6s), &SCustomPlot::updateDashYEvent);
        connect(ui->widget6a, &ACustomPlot::changeDashSize, (ui->widget6s), &SCustomPlot::changeDashSizeEvent);
        connect(ui->widget6s, &SCustomPlot::updateY1, (ui->widget6a), &ACustomPlot::updateY1Event);
        connect(ui->widget6s, &SCustomPlot::updateY2, (ui->widget6a), &ACustomPlot::updateY2Event);
        connect(ui->widget6s, &SCustomPlot::SetShortLineVis, (ui->widget6a), &ACustomPlot::SetShortLineVisEvent);
    }
    else if(curWidget==ui->page7)
    {
        connect(ui->widget7a, &ACustomPlot::updateY1, (ui->widget7s), &SCustomPlot::updateY1Event);
        connect(ui->widget7a, &ACustomPlot::updateY2, (ui->widget7s), &SCustomPlot::updateY2Event);
        connect(ui->widget7a, &ACustomPlot::SetDashLineVis, (ui->widget7s), &SCustomPlot::SetDashLineVisEvent);
        connect(ui->widget7a, &ACustomPlot::updateDash, (ui->widget7s), &SCustomPlot::updateDashEvent);
        connect(ui->widget7a, &ACustomPlot::updateDashY, (ui->widget7s), &SCustomPlot::updateDashYEvent);
        connect(ui->widget7a, &ACustomPlot::changeDashSize, (ui->widget7s), &SCustomPlot::changeDashSizeEvent);
        connect(ui->widget7a, &ACustomPlot::updateY1, (ui->widget7b), &BCustomPlot::updateY1Event);
        connect(ui->widget7a, &ACustomPlot::updateY2, (ui->widget7b), &BCustomPlot::updateY2Event);

        connect(ui->widget7s, &SCustomPlot::updateY1, (ui->widget7a), &ACustomPlot::updateY1Event);
        connect(ui->widget7s, &SCustomPlot::updateY2, (ui->widget7a), &ACustomPlot::updateY2Event);
        connect(ui->widget7s, &SCustomPlot::SetShortLineVis, (ui->widget7a), &ACustomPlot::SetShortLineVisEvent);
        connect(ui->widget7s, &SCustomPlot::updateY1, (ui->widget7b), &BCustomPlot::updateY1Event);
        connect(ui->widget7s, &SCustomPlot::updateY2, (ui->widget7b), &BCustomPlot::updateY2Event);

        connect(ui->widget7b, &BCustomPlot::updateY1, (ui->widget7s), &SCustomPlot::updateY1Event);
        connect(ui->widget7b, &BCustomPlot::updateY2, (ui->widget7s), &SCustomPlot::updateY2Event);
        connect(ui->widget7b, &BCustomPlot::updateY1, (ui->widget7a), &ACustomPlot::updateY1Event);
        connect(ui->widget7b, &BCustomPlot::updateY2, (ui->widget7a), &ACustomPlot::updateY2Event);
        connect(ui->widget7b, &BCustomPlot::SetShortLineVis, (ui->widget7a), &ACustomPlot::SetShortLineVisEvent);
    }
    else if(curWidget==ui->page8)//sa2c
    {
        connect(ui->widget8s, &SCustomPlot::updateY1c, (ui->widget8c), &CCustomPlot::updateY1Event);
        connect(ui->widget8s, &SCustomPlot::updateY2c, (ui->widget8c), &CCustomPlot::updateY2Event);
        connect(ui->widget8s, &SCustomPlot::updateY1, (ui->widget8a), &A2CustomPlot::updateX1Event);
        connect(ui->widget8s, &SCustomPlot::updateY2, (ui->widget8a), &A2CustomPlot::updateX2Event);
        connect(ui->widget8s, &SCustomPlot::SetShortLineVis, (ui->widget8a), &A2CustomPlot::SetShortLineVisEvent);

        connect(ui->widget8a, &A2CustomPlot::updateY1, (ui->widget8s), &SCustomPlot::updateY1Event);
        connect(ui->widget8a, &A2CustomPlot::updateY2, (ui->widget8s), &SCustomPlot::updateY2Event);
        connect(ui->widget8a, &A2CustomPlot::SetDashLineVis, (ui->widget8s), &SCustomPlot::SetDashLineVisEvent);
        connect(ui->widget8a, &A2CustomPlot::updateDash, (ui->widget8s), &SCustomPlot::updateDashEvent);
        connect(ui->widget8a, &A2CustomPlot::updateDashY, (ui->widget8s), &SCustomPlot::updateDashYEvent);
        connect(ui->widget8a, &A2CustomPlot::changeDashSize, (ui->widget8s), &SCustomPlot::changeDashSizeEvent);

        connect(ui->widget8c, &CCustomPlot::updateX1s, (ui->widget8s), &SCustomPlot::updateX1Event);
        connect(ui->widget8c, &CCustomPlot::updateX2s, (ui->widget8s), &SCustomPlot::updateX2Event);
        connect(ui->widget8c, &CCustomPlot::SetShortLineVis, (ui->widget8a), &A2CustomPlot::SetShortLineVisEvent);
    }
    else if(curWidget==ui->page9)
    {
        //a--s/b
        connect(ui->widget9a, &ACustomPlot::updateY1, (ui->widget9s), &SCustomPlot::updateY1Event);
        connect(ui->widget9a, &ACustomPlot::updateY2, (ui->widget9s), &SCustomPlot::updateY2Event);
        connect(ui->widget9a, &ACustomPlot::SetDashLineVis, (ui->widget9s), &SCustomPlot::SetDashLineVisEvent);
        connect(ui->widget9a, &ACustomPlot::updateDash, (ui->widget9s), &SCustomPlot::updateDashEvent);
        connect(ui->widget9a, &ACustomPlot::updateDashY, (ui->widget9s), &SCustomPlot::updateDashYEvent);
        connect(ui->widget9a, &ACustomPlot::changeDashSize, (ui->widget9s), &SCustomPlot::changeDashSizeEvent);
        connect(ui->widget9a, &ACustomPlot::updateY1, (ui->widget9b), &BCustomPlot::updateY1Event);
        connect(ui->widget9a, &ACustomPlot::updateY2, (ui->widget9b), &BCustomPlot::updateY2Event);

        connect(ui->widget9s, &SCustomPlot::updateY1, (ui->widget9a), &ACustomPlot::updateY1Event);
        connect(ui->widget9s, &SCustomPlot::updateY2, (ui->widget9a), &ACustomPlot::updateY2Event);
        connect(ui->widget9s, &SCustomPlot::SetShortLineVis, (ui->widget9a), &ACustomPlot::SetShortLineVisEvent);
        connect(ui->widget9s, &SCustomPlot::updateY1, (ui->widget9b), &BCustomPlot::updateY1Event);
        connect(ui->widget9s, &SCustomPlot::updateY2, (ui->widget9b), &BCustomPlot::updateY2Event);

        connect(ui->widget9b, &BCustomPlot::updateY1, (ui->widget9s), &SCustomPlot::updateY1Event);
        connect(ui->widget9b, &BCustomPlot::updateY2, (ui->widget9s), &SCustomPlot::updateY2Event);
        connect(ui->widget9b, &BCustomPlot::updateY1, (ui->widget9a), &ACustomPlot::updateY1Event);
        connect(ui->widget9b, &BCustomPlot::updateY2, (ui->widget9a), &ACustomPlot::updateY2Event);
        connect(ui->widget9b, &BCustomPlot::SetShortLineVis, (ui->widget9a), &ACustomPlot::SetShortLineVisEvent);
    }
    else if(curWidget==ui->page10)//sa2b
    {

        connect(ui->widget10s, &SCustomPlot::updateY1, (ui->widget10a), &A2CustomPlot::updateX1Event);
        connect(ui->widget10s, &SCustomPlot::updateY2, (ui->widget10a), &A2CustomPlot::updateX2Event);
        connect(ui->widget10s, &SCustomPlot::SetShortLineVis, (ui->widget10a), &A2CustomPlot::SetShortLineVisEvent);
        connect(ui->widget10s, &SCustomPlot::updateY1, (ui->widget10b), &BCustomPlot::updateY1Event);
        connect(ui->widget10s, &SCustomPlot::updateY2, (ui->widget10b), &BCustomPlot::updateY2Event);

        connect(ui->widget10a, &A2CustomPlot::updateY1, (ui->widget10s), &SCustomPlot::updateY1Event);
        connect(ui->widget10a, &A2CustomPlot::updateY2, (ui->widget10s), &SCustomPlot::updateY2Event);
        connect(ui->widget10a, &A2CustomPlot::SetDashLineVis, (ui->widget10s), &SCustomPlot::SetDashLineVisEvent);
        connect(ui->widget10a, &A2CustomPlot::updateDash, (ui->widget10s), &SCustomPlot::updateDashEvent);
        connect(ui->widget10a, &A2CustomPlot::updateDashY, (ui->widget10s), &SCustomPlot::updateDashYEvent);
        connect(ui->widget10a, &A2CustomPlot::changeDashSize, (ui->widget10s), &SCustomPlot::changeDashSizeEvent);
        connect(ui->widget10a, &A2CustomPlot::updateY1, (ui->widget10b), &BCustomPlot::updateY1Event);
        connect(ui->widget10a, &A2CustomPlot::updateY2, (ui->widget10b), &BCustomPlot::updateY2Event);

        connect(ui->widget10b, &BCustomPlot::updateY1, (ui->widget10s), &SCustomPlot::updateY1Event);
        connect(ui->widget10b, &BCustomPlot::updateY2, (ui->widget10s), &SCustomPlot::updateY2Event);
        connect(ui->widget10b, &BCustomPlot::updateY1, (ui->widget10a), &A2CustomPlot::updateX1Event);
        connect(ui->widget10b, &BCustomPlot::updateY2, (ui->widget10a), &A2CustomPlot::updateX2Event);
        connect(ui->widget10b, &BCustomPlot::SetShortLineVis, (ui->widget10a), &A2CustomPlot::SetShortLineVisEvent);

    }
    else if(curWidget==ui->page11)
    {
        connect(ui->widget11a, &ACustomPlot::updateY1, (ui->widget11s), &SCustomPlot::updateY1Event);
        connect(ui->widget11a, &ACustomPlot::updateY2, (ui->widget11s), &SCustomPlot::updateY2Event);
        connect(ui->widget11a, &ACustomPlot::SetDashLineVis, (ui->widget11s), &SCustomPlot::SetDashLineVisEvent);
        connect(ui->widget11a, &ACustomPlot::updateDash, (ui->widget11s), &SCustomPlot::updateDashEvent);
        connect(ui->widget11a, &ACustomPlot::updateDashY, (ui->widget11s), &SCustomPlot::updateDashYEvent);
        connect(ui->widget11a, &ACustomPlot::changeDashSize, (ui->widget11s), &SCustomPlot::changeDashSizeEvent);
        connect(ui->widget11a, &ACustomPlot::updateY1, (ui->widget11b), &BCustomPlot::updateY1Event);
        connect(ui->widget11a, &ACustomPlot::updateY2, (ui->widget11b), &BCustomPlot::updateY2Event);

        connect(ui->widget11s, &SCustomPlot::updateY1, (ui->widget11a), &ACustomPlot::updateY1Event);
        connect(ui->widget11s, &SCustomPlot::updateY2, (ui->widget11a), &ACustomPlot::updateY2Event);
        connect(ui->widget11s, &SCustomPlot::SetShortLineVis, (ui->widget11a), &ACustomPlot::SetShortLineVisEvent);
        connect(ui->widget11s, &SCustomPlot::updateY1, (ui->widget11b), &BCustomPlot::updateY1Event);
        connect(ui->widget11s, &SCustomPlot::updateY2, (ui->widget11b), &BCustomPlot::updateY2Event);
        connect(ui->widget11s, &SCustomPlot::updateY1c, (ui->widget11c), &CCustomPlot::updateY1Event);
        connect(ui->widget11s, &SCustomPlot::updateY2c, (ui->widget11c), &CCustomPlot::updateY2Event);


        connect(ui->widget11b, &BCustomPlot::updateY1, (ui->widget11s), &SCustomPlot::updateY1Event);
        connect(ui->widget11b, &BCustomPlot::updateY2, (ui->widget11s), &SCustomPlot::updateY2Event);
        connect(ui->widget11b, &BCustomPlot::updateY1, (ui->widget11a), &ACustomPlot::updateY1Event);
        connect(ui->widget11b, &BCustomPlot::updateY2, (ui->widget11a), &ACustomPlot::updateY2Event);
        connect(ui->widget11b, &BCustomPlot::SetShortLineVis, (ui->widget11a), &ACustomPlot::SetShortLineVisEvent);
        connect(ui->widget11b, &BCustomPlot::updateX1, (ui->widget11c), &CCustomPlot::updateX1Event);
        connect(ui->widget11b, &BCustomPlot::updateX2, (ui->widget11c), &CCustomPlot::updateX2Event);
        connect(ui->widget11b, &BCustomPlot::updateX3, (ui->widget11c), &CCustomPlot::updateX3Event);

        connect(ui->widget11c, &CCustomPlot::updateX1s, (ui->widget11s), &SCustomPlot::updateX1Event);
        connect(ui->widget11c, &CCustomPlot::updateX2s, (ui->widget11s), &SCustomPlot::updateX2Event);
        connect(ui->widget11c, &CCustomPlot::updateX1b, (ui->widget11b), &BCustomPlot::updateX1Event);
        connect(ui->widget11c, &CCustomPlot::updateX2b, (ui->widget11b), &BCustomPlot::updateX2Event);
        connect(ui->widget11c, &CCustomPlot::updateX3, (ui->widget11b), &BCustomPlot::updateX3Event);
        connect(ui->widget11c, &CCustomPlot::SetShortLineVis, (ui->widget11a), &ACustomPlot::SetShortLineVisEvent);
    }
    else if(curWidget==ui->page12)//sa2bc
    {
        connect(ui->widget12s, &SCustomPlot::updateY1, (ui->widget12a), &A2CustomPlot::updateX1Event);
        connect(ui->widget12s, &SCustomPlot::updateY2, (ui->widget12a), &A2CustomPlot::updateX2Event);
        connect(ui->widget12s, &SCustomPlot::SetShortLineVis, (ui->widget12a), &A2CustomPlot::SetShortLineVisEvent);
        connect(ui->widget12s, &SCustomPlot::updateY1, (ui->widget12b), &BCustomPlot::updateY1Event);
        connect(ui->widget12s, &SCustomPlot::updateY2, (ui->widget12b), &BCustomPlot::updateY2Event);
        connect(ui->widget12s, &SCustomPlot::updateY1c, (ui->widget12c), &CCustomPlot::updateY1Event);
        connect(ui->widget12s, &SCustomPlot::updateY2c, (ui->widget12c), &CCustomPlot::updateY2Event);

        connect(ui->widget12a, &A2CustomPlot::updateY1, (ui->widget12s), &SCustomPlot::updateY1Event);
        connect(ui->widget12a, &A2CustomPlot::updateY2, (ui->widget12s), &SCustomPlot::updateY2Event);
        connect(ui->widget12a, &A2CustomPlot::SetDashLineVis, (ui->widget12s), &SCustomPlot::SetDashLineVisEvent);
        connect(ui->widget12a, &A2CustomPlot::updateDash, (ui->widget12s), &SCustomPlot::updateDashEvent);
        connect(ui->widget12a, &A2CustomPlot::updateDashY, (ui->widget12s), &SCustomPlot::updateDashYEvent);
        connect(ui->widget12a, &A2CustomPlot::changeDashSize, (ui->widget12s), &SCustomPlot::changeDashSizeEvent);
        connect(ui->widget12a, &A2CustomPlot::updateY1, (ui->widget12b), &BCustomPlot::updateY1Event);
        connect(ui->widget12a, &A2CustomPlot::updateY2, (ui->widget12b), &BCustomPlot::updateY2Event);

        connect(ui->widget12b, &BCustomPlot::updateY1, (ui->widget12s), &SCustomPlot::updateY1Event);
        connect(ui->widget12b, &BCustomPlot::updateY2, (ui->widget12s), &SCustomPlot::updateY2Event);
        connect(ui->widget12b, &BCustomPlot::updateY1, (ui->widget12a), &A2CustomPlot::updateX1Event);
        connect(ui->widget12b, &BCustomPlot::updateY2, (ui->widget12a), &A2CustomPlot::updateX2Event);
        connect(ui->widget12b, &BCustomPlot::SetShortLineVis, (ui->widget12a), &A2CustomPlot::SetShortLineVisEvent);
        connect(ui->widget12b, &BCustomPlot::updateX1, (ui->widget12c), &CCustomPlot::updateX1Event);
        connect(ui->widget12b, &BCustomPlot::updateX2, (ui->widget12c), &CCustomPlot::updateX2Event);
        connect(ui->widget12b, &BCustomPlot::updateX3, (ui->widget12c), &CCustomPlot::updateX3Event);

        connect(ui->widget12c, &CCustomPlot::updateX1s, (ui->widget12s), &SCustomPlot::updateX1Event);
        connect(ui->widget12c, &CCustomPlot::updateX2s, (ui->widget12s), &SCustomPlot::updateX2Event);
        connect(ui->widget12c, &CCustomPlot::SetShortLineVis, (ui->widget12a), &A2CustomPlot::SetShortLineVisEvent);
        connect(ui->widget12c, &CCustomPlot::updateX1b, (ui->widget12b), &BCustomPlot::updateX1Event);
        connect(ui->widget12c, &CCustomPlot::updateX2b, (ui->widget12b), &BCustomPlot::updateX2Event);
        connect(ui->widget12c, &CCustomPlot::updateX3, (ui->widget12b), &BCustomPlot::updateX3Event);
    }
    else if(curWidget==ui->page13)//sa2bc
    {
        connect(ui->widget13s, &SCustomPlot::updateY1, (ui->widget13a), &A2CustomPlot::updateX1Event);
        connect(ui->widget13s, &SCustomPlot::updateY2, (ui->widget13a), &A2CustomPlot::updateX2Event);
        connect(ui->widget13s, &SCustomPlot::SetShortLineVis, (ui->widget13a), &A2CustomPlot::SetShortLineVisEvent);
        connect(ui->widget13s, &SCustomPlot::updateY1, (ui->widget13b), &BCustomPlot::updateY1Event);
        connect(ui->widget13s, &SCustomPlot::updateY2, (ui->widget13b), &BCustomPlot::updateY2Event);
        connect(ui->widget13s, &SCustomPlot::updateY1c, (ui->widget13c), &CCustomPlot::updateY1Event);
        connect(ui->widget13s, &SCustomPlot::updateY2c, (ui->widget13c), &CCustomPlot::updateY2Event);

        connect(ui->widget13a, &A2CustomPlot::updateY1, (ui->widget13s), &SCustomPlot::updateY1Event);
        connect(ui->widget13a, &A2CustomPlot::updateY2, (ui->widget13s), &SCustomPlot::updateY2Event);
        connect(ui->widget13a, &A2CustomPlot::SetDashLineVis, (ui->widget13s), &SCustomPlot::SetDashLineVisEvent);
        connect(ui->widget13a, &A2CustomPlot::updateDash, (ui->widget13s), &SCustomPlot::updateDashEvent);
        connect(ui->widget13a, &A2CustomPlot::updateDashY, (ui->widget13s), &SCustomPlot::updateDashYEvent);
        connect(ui->widget13a, &A2CustomPlot::changeDashSize, (ui->widget13s), &SCustomPlot::changeDashSizeEvent);
        connect(ui->widget13a, &A2CustomPlot::updateY1, (ui->widget13b), &BCustomPlot::updateY1Event);
        connect(ui->widget13a, &A2CustomPlot::updateY2, (ui->widget13b), &BCustomPlot::updateY2Event);

        connect(ui->widget13b, &BCustomPlot::updateY1, (ui->widget13s), &SCustomPlot::updateY1Event);
        connect(ui->widget13b, &BCustomPlot::updateY2, (ui->widget13s), &SCustomPlot::updateY2Event);
        connect(ui->widget13b, &BCustomPlot::updateY1, (ui->widget13a), &A2CustomPlot::updateX1Event);
        connect(ui->widget13b, &BCustomPlot::updateY2, (ui->widget13a), &A2CustomPlot::updateX2Event);
        connect(ui->widget13b, &BCustomPlot::SetShortLineVis, (ui->widget13a), &A2CustomPlot::SetShortLineVisEvent);
        connect(ui->widget13b, &BCustomPlot::updateX1, (ui->widget13c), &CCustomPlot::updateX1Event);
        connect(ui->widget13b, &BCustomPlot::updateX2, (ui->widget13c), &CCustomPlot::updateX2Event);
        connect(ui->widget13b, &BCustomPlot::updateX3, (ui->widget13c), &CCustomPlot::updateX3Event);

        connect(ui->widget13c, &CCustomPlot::updateX1s, (ui->widget13s), &SCustomPlot::updateX1Event);
        connect(ui->widget13c, &CCustomPlot::updateX2s, (ui->widget13s), &SCustomPlot::updateX2Event);
        connect(ui->widget13c, &CCustomPlot::SetShortLineVis, (ui->widget13a), &A2CustomPlot::SetShortLineVisEvent);
        connect(ui->widget13c, &CCustomPlot::updateX1b, (ui->widget13b), &BCustomPlot::updateX1Event);
        connect(ui->widget13c, &CCustomPlot::updateX2b, (ui->widget13b), &BCustomPlot::updateX2Event);
        connect(ui->widget13c, &CCustomPlot::updateX3, (ui->widget13b), &BCustomPlot::updateX3Event);
    }
    else if(curWidget==ui->page14)
    {
        connect(ui->widget14a, &ACustomPlot::updateY1, (ui->widget14s), &SCustomPlot::updateY1Event);
        connect(ui->widget14a, &ACustomPlot::updateY2, (ui->widget14s), &SCustomPlot::updateY2Event);
        connect(ui->widget14a, &ACustomPlot::SetDashLineVis, (ui->widget14s), &SCustomPlot::SetDashLineVisEvent);
        connect(ui->widget14a, &ACustomPlot::updateDash, (ui->widget14s), &SCustomPlot::updateDashEvent);
        connect(ui->widget14a, &ACustomPlot::updateDashY, (ui->widget14s), &SCustomPlot::updateDashYEvent);
        connect(ui->widget14a, &ACustomPlot::changeDashSize, (ui->widget14s), &SCustomPlot::changeDashSizeEvent);

        connect(ui->widget14s, &SCustomPlot::updateY1, (ui->widget14a), &ACustomPlot::updateY1Event);
        connect(ui->widget14s, &SCustomPlot::updateY2, (ui->widget14a), &ACustomPlot::updateY2Event);
        connect(ui->widget14s, &SCustomPlot::SetShortLineVis, (ui->widget14a), &ACustomPlot::SetShortLineVisEvent);
        connect(ui->widget14s, &SCustomPlot::updateY1c, (ui->widget14c), &CCustomPlot::updateY1Event);
        connect(ui->widget14s, &SCustomPlot::updateY2c, (ui->widget14c), &CCustomPlot::updateY2Event);

        connect(ui->widget14c, &CCustomPlot::updateX1s, (ui->widget14s), &SCustomPlot::updateX1Event);
        connect(ui->widget14c, &CCustomPlot::updateX2s, (ui->widget14s), &SCustomPlot::updateX2Event);
        connect(ui->widget14c, &CCustomPlot::SetShortLineVis, (ui->widget14a), &ACustomPlot::SetShortLineVisEvent);
    }
    else if(curWidget==ui->page15)//sa2c
    {
        connect(ui->widget15s, &SCustomPlot::updateY1, (ui->widget15c), &CCustomPlot::updateY1Event);
        connect(ui->widget15s, &SCustomPlot::updateY2, (ui->widget15c), &CCustomPlot::updateY2Event);
        connect(ui->widget15s, &SCustomPlot::updateY1, (ui->widget15a), &A2CustomPlot::updateX1Event);
        connect(ui->widget15s, &SCustomPlot::updateY2, (ui->widget15a), &A2CustomPlot::updateX2Event);
        connect(ui->widget15s, &SCustomPlot::SetShortLineVis, (ui->widget15a), &A2CustomPlot::SetShortLineVisEvent);

        connect(ui->widget15a, &A2CustomPlot::updateY1, (ui->widget15s), &SCustomPlot::updateY1Event);
        connect(ui->widget15a, &A2CustomPlot::updateY2, (ui->widget15s), &SCustomPlot::updateY2Event);
        connect(ui->widget15a, &A2CustomPlot::SetDashLineVis, (ui->widget15s), &SCustomPlot::SetDashLineVisEvent);
        connect(ui->widget15a, &A2CustomPlot::updateDash, (ui->widget15s), &SCustomPlot::updateDashEvent);
        connect(ui->widget15a, &A2CustomPlot::updateDashY, (ui->widget15s), &SCustomPlot::updateDashYEvent);
        connect(ui->widget15a, &A2CustomPlot::changeDashSize, (ui->widget15s), &SCustomPlot::changeDashSizeEvent);

        connect(ui->widget15c, &CCustomPlot::updateX1s, (ui->widget15s), &SCustomPlot::updateX1Event);
        connect(ui->widget15c, &CCustomPlot::updateX2s, (ui->widget15s), &SCustomPlot::updateX2Event);
        connect(ui->widget15c, &CCustomPlot::SetShortLineVis, (ui->widget15a), &A2CustomPlot::SetShortLineVisEvent);
    }
    else if(curWidget==ui->page16)
    {
        connect(ui->widget16a, &ACustomPlot::updateY1, (ui->widget16s), &SCustomPlot::updateY1Event);
        connect(ui->widget16a, &ACustomPlot::updateY2, (ui->widget16s), &SCustomPlot::updateY2Event);
        connect(ui->widget16a, &ACustomPlot::SetDashLineVis, (ui->widget16s), &SCustomPlot::SetDashLineVisEvent);
        connect(ui->widget16a, &ACustomPlot::updateDash, (ui->widget16s), &SCustomPlot::updateDashEvent);
        connect(ui->widget16a, &ACustomPlot::updateDashY, (ui->widget16s), &SCustomPlot::updateDashYEvent);
        connect(ui->widget16a, &ACustomPlot::changeDashSize, (ui->widget16s), &SCustomPlot::changeDashSizeEvent);

        connect(ui->widget16s, &SCustomPlot::updateY1, (ui->widget16a), &ACustomPlot::updateY1Event);
        connect(ui->widget16s, &SCustomPlot::updateY2, (ui->widget16a), &ACustomPlot::updateY2Event);
        connect(ui->widget16s, &SCustomPlot::SetShortLineVis, (ui->widget16a), &ACustomPlot::SetShortLineVisEvent);
        connect(ui->widget16s, &SCustomPlot::updateY1c, (ui->widget16c), &CCustomPlot::updateY1Event);
        connect(ui->widget16s, &SCustomPlot::updateY2c, (ui->widget16c), &CCustomPlot::updateY2Event);

        connect(ui->widget16c, &CCustomPlot::updateX1s, (ui->widget16s), &SCustomPlot::updateX1Event);
        connect(ui->widget16c, &CCustomPlot::updateX2s, (ui->widget16s), &SCustomPlot::updateX2Event);
        connect(ui->widget16c, &CCustomPlot::SetShortLineVis, (ui->widget16a), &ACustomPlot::SetShortLineVisEvent);
        connect(ui->widget16c, &CCustomPlot::updateX1b, (ui->widget16topc), &TopcCustomPlot::updateX1Event);
        connect(ui->widget16c, &CCustomPlot::updateX2b, (ui->widget16topc), &TopcCustomPlot::updateX2Event);
        connect(ui->widget16c, &CCustomPlot::updateX3, (ui->widget16topc), &TopcCustomPlot::updateX3Event);

        connect(ui->widget16topc, &TopcCustomPlot::updateX1, (ui->widget16c), &CCustomPlot::updateX1Event);
        connect(ui->widget16topc, &TopcCustomPlot::updateX2, (ui->widget16c), &CCustomPlot::updateX2Event);
        connect(ui->widget16topc, &TopcCustomPlot::updateX3, (ui->widget16c), &CCustomPlot::updateX3Event);
        connect(ui->widget16topc, &TopcCustomPlot::SetShortLineVis, (ui->widget16a), &ACustomPlot::SetShortLineVisEvent);
    }
    else if(curWidget==ui->page17)//sa2c
    {
        connect(ui->widget17s, &SCustomPlot::updateY1c, (ui->widget17c1), &CCustomPlot::updateY1Event);
        connect(ui->widget17s, &SCustomPlot::updateY2c, (ui->widget17c1), &CCustomPlot::updateY2Event);
        connect(ui->widget17s, &SCustomPlot::updateY1c, (ui->widget17c2), &CCustomPlot::updateY1Event);
        connect(ui->widget17s, &SCustomPlot::updateY2c, (ui->widget17c2), &CCustomPlot::updateY2Event);
        connect(ui->widget17s, &SCustomPlot::updateY1c, (ui->widget17c3), &CCustomPlot::updateY1Event);
        connect(ui->widget17s, &SCustomPlot::updateY2c, (ui->widget17c3), &CCustomPlot::updateY2Event);
        connect(ui->widget17s, &SCustomPlot::updateY1, (ui->widget17a), &A2CustomPlot::updateX1Event);
        connect(ui->widget17s, &SCustomPlot::updateY2, (ui->widget17a), &A2CustomPlot::updateX2Event);
        connect(ui->widget17s, &SCustomPlot::SetShortLineVis, (ui->widget17a), &A2CustomPlot::SetShortLineVisEvent);

        connect(ui->widget17a, &A2CustomPlot::updateY1, (ui->widget17s), &SCustomPlot::updateY1Event);
        connect(ui->widget17a, &A2CustomPlot::updateY2, (ui->widget17s), &SCustomPlot::updateY2Event);
        connect(ui->widget17a, &A2CustomPlot::SetDashLineVis, (ui->widget17s), &SCustomPlot::SetDashLineVisEvent);
        connect(ui->widget17a, &A2CustomPlot::updateDash, (ui->widget17s), &SCustomPlot::updateDashEvent);
        connect(ui->widget17a, &A2CustomPlot::updateDashY, (ui->widget17s), &SCustomPlot::updateDashYEvent);
        connect(ui->widget17a, &A2CustomPlot::changeDashSize, (ui->widget17s), &SCustomPlot::changeDashSizeEvent);

        connect(ui->widget17c1, &CCustomPlot::updateX1s, (ui->widget17s), &SCustomPlot::updateX1Event);
        connect(ui->widget17c1, &CCustomPlot::updateX2s, (ui->widget17s), &SCustomPlot::updateX2Event);
        connect(ui->widget17c1, &CCustomPlot::SetShortLineVis, (ui->widget17a), &A2CustomPlot::SetShortLineVisEvent);
        connect(ui->widget17c1, &CCustomPlot::updateX1b, (ui->widget17c2), &CCustomPlot::updateX1Event);
        connect(ui->widget17c1, &CCustomPlot::updateX2b, (ui->widget17c2), &CCustomPlot::updateX2Event);
        connect(ui->widget17c1, &CCustomPlot::updateX3, (ui->widget17c2), &CCustomPlot::updateX3Event);
        connect(ui->widget17c1, &CCustomPlot::updateX1b, (ui->widget17c3), &CCustomPlot::updateX1Event);
        connect(ui->widget17c1, &CCustomPlot::updateX2b, (ui->widget17c3), &CCustomPlot::updateX2Event);
        connect(ui->widget17c1, &CCustomPlot::updateX3, (ui->widget17c3), &CCustomPlot::updateX3Event);

        connect(ui->widget17c2, &CCustomPlot::updateX1s, (ui->widget17s), &SCustomPlot::updateX1Event);
        connect(ui->widget17c2, &CCustomPlot::updateX2s, (ui->widget17s), &SCustomPlot::updateX2Event);
        connect(ui->widget17c2, &CCustomPlot::SetShortLineVis, (ui->widget17a), &A2CustomPlot::SetShortLineVisEvent);
        connect(ui->widget17c2, &CCustomPlot::updateX1b, (ui->widget17c1), &CCustomPlot::updateX1Event);
        connect(ui->widget17c2, &CCustomPlot::updateX2b, (ui->widget17c1), &CCustomPlot::updateX2Event);
        connect(ui->widget17c2, &CCustomPlot::updateX3, (ui->widget17c1), &CCustomPlot::updateX3Event);
        connect(ui->widget17c2, &CCustomPlot::updateX1b, (ui->widget17c3), &CCustomPlot::updateX1Event);
        connect(ui->widget17c2, &CCustomPlot::updateX2b, (ui->widget17c3), &CCustomPlot::updateX2Event);
        connect(ui->widget17c2, &CCustomPlot::updateX3, (ui->widget17c3), &CCustomPlot::updateX3Event);

        connect(ui->widget17c3, &CCustomPlot::updateX1s, (ui->widget17s), &SCustomPlot::updateX1Event);
        connect(ui->widget17c3, &CCustomPlot::updateX2s, (ui->widget17s), &SCustomPlot::updateX2Event);
        connect(ui->widget17c3, &CCustomPlot::SetShortLineVis, (ui->widget17a), &A2CustomPlot::SetShortLineVisEvent);
        connect(ui->widget17c3, &CCustomPlot::updateX1b, (ui->widget17c1), &CCustomPlot::updateX1Event);
        connect(ui->widget17c3, &CCustomPlot::updateX2b, (ui->widget17c1), &CCustomPlot::updateX2Event);
        connect(ui->widget17c3, &CCustomPlot::updateX3, (ui->widget17c1), &CCustomPlot::updateX3Event);
        connect(ui->widget17c3, &CCustomPlot::updateX1b, (ui->widget17c2), &CCustomPlot::updateX1Event);
        connect(ui->widget17c3, &CCustomPlot::updateX2b, (ui->widget17c2), &CCustomPlot::updateX2Event);
        connect(ui->widget17c3, &CCustomPlot::updateX3, (ui->widget17c2), &CCustomPlot::updateX3Event);
    }
    else if(curWidget==ui->page18)
    {
        connect(ui->widget18a, &ACustomPlot::updateY1, (ui->widget18s), &SCustomPlot::updateY1Event);
        connect(ui->widget18a, &ACustomPlot::updateY2, (ui->widget18s), &SCustomPlot::updateY2Event);
        connect(ui->widget18a, &ACustomPlot::SetDashLineVis, (ui->widget18s), &SCustomPlot::SetDashLineVisEvent);
        connect(ui->widget18a, &ACustomPlot::updateDash, (ui->widget18s), &SCustomPlot::updateDashEvent);
        connect(ui->widget18a, &ACustomPlot::updateDashY, (ui->widget18s), &SCustomPlot::updateDashYEvent);
        connect(ui->widget18a, &ACustomPlot::changeDashSize, (ui->widget18s), &SCustomPlot::changeDashSizeEvent);
        connect(ui->widget18a, &ACustomPlot::updateY1, (ui->widget18b), &BCustomPlot::updateY1Event);
        connect(ui->widget18a, &ACustomPlot::updateY2, (ui->widget18b), &BCustomPlot::updateY2Event);

        connect(ui->widget18s, &SCustomPlot::updateY1, (ui->widget18a), &ACustomPlot::updateY1Event);
        connect(ui->widget18s, &SCustomPlot::updateY2, (ui->widget18a), &ACustomPlot::updateY2Event);
        connect(ui->widget18s, &SCustomPlot::SetShortLineVis, (ui->widget18a), &ACustomPlot::SetShortLineVisEvent);
        connect(ui->widget18s, &SCustomPlot::updateY1c, (ui->widget18c), &CCustomPlot::updateY1Event);
        connect(ui->widget18s, &SCustomPlot::updateY2c, (ui->widget18c), &CCustomPlot::updateY2Event);
        connect(ui->widget18s, &SCustomPlot::updateY1, (ui->widget18b), &BCustomPlot::updateY1Event);
        connect(ui->widget18s, &SCustomPlot::updateY2, (ui->widget18b), &BCustomPlot::updateY2Event);

        connect(ui->widget18c, &CCustomPlot::updateX1s, (ui->widget18s), &SCustomPlot::updateX1Event);
        connect(ui->widget18c, &CCustomPlot::updateX2s, (ui->widget18s), &SCustomPlot::updateX2Event);
        connect(ui->widget18c, &CCustomPlot::SetShortLineVis, (ui->widget18a), &ACustomPlot::SetShortLineVisEvent);
        connect(ui->widget18c, &CCustomPlot::updateX1b, (ui->widget18b), &BCustomPlot::updateX1Event);
        connect(ui->widget18c, &CCustomPlot::updateX2b, (ui->widget18b), &BCustomPlot::updateX2Event);
        connect(ui->widget18c, &CCustomPlot::updateX3, (ui->widget18b), &BCustomPlot::updateX3Event);

        connect(ui->widget18b, &BCustomPlot::updateY1, (ui->widget18s), &SCustomPlot::updateY1Event);
        connect(ui->widget18b, &BCustomPlot::updateY2, (ui->widget18s), &SCustomPlot::updateY2Event);
        connect(ui->widget18b, &BCustomPlot::updateY1, (ui->widget18a), &ACustomPlot::updateY1Event);
        connect(ui->widget18b, &BCustomPlot::updateY2, (ui->widget18a), &ACustomPlot::updateY2Event);
        connect(ui->widget18b, &BCustomPlot::SetShortLineVis, (ui->widget18a), &ACustomPlot::SetShortLineVisEvent);
        connect(ui->widget18b, &BCustomPlot::updateX1, (ui->widget18c), &CCustomPlot::updateX1Event);
        connect(ui->widget18b, &BCustomPlot::updateX2, (ui->widget18c), &CCustomPlot::updateX2Event);
        connect(ui->widget18b, &BCustomPlot::updateX3, (ui->widget18c), &CCustomPlot::updateX3Event);
    }
    else if(curWidget==ui->page19)
    {
        connect(ui->widget19a, &ACustomPlot::updateY1, (ui->widget19s), &SCustomPlot::updateY1Event);
        connect(ui->widget19a, &ACustomPlot::updateY2, (ui->widget19s), &SCustomPlot::updateY2Event);
        connect(ui->widget19a, &ACustomPlot::SetDashLineVis, (ui->widget19s), &SCustomPlot::SetDashLineVisEvent);
        connect(ui->widget19a, &ACustomPlot::updateDash, (ui->widget19s), &SCustomPlot::updateDashEvent);
        connect(ui->widget19a, &ACustomPlot::updateDashY, (ui->widget19s), &SCustomPlot::updateDashYEvent);
        connect(ui->widget19a, &ACustomPlot::changeDashSize, (ui->widget19s), &SCustomPlot::changeDashSizeEvent);

        connect(ui->widget19s, &SCustomPlot::updateY1, (ui->widget19a), &ACustomPlot::updateY1Event);
        connect(ui->widget19s, &SCustomPlot::updateY2, (ui->widget19a), &ACustomPlot::updateY2Event);
        connect(ui->widget19s, &SCustomPlot::SetShortLineVis, (ui->widget19a), &ACustomPlot::SetShortLineVisEvent);
        connect(ui->widget19s, &SCustomPlot::updateY1c, (ui->widget19c), &CCustomPlot::updateY1Event);
        connect(ui->widget19s, &SCustomPlot::updateY2c, (ui->widget19c), &CCustomPlot::updateY2Event);

        connect(ui->widget19c, &CCustomPlot::updateX1s, (ui->widget19s), &SCustomPlot::updateX1Event);
        connect(ui->widget19c, &CCustomPlot::updateX2s, (ui->widget19s), &SCustomPlot::updateX2Event);
        connect(ui->widget19c, &CCustomPlot::SetShortLineVis, (ui->widget19a), &ACustomPlot::SetShortLineVisEvent);
    }

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

    if(m_type==2)//a2b
    {
        connect(ui->widget2a, &A2CustomPlot::updateY1, (ui->widget2b), &BCustomPlot::updateY1Event);
        connect(ui->widget2a, &A2CustomPlot::updateY2, (ui->widget2b), &BCustomPlot::updateY2Event);
        connect(ui->widget2b, &BCustomPlot::updateY1, (ui->widget2a), &A2CustomPlot::updateX1Event);
        connect(ui->widget2b, &BCustomPlot::updateY2, (ui->widget2a), &A2CustomPlot::updateX2Event);

    }
    else if(m_type==3)
    {
        connect(ui->widget3a, &ACustomPlot::updateY1, (ui->widget3b), &BCustomPlot::updateY1Event);
        connect(ui->widget3a, &ACustomPlot::updateY2, (ui->widget3b), &BCustomPlot::updateY2Event);
        connect(ui->widget3b, &BCustomPlot::updateY1, (ui->widget3a), &ACustomPlot::updateY1Event);
        connect(ui->widget3b, &BCustomPlot::updateY2, (ui->widget3a), &ACustomPlot::updateY2Event);
    }
    else if(m_type==5)//sa2
    {
        connect(ui->widget5a, &A2CustomPlot::updateY1, (ui->widget5s), &SCustomPlot::updateY1Event);
        connect(ui->widget5a, &A2CustomPlot::updateY2, (ui->widget5s), &SCustomPlot::updateY2Event);
        connect(ui->widget5a, &A2CustomPlot::SetDashLineVis, (ui->widget5s), &SCustomPlot::SetDashLineVisEvent);
        connect(ui->widget5a, &A2CustomPlot::updateDash, (ui->widget5s), &SCustomPlot::updateDashEvent);
        connect(ui->widget5a, &A2CustomPlot::updateDashY, (ui->widget5s), &SCustomPlot::updateDashYEvent);
        connect(ui->widget5a, &A2CustomPlot::changeDashSize, (ui->widget5s), &SCustomPlot::changeDashSizeEvent);

        connect(ui->widget5s, &SCustomPlot::updateY1, (ui->widget5a), &A2CustomPlot::updateX1Event);
        connect(ui->widget5s, &SCustomPlot::updateY2, (ui->widget5a), &A2CustomPlot::updateX2Event);
        connect(ui->widget5s, &SCustomPlot::SetShortLineVis, (ui->widget5a), &A2CustomPlot::SetShortLineVisEvent);

    }
    else if(m_type==6)
    {
        connect(ui->widget6a, &ACustomPlot::updateY1, (ui->widget6s), &SCustomPlot::updateY1Event);
        connect(ui->widget6a, &ACustomPlot::updateY2, (ui->widget6s), &SCustomPlot::updateY2Event);
        connect(ui->widget6a, &ACustomPlot::SetDashLineVis, (ui->widget6s), &SCustomPlot::SetDashLineVisEvent);
        connect(ui->widget6a, &ACustomPlot::updateDash, (ui->widget6s), &SCustomPlot::updateDashEvent);
        connect(ui->widget6a, &ACustomPlot::updateDashY, (ui->widget6s), &SCustomPlot::updateDashYEvent);
        connect(ui->widget6a, &ACustomPlot::changeDashSize, (ui->widget6s), &SCustomPlot::changeDashSizeEvent);
        connect(ui->widget6s, &SCustomPlot::updateY1, (ui->widget6a), &ACustomPlot::updateY1Event);
        connect(ui->widget6s, &SCustomPlot::updateY2, (ui->widget6a), &ACustomPlot::updateY2Event);
        connect(ui->widget6s, &SCustomPlot::SetShortLineVis, (ui->widget6a), &ACustomPlot::SetShortLineVisEvent);
    }
    else if(m_type==7)
    {
        connect(ui->widget7a, &ACustomPlot::updateY1, (ui->widget7s), &SCustomPlot::updateY1Event);
        connect(ui->widget7a, &ACustomPlot::updateY2, (ui->widget7s), &SCustomPlot::updateY2Event);
        connect(ui->widget7a, &ACustomPlot::SetDashLineVis, (ui->widget7s), &SCustomPlot::SetDashLineVisEvent);
        connect(ui->widget7a, &ACustomPlot::updateDash, (ui->widget7s), &SCustomPlot::updateDashEvent);
        connect(ui->widget7a, &ACustomPlot::updateDashY, (ui->widget7s), &SCustomPlot::updateDashYEvent);
        connect(ui->widget7a, &ACustomPlot::changeDashSize, (ui->widget7s), &SCustomPlot::changeDashSizeEvent);
        connect(ui->widget7a, &ACustomPlot::updateY1, (ui->widget7b), &BCustomPlot::updateY1Event);
        connect(ui->widget7a, &ACustomPlot::updateY2, (ui->widget7b), &BCustomPlot::updateY2Event);

        connect(ui->widget7s, &SCustomPlot::updateY1, (ui->widget7a), &ACustomPlot::updateY1Event);
        connect(ui->widget7s, &SCustomPlot::updateY2, (ui->widget7a), &ACustomPlot::updateY2Event);
        connect(ui->widget7s, &SCustomPlot::SetShortLineVis, (ui->widget7a), &ACustomPlot::SetShortLineVisEvent);
        connect(ui->widget7s, &SCustomPlot::updateY1, (ui->widget7b), &BCustomPlot::updateY1Event);
        connect(ui->widget7s, &SCustomPlot::updateY2, (ui->widget7b), &BCustomPlot::updateY2Event);

        connect(ui->widget7b, &BCustomPlot::updateY1, (ui->widget7s), &SCustomPlot::updateY1Event);
        connect(ui->widget7b, &BCustomPlot::updateY2, (ui->widget7s), &SCustomPlot::updateY2Event);
        connect(ui->widget7b, &BCustomPlot::updateY1, (ui->widget7a), &ACustomPlot::updateY1Event);
        connect(ui->widget7b, &BCustomPlot::updateY2, (ui->widget7a), &ACustomPlot::updateY2Event);
        connect(ui->widget7b, &BCustomPlot::SetShortLineVis, (ui->widget7a), &ACustomPlot::SetShortLineVisEvent);
    }
    else if(m_type==8)//sa2c
    {
        connect(ui->widget8s, &SCustomPlot::updateY1c, (ui->widget8c), &CCustomPlot::updateY1Event);
        connect(ui->widget8s, &SCustomPlot::updateY2c, (ui->widget8c), &CCustomPlot::updateY2Event);
        connect(ui->widget8s, &SCustomPlot::updateY1, (ui->widget8a), &A2CustomPlot::updateX1Event);
        connect(ui->widget8s, &SCustomPlot::updateY2, (ui->widget8a), &A2CustomPlot::updateX2Event);
        connect(ui->widget8s, &SCustomPlot::SetShortLineVis, (ui->widget8a), &A2CustomPlot::SetShortLineVisEvent);

        connect(ui->widget8a, &A2CustomPlot::updateY1, (ui->widget8s), &SCustomPlot::updateY1Event);
        connect(ui->widget8a, &A2CustomPlot::updateY2, (ui->widget8s), &SCustomPlot::updateY2Event);
        connect(ui->widget8a, &A2CustomPlot::SetDashLineVis, (ui->widget8s), &SCustomPlot::SetDashLineVisEvent);
        connect(ui->widget8a, &A2CustomPlot::updateDash, (ui->widget8s), &SCustomPlot::updateDashEvent);
        connect(ui->widget8a, &A2CustomPlot::updateDashY, (ui->widget8s), &SCustomPlot::updateDashYEvent);
        connect(ui->widget8a, &A2CustomPlot::changeDashSize, (ui->widget8s), &SCustomPlot::changeDashSizeEvent);

        connect(ui->widget8c, &CCustomPlot::updateX1s, (ui->widget8s), &SCustomPlot::updateX1Event);
        connect(ui->widget8c, &CCustomPlot::updateX2s, (ui->widget8s), &SCustomPlot::updateX2Event);
        connect(ui->widget8c, &CCustomPlot::SetShortLineVis, (ui->widget8a), &A2CustomPlot::SetShortLineVisEvent);
    }
    else if(m_type==9)
    {
        //a--s/b
        connect(ui->widget9a, &ACustomPlot::updateY1, (ui->widget9s), &SCustomPlot::updateY1Event);
        connect(ui->widget9a, &ACustomPlot::updateY2, (ui->widget9s), &SCustomPlot::updateY2Event);
        connect(ui->widget9a, &ACustomPlot::SetDashLineVis, (ui->widget9s), &SCustomPlot::SetDashLineVisEvent);
        connect(ui->widget9a, &ACustomPlot::updateDash, (ui->widget9s), &SCustomPlot::updateDashEvent);
        connect(ui->widget9a, &ACustomPlot::updateDashY, (ui->widget9s), &SCustomPlot::updateDashYEvent);
        connect(ui->widget9a, &ACustomPlot::changeDashSize, (ui->widget9s), &SCustomPlot::changeDashSizeEvent);
        connect(ui->widget9a, &ACustomPlot::updateY1, (ui->widget9b), &BCustomPlot::updateY1Event);
        connect(ui->widget9a, &ACustomPlot::updateY2, (ui->widget9b), &BCustomPlot::updateY2Event);

        connect(ui->widget9s, &SCustomPlot::updateY1, (ui->widget9a), &ACustomPlot::updateY1Event);
        connect(ui->widget9s, &SCustomPlot::updateY2, (ui->widget9a), &ACustomPlot::updateY2Event);
        connect(ui->widget9s, &SCustomPlot::SetShortLineVis, (ui->widget9a), &ACustomPlot::SetShortLineVisEvent);
        connect(ui->widget9s, &SCustomPlot::updateY1, (ui->widget9b), &BCustomPlot::updateY1Event);
        connect(ui->widget9s, &SCustomPlot::updateY2, (ui->widget9b), &BCustomPlot::updateY2Event);

        connect(ui->widget9b, &BCustomPlot::updateY1, (ui->widget9s), &SCustomPlot::updateY1Event);
        connect(ui->widget9b, &BCustomPlot::updateY2, (ui->widget9s), &SCustomPlot::updateY2Event);
        connect(ui->widget9b, &BCustomPlot::updateY1, (ui->widget9a), &ACustomPlot::updateY1Event);
        connect(ui->widget9b, &BCustomPlot::updateY2, (ui->widget9a), &ACustomPlot::updateY2Event);
        connect(ui->widget9b, &BCustomPlot::SetShortLineVis, (ui->widget9a), &ACustomPlot::SetShortLineVisEvent);
    }
    else if(m_type==10)//sa2b
    {

        connect(ui->widget10s, &SCustomPlot::updateY1, (ui->widget10a), &A2CustomPlot::updateX1Event);
        connect(ui->widget10s, &SCustomPlot::updateY2, (ui->widget10a), &A2CustomPlot::updateX2Event);
        connect(ui->widget10s, &SCustomPlot::SetShortLineVis, (ui->widget10a), &A2CustomPlot::SetShortLineVisEvent);
        connect(ui->widget10s, &SCustomPlot::updateY1, (ui->widget10b), &BCustomPlot::updateY1Event);
        connect(ui->widget10s, &SCustomPlot::updateY2, (ui->widget10b), &BCustomPlot::updateY2Event);

        connect(ui->widget10a, &A2CustomPlot::updateY1, (ui->widget10s), &SCustomPlot::updateY1Event);
        connect(ui->widget10a, &A2CustomPlot::updateY2, (ui->widget10s), &SCustomPlot::updateY2Event);
        connect(ui->widget10a, &A2CustomPlot::SetDashLineVis, (ui->widget10s), &SCustomPlot::SetDashLineVisEvent);
        connect(ui->widget10a, &A2CustomPlot::updateDash, (ui->widget10s), &SCustomPlot::updateDashEvent);
        connect(ui->widget10a, &A2CustomPlot::updateDashY, (ui->widget10s), &SCustomPlot::updateDashYEvent);
        connect(ui->widget10a, &A2CustomPlot::changeDashSize, (ui->widget10s), &SCustomPlot::changeDashSizeEvent);
        connect(ui->widget10a, &A2CustomPlot::updateY1, (ui->widget10b), &BCustomPlot::updateY1Event);
        connect(ui->widget10a, &A2CustomPlot::updateY2, (ui->widget10b), &BCustomPlot::updateY2Event);

        connect(ui->widget10b, &BCustomPlot::updateY1, (ui->widget10s), &SCustomPlot::updateY1Event);
        connect(ui->widget10b, &BCustomPlot::updateY2, (ui->widget10s), &SCustomPlot::updateY2Event);
        connect(ui->widget10b, &BCustomPlot::updateY1, (ui->widget10a), &A2CustomPlot::updateX1Event);
        connect(ui->widget10b, &BCustomPlot::updateY2, (ui->widget10a), &A2CustomPlot::updateX2Event);
        connect(ui->widget10b, &BCustomPlot::SetShortLineVis, (ui->widget10a), &A2CustomPlot::SetShortLineVisEvent);

    }
    else if(m_type==11)
    {
        connect(ui->widget11a, &ACustomPlot::updateY1, (ui->widget11s), &SCustomPlot::updateY1Event);
        connect(ui->widget11a, &ACustomPlot::updateY2, (ui->widget11s), &SCustomPlot::updateY2Event);
        connect(ui->widget11a, &ACustomPlot::SetDashLineVis, (ui->widget11s), &SCustomPlot::SetDashLineVisEvent);
        connect(ui->widget11a, &ACustomPlot::updateDash, (ui->widget11s), &SCustomPlot::updateDashEvent);
        connect(ui->widget11a, &ACustomPlot::updateDashY, (ui->widget11s), &SCustomPlot::updateDashYEvent);
        connect(ui->widget11a, &ACustomPlot::changeDashSize, (ui->widget11s), &SCustomPlot::changeDashSizeEvent);
        connect(ui->widget11a, &ACustomPlot::updateY1, (ui->widget11b), &BCustomPlot::updateY1Event);
        connect(ui->widget11a, &ACustomPlot::updateY2, (ui->widget11b), &BCustomPlot::updateY2Event);

        connect(ui->widget11s, &SCustomPlot::updateY1, (ui->widget11a), &ACustomPlot::updateY1Event);
        connect(ui->widget11s, &SCustomPlot::updateY2, (ui->widget11a), &ACustomPlot::updateY2Event);
        connect(ui->widget11s, &SCustomPlot::SetShortLineVis, (ui->widget11a), &ACustomPlot::SetShortLineVisEvent);
        connect(ui->widget11s, &SCustomPlot::updateY1, (ui->widget11b), &BCustomPlot::updateY1Event);
        connect(ui->widget11s, &SCustomPlot::updateY2, (ui->widget11b), &BCustomPlot::updateY2Event);
        connect(ui->widget11s, &SCustomPlot::updateY1c, (ui->widget11c), &CCustomPlot::updateY1Event);
        connect(ui->widget11s, &SCustomPlot::updateY2c, (ui->widget11c), &CCustomPlot::updateY2Event);


        connect(ui->widget11b, &BCustomPlot::updateY1, (ui->widget11s), &SCustomPlot::updateY1Event);
        connect(ui->widget11b, &BCustomPlot::updateY2, (ui->widget11s), &SCustomPlot::updateY2Event);
        connect(ui->widget11b, &BCustomPlot::updateY1, (ui->widget11a), &ACustomPlot::updateY1Event);
        connect(ui->widget11b, &BCustomPlot::updateY2, (ui->widget11a), &ACustomPlot::updateY2Event);
        connect(ui->widget11b, &BCustomPlot::SetShortLineVis, (ui->widget11a), &ACustomPlot::SetShortLineVisEvent);
        connect(ui->widget11b, &BCustomPlot::updateX1, (ui->widget11c), &CCustomPlot::updateX1Event);
        connect(ui->widget11b, &BCustomPlot::updateX2, (ui->widget11c), &CCustomPlot::updateX2Event);
        connect(ui->widget11b, &BCustomPlot::updateX3, (ui->widget11c), &CCustomPlot::updateX3Event);

        connect(ui->widget11c, &CCustomPlot::updateX1s, (ui->widget11s), &SCustomPlot::updateX1Event);
        connect(ui->widget11c, &CCustomPlot::updateX2s, (ui->widget11s), &SCustomPlot::updateX2Event);
        connect(ui->widget11c, &CCustomPlot::updateX1b, (ui->widget11b), &BCustomPlot::updateX1Event);
        connect(ui->widget11c, &CCustomPlot::updateX2b, (ui->widget11b), &BCustomPlot::updateX2Event);
        connect(ui->widget11c, &CCustomPlot::updateX3, (ui->widget11b), &BCustomPlot::updateX3Event);
        connect(ui->widget11c, &CCustomPlot::SetShortLineVis, (ui->widget11a), &ACustomPlot::SetShortLineVisEvent);
    }
    else if(m_type==12)//sa2bc
    {
        connect(ui->widget12s, &SCustomPlot::updateY1, (ui->widget12a), &A2CustomPlot::updateX1Event);
        connect(ui->widget12s, &SCustomPlot::updateY2, (ui->widget12a), &A2CustomPlot::updateX2Event);
        connect(ui->widget12s, &SCustomPlot::SetShortLineVis, (ui->widget12a), &A2CustomPlot::SetShortLineVisEvent);
        connect(ui->widget12s, &SCustomPlot::updateY1, (ui->widget12b), &BCustomPlot::updateY1Event);
        connect(ui->widget12s, &SCustomPlot::updateY2, (ui->widget12b), &BCustomPlot::updateY2Event);
        connect(ui->widget12s, &SCustomPlot::updateY1c, (ui->widget12c), &CCustomPlot::updateY1Event);
        connect(ui->widget12s, &SCustomPlot::updateY2c, (ui->widget12c), &CCustomPlot::updateY2Event);

        connect(ui->widget12a, &A2CustomPlot::updateY1, (ui->widget12s), &SCustomPlot::updateY1Event);
        connect(ui->widget12a, &A2CustomPlot::updateY2, (ui->widget12s), &SCustomPlot::updateY2Event);
        connect(ui->widget12a, &A2CustomPlot::SetDashLineVis, (ui->widget12s), &SCustomPlot::SetDashLineVisEvent);
        connect(ui->widget12a, &A2CustomPlot::updateDash, (ui->widget12s), &SCustomPlot::updateDashEvent);
        connect(ui->widget12a, &A2CustomPlot::updateDashY, (ui->widget12s), &SCustomPlot::updateDashYEvent);
        connect(ui->widget12a, &A2CustomPlot::changeDashSize, (ui->widget12s), &SCustomPlot::changeDashSizeEvent);
        connect(ui->widget12a, &A2CustomPlot::updateY1, (ui->widget12b), &BCustomPlot::updateY1Event);
        connect(ui->widget12a, &A2CustomPlot::updateY2, (ui->widget12b), &BCustomPlot::updateY2Event);

        connect(ui->widget12b, &BCustomPlot::updateY1, (ui->widget12s), &SCustomPlot::updateY1Event);
        connect(ui->widget12b, &BCustomPlot::updateY2, (ui->widget12s), &SCustomPlot::updateY2Event);
        connect(ui->widget12b, &BCustomPlot::updateY1, (ui->widget12a), &A2CustomPlot::updateX1Event);
        connect(ui->widget12b, &BCustomPlot::updateY2, (ui->widget12a), &A2CustomPlot::updateX2Event);
        connect(ui->widget12b, &BCustomPlot::SetShortLineVis, (ui->widget12a), &A2CustomPlot::SetShortLineVisEvent);
        connect(ui->widget12b, &BCustomPlot::updateX1, (ui->widget12c), &CCustomPlot::updateX1Event);
        connect(ui->widget12b, &BCustomPlot::updateX2, (ui->widget12c), &CCustomPlot::updateX2Event);
        connect(ui->widget12b, &BCustomPlot::updateX3, (ui->widget12c), &CCustomPlot::updateX3Event);

        connect(ui->widget12c, &CCustomPlot::updateX1s, (ui->widget12s), &SCustomPlot::updateX1Event);
        connect(ui->widget12c, &CCustomPlot::updateX2s, (ui->widget12s), &SCustomPlot::updateX2Event);
        connect(ui->widget12c, &CCustomPlot::SetShortLineVis, (ui->widget12a), &A2CustomPlot::SetShortLineVisEvent);
        connect(ui->widget12c, &CCustomPlot::updateX1b, (ui->widget12b), &BCustomPlot::updateX1Event);
        connect(ui->widget12c, &CCustomPlot::updateX2b, (ui->widget12b), &BCustomPlot::updateX2Event);
        connect(ui->widget12c, &CCustomPlot::updateX3, (ui->widget12b), &BCustomPlot::updateX3Event);
    }
    else if(m_type==13)//sa2bc
    {
        connect(ui->widget13s, &SCustomPlot::updateY1, (ui->widget13a), &A2CustomPlot::updateX1Event);
        connect(ui->widget13s, &SCustomPlot::updateY2, (ui->widget13a), &A2CustomPlot::updateX2Event);
        connect(ui->widget13s, &SCustomPlot::SetShortLineVis, (ui->widget13a), &A2CustomPlot::SetShortLineVisEvent);
        connect(ui->widget13s, &SCustomPlot::updateY1, (ui->widget13b), &BCustomPlot::updateY1Event);
        connect(ui->widget13s, &SCustomPlot::updateY2, (ui->widget13b), &BCustomPlot::updateY2Event);
        connect(ui->widget13s, &SCustomPlot::updateY1c, (ui->widget13c), &CCustomPlot::updateY1Event);
        connect(ui->widget13s, &SCustomPlot::updateY2c, (ui->widget13c), &CCustomPlot::updateY2Event);

        connect(ui->widget13a, &A2CustomPlot::updateY1, (ui->widget13s), &SCustomPlot::updateY1Event);
        connect(ui->widget13a, &A2CustomPlot::updateY2, (ui->widget13s), &SCustomPlot::updateY2Event);
        connect(ui->widget13a, &A2CustomPlot::SetDashLineVis, (ui->widget13s), &SCustomPlot::SetDashLineVisEvent);
        connect(ui->widget13a, &A2CustomPlot::updateDash, (ui->widget13s), &SCustomPlot::updateDashEvent);
        connect(ui->widget13a, &A2CustomPlot::updateDashY, (ui->widget13s), &SCustomPlot::updateDashYEvent);
        connect(ui->widget13a, &A2CustomPlot::changeDashSize, (ui->widget13s), &SCustomPlot::changeDashSizeEvent);
        connect(ui->widget13a, &A2CustomPlot::updateY1, (ui->widget13b), &BCustomPlot::updateY1Event);
        connect(ui->widget13a, &A2CustomPlot::updateY2, (ui->widget13b), &BCustomPlot::updateY2Event);

        connect(ui->widget13b, &BCustomPlot::updateY1, (ui->widget13s), &SCustomPlot::updateY1Event);
        connect(ui->widget13b, &BCustomPlot::updateY2, (ui->widget13s), &SCustomPlot::updateY2Event);
        connect(ui->widget13b, &BCustomPlot::updateY1, (ui->widget13a), &A2CustomPlot::updateX1Event);
        connect(ui->widget13b, &BCustomPlot::updateY2, (ui->widget13a), &A2CustomPlot::updateX2Event);
        connect(ui->widget13b, &BCustomPlot::SetShortLineVis, (ui->widget13a), &A2CustomPlot::SetShortLineVisEvent);
        connect(ui->widget13b, &BCustomPlot::updateX1, (ui->widget13c), &CCustomPlot::updateX1Event);
        connect(ui->widget13b, &BCustomPlot::updateX2, (ui->widget13c), &CCustomPlot::updateX2Event);
        connect(ui->widget13b, &BCustomPlot::updateX3, (ui->widget13c), &CCustomPlot::updateX3Event);

        connect(ui->widget13c, &CCustomPlot::updateX1s, (ui->widget13s), &SCustomPlot::updateX1Event);
        connect(ui->widget13c, &CCustomPlot::updateX2s, (ui->widget13s), &SCustomPlot::updateX2Event);
        connect(ui->widget13c, &CCustomPlot::SetShortLineVis, (ui->widget13a), &A2CustomPlot::SetShortLineVisEvent);
        connect(ui->widget13c, &CCustomPlot::updateX1b, (ui->widget13b), &BCustomPlot::updateX1Event);
        connect(ui->widget13c, &CCustomPlot::updateX2b, (ui->widget13b), &BCustomPlot::updateX2Event);
        connect(ui->widget13c, &CCustomPlot::updateX3, (ui->widget13b), &BCustomPlot::updateX3Event);
    }
    else if(m_type==14)
    {
        connect(ui->widget14a, &ACustomPlot::updateY1, (ui->widget14s), &SCustomPlot::updateY1Event);
        connect(ui->widget14a, &ACustomPlot::updateY2, (ui->widget14s), &SCustomPlot::updateY2Event);
        connect(ui->widget14a, &ACustomPlot::SetDashLineVis, (ui->widget14s), &SCustomPlot::SetDashLineVisEvent);
        connect(ui->widget14a, &ACustomPlot::updateDash, (ui->widget14s), &SCustomPlot::updateDashEvent);
        connect(ui->widget14a, &ACustomPlot::updateDashY, (ui->widget14s), &SCustomPlot::updateDashYEvent);
        connect(ui->widget14a, &ACustomPlot::changeDashSize, (ui->widget14s), &SCustomPlot::changeDashSizeEvent);

        connect(ui->widget14s, &SCustomPlot::updateY1, (ui->widget14a), &ACustomPlot::updateY1Event);
        connect(ui->widget14s, &SCustomPlot::updateY2, (ui->widget14a), &ACustomPlot::updateY2Event);
        connect(ui->widget14s, &SCustomPlot::SetShortLineVis, (ui->widget14a), &ACustomPlot::SetShortLineVisEvent);
        connect(ui->widget14s, &SCustomPlot::updateY1c, (ui->widget14c), &CCustomPlot::updateY1Event);
        connect(ui->widget14s, &SCustomPlot::updateY2c, (ui->widget14c), &CCustomPlot::updateY2Event);

        connect(ui->widget14c, &CCustomPlot::updateX1s, (ui->widget14s), &SCustomPlot::updateX1Event);
        connect(ui->widget14c, &CCustomPlot::updateX2s, (ui->widget14s), &SCustomPlot::updateX2Event);
        connect(ui->widget14c, &CCustomPlot::SetShortLineVis, (ui->widget14a), &ACustomPlot::SetShortLineVisEvent);
    }
    else if(m_type==15)//sa2c
    {
        connect(ui->widget15s, &SCustomPlot::updateY1, (ui->widget15c), &CCustomPlot::updateY1Event);
        connect(ui->widget15s, &SCustomPlot::updateY2, (ui->widget15c), &CCustomPlot::updateY2Event);
        connect(ui->widget15s, &SCustomPlot::updateY1, (ui->widget15a), &A2CustomPlot::updateX1Event);
        connect(ui->widget15s, &SCustomPlot::updateY2, (ui->widget15a), &A2CustomPlot::updateX2Event);
        connect(ui->widget15s, &SCustomPlot::SetShortLineVis, (ui->widget15a), &A2CustomPlot::SetShortLineVisEvent);

        connect(ui->widget15a, &A2CustomPlot::updateY1, (ui->widget15s), &SCustomPlot::updateY1Event);
        connect(ui->widget15a, &A2CustomPlot::updateY2, (ui->widget15s), &SCustomPlot::updateY2Event);
        connect(ui->widget15a, &A2CustomPlot::SetDashLineVis, (ui->widget15s), &SCustomPlot::SetDashLineVisEvent);
        connect(ui->widget15a, &A2CustomPlot::updateDash, (ui->widget15s), &SCustomPlot::updateDashEvent);
        connect(ui->widget15a, &A2CustomPlot::updateDashY, (ui->widget15s), &SCustomPlot::updateDashYEvent);
        connect(ui->widget15a, &A2CustomPlot::changeDashSize, (ui->widget15s), &SCustomPlot::changeDashSizeEvent);

        connect(ui->widget15c, &CCustomPlot::updateX1s, (ui->widget15s), &SCustomPlot::updateX1Event);
        connect(ui->widget15c, &CCustomPlot::updateX2s, (ui->widget15s), &SCustomPlot::updateX2Event);
        connect(ui->widget15c, &CCustomPlot::SetShortLineVis, (ui->widget15a), &A2CustomPlot::SetShortLineVisEvent);
    }
    else if(m_type==16)
    {
        connect(ui->widget16a, &ACustomPlot::updateY1, (ui->widget16s), &SCustomPlot::updateY1Event);
        connect(ui->widget16a, &ACustomPlot::updateY2, (ui->widget16s), &SCustomPlot::updateY2Event);
        connect(ui->widget16a, &ACustomPlot::SetDashLineVis, (ui->widget16s), &SCustomPlot::SetDashLineVisEvent);
        connect(ui->widget16a, &ACustomPlot::updateDash, (ui->widget16s), &SCustomPlot::updateDashEvent);
        connect(ui->widget16a, &ACustomPlot::updateDashY, (ui->widget16s), &SCustomPlot::updateDashYEvent);
        connect(ui->widget16a, &ACustomPlot::changeDashSize, (ui->widget16s), &SCustomPlot::changeDashSizeEvent);

        connect(ui->widget16s, &SCustomPlot::updateY1, (ui->widget16a), &ACustomPlot::updateY1Event);
        connect(ui->widget16s, &SCustomPlot::updateY2, (ui->widget16a), &ACustomPlot::updateY2Event);
        connect(ui->widget16s, &SCustomPlot::SetShortLineVis, (ui->widget16a), &ACustomPlot::SetShortLineVisEvent);
        connect(ui->widget16s, &SCustomPlot::updateY1c, (ui->widget16c), &CCustomPlot::updateY1Event);
        connect(ui->widget16s, &SCustomPlot::updateY2c, (ui->widget16c), &CCustomPlot::updateY2Event);

        connect(ui->widget16c, &CCustomPlot::updateX1s, (ui->widget16s), &SCustomPlot::updateX1Event);
        connect(ui->widget16c, &CCustomPlot::updateX2s, (ui->widget16s), &SCustomPlot::updateX2Event);
        connect(ui->widget16c, &CCustomPlot::SetShortLineVis, (ui->widget16a), &ACustomPlot::SetShortLineVisEvent);
        connect(ui->widget16c, &CCustomPlot::updateX1b, (ui->widget16topc), &TopcCustomPlot::updateX1Event);
        connect(ui->widget16c, &CCustomPlot::updateX2b, (ui->widget16topc), &TopcCustomPlot::updateX2Event);
        connect(ui->widget16c, &CCustomPlot::updateX3, (ui->widget16topc), &TopcCustomPlot::updateX3Event);

        connect(ui->widget16topc, &TopcCustomPlot::updateX1, (ui->widget16c), &CCustomPlot::updateX1Event);
        connect(ui->widget16topc, &TopcCustomPlot::updateX2, (ui->widget16c), &CCustomPlot::updateX2Event);
        connect(ui->widget16topc, &TopcCustomPlot::updateX3, (ui->widget16c), &CCustomPlot::updateX3Event);
        connect(ui->widget16topc, &TopcCustomPlot::SetShortLineVis, (ui->widget16a), &ACustomPlot::SetShortLineVisEvent);
    }
    else if(m_type==17)//sa2c
    {
        connect(ui->widget17s, &SCustomPlot::updateY1c, (ui->widget17c1), &CCustomPlot::updateY1Event);
        connect(ui->widget17s, &SCustomPlot::updateY2c, (ui->widget17c1), &CCustomPlot::updateY2Event);
        connect(ui->widget17s, &SCustomPlot::updateY1c, (ui->widget17c2), &CCustomPlot::updateY1Event);
        connect(ui->widget17s, &SCustomPlot::updateY2c, (ui->widget17c2), &CCustomPlot::updateY2Event);
        connect(ui->widget17s, &SCustomPlot::updateY1c, (ui->widget17c3), &CCustomPlot::updateY1Event);
        connect(ui->widget17s, &SCustomPlot::updateY2c, (ui->widget17c3), &CCustomPlot::updateY2Event);
        connect(ui->widget17s, &SCustomPlot::updateY1, (ui->widget17a), &A2CustomPlot::updateX1Event);
        connect(ui->widget17s, &SCustomPlot::updateY2, (ui->widget17a), &A2CustomPlot::updateX2Event);
        connect(ui->widget17s, &SCustomPlot::SetShortLineVis, (ui->widget17a), &A2CustomPlot::SetShortLineVisEvent);

        connect(ui->widget17a, &A2CustomPlot::updateY1, (ui->widget17s), &SCustomPlot::updateY1Event);
        connect(ui->widget17a, &A2CustomPlot::updateY2, (ui->widget17s), &SCustomPlot::updateY2Event);
        connect(ui->widget17a, &A2CustomPlot::SetDashLineVis, (ui->widget17s), &SCustomPlot::SetDashLineVisEvent);
        connect(ui->widget17a, &A2CustomPlot::updateDash, (ui->widget17s), &SCustomPlot::updateDashEvent);
        connect(ui->widget17a, &A2CustomPlot::updateDashY, (ui->widget17s), &SCustomPlot::updateDashYEvent);
        connect(ui->widget17a, &A2CustomPlot::changeDashSize, (ui->widget17s), &SCustomPlot::changeDashSizeEvent);

        connect(ui->widget17c1, &CCustomPlot::updateX1s, (ui->widget17s), &SCustomPlot::updateX1Event);
        connect(ui->widget17c1, &CCustomPlot::updateX2s, (ui->widget17s), &SCustomPlot::updateX2Event);
        connect(ui->widget17c1, &CCustomPlot::SetShortLineVis, (ui->widget17a), &A2CustomPlot::SetShortLineVisEvent);
        connect(ui->widget17c1, &CCustomPlot::updateX1b, (ui->widget17c2), &CCustomPlot::updateX1Event);
        connect(ui->widget17c1, &CCustomPlot::updateX2b, (ui->widget17c2), &CCustomPlot::updateX2Event);
        connect(ui->widget17c1, &CCustomPlot::updateX3, (ui->widget17c2), &CCustomPlot::updateX3Event);
        connect(ui->widget17c1, &CCustomPlot::updateX1b, (ui->widget17c3), &CCustomPlot::updateX1Event);
        connect(ui->widget17c1, &CCustomPlot::updateX2b, (ui->widget17c3), &CCustomPlot::updateX2Event);
        connect(ui->widget17c1, &CCustomPlot::updateX3, (ui->widget17c3), &CCustomPlot::updateX3Event);

        connect(ui->widget17c2, &CCustomPlot::updateX1s, (ui->widget17s), &SCustomPlot::updateX1Event);
        connect(ui->widget17c2, &CCustomPlot::updateX2s, (ui->widget17s), &SCustomPlot::updateX2Event);
        connect(ui->widget17c2, &CCustomPlot::SetShortLineVis, (ui->widget17a), &A2CustomPlot::SetShortLineVisEvent);
        connect(ui->widget17c2, &CCustomPlot::updateX1b, (ui->widget17c1), &CCustomPlot::updateX1Event);
        connect(ui->widget17c2, &CCustomPlot::updateX2b, (ui->widget17c1), &CCustomPlot::updateX2Event);
        connect(ui->widget17c2, &CCustomPlot::updateX3, (ui->widget17c1), &CCustomPlot::updateX3Event);
        connect(ui->widget17c2, &CCustomPlot::updateX1b, (ui->widget17c3), &CCustomPlot::updateX1Event);
        connect(ui->widget17c2, &CCustomPlot::updateX2b, (ui->widget17c3), &CCustomPlot::updateX2Event);
        connect(ui->widget17c2, &CCustomPlot::updateX3, (ui->widget17c3), &CCustomPlot::updateX3Event);

        connect(ui->widget17c3, &CCustomPlot::updateX1s, (ui->widget17s), &SCustomPlot::updateX1Event);
        connect(ui->widget17c3, &CCustomPlot::updateX2s, (ui->widget17s), &SCustomPlot::updateX2Event);
        connect(ui->widget17c3, &CCustomPlot::SetShortLineVis, (ui->widget17a), &A2CustomPlot::SetShortLineVisEvent);
        connect(ui->widget17c3, &CCustomPlot::updateX1b, (ui->widget17c1), &CCustomPlot::updateX1Event);
        connect(ui->widget17c3, &CCustomPlot::updateX2b, (ui->widget17c1), &CCustomPlot::updateX2Event);
        connect(ui->widget17c3, &CCustomPlot::updateX3, (ui->widget17c1), &CCustomPlot::updateX3Event);
        connect(ui->widget17c3, &CCustomPlot::updateX1b, (ui->widget17c2), &CCustomPlot::updateX1Event);
        connect(ui->widget17c3, &CCustomPlot::updateX2b, (ui->widget17c2), &CCustomPlot::updateX2Event);
        connect(ui->widget17c3, &CCustomPlot::updateX3, (ui->widget17c2), &CCustomPlot::updateX3Event);
    }
    else if(m_type==18)
    {
        connect(ui->widget18a, &ACustomPlot::updateY1, (ui->widget18s), &SCustomPlot::updateY1Event);
        connect(ui->widget18a, &ACustomPlot::updateY2, (ui->widget18s), &SCustomPlot::updateY2Event);
        connect(ui->widget18a, &ACustomPlot::SetDashLineVis, (ui->widget18s), &SCustomPlot::SetDashLineVisEvent);
        connect(ui->widget18a, &ACustomPlot::updateDash, (ui->widget18s), &SCustomPlot::updateDashEvent);
        connect(ui->widget18a, &ACustomPlot::updateDashY, (ui->widget18s), &SCustomPlot::updateDashYEvent);
        connect(ui->widget18a, &ACustomPlot::changeDashSize, (ui->widget18s), &SCustomPlot::changeDashSizeEvent);
        connect(ui->widget18a, &ACustomPlot::updateY1, (ui->widget18b), &BCustomPlot::updateY1Event);
        connect(ui->widget18a, &ACustomPlot::updateY2, (ui->widget18b), &BCustomPlot::updateY2Event);

        connect(ui->widget18s, &SCustomPlot::updateY1, (ui->widget18a), &ACustomPlot::updateY1Event);
        connect(ui->widget18s, &SCustomPlot::updateY2, (ui->widget18a), &ACustomPlot::updateY2Event);
        connect(ui->widget18s, &SCustomPlot::SetShortLineVis, (ui->widget18a), &ACustomPlot::SetShortLineVisEvent);
        connect(ui->widget18s, &SCustomPlot::updateY1c, (ui->widget18c), &CCustomPlot::updateY1Event);
        connect(ui->widget18s, &SCustomPlot::updateY2c, (ui->widget18c), &CCustomPlot::updateY2Event);
        connect(ui->widget18s, &SCustomPlot::updateY1, (ui->widget18b), &BCustomPlot::updateY1Event);
        connect(ui->widget18s, &SCustomPlot::updateY2, (ui->widget18b), &BCustomPlot::updateY2Event);

        connect(ui->widget18c, &CCustomPlot::updateX1s, (ui->widget18s), &SCustomPlot::updateX1Event);
        connect(ui->widget18c, &CCustomPlot::updateX2s, (ui->widget18s), &SCustomPlot::updateX2Event);
        connect(ui->widget18c, &CCustomPlot::SetShortLineVis, (ui->widget18a), &ACustomPlot::SetShortLineVisEvent);
        connect(ui->widget18c, &CCustomPlot::updateX1b, (ui->widget18b), &BCustomPlot::updateX1Event);
        connect(ui->widget18c, &CCustomPlot::updateX2b, (ui->widget18b), &BCustomPlot::updateX2Event);
        connect(ui->widget18c, &CCustomPlot::updateX3, (ui->widget18b), &BCustomPlot::updateX3Event);

        connect(ui->widget18b, &BCustomPlot::updateY1, (ui->widget18s), &SCustomPlot::updateY1Event);
        connect(ui->widget18b, &BCustomPlot::updateY2, (ui->widget18s), &SCustomPlot::updateY2Event);
        connect(ui->widget18b, &BCustomPlot::updateY1, (ui->widget18a), &ACustomPlot::updateY1Event);
        connect(ui->widget18b, &BCustomPlot::updateY2, (ui->widget18a), &ACustomPlot::updateY2Event);
        connect(ui->widget18b, &BCustomPlot::SetShortLineVis, (ui->widget18a), &ACustomPlot::SetShortLineVisEvent);
        connect(ui->widget18b, &BCustomPlot::updateX1, (ui->widget18c), &CCustomPlot::updateX1Event);
        connect(ui->widget18b, &BCustomPlot::updateX2, (ui->widget18c), &CCustomPlot::updateX2Event);
        connect(ui->widget18b, &BCustomPlot::updateX3, (ui->widget18c), &CCustomPlot::updateX3Event);
    }
    else if(m_type==19)
    {
        connect(ui->widget19a, &ACustomPlot::updateY1, (ui->widget19s), &SCustomPlot::updateY1Event);
        connect(ui->widget19a, &ACustomPlot::updateY2, (ui->widget19s), &SCustomPlot::updateY2Event);
        connect(ui->widget19a, &ACustomPlot::SetDashLineVis, (ui->widget19s), &SCustomPlot::SetDashLineVisEvent);
        connect(ui->widget19a, &ACustomPlot::updateDash, (ui->widget19s), &SCustomPlot::updateDashEvent);
        connect(ui->widget19a, &ACustomPlot::updateDashY, (ui->widget19s), &SCustomPlot::updateDashYEvent);
        connect(ui->widget19a, &ACustomPlot::changeDashSize, (ui->widget19s), &SCustomPlot::changeDashSizeEvent);

        connect(ui->widget19s, &SCustomPlot::updateY1, (ui->widget19a), &ACustomPlot::updateY1Event);
        connect(ui->widget19s, &SCustomPlot::updateY2, (ui->widget19a), &ACustomPlot::updateY2Event);
        connect(ui->widget19s, &SCustomPlot::SetShortLineVis, (ui->widget19a), &ACustomPlot::SetShortLineVisEvent);
        connect(ui->widget19s, &SCustomPlot::updateY1c, (ui->widget19c), &CCustomPlot::updateY1Event);
        connect(ui->widget19s, &SCustomPlot::updateY2c, (ui->widget19c), &CCustomPlot::updateY2Event);

        connect(ui->widget19c, &CCustomPlot::updateX1s, (ui->widget19s), &SCustomPlot::updateX1Event);
        connect(ui->widget19c, &CCustomPlot::updateX2s, (ui->widget19s), &SCustomPlot::updateX2Event);
        connect(ui->widget19c, &CCustomPlot::SetShortLineVis, (ui->widget19a), &ACustomPlot::SetShortLineVisEvent);
    }
}
void MainWindow::CursorEvent( QObject *sender,  QObject *receiver)
{

}

