#ifndef ACUSTOMPLOT_H
#define ACUSTOMPLOT_H
#include <QObject>
#include "qcustomplot.h"
#include "thcustomplot.h"
#include "xxwtraceline.h"

class ACustomPlot:public ThCustomPlot
{
    Q_OBJECT
public:
    explicit ACustomPlot(QWidget* widget);

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
//    void updateY1(float y_val);
//    void updateY2(float y_val);
//    void SetDashLineVis();
//    void updateDashY(float y_val);
//    void updateDash(float x_val,float y_val);
//    void changeDashSize(float y_val);
public slots:
    void updateY1Event(float y_val);
    void updateY2Event(float y_val);
    void SetShortLineVisEvent();
};

#endif // SCUSTOMPLOT_H
