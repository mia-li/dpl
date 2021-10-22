#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Initial();

     connect(customPlot1, SIGNAL(mouseDoubleClick(QMouseEvent*)), this, SLOT(LmouseDoubleClick(QMouseEvent*)));
     connect(customPlot1,SIGNAL(mousePress(QMouseEvent*)),this,SLOT(myLMousePressEvent(QMouseEvent*)));
     connect(customPlot1,SIGNAL(mouseRelease(QMouseEvent*)),this,SLOT(myLMouseReleaseEvent(QMouseEvent*)));
     connect(customPlot1,SIGNAL(mouseMove(QMouseEvent*)),this,SLOT(myLMouseMoveEvent(QMouseEvent*)));

     connect(customPlot2, SIGNAL(mouseDoubleClick(QMouseEvent*)), this, SLOT(RmouseDoubleClick(QMouseEvent*)));
     connect(customPlot2,SIGNAL(mousePress(QMouseEvent*)),this,SLOT(myRMousePressEvent(QMouseEvent*)));
     connect(customPlot2,SIGNAL(mouseRelease(QMouseEvent*)),this,SLOT(myRMouseReleaseEvent(QMouseEvent*)));
     connect(customPlot2,SIGNAL(mouseMove(QMouseEvent*)),this,SLOT(myRMouseMoveEvent(QMouseEvent*)));

}
void MainWindow::Initial()
{
    customPlot1 = ui->customPlot1;
//    customPlot1->yAxis2->setVisible(true);
//    customPlot1->yAxis2->setTickLabels(true);
    customPlot1->setBackground(Qt::darkGray);
    customPlot1->axisRect()->setBackground(Qt::white);

    customPlot1->xAxis->setRange(0, 7);
    customPlot1->xAxis->setBasePen(QPen(Qt::white, 2));
    customPlot1->xAxis->setTickPen(QPen(Qt::white, 2));
    customPlot1->xAxis->setSubTickPen(QPen(Qt::white, 2));
    customPlot1->xAxis->setTickLabelColor(Qt::white);
    customPlot1->xAxis->setTickLengthIn(0);
    customPlot1->xAxis->setTickLengthOut(10);
    customPlot1->xAxis->setSubTickLengthIn(0);
    customPlot1->xAxis->setSubTickLengthOut(5);

    customPlot1->yAxis->setRange(0, 50);
    customPlot1->yAxis->setBasePen(QPen(Qt::white, 2));
    customPlot1->yAxis->setTickPen(QPen(Qt::white, 2));
    customPlot1->yAxis->setSubTickPen(QPen(Qt::white, 2));
    customPlot1->yAxis->setTickLabelColor(Qt::white);
    customPlot1->yAxis->setTickLengthIn(0);
    customPlot1->yAxis->setTickLengthOut(10);
    customPlot1->yAxis->setSubTickLengthIn(0);
    customPlot1->yAxis->setSubTickLengthOut(5);
    customPlot1->yAxis->setRangeReversed(true);

//    customPlot1->yAxis2->setRange(0, 100);

    customPlot2 = ui->customPlot2;
    customPlot2->setBackground(Qt::darkGray);
    customPlot2->axisRect()->setBackground(Qt::white);

    customPlot2->xAxis->setRange(0, 100);
    customPlot2->xAxis->setBasePen(QPen(Qt::white, 2));
    customPlot2->xAxis->setTickPen(QPen(Qt::white, 2));
    customPlot2->xAxis->setSubTickPen(QPen(Qt::white, 2));
    customPlot2->xAxis->setTickLabelColor(Qt::white);
    customPlot2->xAxis->setTickLengthIn(0);
    customPlot2->xAxis->setTickLengthOut(10);
    customPlot2->xAxis->setSubTickLengthIn(0);
    customPlot2->xAxis->setSubTickLengthOut(5);

    customPlot2->yAxis->setRange(0, 50);
    customPlot2->yAxis->setBasePen(QPen(Qt::white, 2));
    customPlot2->yAxis->setTickPen(QPen(Qt::white, 2));
    customPlot2->yAxis->setSubTickPen(QPen(Qt::white, 2));
    customPlot2->yAxis->setTickLabelColor(Qt::white);
    customPlot2->yAxis->setTickLengthIn(0);
    customPlot2->yAxis->setTickLengthOut(10);
    customPlot2->yAxis->setSubTickLengthIn(0);
    customPlot2->yAxis->setSubTickLengthOut(5);
    customPlot2->yAxis->setRangeReversed(true);

//    customPlot1->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom);//可拖拽+可滚轮缩放
//    customPlot2->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom);//可拖拽+可滚轮缩放

    m_lineLTracer1 = new XxwTraceLine(customPlot1);
    m_lineLTracer1->setVisible(false);
    m_lineLTracer2 = new XxwTraceLine(customPlot1,XxwTraceLine::Crosshair,Qt::green);
    m_lineLTracer2->setVisible(false);
    m_lineLDashTracer= new XxwTraceLine(customPlot1,XxwTraceLine::DashLine);
    m_lineLTracer1->setVisible(false);
    m_lineLStLineTracer= new XxwTraceLine(customPlot1,XxwTraceLine::Line);

    m_lineRTracer1 = new XxwTraceLine(customPlot2);
    m_lineRTracer1->setVisible(false);
    m_lineRTracer2 = new XxwTraceLine(customPlot2,XxwTraceLine::Crosshair,Qt::green);
    m_lineRTracer2->setVisible(false);
    m_lineRTracerShort = new XxwTraceLine(customPlot2,XxwTraceLine::ShortLine);
    m_lineRTracerShort->setVisible(false);

   //立即刷新
   customPlot1->rescaleAxes();//自适应大小
   customPlot1->replot();
   customPlot2->rescaleAxes();//自适应大小
   customPlot2->replot();
}
MainWindow::~MainWindow()
{
    delete ui;
}
int clickNum = 0; //用于判断是偶数双击还是单数双击
/**
 * @brief 鼠标双击事件
 * @param e
 */
