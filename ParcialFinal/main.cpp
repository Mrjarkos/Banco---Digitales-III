#include "mainwindow.h"
#include <QApplication>
#include "process.h"
#include "chart.h"
#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>


QT_CHARTS_USE_NAMESPACE
QT_CHARTS_USE_NAMESPACE

typedef struct {
    int i;
    double x;
    double y;
    double z;
} arg_thread;

const char *name_start = "/tmp/exam_3_start";
const char *name_sensor = "/tmp/exam_3_data_";
#define SIZE 4

void proceso();
void* actualizar_datos(void* param);
void* read_pipe(void *param);

arg_thread data[6];
int N_sensores;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;

    proceso();


    window.n_sensores = N_sensores;
    window.configurar_interfaz();
    window.configurar_interfaz2();
    window.show();
    std::cout << "Empezamos" << std::endl;
    window.resize(1172, 735);
    pthread_t tid; //id del hilo
    pthread_attr_t attr; //atributos del hilo
    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, actualizar_datos, &window);

    return a.exec();
}

void proceso(){
        int fd_start;
        char Arr1[SIZE];

        printf("Abriendo: %s\n", name_start);
        fd_start = open(name_start, O_RDONLY);
        printf("Fd: %i\n", fd_start);
        read(fd_start, Arr1, SIZE);
        N_sensores = Arr1[0];
        printf("Numero de sensores leidos: %i\n", N_sensores);

        pthread_t threads[N_sensores];
        pthread_attr_t attr[N_sensores];

        for(int i=0; i<6; i++){
            data[i].x =0;
            data[i].y = 0;
            data[i].z = 0;
        }

        for(int i=0; i<N_sensores; i++){
        data[i].i = i;
        pthread_attr_init(&attr[i]);
        pthread_create(&threads[i], &attr[i], read_pipe, &data[i]);
        }
}

void* read_pipe(void *data){
    int i = ((arg_thread*)data)->i;
    int fd;
    double Read[3];
    char name[50];
    sprintf(name, "%s%i", name_sensor, i);
    printf("[%i] Abriendo: %s\n", i, name);
    sleep(1);
    while(1){
    fd = open(name, O_RDONLY);
    read(fd, Read, 3*sizeof(double));
    ((arg_thread*)data)->x = Read[0];
    ((arg_thread*)data)->y = Read[1];
    ((arg_thread*)data)->z = Read[2];
    close(fd);
    }
}

void* actualizar_datos(void* param){
    while(1){
        for(int i=0; i<N_sensores; i++){
            ((MainWindow*)param)->sensor[i].x= data[i].x;
            ((MainWindow*)param)->sensor[i].y= data[i].y;
            ((MainWindow*)param)->sensor[i].z= data[i].z;
        }

            ((MainWindow*)param)->coord[0].x_1= data[0].x;
            ((MainWindow*)param)->coord[0].x_2= data[1].x;
            ((MainWindow*)param)->coord[0].x_3= data[2].x;
            ((MainWindow*)param)->coord[0].x_4= data[3].x;
            ((MainWindow*)param)->coord[0].x_5= data[4].x;
            ((MainWindow*)param)->coord[0].x_6= data[5].x;

            ((MainWindow*)param)->coord[1].x_1= data[0].y;
            ((MainWindow*)param)->coord[1].x_2= data[1].y;
            ((MainWindow*)param)->coord[1].x_3= data[2].y;
            ((MainWindow*)param)->coord[1].x_4= data[3].y;
            ((MainWindow*)param)->coord[1].x_5= data[4].y;
            ((MainWindow*)param)->coord[1].x_6= data[5].y;

            ((MainWindow*)param)->coord[2].x_1= data[0].z;
            ((MainWindow*)param)->coord[2].x_2= data[1].z;
            ((MainWindow*)param)->coord[2].x_3= data[2].z;
            ((MainWindow*)param)->coord[2].x_4= data[3].z;
            ((MainWindow*)param)->coord[2].x_5= data[4].z;
            ((MainWindow*)param)->coord[2].x_6= data[5].z;

            ((MainWindow*)param)->Actualizar_interfaz();
        usleep(1000*80);
    }

}
