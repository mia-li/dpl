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
    void InitialPlot();
    void on_pushButton_2_clicked();
    void layoutData(QString type);
    void DisplayCustomLayout(int customlayout,int local1,int local2,int local3,int local4);
    void CustomWidget(QSplitter *&splitter,int index,int local);
    void on_pushButton_3_clicked();

private:
    ThCustomPlot *aplot;
    ThCustomPlot *a2plot;
    ThCustomPlot *bplot;
    ThCustomPlot *c1plot;
    ThCustomPlot *c2plot;
    ThCustomPlot *c3plot;
    ThCustomPlot *splot;
    ThCustomPlot *topcplot;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
