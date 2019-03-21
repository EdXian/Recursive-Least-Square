#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rls.h"
#include "time.h"
#include <random>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    srand(time(NULL));
    ui->setupUi(this);
    ui->qcustomplot1->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom );
    ui->qcustomplot2->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom );
    ui->qcustomplot3->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom );

    //QVector<double> x(1001), y(1001); // initialize with entries 0..100

    curve1 = new QCPCurve(ui->qcustomplot1->xAxis, ui->qcustomplot1->yAxis);
    curve2 = new QCPCurve(ui->qcustomplot2->xAxis, ui->qcustomplot2->yAxis);
    curve3 = new QCPCurve(ui->qcustomplot3->xAxis, ui->qcustomplot3->yAxis);

    curve_data1.clear();
    curve_data2.clear();
    curve_data3.clear();


   // curve2->data()->set(curve_data2,true);

    rls num_rls;
    Eigen::VectorXd theta;
    theta.setZero(3,1);
    std::default_random_engine generator;
     std::normal_distribution<double> distribution(0.0,2.0);
    for (int i=0; i<1000; ++i)
    {
        double x = i/10;

         double noise = distribution(generator);
         curve_data3.push_back(QCPCurveData(i,x,0.5*noise));

       // double noise = distribution.
        double y = regressors(i/10 ,10000.0000)+0.5*noise;//+ 0.3*((rand()%2000)-1000)/1000.0;
        curve_data1.push_back(QCPCurveData(i,x,y));
//      x[i] = i/100;
//      y[i] = regressors(x[i] ,10000);
        theta = num_rls.update(  x, y );
    }


    for (int i=0; i<1000; ++i){
        double x = i/10;
        double y = theta(0)* sin(x)+theta(1) * cos(x) +theta(2)*1;
        curve_data2.push_back(QCPCurveData(i,x,y));

    }

    std::cout <<" theta" << theta<<std::endl;
     curve1->data()->set(curve_data1,true);
     curve2->data()->set(curve_data2,true);
     curve3->data()->set(curve_data3,true);

    // create graph and assign data to it:
//    ui->qcustomplot1->addGraph();
//    ui->qcustomplot1->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->qcustomplot1->xAxis->setLabel("x");
    ui->qcustomplot1->yAxis->setLabel("y");
    ui->qcustomplot1->xAxis->setRange(0, 100);
    ui->qcustomplot1->yAxis->setRange(-2, 2);

    ui->qcustomplot2->xAxis->setLabel("x");
    ui->qcustomplot2->yAxis->setLabel("y");
    ui->qcustomplot2->xAxis->setRange(0, 100);
    ui->qcustomplot2->yAxis->setRange(-2, 2);

    ui->qcustomplot3->xAxis->setLabel("x");
    ui->qcustomplot3->yAxis->setLabel("y");
    ui->qcustomplot3->xAxis->setRange(0, 100);
    ui->qcustomplot3->yAxis->setRange(-2, 2);


    ui->qcustomplot2->replot();
    ui->qcustomplot3->replot();

    ui->qcustomplot1->replot();
}

// regressors
double MainWindow::regressors(double x ,double frac ){
    return 0.5*sin(x) + 0.3*cos(x) + 0.3 ;
}

MainWindow::~MainWindow()
{
    delete ui;
}
