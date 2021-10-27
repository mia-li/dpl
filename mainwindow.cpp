#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Initial();
//    connect(ui->custom1, &SCustomPlot::updateY1, (ui->custom2), &ACustomPlot::updateY1Event);
//    connect(ui->custom1, &SCustomPlot::updateY1, (ui->custom3), &BCustomPlot::updateY1Event);
//    connect(ui->custom2, &ACustomPlot::updateY1, (ui->custom1), &SCustomPlot::updateY1Event);
//    connect(ui->custom2, &ACustomPlot::updateY1, (ui->custom3), &BCustomPlot::updateY1Event);
//    connect(ui->custom3, &BCustomPlot::updateY1, (ui->custom1), &SCustomPlot::updateY1Event);
//    connect(ui->custom3, &BCustomPlot::updateY1, (ui->custom2), &ACustomPlot::updateY1Event);

//    connect(ui->custom1, &SCustomPlot::updateY2, (ui->custom2), &ACustomPlot::updateY2Event);
//    connect(ui->custom1, &SCustomPlot::updateY2, (ui->custom3), &BCustomPlot::updateY2Event);
//    connect(ui->custom2, &ACustomPlot::updateY2, (ui->custom1), &SCustomPlot::updateY2Event);
//    connect(ui->custom2, &ACustomPlot::updateY2, (ui->custom3), &BCustomPlot::updateY2Event);
//    connect(ui->custom3, &BCustomPlot::updateY2, (ui->custom1), &SCustomPlot::updateY2Event);
//    connect(ui->custom3, &BCustomPlot::updateY2, (ui->custom2), &ACustomPlot::updateY2Event);

//    connect(ui->custom2, &ACustomPlot::SetDashLineVis, (ui->custom1), &SCustomPlot::SetDashLineVisEvent);
//    connect(ui->custom2, &ACustomPlot::updateDash, (ui->custom1), &SCustomPlot::updateDashEvent);
//    connect(ui->custom2, &ACustomPlot::updateDashY, (ui->custom1), &SCustomPlot::updateDashYEvent);
//    connect(ui->custom2, &ACustomPlot::changeDashSize, (ui->custom1), &SCustomPlot::changeDashSizeEvent);

//    connect(ui->custom1, &SCustomPlot::SetShortLineVis, (ui->custom2), &ACustomPlot::SetShortLineVisEvent);
//    connect(ui->custom3, &BCustomPlot::SetShortLineVis, (ui->custom2), &ACustomPlot::SetShortLineVisEvent);

}
void MainWindow::Initial()
{



}
MainWindow::~MainWindow()
{
    delete ui;
}


int num=0;

void MainWindow::on_pushButton_clicked()
{
    if(num>8)
    {
        num=0;
    }
    ui->stackedWidget->setCurrentIndex(num);
    num++;

}
