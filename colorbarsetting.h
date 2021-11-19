#ifndef COLORBARSETTING_H
#define COLORBARSETTING_H

#include <QWidget>
#include "qcustomplot.h"
namespace Ui {
class ColorBarSetting;
}

class ColorBarSetting : public QWidget
{
    Q_OBJECT

public:
    explicit ColorBarSetting(QWidget *parent = nullptr);
    ~ColorBarSetting();
    //gpJet==ONDT_Amplitude
    //gpHuge==ONDT_Corrosion
    //gpGrayscale == ONDT_RFTOFD
    enum ColorbarType
    {
        ONDT_Amplitude,
        ONDT_Corrosion,
        ONDT_RFTOFD
    };

private slots:

    void paintEvent(QPaintEvent *event);

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();
    void setAmpType();
    void setCorType();
    void setRFType();

signals:
    void Sscanupdatecolorbar(ColorbarType colorbartype);
    void Cscanupdatecolorbar(ColorbarType colorbartype);
    void Bscanupdatecolorbar(ColorbarType colorbartype);
private:
    Ui::ColorBarSetting *ui;
    ColorbarType m_type=ONDT_Corrosion;
};

#endif // COLORBARSETTING_H
