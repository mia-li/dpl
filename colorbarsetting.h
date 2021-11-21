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
    static ColorBarSetting* Instance(){
        if (ColorBarSetting::Singleton==nullptr) {
            ColorBarSetting::Singleton = new ColorBarSetting;
        }
        return ColorBarSetting::Singleton;
    }
    //explicit ColorBarSetting(QWidget *parent = nullptr);
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
    void Sscanupdatecolorbar(ColorBarSetting::ColorbarType colorbartype);
    void Cscanupdatecolorbar(ColorBarSetting::ColorbarType colorbartype);
    void Bscanupdatecolorbar(ColorBarSetting::ColorbarType colorbartype);
private:
    ColorBarSetting(QWidget *parent = nullptr);
    Ui::ColorBarSetting *ui;
    ColorbarType m_type=ONDT_Corrosion;
    inline static ColorBarSetting* Singleton =nullptr;
};

#endif // COLORBARSETTING_H
