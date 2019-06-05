#ifndef CHART2_H
#define CHART2_H

#include <QtCharts/QChart>
#include <QtCore/QTimer>

QT_CHARTS_BEGIN_NAMESPACE
class QSplineSeries;
class QValueAxis;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class Chart2: public QChart
{
    Q_OBJECT
public:
    double data_1, data_2, data_3, data_4, data_5, data_6;
    Chart2(QGraphicsItem *parent = 0, Qt::WindowFlags wFlags = 0);
    virtual ~Chart2();

public slots:
    void handleTimeout();

private:
    int color;
    QTimer m_timer;
    QSplineSeries *x_series, *y_series, *z_series, *xx_series, *yy_series, *zz_series;
    QStringList m_titles;
    QValueAxis *m_axisX;
    QValueAxis *m_axisY;
    qreal m_step;
    qreal m_x;
    qreal x_y, y_y, z_y, xx_y, yy_y, zz_y;
};

#endif // CHART2_H
