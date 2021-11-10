#ifndef TopcCustomPlot_H
#define TopcCustomPlot_H
#include <QObject>
#include "qcustomplot.h"
#include "xxwtraceline.h"
#include "thcustomplot.h"

class TopcCustomPlot:public ThCustomPlot
{
    Q_OBJECT
public:
    explicit TopcCustomPlot(QWidget* widget);

    void Initial();

    int clickNum = 0;

    XxwTraceLine* m_lineTracerLine1;
    XxwTraceLine* m_lineTracerLine2;
    XxwTraceLine* m_lineTracerLine3;

    void mouseDoubleClickEvent(QMouseEvent *event) ;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event) ;
    void mouseReleaseEvent(QMouseEvent *event);
signals:
//    void updateX1(float x_val);
//    void updateX2(float x_val);
//    void updateX3(float x_val);
//    void SetShortLineVis();
public slots:
    void updateX1Event(float x_val);
    void updateX2Event(float x_val);
    void updateX3Event(float x_val);
};

#endif // TopcCustomPlot_H
