#ifndef BODEPLOT_H
#define BODEPLOT_H

#include <QWidget>
#include <QtCharts>
#include <QChartView>
#include <QVector>
#include "complex.h"
#include "global_defines.h"
#include "fftworker.h"


QT_CHARTS_USE_NAMESPACE

class bodeplot : public QWidget
{
    Q_OBJECT
public:
    explicit bodeplot(QWidget *parent = nullptr);

signals:

public slots:
 void PIchanged(double B[3] , double A[2], int channel);
 void EQchanged(double B[3] , double A[2], float fc , int channel , int section);

private:
    void calcLevel(int channel);
    QChart* chart;
    QChartView* chartview;
    QLineSeries bodeTorque;
    QLineSeries bodeFlux;
    QLogValueAxis freqAxis;
    QValueAxis levelAxis;
    QVector<float> freq;
    QVBoxLayout top_layout;
    std::complex<double> H[2][3][BODE_PLOTSIZE]; //channel//section//index
    std::complex<double> c;
    double level[BODE_PLOTSIZE];
    float old_fc=0;

};

#endif // BODEPLOT_H
