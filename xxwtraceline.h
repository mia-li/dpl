#ifndef XXWTRACELINE_H
#define XXWTRACELINE_H

#include <QObject>
#include "qcustomplot.h"
///
/// \brief The XxwCrossLine class:用于显示鼠标移动过程中的鼠标位置的直线
///
class XxwTraceLine : public QObject
{
public:
    enum LineType
    {
        Crosshair,//十字线
        ShortLine, //线段
        Line, //左边的直线
        DashLine //双虚线
    };
    explicit XxwTraceLine(QCustomPlot *_plot, LineType _type = Crosshair,QColor _color=Qt::red,double size=20, QObject *parent = Q_NULLPTR);
    ~XxwTraceLine();
    void initLine();
    void updatePosition(float xValue, float yValue);
    void updatePositionX(float xValue);
    void updatePositionY(float yValue);
    void changeSize(float yValue);
    void setVisible(bool vis);

    double getPositionX()const{return m_xValue;}
    double getPositionY()const{return m_yValue;}

    bool SelectedV=false;
    bool SelectedH=false;
    bool SelectedBottom=false;
    bool SelectedLine=false;
    double m_size;
    bool m_visible=false;//是否可见
protected:
    float m_xValue;
    float m_yValue;


    LineType m_type;//类型
    QColor m_color;
    QCustomPlot *m_plot;//图表
    QCPItemStraightLine *m_lineV; //垂直线
    QCPItemStraightLine *m_lineH; //水平线
    QCPItemStraightLine *m_lineBottom; //水平线
    QCPItemLine *m_lineShort; //垂直线段

    QCPItemText *m_labelx;//显示的数值
    QCPItemText *m_labely;//显示的数值
    QCPItemText *m_labelx1;//显示的数值
};


#endif // XXWTRACELINE_H
