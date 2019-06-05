/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *Title;
    QLabel *JAVIER;
    QTabWidget *tabWidget;
    QWidget *tab;
    QFrame *verticalFrame;
    QVBoxLayout *L1;
    QFrame *chart1;
    QFrame *verticalFrame_2;
    QVBoxLayout *L2;
    QFrame *chart2;
    QFrame *verticalFrame_3;
    QVBoxLayout *L3;
    QFrame *chart6;
    QFrame *verticalFrame_4;
    QVBoxLayout *L4;
    QFrame *chart3;
    QFrame *verticalFrame_6;
    QVBoxLayout *L6;
    QFrame *chart4;
    QFrame *verticalFrame_5;
    QVBoxLayout *L5;
    QFrame *chart5;
    QWidget *tab_2;
    QFrame *verticalFrame_7;
    QVBoxLayout *L1_2;
    QFrame *chartx;
    QFrame *verticalFrame_8;
    QVBoxLayout *L1_3;
    QFrame *charty;
    QFrame *verticalFrame_9;
    QVBoxLayout *L1_4;
    QFrame *chartz;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1171, 734);
        MainWindow->setMinimumSize(QSize(1170, 730));
        MainWindow->setMaximumSize(QSize(1180, 740));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(0, 0));
        centralWidget->setMaximumSize(QSize(1180, 680));
        Title = new QLabel(centralWidget);
        Title->setObjectName(QStringLiteral("Title"));
        Title->setGeometry(QRect(380, 10, 181, 31));
        JAVIER = new QLabel(centralWidget);
        JAVIER->setObjectName(QStringLiteral("JAVIER"));
        JAVIER->setGeometry(QRect(640, 0, 461, 71));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 20, 1171, 671));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalFrame = new QFrame(tab);
        verticalFrame->setObjectName(QStringLiteral("verticalFrame"));
        verticalFrame->setGeometry(QRect(10, 0, 571, 211));
        L1 = new QVBoxLayout(verticalFrame);
        L1->setSpacing(6);
        L1->setContentsMargins(11, 11, 11, 11);
        L1->setObjectName(QStringLiteral("L1"));
        chart1 = new QFrame(verticalFrame);
        chart1->setObjectName(QStringLiteral("chart1"));
        chart1->setFrameShape(QFrame::StyledPanel);
        chart1->setFrameShadow(QFrame::Raised);

        L1->addWidget(chart1);

        verticalFrame_2 = new QFrame(tab);
        verticalFrame_2->setObjectName(QStringLiteral("verticalFrame_2"));
        verticalFrame_2->setGeometry(QRect(580, 0, 551, 211));
        L2 = new QVBoxLayout(verticalFrame_2);
        L2->setSpacing(6);
        L2->setContentsMargins(11, 11, 11, 11);
        L2->setObjectName(QStringLiteral("L2"));
        chart2 = new QFrame(verticalFrame_2);
        chart2->setObjectName(QStringLiteral("chart2"));
        chart2->setFrameShape(QFrame::StyledPanel);
        chart2->setFrameShadow(QFrame::Raised);

        L2->addWidget(chart2);

        verticalFrame_3 = new QFrame(tab);
        verticalFrame_3->setObjectName(QStringLiteral("verticalFrame_3"));
        verticalFrame_3->setGeometry(QRect(580, 420, 551, 201));
        L3 = new QVBoxLayout(verticalFrame_3);
        L3->setSpacing(6);
        L3->setContentsMargins(11, 11, 11, 11);
        L3->setObjectName(QStringLiteral("L3"));
        chart6 = new QFrame(verticalFrame_3);
        chart6->setObjectName(QStringLiteral("chart6"));
        chart6->setFrameShape(QFrame::StyledPanel);
        chart6->setFrameShadow(QFrame::Raised);

        L3->addWidget(chart6);

        verticalFrame_4 = new QFrame(tab);
        verticalFrame_4->setObjectName(QStringLiteral("verticalFrame_4"));
        verticalFrame_4->setGeometry(QRect(10, 210, 571, 211));
        L4 = new QVBoxLayout(verticalFrame_4);
        L4->setSpacing(6);
        L4->setContentsMargins(11, 11, 11, 11);
        L4->setObjectName(QStringLiteral("L4"));
        chart3 = new QFrame(verticalFrame_4);
        chart3->setObjectName(QStringLiteral("chart3"));
        chart3->setFrameShape(QFrame::StyledPanel);
        chart3->setFrameShadow(QFrame::Raised);

        L4->addWidget(chart3);

        verticalFrame_6 = new QFrame(tab);
        verticalFrame_6->setObjectName(QStringLiteral("verticalFrame_6"));
        verticalFrame_6->setGeometry(QRect(580, 210, 551, 211));
        L6 = new QVBoxLayout(verticalFrame_6);
        L6->setSpacing(6);
        L6->setContentsMargins(11, 11, 11, 11);
        L6->setObjectName(QStringLiteral("L6"));
        chart4 = new QFrame(verticalFrame_6);
        chart4->setObjectName(QStringLiteral("chart4"));
        chart4->setFrameShape(QFrame::StyledPanel);
        chart4->setFrameShadow(QFrame::Raised);

        L6->addWidget(chart4);

        verticalFrame_5 = new QFrame(tab);
        verticalFrame_5->setObjectName(QStringLiteral("verticalFrame_5"));
        verticalFrame_5->setGeometry(QRect(10, 420, 571, 201));
        L5 = new QVBoxLayout(verticalFrame_5);
        L5->setSpacing(6);
        L5->setContentsMargins(11, 11, 11, 11);
        L5->setObjectName(QStringLiteral("L5"));
        chart5 = new QFrame(verticalFrame_5);
        chart5->setObjectName(QStringLiteral("chart5"));
        chart5->setFrameShape(QFrame::StyledPanel);
        chart5->setFrameShadow(QFrame::Raised);

        L5->addWidget(chart5);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalFrame_7 = new QFrame(tab_2);
        verticalFrame_7->setObjectName(QStringLiteral("verticalFrame_7"));
        verticalFrame_7->setGeometry(QRect(10, 50, 571, 281));
        L1_2 = new QVBoxLayout(verticalFrame_7);
        L1_2->setSpacing(6);
        L1_2->setContentsMargins(11, 11, 11, 11);
        L1_2->setObjectName(QStringLiteral("L1_2"));
        chartx = new QFrame(verticalFrame_7);
        chartx->setObjectName(QStringLiteral("chartx"));
        chartx->setFrameShape(QFrame::StyledPanel);
        chartx->setFrameShadow(QFrame::Raised);

        L1_2->addWidget(chartx);

        verticalFrame_8 = new QFrame(tab_2);
        verticalFrame_8->setObjectName(QStringLiteral("verticalFrame_8"));
        verticalFrame_8->setGeometry(QRect(580, 50, 571, 281));
        L1_3 = new QVBoxLayout(verticalFrame_8);
        L1_3->setSpacing(6);
        L1_3->setContentsMargins(11, 11, 11, 11);
        L1_3->setObjectName(QStringLiteral("L1_3"));
        charty = new QFrame(verticalFrame_8);
        charty->setObjectName(QStringLiteral("charty"));
        charty->setFrameShape(QFrame::StyledPanel);
        charty->setFrameShadow(QFrame::Raised);

        L1_3->addWidget(charty);

        verticalFrame_9 = new QFrame(tab_2);
        verticalFrame_9->setObjectName(QStringLiteral("verticalFrame_9"));
        verticalFrame_9->setGeometry(QRect(320, 330, 571, 281));
        L1_4 = new QVBoxLayout(verticalFrame_9);
        L1_4->setSpacing(6);
        L1_4->setContentsMargins(11, 11, 11, 11);
        L1_4->setObjectName(QStringLiteral("L1_4"));
        chartz = new QFrame(verticalFrame_9);
        chartz->setObjectName(QStringLiteral("chartz"));
        chartz->setFrameShape(QFrame::StyledPanel);
        chartz->setFrameShadow(QFrame::Raised);

        L1_4->addWidget(chartz);

        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(950, 420, 171, 161));
        label->setWordWrap(true);
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 400, 171, 161));
        label_2->setWordWrap(true);
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1171, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        Title->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Parcial FInal Digitales III</p></body></html>", Q_NULLPTR));
        JAVIER->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Presentado por: Javier Alexis Cardenas y Johan Sebasti\303\241n Casagua</p></body></html>", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Sensores", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Ahi estan todas las lineas... lo que pasa es que como algunas tuberias el numero aleatorio es el mismo, pues entonces las lineas se superponen </p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Tambien toca maximixar el programa para que los cuadros se acomoden o simplemente modificar alguno de los bordes (ampliar la ventana o reducirla)</p></body></html>", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Coordenadas", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
