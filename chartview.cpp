#include <QPushButton>
#include "chartview.h"

ChartView::ChartView(QWidget *parent)
    : QWidget{parent}
{
    qDebug()<<"hey chart";
    chart = new QChart;
    chartView= new QChartView(chart);

    QLineSeries* series = new QLineSeries();
    QVector<QPointF> data;
    data << QPointF(0, 0) << QPointF(1, 1) << QPointF(2, 2) << QPointF(3, 1) << QPointF(4, 0) << QPointF(5, 2) << QPointF(6, 5) << QPointF(7, 10);


    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(chartView);
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);

//    QPen pen(QColor("#dcbc14"));
//    pen.setWidth(2);
//    series->setPen(pen);
//    chart->setBackgroundBrush(QColor("#333333"));

    // Set the size policy of the chart widget to expand and fill the available space
    chartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    chart->layout()->setContentsMargins(0, 0, 0, 0);

    series->append(data);

    chart->addSeries(series);

    chart->createDefaultAxes();


    chartView->setRenderHint(QPainter::Antialiasing);

    chart->legend()->setVisible(false);

    chartView->setChart(chart);

    chartView->setParent(this);


}
