#include "xxwtraceline.h"

XxwTraceLine::XxwTraceLine(QCustomPlot *_plot,LineType _type,QColor _color, double size, QObject *parent)
    : QObject(parent),
      m_type(_type),
      m_color(_color),
      m_size(size),
      m_plot(_plot)
{
    if(Crosshair == m_type)
    {
        m_lineV = Q_NULLPTR;
        m_lineH = Q_NULLPTR;
    }
    else if(ShortLine == m_type)
    {
        m_lineV = Q_NULLPTR;
        m_lineH = Q_NULLPTR;
        m_lineBottom = Q_NULLPTR;
        m_lineShort = Q_NULLPTR;
    }
    else if(Line == m_type)
    {
        m_lineV = Q_NULLPTR;
    }
    else
    {
        m_lineH = Q_NULLPTR;
        m_lineBottom = Q_NULLPTR;
    }
    initLine();
}

XxwTraceLine::~XxwTraceLine()
{
    if(m_plot)
    {
        if (m_lineV)
            m_plot->removeItem(m_lineV);
        if (m_lineH)
            m_plot->removeItem(m_lineH);
        if (m_lineBottom)
            m_plot->removeItem(m_lineBottom);
        if (m_lineShort)
            m_plot->removeItem(m_lineShort);
    }
}
void XxwTraceLine::setVisible(bool vis)
{
    m_visible=vis;
    if(Crosshair == m_type)
    {
        if(m_lineV)
            m_lineV->setVisible(vis);
        if(m_lineH)
            m_lineH->setVisible(vis);
        m_labelx->setVisible(vis);
        m_labely->setVisible(vis);
    }
    else if(ShortLine == m_type)
    {
        if(m_lineV)
            m_lineV->setVisible(vis);
        if(m_lineH)
            m_lineH->setVisible(vis);
        if(m_lineBottom)
            m_lineBottom->setVisible(vis);
        m_labelx->setVisible(vis);
        m_labely->setVisible(vis);
        m_labelx1->setVisible(vis);
    }
    else if(DashLine == m_type)
    {
        if(m_lineH)
            m_lineH->setVisible(vis);
        if(m_lineBottom)
            m_lineBottom->setVisible(vis);
    }
}