void MainWindow::LmouseDoubleClick(QMouseEvent* e)
{
    QCustomPlot *curCustomPlot = qobject_cast<QCustomPlot *>(sender());
    if(curCustomPlot == customPlot1)
    {
        float x = curCustomPlot->xAxis->pixelToCoord(e->pos().x());
        float y = curCustomPlot->yAxis->pixelToCoord(e->pos().y());

        if(clickNum%2 == 0)
        {
            m_lineLTracer1->updatePosition(x,y);
            m_lineLTracer1->setVisible(true);
            m_lineRTracer1->updatePositionY(y);
            m_lineRTracer1->setVisible(true);
        }
        else
        {
            m_lineLTracer2->updatePosition(x,y);
            m_lineLTracer2->setVisible(true);
            m_lineRTracer2->updatePositionY(y);
            m_lineRTracer2->setVisible(true);
        }
        clickNum++;
        curCustomPlot->replot();
        customPlot2->replot();
    }
}
void MainWindow::RmouseDoubleClick(QMouseEvent* e)
{
    QCustomPlot *curCustomPlot = qobject_cast<QCustomPlot *>(sender());
    if(curCustomPlot == customPlot2)
    {
        float x = curCustomPlot->xAxis->pixelToCoord(e->pos().x());
        float y = curCustomPlot->yAxis->pixelToCoord(e->pos().y());

        if(clickNum%2 == 0)
        {
            m_lineRTracer1->updatePosition(x,y);
            m_lineRTracer1->setVisible(true);
            m_lineLTracer1->updatePositionY(y);
            m_lineLTracer1->setVisible(true);
        }
        else
        {
            m_lineRTracer2->updatePosition(x,y);
            m_lineRTracer2->setVisible(true);
            m_lineLTracer2->updatePositionY(y);
            m_lineLTracer2->setVisible(true);
        }
        clickNum++;
        curCustomPlot->replot();
        customPlot1->replot();
    }
}
void MainWindow::myLMousePressEvent(QMouseEvent *event)
{
    qDebug()<<"mousePressEvent";

    int x_pos = event->pos().x();
    int y_pos = event->pos().y();

    float x_val = customPlot1->xAxis->pixelToCoord(x_pos);
    float y_val = customPlot1->yAxis->pixelToCoord(y_pos);

    if(fabs(x_val-m_lineLTracer1->getPositionX())<1.0)
    {
//        customPlot->cursor().setShape(Qt::SizeVerCursor);
        m_lineLTracer1->SelectedV=true;
    }
    else if(fabs(x_val-m_lineLTracer2->getPositionX())<1.0)
    {
//        customPlot->cursor().setShape(Qt::SizeVerCursor);
        m_lineLTracer2->SelectedV=true;
    }
    else if(fabs(x_val-m_lineLStLineTracer->getPositionX())<2.0)
    {
        m_lineLStLineTracer->SelectedV=true;
    }
    else if(fabs(y_val-m_lineLTracer1->getPositionY())<1.0)
    {
//        customPlot->cursor().setShape(Qt::SizeHorCursor);
        m_lineLTracer1->SelectedH=true;
    }
    else if(fabs(y_val-m_lineLTracer2->getPositionY())<1.0)
    {
//        customPlot->cursor().setShape(Qt::SizeHorCursor);
        m_lineLTracer2->SelectedH=true;
    }
    else
    {
        m_lineRTracerShort->setVisible(false);
        m_lineLTracer1->SelectedH=false;
        m_lineLTracer2->SelectedH=false;
        m_lineLTracer1->SelectedV=false;
        m_lineLTracer2->SelectedV=false;
        m_lineLStLineTracer->SelectedV=false;

        customPlot1->replot();
        customPlot2->replot();
    }
}
void MainWindow::myRMousePressEvent(QMouseEvent *event)
{
    qDebug()<<"mousePressEvent";

    int x_pos = event->pos().x();
    int y_pos = event->pos().y();

    float x_val = customPlot2->xAxis->pixelToCoord(x_pos);
    float y_val = customPlot2->yAxis->pixelToCoord(y_pos);

    if(fabs(x_val-m_lineRTracer1->getPositionX())<1.0)
    {
//        customPlot->cursor().setShape(Qt::SizeVerCursor);
        m_lineRTracer1->SelectedV=true;
    }
    else if(fabs(x_val-m_lineRTracer2->getPositionX())<1.0)
    {
//        customPlot->cursor().setShape(Qt::SizeVerCursor);
        m_lineRTracer2->SelectedV=true;
    }
    else if(fabs(y_val-m_lineRTracer1->getPositionY())<1.0)
    {
//        customPlot->cursor().setShape(Qt::SizeHorCursor);
        m_lineRTracer1->SelectedH=true;
    }
    else if(fabs(y_val-m_lineRTracer2->getPositionY())<1.0)
    {
//        customPlot->cursor().setShape(Qt::SizeHorCursor);
        m_lineRTracer2->SelectedH=true;
    }
    else if(fabs(x_val-m_lineRTracerShort->getPositionX())<1.0&&(y_val>=(m_lineRTracerShort->getPositionY()-m_lineRTracerShort->m_size/2.0))&&(y_val<=(m_lineRTracerShort->getPositionY()+m_lineRTracerShort->m_size/2.0)))
    {
        if(!m_lineRTracerShort->m_visible)
        {
            m_lineRTracerShort->setVisible(true);
        }
        if(!m_lineLDashTracer->m_visible)
        {
            m_lineLDashTracer->setVisible(true);
        }
        m_lineRTracerShort->SelectedLine=true;
    }
    else if(m_lineRTracerShort->m_visible&&fabs(y_val-m_lineRTracerShort->getPositionY()+m_lineRTracerShort->m_size/2.0)<1.0)
    {
        m_lineRTracerShort->SelectedH=true;
    }
    else if(m_lineRTracerShort->m_visible&&fabs(x_val-m_lineRTracerShort->getPositionX())<1.0)
    {
        m_lineRTracerShort->SelectedV=true;
    }
    else if(m_lineRTracerShort->m_visible&&fabs(y_val-m_lineRTracerShort->getPositionY()-m_lineRTracerShort->m_size/2.0)<1.0)
    {
        m_lineRTracerShort->SelectedBottom=true;
    }
    else
    {
//        customPlot->cursor().setShape(Qt::ArrowCursor);
        m_lineRTracerShort->setVisible(false);
        m_lineRTracer1->SelectedH=false;
        m_lineRTracer2->SelectedH=false;
        m_lineRTracer1->SelectedV=false;
        m_lineRTracer2->SelectedV=false;
        m_lineRTracerShort->SelectedH=false;
        m_lineRTracerShort->SelectedV=false;
        m_lineRTracerShort->SelectedBottom=false;
        m_lineRTracerShort->SelectedLine=false;
        customPlot2->replot();
        customPlot1->replot();
    }
}
void MainWindow::myLMouseReleaseEvent(QMouseEvent *event)
{
    //customPlot1->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom);

    m_lineLTracer1->SelectedH=false;
    m_lineLTracer2->SelectedH=false;
    m_lineLTracer1->SelectedV=false;
    m_lineLTracer2->SelectedV=false;
    m_lineLStLineTracer->SelectedV=false;
}
void MainWindow::myRMouseReleaseEvent(QMouseEvent *event)
{
   // customPlot2->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom);

    m_lineRTracer1->SelectedH=false;
    m_lineRTracer2->SelectedH=false;
    m_lineRTracer1->SelectedV=false;
    m_lineRTracer2->SelectedV=false;
    m_lineRTracerShort->SelectedH=false;
    m_lineRTracerShort->SelectedV=false;
    m_lineRTracerShort->SelectedBottom=false;
    m_lineRTracerShort->SelectedLine=false;
}
void MainWindow::myLMouseMoveEvent(QMouseEvent *event)
{
    int x_pos = event->pos().x();
    int y_pos = event->pos().y();

    float x_val = customPlot1->xAxis->pixelToCoord(x_pos);
    float y_val = customPlot1->yAxis->pixelToCoord(y_pos);

    customPlot1->setInteractions(QCP::iRangeZoom);


    if(m_lineLTracer1->SelectedH)
    {
        m_lineLTracer1->updatePositionY(y_val);
        m_lineRTracer1->updatePositionY(y_val);
//        m_lineTracer1->m_lineH->point1->setCoords(leftAxisRect->axis(QCPAxis::atBottom)->range().lower, y_val);
//        m_lineTracer1->m_lineH->point2->setCoords(rightAxisRect->axis(QCPAxis::atBottom)->range().upper, y_val);
    }
    else if(m_lineLTracer1->SelectedV)
    {
        m_lineLTracer1->updatePositionX(x_val);
    }
    else if(m_lineLTracer2->SelectedH)
    {
        m_lineLTracer2->updatePositionY(y_val);
        m_lineRTracer2->updatePositionY(y_val);
    }
    else if(m_lineLTracer2->SelectedV)
    {
        m_lineLTracer2->updatePositionX(x_val);
    }
    else if(m_lineLStLineTracer->SelectedV)
    {
        m_lineLStLineTracer->updatePositionX(x_val);
    }

    customPlot1->replot();
    customPlot2->replot();
}
void MainWindow::myRMouseMoveEvent(QMouseEvent *event)
{
    int x_pos = event->pos().x();
    int y_pos = event->pos().y();

    float x_val = customPlot2->xAxis->pixelToCoord(x_pos);
    float y_val = customPlot2->yAxis->pixelToCoord(y_pos);

    customPlot2->setInteractions(QCP::iRangeZoom);

    if(m_lineRTracerShort->SelectedH)
    {
        m_lineRTracerShort->updatePositionY(y_val);
        m_lineLDashTracer->updatePositionY(y_val);
    }
    else if(m_lineRTracerShort->SelectedV)
    {
        m_lineRTracerShort->updatePositionX(x_val);
    }
    else if(m_lineRTracerShort->SelectedLine)
    {
        m_lineRTracerShort->updatePosition(x_val,y_val);
        m_lineLDashTracer->updatePosition(x_val,y_val);
    }
    else if(m_lineRTracerShort->SelectedBottom)
    {
        m_lineRTracerShort->changeSize(y_val);
        m_lineLDashTracer->changeSize(y_val);
    }
    else if(m_lineRTracer1->SelectedH)
    {
        m_lineRTracer1->updatePositionY(y_val);
        m_lineLTracer1->updatePositionY(y_val);
//        m_lineTracer1->m_lineH->point1->setCoords(leftAxisRect->axis(QCPAxis::atBottom)->range().lower, y_val);
//        m_lineTracer1->m_lineH->point2->setCoords(rightAxisRect->axis(QCPAxis::atBottom)->range().upper, y_val);
    }
    else if(m_lineRTracer1->SelectedV)
    {
        m_lineRTracer1->updatePositionX(x_val);
    }
    else if(m_lineRTracer2->SelectedH)
    {
        m_lineRTracer2->updatePositionY(y_val);
        m_lineLTracer2->updatePositionY(y_val);
    }
    else if(m_lineRTracer2->SelectedV)
    {
        m_lineRTracer2->updatePositionX(x_val);
    }

    customPlot1->replot();
    customPlot2->replot();
}
