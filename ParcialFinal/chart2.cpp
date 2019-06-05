#include "chart2.h"

#include "chart.h"
#include <QtCharts/QAbstractAxis>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QtCore/QDebug>

Chart2::Chart2(QGraphicsItem *parent, Qt::WindowFlags wFlags):
    QChart(QChart::ChartTypeCartesian, parent, wFlags),
    x_series(0), y_series(0), z_series(0),
    xx_series(0), yy_series(0), zz_series(0),
    m_axisX(new QValueAxis()),
    m_axisY(new QValueAxis()),
    m_step(0),
    m_x(5),
    x_y(1),
    y_y(1),
    z_y(1),
    xx_y(1),
    yy_y(1),
    zz_y(1)
{
    QObject::connect(&m_timer, &QTimer::timeout, this, &Chart::handleTimeout);
    m_timer.setInterval(500);

    x_series = new QSplineSeries(this);
    y_series = new QSplineSeries(this);
    z_series = new QSplineSeries(this);
    xx_series = new QSplineSeries(this);
    yy_series = new QSplineSeries(this);
    zz_series = new QSplineSeries(this);

    QPen x_pen(QRgb(0xFF8B00));
    QPen y_pen(QRgb(0x0085FF));
    QPen z_pen(QRgb(0x06FF00));

    QPen xx_pen(QRgb(0xD00707));
    QPen yy_pen(QRgb(0x8800FF));
    QPen zz_pen(QRgb(0x000000));


    x_pen.setWidth(1);
    y_pen.setWidth(1);
    z_pen.setWidth(1);
    xx_pen.setWidth(1);
    yy_pen.setWidth(1);
    zz_pen.setWidth(1);

    x_series->setPen(x_pen);
    y_series->setPen(y_pen);
    z_series->setPen(z_pen);
    xx_series->setPen(xx_pen);
    yy_series->setPen(yy_pen);
    zz_series->setPen(zz_pen);

    x_series->append(m_x, x_y);
    y_series->append(m_x, y_y);
    z_series->append(m_x, z_y);

    xx_series->append(m_x, xx_y);
    yy_series->append(m_x, yy_y);
    zz_series->append(m_x, zz_y);

    addSeries(x_series);
    addSeries(y_series);
    addSeries(z_series);

    addSeries(xx_series);
    addSeries(yy_series);
    addSeries(zz_series);

    addAxis(m_axisX,Qt::AlignBottom);
    addAxis(m_axisY,Qt::AlignLeft);
    x_series->attachAxis(m_axisX);
    x_series->attachAxis(m_axisY);

    y_series->attachAxis(m_axisX);
    y_series->attachAxis(m_axisY);

    z_series->attachAxis(m_axisX);
    z_series->attachAxis(m_axisY);

    xx_series->attachAxis(m_axisX);
    x_series->attachAxis(m_axisY);

    yy_series->attachAxis(m_axisX);
    y_series->attachAxis(m_axisY);

    zz_series->attachAxis(m_axisX);
    z_series->attachAxis(m_axisY);

    m_axisX->setTickCount(10);
    m_axisX->setRange(0, 5);
    m_axisY->setRange(-2, 2);

    m_timer.start();
}

Chart2::~Chart()
{

}

void Chart2::handleTimeout()
{
    qreal x = plotArea().width() / m_axisX->tickCount();
    qreal y = (m_axisX->max() - m_axisX->min()) / m_axisX->tickCount();
    m_x += y;
    x_y = data_1;
    y_y = data_2;
    z_y = data_3;
    xx_y = data_4;
    yy_y = data_5;
    zz_y = data_6;

    if(x_y!=0){x_series->append(m_x, x_y);}
    if(y_y!=0){y_series->append(m_x, y_y);}
    if(z_y!=0){z_series->append(m_x, z_y);}

    if(xx_y!=0){x_series->append(m_x, xx_y);}
    if(yy_y!=0){y_series->append(m_x, yy_y);}
    if(zz_y!=0){z_series->append(m_x, zz_y);}

    scroll(x, 0);
    if (m_x == 500)
            m_timer.stop();
}
