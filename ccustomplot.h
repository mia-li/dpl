#ifndef CCustomPlot_H
#define CCustomPlot_H
#include <QObject>
#include "qcustomplot.h"
#include "xxwtraceline.h"

class CCustomPlot:public QCustomPlot
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
};

#endif // CCustomPlot_H
