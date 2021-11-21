#include "colorbarsetting.h"
#include "ui_colorbarsetting.h"
#include <QPainter>

ColorBarSetting::ColorBarSetting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ColorBarSetting)
{
    ui->setupUi(this);
    connect(ui->pushButtonA, SIGNAL(clicked()),this, SLOT(setAmpType()));
    connect(ui->pushButtonC, SIGNAL(clicked()),this, SLOT(setCorType()));
    connect(ui->pushButtonR, SIGNAL(clicked()),this, SLOT(setRFType()));
}

ColorBarSetting::~ColorBarSetting()
{
    delete ui;
}
void ColorBarSetting::setAmpType()
{
    m_type=ONDT_Amplitude;
    ColorBarSetting::repaint();
}
void ColorBarSetting::setCorType()
{
    m_type=ONDT_Corrosion;
    ColorBarSetting::repaint();
}
void ColorBarSetting::setRFType()
{
    m_type=ONDT_RFTOFD;
    ColorBarSetting::repaint();
}
void ColorBarSetting::paintEvent(QPaintEvent *event)  //被系统自动调用
{

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);
    //gpJet==ONDT_Amplitude
    //gpHuge==ONDT_Corrosion
    //gpGrayscale == ONDT_RFTOFD

    QLinearGradient linearGradient(310, 391, 310, 10);

    if(m_type==ColorbarType::ONDT_Amplitude)
    {
        linearGradient.setColorAt(0, QColor(255, 255, 255));
        linearGradient.setColorAt(0.15, QColor(10, 10, 190));
        linearGradient.setColorAt(0.33, QColor(100, 140, 100));
        linearGradient.setColorAt(0.6, QColor(255, 255, 40));
        linearGradient.setColorAt(0.85, QColor(255, 100, 0));
        linearGradient.setColorAt(1, QColor(190, 10, 10));
    }
    else if(m_type==ColorbarType::ONDT_Corrosion)
    {
        linearGradient.setColorAt(0, QColor(255, 0, 0));
        linearGradient.setColorAt(0.15, QColor(255, 100, 0));
        linearGradient.setColorAt(0.33, QColor(255, 255, 40));
        linearGradient.setColorAt(0.6, QColor(0, 255, 0));
        linearGradient.setColorAt(0.75, QColor(50, 255, 255));
        linearGradient.setColorAt(1, QColor(0, 0, 255));
    }
    else
    {
        //linearGradient.interpolationMode(ciRGB);
        linearGradient.setColorAt(0, Qt::black);
        linearGradient.setColorAt(1, Qt::white);
    }

    painter.setPen(Qt::transparent); //添加画笔
    painter.setBrush(linearGradient); //添加画刷
    painter.drawRect(310, 10, 351, 381); //绘制矩形

}



void ColorBarSetting::on_pushButton_9_clicked()//s
{
    emit Sscanupdatecolorbar(m_type);
}

void ColorBarSetting::on_pushButton_10_clicked()//c
{
    emit Cscanupdatecolorbar(m_type);
}

void ColorBarSetting::on_pushButton_11_clicked()//b
{

    Bscanupdatecolorbar(m_type);
}


