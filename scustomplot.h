#ifndef SCUSTOMPLOT_H
#define SCUSTOMPLOT_H
#include <QObject>
#include "qcustomplot.h"
#include "xxwtraceline.h"
#include "thcustomplot.h"
class SCustomPlot:public ThCustomPlot
{
    Q_OBJECT
public:
    static SCustomPlot* Instance(){
        if (SCustomPlot::Singleton==nullptr) {
            SCustomPlot::Singleton = new SCustomPlot;
        }
        return SCustomPlot::Singleton;
    }
    SCustomPlot(QWidget* widget=nullptr);

    void Initial();
    void OthersMouseEvent();

    int clickNum = 0;

    XxwTraceLine* m_lineTracer1;
    XxwTraceLine* m_lineTracer2;
    XxwTraceLine* m_lineTracerLine;
    XxwTraceLine* m_lineTracerDashLine;

    void mouseDoubleClickEvent(QMouseEvent *event) ;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event) ;
    void mouseReleaseEvent(QMouseEvent *event);

signals:
public slots:
    void updateY1Event(float y_val);
    void updateY2Event(float y_val);
    void updateX1Event(float x_val);
    void updateX2Event(float x_val);
    void SetDashLineVisEvent();
    void updateDashYEvent(float y_val);
    void updateDashEvent(float x_val,float y_val);
    void changeDashSizeEvent(float y_val);
private:
    inline static SCustomPlot* Singleton =nullptr;
};

#endif // SCUSTOMPLOT_H
