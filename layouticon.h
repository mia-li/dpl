#ifndef LAYOUTICON_H
#define LAYOUTICON_H

#include <QObject>
#include "qradiobutton.h"
#include "qlabel.h"

class LayoutIcon : public QObject
{
    Q_OBJECT
public:
    explicit LayoutIcon(int customlayout, QWidget *widgetparent=Q_NULLPTR,int lo1=1,int lo2=1,int lo3=1,int lo4=1,QObject *parent = Q_NULLPTR);
    void Delete();
    void UpdateIndex(int ix);
    void Paint();
    static int layoutNum;
    QRadioButton* rb;
    int index;
    int m_customlayout=1;
signals:

private:

    QRect Point;
    QLabel* l1;
    QLabel* l2;
    QLabel* l3;
    QLabel* l4;
    int local1;
    int local2;
    int local3;
    int local4;
    QString t1;
    QString t2;
    QString t3;
    QString t4;

    QWidget *m_widget;

    int lx=10,ly=10;

    QString IndToString(int index);
};

#endif // LAYOUTICON_H
