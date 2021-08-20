#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    void squareShow();
    void circleShow();
    void ellipseShow();
    void rectangleShow();
    void triangleShow();
    void parallelogramShow();
    void hide();
    void calculator();
    ~Calculator();

private:
    Ui::Calculator *ui;
};
#endif // CALCULATOR_H
