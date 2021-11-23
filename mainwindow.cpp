#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "layoutpage.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Initial();
    InitialPlot();


    lay=new LayoutPage();
    colorbar=ColorBarSetting::Instance();
    connect(lay,SIGNAL(sendLayoutData(QString)),this,SLOT(layoutData(QString)));
    connect(lay,SIGNAL(DisplayCustomLayout(int ,int ,int ,int ,int )),this,SLOT(DisplayCustomLayout(int ,int ,int ,int ,int )));
    //connect(colorbar,SIGNAL(Bscanupdatecolorbar(ColorBarSetting::ColorbarType)),this,SLOT(changeColorbar(ColorBarSetting::ColorbarType)));

}
void MainWindow::Initial()
{


}

MainWindow::~MainWindow()
{
    delete ui;
}

//自定义11种布局
void MainWindow::DisplayCustomLayout(int customlayout,int local1,int local2,int local3,int local4)
{
    ThCustomPlot *cp1;

    if(local1==1) //自定义布局里的acustomplot 都是a2
        local1=0;
    if(local2==1) //自定义布局里的acustomplot 都是a2
        local2=0;
    if(local3==1) //自定义布局里的acustomplot 都是a2
        local3=0;
    if(local4==1) //自定义布局里的acustomplot 都是a2
        local4=0;

    if(customlayout==1)
    {
        ui->splitter_33->widget(0)->hide();

        CustomWidget(ui->splitter_33,1,local1);
    }
    else if(customlayout==2)
    {
        CustomWidget(ui->splitterc2,0,local1);
        CustomWidget(ui->splitterc2,1,local2);

    }
    else if(customlayout==3)
    {
        CustomWidget(ui->splitterc3,0,local1);
        CustomWidget(ui->splitterc3,1,local2);

    }
    else if(customlayout==4)
    {
        CustomWidget(ui->splitterc4,0,local1);
        CustomWidget(ui->splitterc4,1,local2);
        CustomWidget(ui->splitterc4,2,local3);

    }
    else if(customlayout==5)
    {
        CustomWidget(ui->splitterc5,0,local1);
        CustomWidget(ui->splitterc5,1,local2);
        CustomWidget(ui->splitterc5,2,local3);

    }
    else if(customlayout==6)
    {
        CustomWidget(ui->splitterc6h,0,local1);
        CustomWidget(ui->splitterc6h,1,local2);
        CustomWidget(ui->splitterc6v,1,local3);

    }
    else if(customlayout==7)
    {
        CustomWidget(ui->splitterc7v,0,local1);
        CustomWidget(ui->splitterc7v,1,local2);
        CustomWidget(ui->splitterc7h,1,local3);

    }
    else if(customlayout==8)
    {
        CustomWidget(ui->splitterc8h,0,local1);
        CustomWidget(ui->splitterc8h,1,local2);
        CustomWidget(ui->splitterc8h,2,local3);
        CustomWidget(ui->splitterc8v,1,local4);

    }
    else if(customlayout==9)
    {
        CustomWidget(ui->splitterc9v,0,local1);
        CustomWidget(ui->splitterc9h1,0,local2);
        CustomWidget(ui->splitterc9h1,1,local3);
        CustomWidget(ui->splitterc9h2,1,local4);
    }
    else if(customlayout==10)
    {
        CustomWidget(ui->splitterc10h,0,local1);
        CustomWidget(ui->splitterc10h,1,local2);
        CustomWidget(ui->splitterc10v,1,local3);
        CustomWidget(ui->splitterc10v,2,local4);

    }
    else if(customlayout==11)
    {
        CustomWidget(ui->splitterc11v,0,local1);
        CustomWidget(ui->splitterc11v,1,local2);
        CustomWidget(ui->splitterc11h,1,local3);
        CustomWidget(ui->splitterc11h,2,local4);

    }

    int curIndex=customlayout+20;//customlayout 1-11
    ui->stackedWidget->setCurrentIndex(curIndex);

}
void MainWindow::CustomWidget(QSplitter *&splitter,int index,int local)//在子函数中为指针分配空间，参数列表中要使用指针的引用。
{//若直接将指针作为形参，动态分配的空间会成为内存泄漏，不能达到分配空间的效果。
    splitter->widget(index)->hide();
    if(local==0)//a2
    {
        a2plot->setVisible(true);
        splitter->insertWidget(index,a2plot);
    }
    else if(local==2)//b
    {
        bplot->setVisible(true);
        splitter->insertWidget(index,bplot);
    }
    else if(local==3)
    {
        c1plot->setVisible(true);
        splitter->insertWidget(index,c1plot);
    }
    else if(local==4)
    {
        c2plot->setVisible(true);
        splitter->insertWidget(index,c2plot);
    }
    else if(local==5)
    {
        c3plot->setVisible(true);
        splitter->insertWidget(index,c3plot);
    }
    else if(local==6)
    {
        splot->setVisible(true);
        splitter->insertWidget(index,splot);
    }
    else if(local==7)
    {
        topcplot->setVisible(true);
        splitter->insertWidget(index,topcplot);
    }
    else if(local==8)
    {
        //cp=new BCustomPlot(ui->pagec1);
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
    //qDebug("%d",m_type);

    //0:a2 1:a 2:b 3-5:c 6:s 7:topc
    if(m_type==1)
    {
        ui->splitter_31->widget(0)->hide();
        ui->splitter_31->widget(1)->hide();

        aplot->setVisible(true);
        ui->splitter_31->insertWidget(1,aplot);

    }
    else if(m_type==2)//a2b
    {
        ui->splitter_2->widget(0)->hide();
        ui->splitter_2->widget(1)->hide();

        a2plot->setVisible(true);
        bplot->setVisible(true);
        ui->splitter_2->insertWidget(0,a2plot);
        ui->splitter_2->insertWidget(1,bplot);

    }
    else if(m_type==3)//b|a
    {
        ui->splitter->widget(0)->hide();
        ui->splitter->widget(1)->hide();
        aplot->setVisible(true);
        bplot->setVisible(true);
        ui->splitter->insertWidget(0,bplot);
        ui->splitter->insertWidget(1,aplot);

    }
    else if(m_type==4)
    {
        ui->splitter_32->widget(0)->hide();
        ui->splitter_32->widget(1)->hide();

        splot->setVisible(true);
        ui->splitter_32->insertWidget(1,splot);

    }
    else if(m_type==5)//s/a2
    {
        ui->splitter_3->widget(0)->hide();
        ui->splitter_3->widget(1)->hide();
        a2plot->setVisible(true);
        splot->setVisible(true);
        ui->splitter_3->insertWidget(0,splot);
        ui->splitter_3->insertWidget(1,a2plot);

    }
    else if(m_type==6)//as
    {
        ui->splitter_4->widget(0)->hide();
        ui->splitter_4->widget(1)->hide();
        aplot->setVisible(true);
        splot->setVisible(true);
        ui->splitter_4->insertWidget(0,splot);
        ui->splitter_4->insertWidget(1,aplot);
    }
    else if(m_type==7) //s|a|b
    {
        ui->splitter_5->widget(0)->hide();
        ui->splitter_5->widget(1)->hide();
        ui->splitter_5->widget(2)->hide();
        splot->setVisible(true);
        bplot->setVisible(true);
        aplot->setVisible(true);
        ui->splitter_5->insertWidget(0,splot);
        ui->splitter_5->insertWidget(1,aplot);
        ui->splitter_5->insertWidget(2,bplot);

    }
    else if(m_type==8)//s/a2/c
    {
        ui->splitter_6->widget(0)->hide();
        ui->splitter_6->widget(1)->hide();
        ui->splitter_6->widget(2)->hide();
        splot->setVisible(true);
        c1plot->setVisible(true);
        a2plot->setVisible(true);
        ui->splitter_6->insertWidget(0,splot);
        ui->splitter_6->insertWidget(1,a2plot);
        ui->splitter_6->insertWidget(2,c1plot);
    }
    else if(m_type==9) //abs
    {
        ui->splitter_7->widget(0)->hide();
        ui->splitter_7->widget(1)->hide();
        ui->splitter_8->widget(1)->hide();
        splot->setVisible(true);
        bplot->setVisible(true);
        aplot->setVisible(true);
        ui->splitter_7->insertWidget(0,splot);
        ui->splitter_7->insertWidget(1,bplot);
        ui->splitter_8->insertWidget(2,aplot);
    }
    else if(m_type==10)//sa2b
    {
        ui->splitter_9->widget(0)->hide();
        ui->splitter_9->widget(1)->hide();
        ui->splitter_10->widget(1)->hide();
        splot->setVisible(true);
        bplot->setVisible(true);
        a2plot->setVisible(true);
        ui->splitter_9->insertWidget(0,splot);
        ui->splitter_9->insertWidget(1,a2plot);
        ui->splitter_10->insertWidget(2,bplot);

    }
    else if(m_type==11)//abcs
    {
        ui->splitter_11->widget(0)->hide();
        ui->splitter_11->widget(1)->hide();
        ui->splitter_11->widget(2)->hide();
        ui->splitter_12->widget(1)->hide();
        splot->setVisible(true);
        bplot->setVisible(true);
        aplot->setVisible(true);
        c1plot->setVisible(true);
        ui->splitter_11->insertWidget(0,splot);
        ui->splitter_11->insertWidget(1,bplot);
        ui->splitter_11->insertWidget(2,c1plot);
        ui->splitter_12->insertWidget(1,aplot);
    }
    else if(m_type==12)//sa2bc
    {
        ui->splitter_13->widget(0)->hide();
        ui->splitter_13->widget(1)->hide();
        ui->splitter_14->widget(0)->hide();
        ui->splitter_15->widget(1)->hide();
        splot->setVisible(true);
        bplot->setVisible(true);
        aplot->setVisible(true);
        c1plot->setVisible(true);
        ui->splitter_13->insertWidget(0,aplot);
        ui->splitter_13->insertWidget(1,bplot);
        ui->splitter_14->insertWidget(0,splot);
        ui->splitter_15->insertWidget(1,c1plot);
    }
    else if(m_type==13)//sa2bc
    {
        ui->splitter_16->widget(0)->hide();
        ui->splitter_16->widget(1)->hide();
        ui->splitter_16->widget(2)->hide();
        ui->splitter_17->widget(1)->hide();
        splot->setVisible(true);
        bplot->setVisible(true);
        a2plot->setVisible(true);
        c1plot->setVisible(true);
        ui->splitter_16->insertWidget(0,splot);
        ui->splitter_16->insertWidget(1,a2plot);
        ui->splitter_16->insertWidget(2,bplot);
        ui->splitter_17->insertWidget(1,c1plot);

    }
    else if(m_type==14)//acs
    {
        ui->splitter_18->widget(0)->hide();
        ui->splitter_18->widget(1)->hide();
        ui->splitter_19->widget(1)->hide();
        splot->setVisible(true);
        aplot->setVisible(true);
        c1plot->setVisible(true);
        ui->splitter_18->insertWidget(0,splot);
        ui->splitter_18->insertWidget(1,c1plot);
        ui->splitter_19->insertWidget(1,aplot);
    }
    else if(m_type==15)//sa2c
    {
        ui->splitter_20->widget(0)->hide();
        ui->splitter_20->widget(1)->hide();
        ui->splitter_21->widget(1)->hide();
        splot->setVisible(true);
        a2plot->setVisible(true);
        c1plot->setVisible(true);
        ui->splitter_20->insertWidget(0,splot);
        ui->splitter_20->insertWidget(1,a2plot);
        ui->splitter_21->insertWidget(1,c1plot);

    }
    else if(m_type==16) //acstopc
    {
        ui->splitter_29->widget(0)->hide();
        ui->splitter_29->widget(1)->hide();
        ui->splitter_29->widget(2)->hide();
        ui->splitter_30->widget(1)->hide();
        splot->setVisible(true);
        aplot->setVisible(true);
        c1plot->setVisible(true);
        topcplot->setVisible(true);
        ui->splitter_29->insertWidget(0,splot);
        ui->splitter_29->insertWidget(1,c1plot);
        ui->splitter_29->insertWidget(2,topcplot);
        ui->splitter_30->insertWidget(1,aplot);

    }
    else if(m_type==17)//sa2c1c2c3 !!!!
    {
        ui->splitter_22->widget(0)->hide();
        ui->splitter_22->widget(1)->hide();
        ui->splitter_22->widget(2)->hide();
        ui->splitter_23->widget(0)->hide();
        ui->splitter_23->widget(1)->hide();
       // ui->splitter_23->widget(1)->hide();
        splot->setVisible(true);
        a2plot->setVisible(true);
        c1plot->setVisible(true);
        c2plot->setVisible(true);
        c3plot->setVisible(true);
        ui->splitter_22->insertWidget(0,c1plot);
        ui->splitter_22->insertWidget(1,c2plot);
        ui->splitter_22->insertWidget(2,c3plot);
        ui->splitter_23->insertWidget(0,a2plot);
        ui->splitter_23->insertWidget(1,splot);
    }
    else if(m_type==18)//abcs
    {
        ui->splitter_25->widget(0)->hide();
        ui->splitter_25->widget(1)->hide();
        ui->splitter_26->widget(1)->hide();
        ui->splitter_26->widget(2)->hide();
        splot->setVisible(true);
        aplot->setVisible(true);
        c1plot->setVisible(true);
        bplot->setVisible(true);
        ui->splitter_25->insertWidget(0,splot);
        ui->splitter_25->insertWidget(1,aplot);
        ui->splitter_26->insertWidget(1,c1plot);
        ui->splitter_26->insertWidget(2,bplot);
    }
    else if(m_type==19)//acs
    {
        ui->splitter_27->widget(0)->hide();
        ui->splitter_27->widget(1)->hide();
        ui->splitter_28->widget(1)->hide();
        splot->setVisible(true);
        aplot->setVisible(true);
        c1plot->setVisible(true);
        ui->splitter_27->insertWidget(0,splot);
        ui->splitter_27->insertWidget(1,aplot);
        ui->splitter_28->insertWidget(1,c1plot);
    }

}
void MainWindow::InitialPlot()
{
    aplot=new ACustomPlot(this);
    a2plot=new A2CustomPlot(this);
    bplot=new BCustomPlot(this);
    c1plot=new CCustomPlot(this);
    c2plot=new CCustomPlot(this);
    c3plot=new CCustomPlot(this);
    splot=new SCustomPlot(this);
    topcplot=new TopcCustomPlot(this);



    connect(a2plot, SIGNAL(updateY1(float)), bplot, SLOT(updateY1Event(float)));
    connect(a2plot, SIGNAL(updateY2(float)), bplot, SLOT(updateY2Event(float)));
    connect(a2plot, SIGNAL(updateY1(float)), bplot, SLOT(updateY1Event(float)));
    connect(a2plot, SIGNAL(updateY2(float)), bplot, SLOT(updateY2Event(float)));
    connect(a2plot, SIGNAL(SetDashLineVis), bplot, SLOT(SetDashLineVisEvent));
    connect(a2plot, SIGNAL(updateDash(float.float)), bplot, SLOT(updateDashEvent(float,float)));
    connect(a2plot, SIGNAL(updateDashY(float)), bplot, SLOT(updateDashYEvent(float)));
    connect(a2plot, SIGNAL(changeDashSize(float)), bplot, SLOT(changeDashSizeEvent(float)));

    connect(aplot, SIGNAL(updateY1(float)), bplot, SLOT(updateY1Event(float)));
    connect(aplot, SIGNAL(updateY2(float)), bplot, SLOT(updateY2Event(float)));
    connect(aplot, SIGNAL(updateY1(float)), bplot, SLOT(updateY1Event(float)));
    connect(aplot, SIGNAL(updateY2(float)), bplot, SLOT(updateY2Event(float)));
    connect(aplot, SIGNAL(SetDashLineVis), bplot, SLOT(SetDashLineVisEvent));
    connect(aplot, SIGNAL(updateDash(float.float)), bplot, SLOT(updateDashEvent(float,float)));
    connect(aplot, SIGNAL(updateDashY(float)), bplot, SLOT(updateDashYEvent(float)));
    connect(aplot, SIGNAL(changeDashSize(float)), bplot, SLOT(changeDashSizeEvent(float)));

    connect(bplot, SIGNAL(updateY1(float)), a2plot, SLOT(updateX1Event(float)));
    connect(bplot, SIGNAL(updateY2(float)), a2plot, SLOT(updateX2Event(float)));
    connect(bplot, SIGNAL(SetShortLineVis()), a2plot, SLOT(SetShortLineVisEvent()));
    connect(bplot, SIGNAL(updateY1(float)), aplot, SLOT(updateY1Event(float)));
    connect(bplot, SIGNAL(updateY2(float)), aplot, SLOT(updateY2Event(float)));
    connect(bplot, SIGNAL(SetShortLineVis()), aplot, SLOT(SetShortLineVisEvent()));
    connect(bplot, SIGNAL(updateX1(float)), c1plot, SLOT(updateX1Event(float)));
    connect(bplot, SIGNAL(updateX2(float)), c1plot, SLOT(updateX2Event(float)));
    connect(bplot, SIGNAL(updateX3(float)), c1plot, SLOT(updateX3Event(float)));
    connect(bplot, SIGNAL(updateX1(float)), c2plot, SLOT(updateX1Event(float)));
    connect(bplot, SIGNAL(updateX2(float)), c2plot, SLOT(updateX2Event(float)));
    connect(bplot, SIGNAL(updateX3(float)), c2plot, SLOT(updateX3Event(float)));
    connect(bplot, SIGNAL(updateX1(float)), c3plot, SLOT(updateX1Event(float)));
    connect(bplot, SIGNAL(updateX2(float)), c3plot, SLOT(updateX2Event(float)));
    connect(bplot, SIGNAL(updateX3(float)), c3plot, SLOT(updateX3Event(float)));
    connect(bplot, SIGNAL(updateY1(float)), splot, SLOT(updateY1Event(float)));
    connect(bplot, SIGNAL(updateY2(float)), splot, SLOT(updateY2Event(float)));


    connect(c1plot, SIGNAL(SetShortLineVis()), a2plot, SLOT(SetShortLineVisEvent()));
    connect(c1plot, SIGNAL(SetShortLineVis()), aplot, SLOT(SetShortLineVisEvent()));
    connect(c1plot, SIGNAL(updateX1s(float)), bplot, SLOT(updateY1Event(float))); //红色水平线动
    connect(c1plot, SIGNAL(updateX2s(float)), bplot, SLOT(updateY2Event(float))); //绿色水平线动
    connect(c1plot, SIGNAL(updateX1b(float)), bplot, SLOT(updateX1Event(float)));//红色竖直线动
    connect(c1plot, SIGNAL(updateX2b(float)), bplot, SLOT(updateX2Event(float)));
    connect(c1plot, SIGNAL(updateX3(float)), bplot, SLOT(updateX3Event(float)));
    connect(c1plot, SIGNAL(updateX1s(float)), c2plot, SLOT(updateY1Event(float))); //红色水平线动
    connect(c1plot, SIGNAL(updateX2s(float)), c2plot, SLOT(updateY2Event(float))); //绿色水平线动
    connect(c1plot, SIGNAL(updateX1b(float)), c2plot, SLOT(updateX1Event(float)));//红色竖直线动
    connect(c1plot, SIGNAL(updateX2b(float)), c2plot, SLOT(updateX2Event(float)));
    connect(c1plot, SIGNAL(updateX3(float)), c2plot, SLOT(updateX3Event(float)));
    connect(c1plot, SIGNAL(updateX1s(float)), c3plot, SLOT(updateY1Event(float))); //红色水平线动
    connect(c1plot, SIGNAL(updateX2s(float)), c3plot, SLOT(updateY2Event(float))); //绿色水平线动
    connect(c1plot, SIGNAL(updateX1b(float)), c3plot, SLOT(updateX1Event(float)));//红色竖直线动
    connect(c1plot, SIGNAL(updateX2b(float)), c3plot, SLOT(updateX2Event(float)));
    connect(c1plot, SIGNAL(updateX3(float)), c3plot, SLOT(updateX3Event(float)));
    connect(c1plot, SIGNAL(updateX1s(float)), topcplot, SLOT(updateY1Event(float))); //红色水平线动
    connect(c1plot, SIGNAL(updateX2s(float)), topcplot, SLOT(updateY2Event(float))); //绿色水平线动
    connect(c1plot, SIGNAL(updateX1b(float)), topcplot, SLOT(updateX1Event(float)));//红色竖直线动
    connect(c1plot, SIGNAL(updateX2b(float)), topcplot, SLOT(updateX2Event(float)));
    connect(c1plot, SIGNAL(updateX3(float)), topcplot, SLOT(updateX3Event(float)));
    connect(c1plot, SIGNAL(updateX1s(float)), splot, SLOT(updateX1Event(float)));
    connect(c1plot, SIGNAL(updateX2s(float)), splot, SLOT(updateX2Event(float)));

    connect(c2plot, SIGNAL(SetShortLineVis()), a2plot, SLOT(SetShortLineVisEvent()));
    connect(c2plot, SIGNAL(SetShortLineVis()), aplot, SLOT(SetShortLineVisEvent()));
    connect(c2plot, SIGNAL(updateX1s(float)), bplot, SLOT(updateY1Event(float))); //红色水平线动
    connect(c2plot, SIGNAL(updateX2s(float)), bplot, SLOT(updateY2Event(float))); //绿色水平线动
    connect(c2plot, SIGNAL(updateX1b(float)), bplot, SLOT(updateX1Event(float)));//红色竖直线动
    connect(c2plot, SIGNAL(updateX2b(float)), bplot, SLOT(updateX2Event(float)));
    connect(c2plot, SIGNAL(updateX3(float)), bplot, SLOT(updateX3Event(float)));
    connect(c2plot, SIGNAL(updateX1s(float)), c1plot, SLOT(updateY1Event(float))); //红色水平线动
    connect(c2plot, SIGNAL(updateX2s(float)), c1plot, SLOT(updateY2Event(float))); //绿色水平线动
    connect(c2plot, SIGNAL(updateX1b(float)), c1plot, SLOT(updateX1Event(float)));//红色竖直线动
    connect(c2plot, SIGNAL(updateX2b(float)), c1plot, SLOT(updateX2Event(float)));
    connect(c2plot, SIGNAL(updateX3(float)), c1plot, SLOT(updateX3Event(float)));
    connect(c2plot, SIGNAL(updateX1s(float)), c3plot, SLOT(updateY1Event(float))); //红色水平线动
    connect(c2plot, SIGNAL(updateX2s(float)), c3plot, SLOT(updateY2Event(float))); //绿色水平线动
    connect(c2plot, SIGNAL(updateX1b(float)), c3plot, SLOT(updateX1Event(float)));//红色竖直线动
    connect(c2plot, SIGNAL(updateX2b(float)), c3plot, SLOT(updateX2Event(float)));
    connect(c2plot, SIGNAL(updateX3(float)), c3plot, SLOT(updateX3Event(float)));
    connect(c2plot, SIGNAL(updateX1s(float)), topcplot, SLOT(updateY1Event(float))); //红色水平线动
    connect(c2plot, SIGNAL(updateX2s(float)), topcplot, SLOT(updateY2Event(float))); //绿色水平线动
    connect(c2plot, SIGNAL(updateX1b(float)), topcplot, SLOT(updateX1Event(float)));//红色竖直线动
    connect(c2plot, SIGNAL(updateX2b(float)), topcplot, SLOT(updateX2Event(float)));
    connect(c2plot, SIGNAL(updateX3(float)), topcplot, SLOT(updateX3Event(float)));
    connect(c2plot, SIGNAL(updateX1s(float)), splot, SLOT(updateX1Event(float)));
    connect(c2plot, SIGNAL(updateX2s(float)), splot, SLOT(updateX2Event(float)));

    connect(c3plot, SIGNAL(SetShortLineVis()), a2plot, SLOT(SetShortLineVisEvent()));
    connect(c3plot, SIGNAL(SetShortLineVis()), aplot, SLOT(SetShortLineVisEvent()));
    connect(c3plot, SIGNAL(updateX1s(float)), bplot, SLOT(updateY1Event(float))); //红色水平线动
    connect(c3plot, SIGNAL(updateX2s(float)), bplot, SLOT(updateY2Event(float))); //绿色水平线动
    connect(c3plot, SIGNAL(updateX1b(float)), bplot, SLOT(updateX1Event(float)));//红色竖直线动
    connect(c3plot, SIGNAL(updateX2b(float)), bplot, SLOT(updateX2Event(float)));
    connect(c3plot, SIGNAL(updateX3(float)), bplot, SLOT(updateX3Event(float)));

    connect(c3plot, SIGNAL(updateX1s(float)), c2plot, SLOT(updateY1Event(float))); //红色水平线动
    connect(c3plot, SIGNAL(updateX2s(float)), c2plot, SLOT(updateY2Event(float))); //绿色水平线动
    connect(c3plot, SIGNAL(updateX1b(float)), c2plot, SLOT(updateX1Event(float)));//红色竖直线动
    connect(c3plot, SIGNAL(updateX2b(float)), c2plot, SLOT(updateX2Event(float)));
    connect(c3plot, SIGNAL(updateX3(float)), c2plot, SLOT(updateX3Event(float)));

    connect(c3plot, SIGNAL(updateX1s(float)), c1plot, SLOT(updateY1Event(float))); //红色水平线动
    connect(c3plot, SIGNAL(updateX2s(float)), c1plot, SLOT(updateY2Event(float))); //绿色水平线动
    connect(c3plot, SIGNAL(updateX1b(float)), c1plot, SLOT(updateX1Event(float)));//红色竖直线动
    connect(c3plot, SIGNAL(updateX2b(float)), c1plot, SLOT(updateX2Event(float)));
    connect(c3plot, SIGNAL(updateX3(float)), c1plot, SLOT(updateX3Event(float)));

    connect(c3plot, SIGNAL(updateX1s(float)), topcplot, SLOT(updateY1Event(float))); //红色水平线动
    connect(c3plot, SIGNAL(updateX2s(float)), topcplot, SLOT(updateY2Event(float))); //绿色水平线动
    connect(c3plot, SIGNAL(updateX1b(float)), topcplot, SLOT(updateX1Event(float)));//红色竖直线动
    connect(c3plot, SIGNAL(updateX2b(float)), topcplot, SLOT(updateX2Event(float)));
    connect(c3plot, SIGNAL(updateX3(float)), topcplot, SLOT(updateX3Event(float)));
    connect(c3plot, SIGNAL(updateX1s(float)), splot, SLOT(updateX1Event(float)));
    connect(c3plot, SIGNAL(updateX2s(float)), splot, SLOT(updateX2Event(float)));

    connect(splot, SIGNAL(updateY1(float)), a2plot, SLOT(updateX1Event(float)));
    connect(splot, SIGNAL(updateY2(float)), a2plot, SLOT(updateX2Event(float)));
    connect(splot, SIGNAL(SetShortLineVis()), a2plot, SLOT(SetShortLineVisEvent()));
    connect(splot, SIGNAL(updateY1(float)), aplot, SLOT(updateY1Event(float)));
    connect(splot, SIGNAL(updateY2(float)), aplot, SLOT(updateY2Event(float)));
    connect(splot, SIGNAL(SetShortLineVis()), aplot, SLOT(SetShortLineVisEvent()));
    connect(splot, SIGNAL(updateY1(float)), bplot, SLOT(updateY1Event(float)));
    connect(splot, SIGNAL(updateY2(float)), bplot, SLOT(updateY2Event(float)));
    connect(splot, SIGNAL(updateY1c(float)), c1plot, SLOT(updateY1Event(float)));
    connect(splot, SIGNAL(updateY2c(float)), c1plot, SLOT(updateY2Event(float)));
    connect(splot, SIGNAL(updateY1c(float)), c2plot, SLOT(updateY1Event(float)));
    connect(splot, SIGNAL(updateY2c(float)), c2plot, SLOT(updateY2Event(float)));
    connect(splot, SIGNAL(updateY1c(float)), c3plot, SLOT(updateY1Event(float)));
    connect(splot, SIGNAL(updateY2c(float)), c3plot, SLOT(updateY2Event(float)));

    connect(topcplot, SIGNAL(SetShortLineVis()), a2plot, SLOT(SetShortLineVisEvent()));
    connect(topcplot, SIGNAL(updateX1(float)), c1plot, SLOT(updateX1Event(float)));
    connect(topcplot, SIGNAL(updateX2(float)), c1plot, SLOT(updateX2Event(float)));
    connect(topcplot, SIGNAL(updateX3(float)), c1plot, SLOT(updateX3Event(float)));
    connect(topcplot, SIGNAL(updateX1(float)), c2plot, SLOT(updateX1Event(float)));
    connect(topcplot, SIGNAL(updateX2(float)), c2plot, SLOT(updateX2Event(float)));
    connect(topcplot, SIGNAL(updateX3(float)), c2plot, SLOT(updateX3Event(float)));
    connect(topcplot, SIGNAL(updateX1(float)), c3plot, SLOT(updateX1Event(float)));
    connect(topcplot, SIGNAL(updateX2(float)), c3plot, SLOT(updateX2Event(float)));
    connect(topcplot, SIGNAL(updateX3(float)), c3plot, SLOT(updateX3Event(float)));

    aplot->setVisible(false);
    a2plot->setVisible(false);
    bplot->setVisible(false);
    c1plot->setVisible(false);
    c2plot->setVisible(false);
    c3plot->setVisible(false);
    splot->setVisible(false);
    topcplot->setVisible(false);
}

void MainWindow::on_pushButton_3_clicked()
{

    colorbar->show();
}

