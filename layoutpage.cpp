#include "layoutpage.h"
#include "ui_layoutpage.h"
#include "QMessageBox"
#include "qdebug.h"
#include "layouticon.h"

LayoutPage::LayoutPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::LayoutPage)
{
    ui->setupUi(this);
}

LayoutPage::~LayoutPage()
{
    delete ui;
}

void LayoutPage::on_pushButtonno_clicked()
{
    this->hide();
}

void LayoutPage::on_pushButtonyes_clicked()
{

    if(ui->radioButton1->isChecked())
    {
        m_type=1;
    }
    else if(ui->radioButton2->isChecked())
    {
        m_type=2;
    }
    else if(ui->radioButton3->isChecked())
    {
        m_type=3;
    }
    else if(ui->radioButton4->isChecked())
    {
        m_type=4;
    }
    else if(ui->radioButton5->isChecked())
    {
        m_type=5;
    }
    else if(ui->radioButton6->isChecked())
    {
        m_type=6;
    }
    else if(ui->radioButton7->isChecked())
    {
        m_type=7;
    }
    else if(ui->radioButton8->isChecked())
    {
        m_type=8;
    }
    else if(ui->radioButton9->isChecked())
    {
        m_type=9;
    }
    else if(ui->radioButton10->isChecked())
    {
        m_type=10;
    }
    else if(ui->radioButton11->isChecked())
    {
        m_type=11;
    }
    else if(ui->radioButton12->isChecked())
    {
        m_type=12;
    }
    else if(ui->radioButton13->isChecked())
    {
        m_type=13;
    }
    else if(ui->radioButton14->isChecked())
    {
        m_type=14;
    }
    else if(ui->radioButton15->isChecked())
    {
        m_type=15;
    }
    else if(ui->radioButton16->isChecked())
    {
        m_type=16;
    }
    else if(ui->radioButton17->isChecked())
    {
        m_type=17;
    }
    else if(ui->radioButton18->isChecked())
    {
        m_type=18;
    }
    else if(ui->radioButton19->isChecked())
    {
        m_type=19;
    }
    else if(ui->radioButton20->isChecked())
    {
        m_type=20;
    }
    emit sendLayoutData(QString::number(m_type));
    this->hide();
}

void LayoutPage::on_pushButtonadd_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void LayoutPage::on_pushButtonno_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void LayoutPage::on_pushButtonnext_clicked()
{
    if(ui->radioButtons1->isChecked())
        customLayout=1;
    else if(ui->radioButtons2->isChecked())
        customLayout=2;
    else if(ui->radioButtons3->isChecked())
        customLayout=3;
    else if(ui->radioButtons4->isChecked())
        customLayout=4;
    else if(ui->radioButtons5->isChecked())
        customLayout=5;
    else if(ui->radioButtons6->isChecked())
        customLayout=6;
    else if(ui->radioButtons7->isChecked())
        customLayout=7;
    else if(ui->radioButtons8->isChecked())
        customLayout=8;
    else if(ui->radioButtons9->isChecked())
        customLayout=9;
    else if(ui->radioButtons10->isChecked())
        customLayout=10;
    else if(ui->radioButtons11->isChecked())
        customLayout=11;
    else
        customLayout=1;
    ui->stackedWidget->setCurrentIndex(2);

    if(customLayout==1)
    {
        ui->label2->setVisible(false);
        ui->label3->setVisible(false);
        ui->label4->setVisible(false);
        ui->comboBox2->setVisible(false);
        ui->comboBox3->setVisible(false);
        ui->comboBox4->setVisible(false);
    }
    else if(customLayout>=2&&customLayout<=3)
    {
        ui->label2->setVisible(true);
        ui->comboBox2->setVisible(true);

        ui->label3->setVisible(false);
        ui->label4->setVisible(false);
        ui->comboBox3->setVisible(false);
        ui->comboBox4->setVisible(false);

    }
    else if(customLayout>=4&&customLayout<=7)
    {
        ui->label2->setVisible(true);
        ui->comboBox2->setVisible(true);
        ui->label3->setVisible(true);
        ui->comboBox3->setVisible(true);

        ui->label4->setVisible(false);
        ui->comboBox4->setVisible(false);
    }
    else
    {
        ui->label2->setVisible(true);
        ui->comboBox2->setVisible(true);
        ui->label3->setVisible(true);
        ui->comboBox3->setVisible(true);

        ui->label4->setVisible(true);
        ui->comboBox4->setVisible(true);
    }
    QString ima=QString("background-image:url(:/image/pics/s%1.png)").arg(customLayout);
    qDebug()<<ima;
    ima.append(";background-repeat:no-repeat;background-position:right center;");
    ui->labellayouttype->setStyleSheet(ima);
}

