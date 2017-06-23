#ifndef INPUTDATAMODEL_H
#define INPUTDATAMODEL_H

#include <QAbstractTableModel>
#include <QList>
#include <QPair>
#include "mathfunctions.h"


class TableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    TableModel(QObject *parent = 0);

    TableModel(int rows, int columns, QVector<QVariant> header, QObject *parent = 0);

    TableModel(QVector<QVector<QVariant> > dataTable, QObject *parent = 0);

    int rowCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;

    int columnCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &cellIndex, int role) const Q_DECL_OVERRIDE;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;

    Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;

    bool setData(const QModelIndex &startIndex, const QVector<QVariant> &rowData, int role = Qt::EditRole); //  Q_DECL_OVERRIDE;

    bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex()) Q_DECL_OVERRIDE;

    bool insertRows(int position, int rows, int idStartValue, const QModelIndex &index = QModelIndex());

    bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex()) Q_DECL_OVERRIDE;

    bool insertColumns(int position, int columns, const QModelIndex &index= QModelIndex()) Q_DECL_OVERRIDE;

    QVector<QVector<QVariant> > getDataTable();

    void setDataTable(QVector<QVector<QVariant> > dataTable);

    float sumOfColumn (int column);

    QVector<QVariant> columnVector(int index);

    void setHeader(QVector<QVariant> header);

    void setRowNum(int rows);

    void setColumnNum(int columns);

private:
    int arrayRows, arrayColumns;
    QVector<QVariant> m_header;
    QVector<QVector<QVariant> > m_dataTable;
};

#endif // INPUTDATAMODEL_H
