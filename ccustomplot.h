#ifndef CCustomPlot_H
#define CCustomPlot_H
#include <QObject>
#include "qcustomplot.h"
#include "xxwtraceline.h"
#include "thcustomplot.h"
#include "colorbarsetting.h"
class CCustomPlot:public ThCustomPlot
{
    Q_OBJECT
public:
    static CCustomPlot* Instance(){
        if (CCustomPlot::Singleton==nullptr) {
            CCustomPlot::Singleton = new CCustomPlot;
        }
        return CCustomPlot::Singleton;
    }
    CCustomPlot(QWidget* widget=nullptr);

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
    QCPColorMap *colorMap;
    QCPColorGradient gradient;
    QCPColorScale *colorScale;
signals:
public slots:
    void updateY1Event(float y_val);
    void updateY2Event(float y_val);
    void updateX1Event(float x_val);
    void updateX2Event(float x_val);
    void updateX3Event(float x_val);
    void changeColorbar(ColorBarSetting::ColorbarType colorbartype);
private:
    inline static CCustomPlot* Singleton =nullptr;
};

#endif // CCustomPlot_H
