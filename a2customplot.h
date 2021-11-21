#ifndef A2CUSTOMPLOT_H
#define A2CUSTOMPLOT_H
#include <QObject>
#include "qcustomplot.h"
#include "thcustomplot.h"
#include "xxwtraceline.h"

class A2CustomPlot:public ThCustomPlot
{
    Q_OBJECT
public:
    static A2CustomPlot* Instance(){
        if (A2CustomPlot::Singleton==nullptr) {
            A2CustomPlot::Singleton = new A2CustomPlot;
        }
        return A2CustomPlot::Singleton;
    }
    A2CustomPlot(QWidget* widget=nullptr);

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
private:
    inline static A2CustomPlot* Singleton =nullptr;
signals:
public slots:
    void updateX1Event(float x_val);
    void updateX2Event(float x_val);
    void SetShortLineVisEvent();
};

#endif // SCUSTOMPLOT_H
