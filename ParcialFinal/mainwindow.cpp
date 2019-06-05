#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    bandera = true;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::configurar_interfaz(){
    char name[50];
    QFont font;
    font.setPixelSize(12);

    for(int i=0; i<n_sensores; i++){
        chart[i] = new Chart;
        sprintf(name, "Sensor %i", i+1);
        chart[i]->setTitle(name);
        chart[i]->setTitleFont(font);
        chart[i]->setTitleBrush(QBrush(Qt::black));
        chart[i]->legend()->hide();
        chart[i]->setAnimationOptions(QChart::AllAnimations);
        chartView[i] = new QChartView(chart[i]);
        chartView[i]->setRenderHint(QPainter::Antialiasing);
        //chartView[i]->resize(chartView[i]->parentWidget()->size());
    }

    chartView[0]->setParent(ui->chart1);
    if(n_sensores>1){chartView[1]->setParent(ui->chart2);}
    if(n_sensores>2){chartView[2]->setParent(ui->chart3);}
    if(n_sensores>3){chartView[3]->setParent(ui->chart4);}
    if(n_sensores>4){chartView[4]->setParent(ui->chart5);}
    if(n_sensores>5){chartView[5]->setParent(ui->chart6);}

    for(int i=0; i<n_sensores; i++){
        chartView[i]->resize(chartView[i]->parentWidget()->size());
    }
}

void MainWindow::configurar_interfaz2(){
    char name[50];
    QFont font;
    font.setPixelSize(12);

    for(int i=0; i<3; i++){
        chart2[i] = new Chart;
        if(i==0){chart2[i]->setTitle("Coordenada X");}
        if(i==1){chart2[i]->setTitle("Coordenada Y");}
        if(i==2){chart2[i]->setTitle("Coordenada Z");}
        chart2[i]->setTitleFont(font);
        chart2[i]->setTitleBrush(QBrush(Qt::black));
        chart2[i]->legend()->hide();
        chart2[i]->setAnimationOptions(QChart::AllAnimations);
        chartView2[i] = new QChartView(chart2[i]);
        chartView2[i]->setRenderHint(QPainter::Antialiasing);
        //chartView[i]->resize(chartView[i]->parentWidget()->size());
    }

    chartView2[0]->setParent(ui->chartx);
    chartView2[1]->setParent(ui->charty);
    chartView2[2]->setParent(ui->chartz);
    for(int i=0; i<3; i++){
        chartView2[i]->resize(chartView2[i]->parentWidget()->size());
    }
}

void MainWindow::resizeEvent(QResizeEvent *event){
    QMainWindow::resizeEvent(event);


    for(int i=0; i<n_sensores; i++){
        chartView[i]->resize(chartView[i]->parentWidget()->size());
    }
    for(int i=0; i<3; i++){
        chartView2[i]->resize(chartView2[i]->parentWidget()->size());
    }
}

void MainWindow::Actualizar_interfaz(){

        for(int i=0;i<n_sensores; i++){
            chart[i]->data_1 = this->sensor[i].x;
            chart[i]->data_2 = this->sensor[i].y;
            chart[i]->data_3 = this->sensor[i].z;
            chart[i]->data_4 = 0;
            chart[i]->data_5 = 0;
            chart[i]->data_6 = 0;
        }

        for(int i=0; i<3; i++){
            chart2[i]->data_1 = this->coord[i].x_1;
            chart2[i]->data_2 = this->coord[i].x_2;
            chart2[i]->data_3 = this->coord[i].x_3;
            chart2[i]->data_4 = this->coord[i].x_4;
            chart2[i]->data_5 = this->coord[i].x_5;
            chart2[i]->data_6 = this->coord[i].x_6;
        }
        usleep(1000);
}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{

    for(int i=0; i<n_sensores; i++){
        chartView[i]->resize(chartView[i]->parentWidget()->size());
    }
    for(int i=0; i<3; i++){
        chartView2[i]->resize(chartView2[i]->parentWidget()->size());
    }
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    if(index==1){
        this->resize(1173, 734);
        for(int i=0; i<3; i++){
            chartView2[i]->resize(chartView2[i]->parentWidget()->size());
        }
    }else{
        this->resize(1172, 735);
        for(int i=0; i<n_sensores; i++){
            chartView[i]->resize(chartView[i]->parentWidget()->size());
        }
    }
}
