#include "calculator.h"
#include "ui_calculator.h"
#include <cmath>

extern int graphicsFlag=1;
extern int unitFlag=1;
Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);
    hide();
    connect(ui->square,&QAction::triggered,this,[=](){hide();squareShow();graphicsFlag=1;});
    connect(ui->circle,&QAction::triggered,this,[=](){hide();circleShow();graphicsFlag=2;});
    connect(ui->rectangle,&QAction::triggered,this,[=](){hide();rectangleShow();graphicsFlag=3;});
    connect(ui->triangle,&QAction::triggered,this,[=](){hide();triangleShow();graphicsFlag=4;});
    connect(ui->calculator,&QPushButton::clicked,this,[=](){calculator();});
    connect(ui->cm,&QAction::triggered,this,[=](){unitFlag=1;ui->cm->setText("厘米(当前)");ui->inches->setText("英寸");});
    connect(ui->inches,&QAction::triggered,this,[=](){unitFlag=2;ui->cm->setText("厘米");ui->inches->setText("英寸(当前)");});
}

void Calculator::squareShow()
{
    ui->label->setText("正方形");
    ui->label->show();
    ui->value1->setPlaceholderText("此处输入边长");
    ui->value1->show();
    ui->value2->setPlaceholderText("当前状态下禁用");
    ui->value2->setEnabled(false);
    ui->value2->show();
    ui->result->show();
    ui->calculator->show();
}

void Calculator::circleShow()
{
    ui->label->setText("圆形");
    ui->label->show();
    ui->value1->setPlaceholderText("此处输入半径");
    ui->value1->show();
    ui->value2->setPlaceholderText("当前状态下禁用");
    ui->value2->setEnabled(false);
    ui->value2->show();
    ui->result->show();
    ui->calculator->show();
}

void Calculator::rectangleShow()
{
    ui->label->setText("长方形");
    ui->label->show();
    ui->value1->setPlaceholderText("此处输入长");
    ui->value1->show();
    ui->value2->setPlaceholderText("此处输入宽");
    ui->value2->setEnabled(true);
    ui->value2->show();
    ui->result->show();
    ui->calculator->show();
}

void Calculator::triangleShow()
{
    ui->label->setText("三角形");
    ui->label->show();
    ui->value1->setPlaceholderText("此处输入底");
    ui->value1->show();
    ui->value2->setPlaceholderText("此处输入高");
    ui->value2->setEnabled(true);
    ui->value2->show();
    ui->result->show();
    ui->calculator->show();
}

void Calculator::hide()
{
    ui->label->hide();
    ui->value1->hide();
    ui->value1->clear();
    ui->value2->hide();
    ui->value2->clear();
    ui->result->hide();
    ui->result->clear();
    ui->calculator->hide();
}

void Calculator::calculator()
{
    if(graphicsFlag==1)
    {
        QString str=ui->value1->text();
        double vvalue=str.toDouble();
        if(unitFlag==1)
            ui->result->setText(QString::number(vvalue*vvalue,'f',3));
        else if(unitFlag==2)
            ui->result->setText(QString::number(2.54*2.54*vvalue*vvalue,'f',3));
    }
    else if(graphicsFlag==2)
    {
        QString str=ui->value1->text();
        double vvalue=str.toDouble();
        if(unitFlag==1)
            ui->result->setText(QString::number(3.1415926535*vvalue*vvalue,'f',3));
        else if(unitFlag==2)
            ui->result->setText(QString::number(3.1415926535*2.54*2.54*vvalue*vvalue,'f',3));
    }
    else if(graphicsFlag==3)
    {
        QString str1=ui->value1->text();
        double vvalue1=str1.toDouble();
        QString str2=ui->value2->text();
        double vvalue2=str2.toDouble();
        if(unitFlag==1)
            ui->result->setText(QString::number(vvalue1*vvalue2,'f',3));
        else if(unitFlag==2)
            ui->result->setText(QString::number(2.54*2.54*vvalue1*vvalue2,'f',3));
    }
    else if(graphicsFlag==4)
    {
        QString str1=ui->value1->text();
        double vvalue1=str1.toDouble();
        QString str2=ui->value2->text();
        double vvalue2=str2.toDouble();
        if(unitFlag==1)
            ui->result->setText(QString::number(0.5*vvalue1*vvalue2,'f',3));
        else if(unitFlag==2)
            ui->result->setText(QString::number(0.5*2.54*2.54*vvalue1*vvalue2,'f',3));
    }
}

Calculator::~Calculator()
{
    delete ui;
}
