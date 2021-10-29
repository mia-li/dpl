#ifndef A2CUSTOMPLOT_H
#define A2CUSTOMPLOT_H
#include <QObject>
#include "qcustomplot.h"
#include "xxwtraceline.h"

class A2CustomPlot:public QCustomPlot
{
    Q_OBJECT
public:
    explicit A2CustomPlot(QWidget* widget);

    void Initial();
    void OthersMouseEvent();

    int clickNum = 0;

    XxwTraceLine* m_lineTracer1;
    XxwTraceLine* m_lineTracer2;
    XxwTraceLine* m_lineTracerShortLine;

    void mouseDoubleClickEvent(QMouseEvent *event) ;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event) ;
    void mouseReleaseEvent(QMouseEvent *event);
signals:
    void updateY1(float y_val);
    void updateY2(float y_val);
    void SetDashLineVis();
    void updateDashY(float y_val);
    void updateDash(float x_val,float y_val);
    void changeDashSize(float x_val);
public slots:
    void updateX1Event(float y_val);
    void updateX2Event(float y_val);
    void SetShortLineVisEvent();
};

#endif // SCUSTOMPLOT_H
