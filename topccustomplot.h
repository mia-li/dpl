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
    static TopcCustomPlot* Instance(){
        if (TopcCustomPlot::Singleton==nullptr) {
            TopcCustomPlot::Singleton = new TopcCustomPlot;
        }
        return TopcCustomPlot::Singleton;
    }
    TopcCustomPlot(QWidget* widget=nullptr);

    void Initial();

    int clickNum = 0;

    XxwTraceLine* m_lineTracerLine1;
    XxwTraceLine* m_lineTracerLine2;
    XxwTraceLine* m_lineTracerLine3;

    void mouseDoubleClickEvent(QMouseEvent *event) ;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event) ;
    void mouseReleaseEvent(QMouseEvent *event);
signals://signals可以继承父类的
public slots:
    void updateX1Event(float x_val);
    void updateX2Event(float x_val);
    void updateX3Event(float x_val);
private:
    inline static TopcCustomPlot* Singleton =nullptr;
};

#endif // TopcCustomPlot_H
