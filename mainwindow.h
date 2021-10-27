#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"
#include "xxwtraceline.h"
#include "acustomplot.h"
#include "bcustomplot.h"
#include "ccustomplot.h"
#include "scustomplot.h"
#include "topccustomplot.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void Initial();

    XxwTraceLine* m_lineRTracer1;
    XxwTraceLine* m_lineRTracer2;
    XxwTraceLine* m_lineRTracerShort;

    XxwTraceLine* m_lineLTracer1;
    XxwTraceLine* m_lineLTracer2;
    XxwTraceLine* m_lineLDashTracer;
    XxwTraceLine* m_lineLStLineTracer;
private slots:
    void on_pushButton_clicked();

private:

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
