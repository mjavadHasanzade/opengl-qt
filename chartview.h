#ifndef CHARTVIEW_H
#define CHARTVIEW_H

#include <QWidget>
#include <QtCharts>


class ChartView : public QWidget
{
    Q_OBJECT
public:
    explicit ChartView(QWidget *parent = nullptr);
signals:

private:
    QChartView *chartView;
    QChart *chart;



};

#endif // CHARTVIEW_H
