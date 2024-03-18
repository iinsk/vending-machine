#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setDefault();
}

Widget::~Widget()
{
    delete ui;
}
void Widget::setDefault()
{
    ui->pbCoffee->setDisabled(1);
    ui->pbTea->setDisabled(1);
    ui->pbTang->setDisabled(1);

}
void Widget::changeMoney(int diff)
{
    money += diff;
    ui->lcdNumber->display(money);

    ui->pbCoffee->setEnabled(money>=100);
    ui->pbTea->setEnabled(money>=200);
    ui->pbTang->setEnabled(money>=300);
}

void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}

void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}

void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}

void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbTang_clicked()
{
    changeMoney(-300);
}


void Widget::on_pbReset_clicked()
{
    QMessageBox mb;
    int c500 = money/500;
    int c100 = (money%500) / 100;
    int c50 = (money%100) / 50;
    int c10 =  (money%50) / 10;

    mb.information(nullptr, "title", "Total: " + QString::number(money)+"\n500 = " + QString::number(c500) + "\n100 = "+QString::number(c100) + "\n50 = " + QString::number(c50) + "\n10 = " + QString::number(c10));

    changeMoney(-money);
}

