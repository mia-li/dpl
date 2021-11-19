#ifndef BCustomPlot_H
#define BCustomPlot_H
#include <QObject>
#include "qcustomplot.h"
#include "xxwtraceline.h"
#include "thcustomplot.h"
class BCustomPlot:public ThCustomPlot
{
    Q_OBJECT
public:
    explicit BCustomPlot(QWidget* widget);

    void Initial();

    int clickNum = 0;

    XxwTraceLine* m_lineTracer1;
    XxwTraceLine* m_lineTracer2;
    XxwTraceLine* m_lineTracerLine;

    void mouseDoubleClickEvent(QMouseEvent *event) ;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event) ;
    void mouseReleaseEvent(QMouseEvent *event);
    //static
signals:
public slots:
    void updateY1Event(float y_val);
    void updateY2Event(float y_val);
    void updateX1Event(float x_val);
    void updateX2Event(float x_val);
    void updateX3Event(float x_val);
};

#endif // BCustomPlot_H
