#include "threaddatos.h"
#include "mainwindow.h".h"

ThreadDatos::ThreadDatos(QObject *parent) : QThread(parent)
{

}

void ThreadDatos::run(){
    while (1) {
       emit signal(0);
        usleep(1000*100);;
    }
}
