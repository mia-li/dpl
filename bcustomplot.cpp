#include "bcustomplot.h"

BCustomPlot::BCustomPlot(QWidget* widget):ThCustomPlot(widget)
{
    Initial();
    //colorbar=ColorBarSetting::Instance();
    connect(ColorBarSetting::Instance(),SIGNAL(Bscanupdatecolorbar(ColorBarSetting::ColorbarType)),this,SLOT(changeColorbar(ColorBarSetting::ColorbarType)));
}
BCustomPlot::~BCustomPlot()
{

}
void BCustomPlot::Initial()
{
    //坐标轴样式设计
    setBackground(Qt::darkGray); // 设置背景颜色
    axisRect()->setBackground(Qt::black);   // 设置QCPAxisRect背景颜色

    xAxis->setRange(0, 0.65);
    yAxis->setRange(0, 50);

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
    colorMap = new QCPColorMap(xAxis, yAxis);

    colorMap->data()->setRange(QCPRange(0,0.65), QCPRange(0, 50));

    //添加色标
    colorScale = new QCPColorScale(this);
    colorScale->setBarWidth(11);
    colorScale->setDataRange(QCPRange(0, 100));
    colorScale->axis()->setBasePen(QPen(Qt::white, 2));
    colorScale->axis()->setTickPen(QPen(Qt::white, 2));
    colorScale->axis()->setSubTickPen(QPen(Qt::white, 2));
    colorScale->axis()->setTickLabelColor(Qt::white);
    colorScale->axis()->setTickLengthIn(0);
    colorScale->axis()->setTickLengthOut(10);
    colorScale->axis()->setSubTickLengthIn(0);
    colorScale->axis()->setSubTickLengthOut(5);

    plotLayout()->addElement(0, 1, colorScale); // add it to the right of the main axis rect
    colorScale->setType(QCPAxis::atRight); // scale shall be vertical bar with tick/axis labels right (actually atRight is already the default)
    //将色标和颜色图关联起来，颜色图什么颜色，色标就是什么颜色
    colorMap->setColorScale(colorScale);

    //设置色条的颜色变化
    //gpHuge==ONDT_Corrosion
    //gpGrayscale == ONDT_RFTOFD
    //gpJet==ONDT_Amplitude
    gradient=QCPColorGradient::gpJet;  // 色条使用的颜色渐变
    colorMap->setGradient(gradient);
    // rescale the data dimension (color) such that all data points lie in the span visualized by the color gradient:
    colorMap->rescaleDataRange();

    // make sure the axis rect and color scale synchronize their bottom and top margins (so they line up):
    QCPMarginGroup *marginGroup = new QCPMarginGroup(this);
    axisRect()->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);
    colorScale->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);

    m_lineTracer1 = new XxwTraceLine(this);
    m_lineTracer1->setVisible(false);
    m_lineTracer2 = new XxwTraceLine(this,XxwTraceLine::Crosshair,QPen(Qt::green,2,Qt::SolidLine));
    m_lineTracer2->setVisible(false);
    m_lineTracerLine = new XxwTraceLine(this,XxwTraceLine::Line,QPen(Qt::red,2,Qt::DashLine));

    QCPTextElement *title=new QCPTextElement(this);
    title->setText("GROUP -1/B SCAN/[LAW-11/ANGLE-0.0]");
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
void BCustomPlot::changeColorbar(ColorBarSetting::ColorbarType colorbartype)
{
    //设置色条的颜色变化
    //gpHuge==ONDT_Corrosion
    //gpGrayscale == ONDT_RFTOFD
    //gpJet==ONDT_Amplitude


    if(colorbartype==ColorBarSetting::ColorbarType::ONDT_Amplitude)
    {
        gradient=QCPColorGradient::gpJet;
    }
    else if(colorbartype==ColorBarSetting::ColorbarType::ONDT_Corrosion)
    {
        gradient=QCPColorGradient::gpHues;
    }
    else
    {
        gradient=QCPColorGradient::gpGrayscale;
    }
    colorMap->setGradient(gradient);
    // rescale the data dimension (color) such that all data points lie in the span visualized by the color gradient:
    colorMap->rescaleDataRange();
    this->replot();
}

