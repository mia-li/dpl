#ifndef TopcCustomPlot_H
#define TopcCustomPlot_H
#include <QObject>
#include "qcustomplot.h"
#include "xxwtraceline.h"

class TopcCustomPlot:public QCustomPlot
{
    Q_OBJECT
public:
    explicit TopcCustomPlot(QWidget* widget);

    void Initial();
    void OthersMouseEvent();

    int clickNum = 0;

    XxwTraceLine* m_lineTracerLine1;
    XxwTraceLine* m_lineTracerLine2;
    XxwTraceLine* m_lineTracerLine3;

    void mouseDoubleClickEvent(QMouseEvent *event) ;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event) ;
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // TopcCustomPlot_H
