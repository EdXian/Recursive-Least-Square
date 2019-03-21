#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qcustomplot.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    double regressors(double x ,double frac);

    QCPCurve *curve1 ;//= new QCPCurve(customPlot->xAxis, customPlot->yAxis);
    QCPCurve *curve2 ;
    QCPCurve *curve3 ;
    QVector<QCPCurveData> curve_data1;
    QVector<QCPCurveData> curve_data2;
    QVector<QCPCurveData> curve_data3;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