void BCustomPlot::updateY1Event(float y_val)
{
    qDebug("i'm b");
    m_lineTracer1->updatePositionY(y_val);
    m_lineTracer1->setVisible(true);
    this->replot();
}
void BCustomPlot::updateY2Event(float y_val)
{
    m_lineTracer2->updatePositionY(y_val);
    m_lineTracer2->setVisible(true);
    this->replot();
}
void BCustomPlot::updateX1Event(float x_val)
{
    m_lineTracer1->updatePositionX(x_val);
    m_lineTracer1->setVisible(true);
    this->replot();
}
void BCustomPlot::updateX2Event(float x_val)
{
    m_lineTracer2->updatePositionX(x_val);
    m_lineTracer2->setVisible(true);
    this->replot();
}
void BCustomPlot::updateX3Event(float x_val)
{
    m_lineTracerLine->updatePositionX(x_val);
    m_lineTracerLine->setVisible(true);
    this->replot();
}
void BCustomPlot::mouseDoubleClickEvent(QMouseEvent* e)
{

    float x = xAxis->pixelToCoord(e->pos().x());
    float y = yAxis->pixelToCoord(e->pos().y());

    if(clickNum%2 == 0)
    {
        m_lineTracer1->updatePosition(x,y);
        m_lineTracer1->setVisible(true);
        emit updateY1(y);
        emit updateX1(x);
    }
    else
    {
        m_lineTracer2->updatePosition(x,y);
        m_lineTracer2->setVisible(true);
        emit updateY2(y);
        emit updateX2(x);
    }
    clickNum++;
    replot();
}
void BCustomPlot::mousePressEvent(QMouseEvent *event)
{
    int x_pos = event->pos().x();
    int y_pos = event->pos().y();

    float x_val = xAxis->pixelToCoord(x_pos);
    float y_val = yAxis->pixelToCoord(y_pos);

    if(fabs(x_val-m_lineTracer1->getPositionX())<0.1)
    {
//        customPlot->cursor().setShape(Qt::SizeVerCursor);
        m_lineTracer1->SelectedV=true;
    }
    else if(fabs(x_val-m_lineTracer2->getPositionX())<0.1)
    {
//        customPlot->cursor().setShape(Qt::SizeVerCursor);
        m_lineTracer2->SelectedV=true;
    }
    else if(fabs(x_val-m_lineTracerLine->getPositionX())<0.1)
    {
        m_lineTracerLine->SelectedV=true;
    }
    else if(fabs(y_val-m_lineTracer1->getPositionY())<1)
    {
//        customPlot->cursor().setShape(Qt::SizeHorCursor);
        m_lineTracer1->SelectedH=true;
    }
    else if(fabs(y_val-m_lineTracer2->getPositionY())<1)
    {
//        customPlot->cursor().setShape(Qt::SizeHorCursor);
        m_lineTracer2->SelectedH=true;
    }
    else
    {
        emit SetShortLineVis();
        //m_lineRTracerShort->setVisible(false);
        m_lineTracer1->SelectedH=false;
        m_lineTracer2->SelectedH=false;
        m_lineTracer1->SelectedV=false;
        m_lineTracer2->SelectedV=false;
        m_lineTracerLine->SelectedV=false;
        replot();
    }
}
void BCustomPlot::mouseReleaseEvent(QMouseEvent *event)
{
    //customPlot1->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom);

    m_lineTracer1->SelectedH=false;
    m_lineTracer2->SelectedH=false;
    m_lineTracer1->SelectedV=false;
    m_lineTracer2->SelectedV=false;
    m_lineTracerLine->SelectedV=false;
}
void BCustomPlot::mouseMoveEvent(QMouseEvent *event)
{
    int x_pos = event->pos().x();
    int y_pos = event->pos().y();

    float x_val = xAxis->pixelToCoord(x_pos);
    float y_val = yAxis->pixelToCoord(y_pos);

    setInteractions(QCP::iRangeZoom);

    if(m_lineTracer1->SelectedH)
    {
        m_lineTracer1->updatePositionY(y_val);
        emit updateY1(y_val);
    }
    else if(m_lineTracer1->SelectedV)
    {
        m_lineTracer1->updatePositionX(x_val);
        emit updateX1(x_val);
    }
    else if(m_lineTracer2->SelectedH)
    {
        m_lineTracer2->updatePositionY(y_val);
        emit updateY2(y_val);
    }
    else if(m_lineTracer2->SelectedV)
    {
        m_lineTracer2->updatePositionX(x_val);
        emit updateX2(x_val);
    }
    else if(m_lineTracerLine->SelectedV)
    {
        m_lineTracerLine->updatePositionX(x_val);
        emit updateX3(x_val);
    }
    replot();
}