void LayoutPage::on_pushButtonback_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void LayoutPage::on_pushButtonsure_clicked()
{
    LayoutIcon* con1;
    int local1=0;
    int local2=0;
    int local3=0;
    int local4=0;
    if(customLayout==1)
    {
        if(ui->comboBox1->currentIndex()==0)
        {
            QMessageBox msgBox;
            msgBox.setText(tr("aaa"));
            //QMessageBox::information(this,"提示信息","存在没有选择视图的位置");
        }
        else
        {
            local1=ui->comboBox1->currentIndex();

            con1=new LayoutIcon(customLayout,ui->page1,local1);

            ui->stackedWidget->setCurrentIndex(0);
        }
    }
    else if(customLayout>=2&&customLayout<=3)
    {
        if(ui->comboBox1->currentIndex()==0||ui->comboBox2->currentIndex()==0)
        {
            QMessageBox msgBox;
            msgBox.setText(tr("aaa"));
            //QMessageBox::information(this,"提示信息","存在没有选择视图的位置");
        }
        else
        {
            local1=ui->comboBox1->currentIndex();
            local2=ui->comboBox2->currentIndex();
            con1=new LayoutIcon(customLayout,ui->page1,local1,local2);

            ui->stackedWidget->setCurrentIndex(0);
        }
    }
    else if(customLayout>=4&&customLayout<=7)
    {
        if(ui->comboBox1->currentIndex()==0||ui->comboBox2->currentIndex()==0||ui->comboBox3->currentIndex()==0)
        {
            QMessageBox msgBox;
            msgBox.setText(tr("aaa"));
            //QMessageBox::information(this,"提示信息","存在没有选择视图的位置");
        }
        else
        {
            local1=ui->comboBox1->currentIndex();
            local2=ui->comboBox2->currentIndex();
            local3=ui->comboBox3->currentIndex();
            con1=new LayoutIcon(customLayout,ui->page1,local1,local2,local3);

            ui->stackedWidget->setCurrentIndex(0);
        }

    }
    else if(customLayout>=8&&customLayout<=11)
    {
        if(ui->comboBox1->currentIndex()==0||ui->comboBox2->currentIndex()==0||ui->comboBox3->currentIndex()==0||ui->comboBox4->currentIndex()==0)
        {
            //QMessageBox messageBox(QMessageBox::NoIcon,"提示信息", "存在没有选择视图的位置",NULL);
            //messageBox.exec();
            //QMessageBox::information(NULL, "提示信息", "存在没有选择视图的位置");
        }
        else
        {
            local1=ui->comboBox1->currentIndex();
            local2=ui->comboBox2->currentIndex();
            local3=ui->comboBox3->currentIndex();
            local4=ui->comboBox4->currentIndex();
            con1=new LayoutIcon(customLayout,ui->page1,local1,local2,local3,local4);
            ui->stackedWidget->setCurrentIndex(0);
        }
    }

    customButton.push_back(con1);
    con1->UpdateIndex(customButton.size()-1);
}
QString LayoutPage::IndToString(int index)
{
    if(index==1)
        return "A";
    else if(index==2)
        return "B";
    else if(index==3)
        return "C1";
    else if(index==4)
        return "C2";
    else if(index==5)
        return "C3";
    else if(index==6)
        return "S";
    else if(index==7)
        return "TopC";
    else if(index==1)
        return "Pa3D";
}

void LayoutPage::on_pushButtondelete_clicked()
{
    for(int i=0;i<customButton.size();i++)
    {
        if(customButton[i]->rb->isChecked())
        {
            customButton[i]->Delete();
            for(int j=i+1;j<customButton.size();j++)
            {
                customButton[j]->UpdateIndex(j-1);
                customButton[j-1]=customButton[j];
            }

            customButton.pop_back();
            break;
        }

    }
}

void LayoutPage::on_pushButtonno_2_clicked()
{
    this->hide();
}

void LayoutPage::on_pushButtonyes_2_clicked()
{
    for(int i=0;i<customButton.size();i++)
    {
        if(customButton[i]->rb->isChecked())
        {

            emit DisplayCustomLayout(customButton[i]->m_customlayout,customButton[i]->local1,customButton[i]->local2,customButton[i]->local3,customButton[i]->local4);
            this->hide();
            break;
        }
    }

}
