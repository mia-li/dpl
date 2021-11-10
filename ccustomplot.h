#ifndef CCustomPlot_H
#define CCustomPlot_H
#include <QObject>
#include "qcustomplot.h"
#include "xxwtraceline.h"
#include "thcustomplot.h"
class CCustomPlot:public ThCustomPlot
{
    Q_OBJECT
public:
    explicit CCustomPlot(QWidget* widget);

    void Initial();
    void OthersMouseEvent();

    int clickNum = 0;

    XxwTraceLine* m_lineTracer1;
    XxwTraceLine* m_lineTracer2;
    XxwTraceLine* m_lineTracerLine;

    void mouseDoubleClickEvent(QMouseEvent *event) ;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event) ;
    void mouseReleaseEvent(QMouseEvent *event);
signals:
//    void updateX1b(float y_val);
//    void updateX2b(float y_val);
//    void updateX1s(float x_val);
//    void updateX2s(float x_val);
//    void updateX3(float x_val);
//    void SetShortLineVis();
public slots:
    void updateY1Event(float y_val);
    void updateY2Event(float y_val);
    void updateX1Event(float x_val);
    void updateX2Event(float x_val);
    void updateX3Event(float x_val);
};

#endif // CCustomPlot_H
