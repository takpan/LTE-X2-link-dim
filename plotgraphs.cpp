#include "plotgraphs.h"

PlotGraphs::PlotGraphs(QWidget *parent):
    QCustomPlot(parent)
{
    this->xAxis->setLabel("Step");
    this->yAxis->setLabel("Blocking probabiity");
    this->xAxis->setAutoTickStep(false);
    this->xAxis->setTickStep(1);
}

void PlotGraphs::createGraph(QVector<QVector<double> > pbOut, QVector<QString> colorList)
{
    QVector<double> x;
    QVector<QVector<double> > y;
    QColor baseColor;
    int xItems, c, count;

    xItems = pbOut[0].size();
    c = pbOut.size();
    x.resize(xItems);
    y.resize(xItems);

    if ((count = c - graphCount()) > 0)
    {
        for (int i = 0; i < count; i++)
            addGraph();
    }
    else if ((count = graphCount() - c) < 0)
    {
        for (int i = 0; i < count; i++)
            removeGraph(graphCount() - 1);
    }

    for (int i = 0; i < xItems; i++)
    {
        x[i] = i;
    }

    for (int i = 0; i < c; i++)
    {
        graph(i)->setData(x, pbOut[i]);
        if (i < colorList.size())
            baseColor.setNamedColor(colorList[i]);
        else
            baseColor.setNamedColor("#494949");

        graph(i)->setPen(QPen(baseColor));
        graph(i)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, QPen(baseColor, 1), QBrush(baseColor), 6));
        graph(i)->setName("Serv. class " + QString::number(i + 1));
        //graph(i)->rescaleAxes();
    }

    this->legend->setVisible(true);
    QObject::connect(this->xAxis, SIGNAL(rangeChanged(QCPRange)), this->xAxis2, SLOT(setRange(QCPRange)));
    QObject::connect(this->yAxis, SIGNAL(rangeChanged(QCPRange)), this->yAxis2, SLOT(setRange(QCPRange)));
    setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    this->rescaleAxes();
    replot();
}

//void PlotGraphs::createUGraph(const QVector<double> &linkUt)
//{
//    QVector<double> x, y;
//    int xItems;

//    xItems = linkUt.size();
//    x.resize(xItems);
//    y.resize(xItems);
//    clearGraphs();
//    addGraph();

//    for (int i = 0; i < xItems; i++)
//    {
//        x[i] = i;
//        y[i] = linkUt[i];
//    }

//    graph(0)->setData(x, y);
//    graph(0)->setPen(QPen(Qt::gray));
//    graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, QPen(Qt::gray, 1), QBrush(Qt::gray), 6));

//    QObject::connect(this->xAxis, SIGNAL(rangeChanged(QCPRange)), this->xAxis2, SLOT(setRange(QCPRange)));
//    QObject::connect(this->yAxis, SIGNAL(rangeChanged(QCPRange)), this->yAxis2, SLOT(setRange(QCPRange)));
//    setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
//    this->rescaleAxes();
//    replot();
//}