void XxwTraceLine::initLine()
{
    if(m_plot)
    {
        QPen linesPen;
        if(Crosshair == m_type)
        {
            linesPen=QPen(m_color, 2, Qt::SolidLine);
            m_lineV = new QCPItemStraightLine(m_plot);//垂直线
            m_lineV->setLayer("overlay");
            m_lineV->setPen(linesPen);
            m_lineV->setClipToAxisRect(true);
            m_lineV->point1->setCoords(0, 0);
            m_lineV->point2->setCoords(0, 1);

            m_lineH = new QCPItemStraightLine(m_plot);//水平线
            m_lineH->setLayer("overlay");
            m_lineH->setPen(linesPen);
            m_lineH->setClipToAxisRect(true);
            m_lineH->point1->setCoords(0, 0);
            m_lineH->point2->setCoords(0, 0);

            //游标说明
            m_labelx = new QCPItemText(m_plot); //生成游标说明
            m_labelx->setLayer("overlay");//设置图层为overlay，因为需要频繁刷新
            m_labelx->setPen(linesPen);//设置游标说明颜色
    //        m_labelx->setBrush(QBrush(Qt::gray));
            m_labelx->setPositionAlignment(Qt::AlignTop|Qt::AlignLeft);//文字布局：顶、左对齐

            m_labely = new QCPItemText(m_plot); //生成游标说明
            m_labely->setLayer("overlay");//设置图层为overlay，因为需要频繁刷新
            m_labely->setPen(linesPen);//设置游标说明颜色
    //        m_labely->setBrush(QBrush(Qt::gray));
            m_labely->setPositionAlignment(Qt::AlignTop|Qt::AlignLeft);//文字布局：顶、左对齐
        }
        else if(ShortLine==m_type)
        {
            linesPen=QPen(m_color, 2, Qt::DashLine);
            m_xValue=5;
            m_yValue=5;

            m_lineV = new QCPItemStraightLine(m_plot);//垂直线
            m_lineV->setLayer("overlay");
            m_lineV->setPen(linesPen);
            m_lineV->setClipToAxisRect(true);
            m_lineV->point1->setCoords(m_xValue, m_plot->yAxis->range().lower);
            m_lineV->point2->setCoords(m_xValue, m_plot->yAxis->range().lower);

            m_lineH = new QCPItemStraightLine(m_plot);//水平线
            m_lineH->setLayer("overlay");
            m_lineH->setPen(linesPen);
            m_lineH->setClipToAxisRect(true);
            m_lineH->point1->setCoords(m_plot->xAxis->range().lower, m_yValue-m_size);
            m_lineH->point2->setCoords(m_plot->xAxis->range().upper, m_yValue-m_size);

            m_lineBottom = new QCPItemStraightLine(m_plot);//水平底线
            m_lineBottom->setLayer("overlay");
            m_lineBottom->setPen(linesPen);
            m_lineBottom->setClipToAxisRect(true);
            m_lineBottom->point1->setCoords(m_plot->xAxis->range().lower, m_yValue+m_size);
            m_lineBottom->point2->setCoords(m_plot->xAxis->range().upper, m_yValue+m_size);

            m_lineShort = new QCPItemLine(m_plot);//多加一条线段
            m_lineShort->setLayer("overlay");
            m_lineShort->setPen(QPen(m_color, 2, Qt::SolidLine));
            m_lineShort->setClipToAxisRect(true);
            m_lineShort->start->setCoords(m_xValue, m_yValue);
            m_lineShort->end->setCoords(m_xValue, m_yValue+m_size);
            m_lineShort->setHead(QCPLineEnding::esBar);
            m_lineShort->setTail(QCPLineEnding::esBar);
            m_lineShort->setVisible(true);

            //游标说明
            m_labelx = new QCPItemText(m_plot); //生成游标说明
            m_labelx->setLayer("overlay");//设置图层为overlay，因为需要频繁刷新
            m_labelx->setPen(linesPen);//设置游标说明颜色
    //        m_labelx->setBrush(QBrush(Qt::gray));
            m_labelx->setPositionAlignment(Qt::AlignTop|Qt::AlignLeft);//文字布局：顶、左对齐

            m_labely = new QCPItemText(m_plot); //生成游标说明
            m_labely->setLayer("overlay");//设置图层为overlay，因为需要频繁刷新
            m_labely->setPen(linesPen);//设置游标说明颜色
    //        m_labely->setBrush(QBrush(Qt::gray));
            m_labely->setPositionAlignment(Qt::AlignTop|Qt::AlignLeft);//文字布局：顶、左对齐

            m_labelx1 = new QCPItemText(m_plot); //线段旁边的游标说明
            m_labelx1->setLayer("overlay");//设置图层为overlay，因为需要频繁刷新
            m_labelx1->setPositionAlignment(Qt::AlignTop|Qt::AlignLeft);//文字布局：顶、左对齐

        }
        else if(Line==m_type)
        {
            m_xValue=0;
            m_yValue=0;
            m_lineV = new QCPItemStraightLine(m_plot);//垂直线
            m_lineV->setLayer("overlay");
            m_lineV->setPen(QPen(Qt::red, 2, Qt::SolidLine));
            m_lineV->setClipToAxisRect(true);
            m_lineV->point1->setCoords(0, m_plot->yAxis->range().lower);
            m_lineV->point2->setCoords(0, m_plot->yAxis->range().upper);
            m_lineV->setVisible(true);

            m_labelx = new QCPItemText(m_plot); //生成游标说明
            m_labelx->setLayer("overlay");//设置图层为overlay，因为需要频繁刷新
            m_labelx->setPen(QPen(Qt::white, 2, Qt::SolidLine));//设置游标说明颜色
    //        m_labely->setBrush(QBrush(Qt::gray));
            m_labelx->setPositionAlignment(Qt::AlignTop|Qt::AlignLeft);//文字布局：顶、左对齐
            m_labelx->position->setCoords(0,m_plot->yAxis->range().lower);
            m_labelx->setText("v0");
        }
        else
        {

            m_lineH = new QCPItemStraightLine(m_plot);//水平线
            m_lineH->setLayer("overlay");
            m_lineH->setPen(QPen(Qt::red, 2, Qt::DashLine));
            m_lineH->setClipToAxisRect(true);
            m_lineH->point1->setCoords(0, 0);
            m_lineH->point2->setCoords(0,0);

            m_lineBottom = new QCPItemStraightLine(m_plot);//水平底线
            m_lineBottom->setLayer("overlay");
            m_lineBottom->setPen(QPen(Qt::red, 2, Qt::DashLine));
            m_lineBottom->setClipToAxisRect(true);
            m_lineBottom->point1->setCoords(0, 0);
            m_lineBottom->point2->setCoords(0, 0);

        }

    }
}

