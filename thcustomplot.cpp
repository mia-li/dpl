#include "thcustomplot.h"

ThCustomPlot::ThCustomPlot(QWidget* widget):QCustomPlot(widget)
{

}
void ThCustomPlot:: updateY1Event(float y_val)
{
    qDebug("aa");
}
void ThCustomPlot::updateY2Event(float y_val){}
void ThCustomPlot::updateX1Event(float y_val){}
void ThCustomPlot::updateX2Event(float y_val){}
void ThCustomPlot::updateX3Event(float x_val){}
void ThCustomPlot::SetShortLineVisEvent(){}
void ThCustomPlot::SetDashLineVisEvent(){}
void ThCustomPlot::updateDashYEvent(float y_val){}
void ThCustomPlot::updateDashEvent(float x_val,float y_val){}
void ThCustomPlot::changeDashSizeEvent(float y_val){}
