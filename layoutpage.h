#ifndef LAYOUTPAGE_H
#define LAYOUTPAGE_H

#include <QWizardPage>
#include "layouticon.h"

namespace Ui {
class LayoutPage;
}

class LayoutPage : public QWizardPage
{
    Q_OBJECT

public:
    explicit LayoutPage(QWidget *parent = nullptr);
    ~LayoutPage();
    int m_type=0;
    enum CustomPlotType
    {
        Ascan,
        Bscan,
        Cscan1,
        Cscan2,
        Cscan3,
        Sscan,
        TopCScan,
        Pa3D
    };

signals:
    void sendLayoutData(QString);
    void DisplayCustomLayout(int ,int ,int ,int ,int );
private slots:
    void on_pushButtonno_clicked();

    void on_pushButtonyes_clicked();


    void on_pushButtonadd_clicked();

    void on_pushButtonno_5_clicked();

    void on_pushButtonnext_clicked();

    void on_pushButtonback_clicked();

    void on_pushButtonsure_clicked();

    void on_pushButtondelete_clicked();

    void on_pushButtonno_2_clicked();

    void on_pushButtonyes_2_clicked();

private:
    Ui::LayoutPage *ui;
    int customLayout=1;
    int local1;
    int local2;
    int local3;
    int local4;
    int lx=10,ly=10;
    int layoutNum=0;
    QString IndToString(int index);
    std::vector<LayoutIcon*> customButton;

};

#endif // LAYOUTPAGE_H