void XxwTraceLine::updatePosition(float xValue, float yValue)
{
    m_xValue=xValue;
    m_yValue=yValue;
    if(Crosshair == m_type)
    {
        m_lineV->point1->setCoords(xValue, m_plot->yAxis->range().lower);
        m_lineV->point2->setCoords(xValue, m_plot->yAxis->range().upper);

//        m_labelx->position->setParentAnchor(m_lineV->point2);
        m_labelx->position->setCoords(xValue,m_plot->yAxis->range().lower);
        m_labelx->setText(QString::number(xValue,'f',1));

        m_lineH->point1->setCoords(m_plot->xAxis->range().lower, yValue);
        m_lineH->point2->setCoords(m_plot->xAxis->range().upper, yValue);

//        m_labely->position->setParentAnchor(m_lineH->point1);
        m_labely->position->setCoords(m_plot->xAxis->range().lower,yValue);
        m_labely->setText(QString::number(yValue,'f',2));

    }
    else if(ShortLine==m_type)
    {
        //虚线
        m_lineV->point1->setCoords(xValue, m_plot->yAxis->range().lower); //垂直线
        m_lineV->point2->setCoords(xValue, m_plot->yAxis->range().upper);

        m_lineBottom->point1->setCoords(m_plot->xAxis->range().lower, m_yValue+m_size/2.0); //水平底线
        m_lineBottom->point2->setCoords(m_plot->xAxis->range().upper, m_yValue+m_size/2.0);

//        m_labely->position->setParentAnchor(m_lineH->point1);
        m_labely->position->setCoords(m_plot->xAxis->range().lower,m_yValue+m_size/2.0); //水平底线游标说明
        m_labely->setText(QString::number(m_yValue+m_size/2.0,'f',1));

        m_lineH->point1->setCoords(m_plot->xAxis->range().lower, m_yValue-m_size/2.0); //水平线
        m_lineH->point2->setCoords(m_plot->xAxis->range().upper, m_yValue-m_size/2.0);

        m_labelx->position->setCoords(m_plot->xAxis->range().lower,m_yValue-m_size/2.0);
        m_labelx->setText(QString::number(m_yValue-m_size/2.0,'f',1));

         //线段
        m_lineShort->start->setCoords(xValue, m_yValue-m_size/2.0);
        m_lineShort->end->setCoords(xValue, m_yValue+m_size/2.0);

        m_labelx1->position->setCoords(xValue,m_yValue-m_size/2.0);
        m_labelx1->setText(QString::number(xValue,'f',0)+'%');

    }
    else if(DashLine==m_type)
    {
        m_lineBottom->point1->setCoords(m_plot->xAxis->range().lower, m_yValue+m_size/2.0); //水平底线
        m_lineBottom->point2->setCoords(m_plot->xAxis->range().upper, m_yValue+m_size/2.0);

        m_lineH->point1->setCoords(m_plot->xAxis->range().lower, m_yValue-m_size/2.0); //水平线
        m_lineH->point2->setCoords(m_plot->xAxis->range().upper, m_yValue-m_size/2.0);
    }
}
void XxwTraceLine::updatePositionX(float xValue)
{
    m_xValue=xValue;
    if(Crosshair == m_type)
    {
        m_lineV->point1->setCoords(xValue, m_plot->yAxis->range().lower);
        m_lineV->point2->setCoords(xValue, m_plot->yAxis->range().upper);

        m_labelx->position->setCoords(xValue,m_plot->yAxis->range().lower);
        m_labelx->setText(QString::number(xValue,'f',1));
    }
    else if(ShortLine==m_type)
    {
        //虚线
        m_lineV->point1->setCoords(xValue, m_plot->yAxis->range().lower); //垂直线
        m_lineV->point2->setCoords(xValue, m_plot->yAxis->range().upper);

         //线段
        m_lineShort->start->setCoords(xValue, m_yValue-m_size/2.0);
        m_lineShort->end->setCoords(xValue, m_yValue+m_size/2.0);

        m_labelx1->position->setCoords(xValue,m_yValue-m_size/2.0);
        m_labelx1->setText(QString::number(xValue,'f',0)+'%');
    }
    else if(Line==m_type)
    {
        //虚线
        m_lineV->point1->setCoords(xValue, m_plot->yAxis->range().lower); //垂直线
        m_lineV->point2->setCoords(xValue, m_plot->yAxis->range().upper);

        m_labelx->position->setCoords(xValue,m_plot->yAxis->range().lower);
        m_labelx->setText("v"+QString::number(xValue,'f',0));
    }

}
void XxwTraceLine::updatePositionY(float yValue)
{
    m_yValue=yValue+m_size/2.0;
    if(Crosshair == m_type)
    {
        m_lineH->point1->setCoords(m_plot->xAxis->range().lower, yValue);
        m_lineH->point2->setCoords(m_plot->xAxis->range().upper, yValue);

        m_labely->position->setCoords(m_plot->xAxis->range().lower,yValue);
        m_labely->setText(QString::number(yValue,'f',2));
    }
    else if(ShortLine==m_type)
    {
        m_lineH->point1->setCoords(m_plot->xAxis->range().lower, m_yValue-m_size/2.0); //水平线
        m_lineH->point2->setCoords(m_plot->xAxis->range().upper, m_yValue-m_size/2.0);

        m_labelx->position->setCoords(m_plot->xAxis->range().lower,m_yValue-m_size/2.0);
        m_labelx->setText(QString::number(m_yValue-m_size/2.0,'f',1));

        m_lineBottom->point1->setCoords(m_plot->xAxis->range().lower, m_yValue+m_size/2.0); //水平底线
        m_lineBottom->point2->setCoords(m_plot->xAxis->range().upper, m_yValue+m_size/2.0);

        m_labely->position->setCoords(m_plot->xAxis->range().lower,m_yValue+m_size/2.0);
        m_labely->setText(QString::number(m_yValue+m_size/2.0,'f',1));

         //线段
        m_lineShort->start->setCoords(m_xValue,  m_yValue-m_size/2.0);
        m_lineShort->end->setCoords(m_xValue,  m_yValue+m_size/2.0);

        m_labelx1->position->setCoords(m_xValue,m_yValue-m_size/2.0);
        m_labelx1->setText(QString::number(m_xValue,'f',0)+'%');

    }
    else if(DashLine==m_type)
    {
        m_lineH->point1->setCoords(m_plot->xAxis->range().lower, m_yValue-m_size/2.0); //水平线
        m_lineH->point2->setCoords(m_plot->xAxis->range().upper, m_yValue-m_size/2.0);

        m_lineBottom->point1->setCoords(m_plot->xAxis->range().lower, m_yValue+m_size/2.0); //水平底线
        m_lineBottom->point2->setCoords(m_plot->xAxis->range().upper, m_yValue+m_size/2.0);
    }
}
void XxwTraceLine::changeSize(float yValue)
{
    if(yValue<(m_yValue-m_size/2.0))
        return;
    m_size=yValue-m_yValue+m_size/2.0;
    m_yValue=yValue-m_size/2.0;

    if(ShortLine==m_type)
    {
        m_lineBottom->point1->setCoords(m_plot->xAxis->range().lower, m_yValue+m_size/2.0); //水平底线
        m_lineBottom->point2->setCoords(m_plot->xAxis->range().upper, m_yValue+m_size/2.0);

        m_labely->position->setCoords(m_plot->xAxis->range().lower,m_yValue+m_size/2.0);
        m_labely->setText(QString::number(m_yValue+m_size/2.0,'f',1));

         //线段
        m_lineShort->start->setCoords(m_xValue,  m_yValue-m_size/2.0);
        m_lineShort->end->setCoords(m_xValue,  m_yValue+m_size/2.0);

        m_labelx1->position->setCoords(m_xValue,m_yValue-m_size/2.0);
        m_labelx1->setText(QString::number(m_xValue,'f',0)+'%');
    }
    else
    {
        m_lineBottom->point1->setCoords(m_plot->xAxis->range().lower, m_yValue+m_size/2.0); //水平底线
        m_lineBottom->point2->setCoords(m_plot->xAxis->range().upper, m_yValue+m_size/2.0);
    }

}
