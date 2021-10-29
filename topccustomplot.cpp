#include "topccustomplot.h"

TopcCustomPlot::TopcCustomPlot(QWidget* widget):QCustomPlot(widget)
{
    Initial();


}
void TopcCustomPlot::Initial()
{
    //坐标轴样式设计
    setBackground(Qt::darkGray); // 设置背景颜色
    axisRect()->setBackground(Qt::white);   // 设置QCPAxisRect背景颜色

    xAxis->setRange(0, 0.65);
    yAxis->setRange(1, 7);

    xAxis->setBasePen(QPen(Qt::white, 2));  // 轴线的画笔
    xAxis->setTickPen(QPen(Qt::white, 2));  // 轴刻度线的画笔
    xAxis->setSubTickPen(QPen(Qt::white, 2)); // 轴子刻度线的画笔
    xAxis->setTickLabelColor(Qt::white);  // 轴刻度文字颜色
    xAxis->setTickLengthIn(1);       // 轴线内刻度的长度
    xAxis->setTickLengthOut(10);      // 轴线外刻度的长度
    xAxis->setSubTickLengthOut(5);     // 轴线外子刻度的长度
    yAxis->setRangeReversed(true);
    yAxis->setBasePen(QPen(Qt::white, 2));  // 轴线的画笔
    yAxis->setTickPen(QPen(Qt::white, 2));  // 轴刻度线的画笔
    yAxis->setSubTickPen(QPen(Qt::white, 2)); // 轴子刻度线的画笔
    yAxis->setTickLabelColor(Qt::white);  // 轴刻度文字颜色
    yAxis->setTickLengthIn(1);       // 轴线内刻度的长度
    yAxis->setTickLengthOut(10);      // 轴线外刻度的长度
    yAxis->setSubTickLengthOut(5);

//色标
    QCPColorMap *colorMap = new QCPColorMap(xAxis, yAxis);
    colorMap->data()->setRange(QCPRange(0, 7), QCPRange(0, 50));
    QCPColorScale *colorScale = new QCPColorScale(this);
    colorScale->setBarWidth(11);
    colorScale->setDataRange(QCPRange(0, 100));
//    colorScale->axis()->setTickLabels(false);
//    colorScale->axis()->setTickLabelFont(QFont(("Arial"),10));
//    colorScale->axis()->setLabelFont(QFont(("Arial"), 10));
    colorScale->axis()->setBasePen(QPen(Qt::white, 2));
    colorScale->axis()->setTickPen(QPen(Qt::white, 2));
    colorScale->axis()->setSubTickPen(QPen(Qt::white, 2));
    colorScale->axis()->setTickLabelColor(Qt::white);
    colorScale->axis()->setTickLengthIn(0);
    colorScale->axis()->setTickLengthOut(10);
    colorScale->axis()->setSubTickLengthIn(0);
    colorScale->axis()->setSubTickLengthOut(5);

//    colorScale->axis()
    plotLayout()->addElement(0, 1, colorScale); // add it to the right of the main axis rect
    colorScale->setType(QCPAxis::atRight); // scale shall be vertical bar with tick/axis labels right (actually atRight is already the default)
    colorMap->setColorScale(colorScale);

    //设置色条的颜色变化
    QCPColorGradient gradient;  // 色条使用的颜色渐变
    gradient.setColorInterpolation(QCPColorGradient::ciRGB);
    gradient.setColorStopAt(0, QColor(255, 255, 255));
    gradient.setColorStopAt(0.15, QColor(10, 10, 190));
    gradient.setColorStopAt(0.33, QColor(100, 140, 100));
    gradient.setColorStopAt(0.6, QColor(255, 255, 40));
    gradient.setColorStopAt(0.85, QColor(255, 100, 0));
    gradient.setColorStopAt(1, QColor(190, 10, 10));
    colorMap->setGradient(gradient);
    // rescale the data dimension (color) such that all data points lie in the span visualized by the color gradient:
    colorMap->rescaleDataRange();

    // make sure the axis rect and color scale synchronize their bottom and top margins (so they line up):
    QCPMarginGroup *marginGroup = new QCPMarginGroup(this);
    axisRect()->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);
    colorScale->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);

    m_lineTracerLine1 = new XxwTraceLine(this);
    m_lineTracerLine1->setVisible(false);
    m_lineTracerLine2 = new XxwTraceLine(this,XxwTraceLine::Line,QPen(Qt::green,2,Qt::SolidLine));
    m_lineTracerLine2->setVisible(false);
    m_lineTracerLine3 = new XxwTraceLine(this,XxwTraceLine::Line,QPen(Qt::red,2,Qt::DashLine));

    QCPTextElement *title=new QCPTextElement(this);
    title->setText("GROUP -1/TOPC SCAN/[FRAME-342]");
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
void TopcCustomPlot::updateX1Event(float x_val)
{
    m_lineTracerLine1->updatePositionX(x_val);
    m_lineTracerLine1->setVisible(true);
    this->replot();
}
void TopcCustomPlot::updateX2Event(float x_val)
{
    m_lineTracerLine2->updatePositionX(x_val);
    m_lineTracerLine2->setVisible(true);
    this->replot();
}
void TopcCustomPlot::updateX3Event(float x_val)
{
    m_lineTracerLine3->updatePositionX(x_val);
    m_lineTracerLine3->setVisible(true);
    this->replot();
}
void TopcCustomPlot::mouseDoubleClickEvent(QMouseEvent* e)
{

//    float x = xAxis->pixelToCoord(e->pos().x());
//    float y = yAxis->pixelToCoord(e->pos().y());

//    if(clickNum%2 == 0)
//    {
//        m_lineTracer1->updatePosition(x,y);
//        m_lineTracer1->setVisible(true);
////        m_lineRTracer1->updatePositionY(y);
////        m_lineRTracer1->setVisible(true);
//    }
//    else
//    {
//        m_lineTracer2->updatePosition(x,y);
//        m_lineTracer2->setVisible(true);
////        m_lineRTracer2->updatePositionY(y);
////        m_lineRTracer2->setVisible(true);
//    }
//    clickNum++;
//    replot();
}
void TopcCustomPlot::mousePressEvent(QMouseEvent *event)
{
    int x_pos = event->pos().x();
    int y_pos = event->pos().y();

    float x_val = xAxis->pixelToCoord(x_pos);
    float y_val = yAxis->pixelToCoord(y_pos);

    if(fabs(x_val-m_lineTracerLine1->getPositionX())<1.0)
    {
//        customPlot->cursor().setShape(Qt::SizeVerCursor);
        m_lineTracerLine1->SelectedV=true;
    }
    else if(fabs(x_val-m_lineTracerLine2->getPositionX())<1.0)
    {
//        customPlot->cursor().setShape(Qt::SizeVerCursor);
        m_lineTracerLine2->SelectedV=true;
    }
    else if(fabs(x_val-m_lineTracerLine3->getPositionX())<1.0)
    {
        m_lineTracerLine3->SelectedV=true;
    }
    else
    {
        SetShortLineVis();
        m_lineTracerLine1->SelectedV=false;
        m_lineTracerLine2->SelectedV=false;
        m_lineTracerLine3->SelectedV=false;
        replot();
    }
}
void TopcCustomPlot::mouseReleaseEvent(QMouseEvent *event)
{
    m_lineTracerLine1->SelectedV=false;
    m_lineTracerLine2->SelectedV=false;
    m_lineTracerLine3->SelectedV=false;
}
void TopcCustomPlot::mouseMoveEvent(QMouseEvent *event)
{
    int x_pos = event->pos().x();
    int y_pos = event->pos().y();

    float x_val = xAxis->pixelToCoord(x_pos);
    float y_val = yAxis->pixelToCoord(y_pos);

    setInteractions(QCP::iRangeZoom);

    if(m_lineTracerLine1->SelectedV)
    {
        m_lineTracerLine1->updatePositionX(x_val);
        updateX1(x_val);
    }
    else if(m_lineTracerLine2->SelectedV)
    {
        m_lineTracerLine2->updatePositionX(x_val);
        updateX2(x_val);
    }
    else if(m_lineTracerLine3->SelectedV)
    {
        m_lineTracerLine3->updatePositionX(x_val);
        updateX3(x_val);
    }
    replot();
}
