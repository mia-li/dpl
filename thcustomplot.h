#ifndef THCUSTOMPLOT_H
#define THCUSTOMPLOT_H

#include <QObject>
#include "qcustomplot.h"

class ThCustomPlot : public QCustomPlot
{
    Q_OBJECT
public:
    explicit ThCustomPlot(QWidget* widget);

signals:
     void updateY1(float y_val);
     void updateY2(float y_val);
     void SetDashLineVis();
     void updateDashY(float y_val);
     void updateDash(float x_val,float y_val);
     void changeDashSize(float x_val);
     void updateX1(float x_val);
     void updateX2(float x_val);
     void updateX3(float x_val);
     void SetShortLineVis();
     void updateX1b(float y_val);
     void updateX2b(float y_val);
     void updateX1s(float x_val);
     void updateX2s(float x_val);
     void updateY1c(float y_val);
     void updateY2c(float y_val);
public slots:
    virtual void updateY1Event(float y_val);
    virtual void updateY2Event(float y_val);
    virtual void updateX1Event(float x_val);
    virtual void updateX2Event(float x_val);
    virtual void updateX3Event(float x_val);
    virtual void SetShortLineVisEvent();
    virtual void SetDashLineVisEvent();
    virtual void updateDashYEvent(float y_val);
    virtual void updateDashEvent(float x_val,float y_val);
    virtual void changeDashSizeEvent(float y_val);

};

#endif // THCUSTOMPLOT_H
