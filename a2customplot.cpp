#include "a2customplot.h"

A2CustomPlot::A2CustomPlot(QWidget* widget):QCustomPlot(widget)
{
    Initial();


}
void A2CustomPlot::Initial()
{
    //坐标轴样式设计
    setBackground(Qt::darkGray); // 设置背景颜色
    axisRect()->setBackground(Qt::white);   // 设置QCPAxisRect背景颜色

    xAxis->setRange(0, 50);
    yAxis->setRange(0, 100);

    xAxis->setBasePen(QPen(Qt::white, 2));  // 轴线的画笔
    xAxis->setTickPen(QPen(Qt::white, 2));  // 轴刻度线的画笔
    xAxis->setSubTickPen(QPen(Qt::white, 2)); // 轴子刻度线的画笔
    xAxis->setTickLabelColor(Qt::white);  // 轴刻度文字颜色
    xAxis->setTickLengthIn(1);       // 轴线内刻度的长度
    xAxis->setTickLengthOut(10);      // 轴线外刻度的长度
    xAxis->setSubTickLengthOut(5);     // 轴线外子刻度的长度

    yAxis->setBasePen(QPen(Qt::white, 2));  // 轴线的画笔
    yAxis->setTickPen(QPen(Qt::white, 2));  // 轴刻度线的画笔
    yAxis->setSubTickPen(QPen(Qt::white, 2)); // 轴子刻度线的画笔
    yAxis->setTickLabelColor(Qt::white);  // 轴刻度文字颜色
    yAxis->setTickLengthIn(1);       // 轴线内刻度的长度
    yAxis->setTickLengthOut(10);      // 轴线外刻度的长度
    yAxis->setSubTickLengthOut(5);

    m_lineTracer1 = new XxwTraceLine(this,XxwTraceLine::Crosshair,QPen(Qt::red,2,Qt::SolidLine),true);
    m_lineTracer1->setVisible(false);
    m_lineTracer2 = new XxwTraceLine(this,XxwTraceLine::Crosshair,QPen(Qt::green,2,Qt::SolidLine),true);
    m_lineTracer2->setVisible(false);
    m_lineTracerShortLine = new XxwTraceLine(this,XxwTraceLine::ShortLine2,QPen(Qt::red,2,Qt::DashLine));
    m_lineTracerShortLine->setVisible(false);

    QCPTextElement *title=new QCPTextElement(this);
    title->setText("GROUP -1/A SCAN/[LAW-11/ANGLE-0.0]");
    title->setTextFlags(Qt::AlignLeft|Qt::AlignBottom);
    title->setTextColor(Qt::red);
    title->setFont(QFont("sans",12,QFont::Thin));
    plotLayout()->insertRow(0);
    plotLayout()->addElement(0,0,title);
    plotLayout()->setRowSpacing(0);
   //立即刷新
    rescaleAxes();//自适应大小
    replot();
}
void A2CustomPlot::updateX1Event(float y_val)
{
    m_lineTracer1->updatePositionX(y_val);
    m_lineTracer1->setVisible(true);
    this->replot();
}
void A2CustomPlot::updateX2Event(float y_val)
{
    m_lineTracer2->updatePositionX(y_val);
    m_lineTracer2->setVisible(true);
    this->replot();
}
void A2CustomPlot::SetShortLineVisEvent()
{
    m_lineTracerShortLine->setVisible(false);
    this->replot();
}
void A2CustomPlot::mouseDoubleClickEvent(QMouseEvent* e)
{

    float x = xAxis->pixelToCoord(e->pos().x());
    float y = yAxis->pixelToCoord(e->pos().y());

    if(clickNum%2 == 0)
    {
        m_lineTracer1->updatePosition(x,y);
        m_lineTracer1->setVisible(true);
        updateY1(x);
//        m_lineRTracer1->updatePositionY(y);
//        m_lineRTracer1->setVisible(true);
    }
    else
    {
        m_lineTracer2->updatePosition(x,y);
        m_lineTracer2->setVisible(true);
        updateY2(x);
//        m_lineRTracer2->updatePositionY(y);
//        m_lineRTracer2->setVisible(true);
    }
    clickNum++;
    replot();
}
void A2CustomPlot::mousePressEvent(QMouseEvent *event)
{
    int x_pos = event->pos().x();
    int y_pos = event->pos().y();

    float x_val = xAxis->pixelToCoord(x_pos);
    float y_val = yAxis->pixelToCoord(y_pos);

    if(fabs(x_val-m_lineTracer1->getPositionX())<1.0)
    {
//        customPlot->cursor().setShape(Qt::SizeVerCursor);
        m_lineTracer1->SelectedV=true;
    }
    else if(fabs(x_val-m_lineTracer2->getPositionX())<1.0)
    {
//        customPlot->cursor().setShape(Qt::SizeVerCursor);
        m_lineTracer2->SelectedV=true;
    }
    else if(fabs(y_val-m_lineTracer1->getPositionY())<1.0)
    {
//        customPlot->cursor().setShape(Qt::SizeHorCursor);
        m_lineTracer1->SelectedH=true;
    }
    else if(fabs(y_val-m_lineTracer2->getPositionY())<1.0)
    {
//        customPlot->cursor().setShape(Qt::SizeHorCursor);
        m_lineTracer2->SelectedH=true;
    }
    else if(fabs(y_val-m_lineTracerShortLine->getPositionY())<1.0&&(x_val>=(m_lineTracerShortLine->getPositionX()-m_lineTracerShortLine->m_size/2.0))&&(x_val<=(m_lineTracerShortLine->getPositionX()+m_lineTracerShortLine->m_size/2.0)))
    {
        if(!m_lineTracerShortLine->m_visible)
        {
            m_lineTracerShortLine->setVisible(true);
        }
        SetDashLineVis();
        m_lineTracerShortLine->SelectedLine=true;
    }
    else if(m_lineTracerShortLine->m_visible&&fabs(x_val-m_lineTracerShortLine->getPositionX()+m_lineTracerShortLine->m_size/2.0)<1.0)
    {
        m_lineTracerShortLine->SelectedH=true;
    }
    else if(m_lineTracerShortLine->m_visible&&fabs(y_val-m_lineTracerShortLine->getPositionY())<1.0)
    {
        m_lineTracerShortLine->SelectedV=true;
    }
    else if(m_lineTracerShortLine->m_visible&&fabs(x_val-m_lineTracerShortLine->getPositionX()-m_lineTracerShortLine->m_size/2.0)<1.0)
    {
        m_lineTracerShortLine->SelectedBottom=true;
    }
    else
    {
//        customPlot->cursor().setShape(Qt::ArrowCursor);
        m_lineTracerShortLine->setVisible(false);
        m_lineTracer1->SelectedH=false;
        m_lineTracer2->SelectedH=false;
        m_lineTracer1->SelectedV=false;
        m_lineTracer2->SelectedV=false;
        m_lineTracerShortLine->SelectedH=false;
        m_lineTracerShortLine->SelectedV=false;
        m_lineTracerShortLine->SelectedBottom=false;
        m_lineTracerShortLine->SelectedLine=false;

    }
}
void A2CustomPlot::mouseReleaseEvent(QMouseEvent *event)
{
    m_lineTracer1->SelectedH=false;
    m_lineTracer2->SelectedH=false;
    m_lineTracer1->SelectedV=false;
    m_lineTracer2->SelectedV=false;
    m_lineTracerShortLine->SelectedH=false;
    m_lineTracerShortLine->SelectedV=false;
    m_lineTracerShortLine->SelectedBottom=false;
    m_lineTracerShortLine->SelectedLine=false;
}
void A2CustomPlot::mouseMoveEvent(QMouseEvent *event)
{
    int x_pos = event->pos().x();
    int y_pos = event->pos().y();

    float x_val = xAxis->pixelToCoord(x_pos);
    float y_val = yAxis->pixelToCoord(y_pos);

    setInteractions(QCP::iRangeZoom);

    if(m_lineTracerShortLine->SelectedH)
    {
        m_lineTracerShortLine->updatePositionX(x_val);
        updateDashY(x_val);
       // m_lineLDashTracer->updatePositionY(y_val);
    }
    else if(m_lineTracerShortLine->SelectedV)
    {
        m_lineTracerShortLine->updatePositionY(y_val);
    }
    else if(m_lineTracerShortLine->SelectedLine)
    {
        m_lineTracerShortLine->updatePosition(x_val,y_val);
        updateDash(x_val,y_val);
        //m_lineLDashTracer->updatePosition(x_val,y_val);
    }
    else if(m_lineTracerShortLine->SelectedBottom)
    {
        m_lineTracerShortLine->changeSize(x_val);
        changeDashSize(x_val);
        //m_lineLDashTracer->changeSize(y_val);
    }
    else if(m_lineTracer1->SelectedH)
    {
        m_lineTracer1->updatePositionY(y_val);

    }
    else if(m_lineTracer1->SelectedV)
    {
        m_lineTracer1->updatePositionX(x_val);
        updateY1(x_val);
    }
    else if(m_lineTracer2->SelectedH)
    {
        m_lineTracer2->updatePositionY(y_val);
    }
    else if(m_lineTracer2->SelectedV)
    {
        m_lineTracer2->updatePositionX(x_val);
        updateY2(x_val);
    }

    replot();
}
