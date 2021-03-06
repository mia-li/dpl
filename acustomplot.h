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
    static ACustomPlot* Instance(){
        if (ACustomPlot::Singleton==nullptr) {
            ACustomPlot::Singleton = new ACustomPlot;
        }
        return ACustomPlot::Singleton;
    }
    ACustomPlot(QWidget* widget=nullptr);

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
    inline static ACustomPlot* Singleton =nullptr;
signals:
public slots:
    void updateY1Event(float y_val);
    void updateY2Event(float y_val);
    void SetShortLineVisEvent();
};

#endif // SCUSTOMPLOT_H
