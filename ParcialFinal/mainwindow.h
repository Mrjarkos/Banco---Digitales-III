#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QtCore>
#include <QtWidgets>
#include <QMessageBox>
#include "chart.h"
#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

#include <QApplication>
#include <QtWidgets/QMainWindow>
#include <QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QFont>
#include <QPen>
#include <QCategoryAxis>
#include <QChartView>

using namespace QtCharts;


typedef struct {
    double x;
    double y;
    double z;
} coordenadas;

typedef struct {
    double x_1;
    double x_2;
    double x_3;
    double x_4;
    double x_5;
    double x_6;
} porsensores;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    bool bandera;
    porsensores coord[3];
    coordenadas sensor[6];
    int n_sensores;
    explicit MainWindow(QWidget *parent = 0);
    void configurar_interfaz();
    void configurar_interfaz2();
    void Actualizar_interfaz();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QChartView* chartView[6];
    Chart *chart[6];
    QChartView* chartView2[3];
    Chart *chart2[3];

protected:
    void resizeEvent(QResizeEvent* event);
private slots:
    void on_Sensores_Button_clicked();
    void on_Component_Button_clicked();
    void on_tabWidget_tabBarClicked(int index);
    void on_tabWidget_currentChanged(int index);
};

#endif // MAINWINDOW_H
