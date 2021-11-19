#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"
#include "thcustomplot.h"
#include "xxwtraceline.h"
#include "acustomplot.h"
#include "bcustomplot.h"
#include "ccustomplot.h"
#include "scustomplot.h"
#include "topccustomplot.h"
#include "a2customplot.h"
#include "layoutpage.h"
#include "colorbarsetting.h"
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
    ColorBarSetting *colorbar;
    LayoutPage* lay;
private slots:
    void CursorEvent(ThCustomPlot *sender, ThCustomPlot *receiver,int loc1,int loc2);
    void CustomCursorEvent(ThCustomPlot *&cp1, ThCustomPlot *&cp2,ThCustomPlot *&cp3,ThCustomPlot *&cp4,int customlayout,int local1,int local2,int local3,int local4);
    void on_pushButton_2_clicked();
    void layoutData(QString type);
    void DisplayCustomLayout(int customlayout,int local1,int local2,int local3,int local4);
    void InitCustomWidget(QWidget* widget,ThCustomPlot *&cp,int local);

    void on_pushButton_3_clicked();

private:

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
