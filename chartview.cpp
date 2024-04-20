#include <QPushButton>
#include "chartview.h"

ChartView::ChartView(QWidget *parent)
    : QWidget{parent}
{
    qDebug()<<"hey chart";
    chart = new QChart;
    chartView= new QChartView(chart);

    QLineSeries* series = new QLineSeries();
    QList<QPointF> data;
    *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);


    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(chartView);
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);
    chartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    chart->layout()->setContentsMargins(0, 0, 0, 0);

    chart->addSeries(series);

    chart->createDefaultAxes();


    chartView->setRenderHint(QPainter::Antialiasing);

    chart->legend()->setVisible(false);

    chartView->setChart(chart);

    chartView->setParent(this);


}
