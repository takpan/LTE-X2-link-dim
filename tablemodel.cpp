#include "tablemodel.h"

TableModel::TableModel(QObject *parent) :
    QAbstractTableModel(parent)
{
    arrayRows = 0;
    arrayColumns = 0;
}

TableModel::TableModel(int rows, int columns, QVector<QVariant> header, QObject *parent) :
    QAbstractTableModel(parent)
{
    arrayRows = rows;
    arrayColumns = columns;
    header.resize(arrayColumns);
    m_header = header;

    if (rows >= 0)
    {
        arrayRows = rows;
        m_dataTable.resize(arrayRows);
    }

    if (arrayRows > 0 && columns >= 0)
    {
        arrayColumns = columns;
        for (int i = 0; i < arrayRows; i++)
            m_dataTable[i].resize(arrayColumns);
    }
}

TableModel::TableModel(QVector<QVector<QVariant> > dataTable, QObject *parent)
    : QAbstractTableModel(parent)
{
    arrayRows = dataTable.size();
    if (arrayRows > 0)
        arrayColumns = dataTable[0].size();

    m_dataTable = dataTable;
    m_dataTable.resize(arrayRows);

    for (int i = 0; i < arrayRows; i++)
        m_dataTable[i].resize(arrayColumns);
}

int TableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return arrayRows;
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return arrayColumns;
}

QVariant TableModel::data(const QModelIndex &cellIndex, int role) const
{
    if (!cellIndex.isValid())
        return QVariant();

    if (cellIndex.row() >= m_dataTable.size() || cellIndex.row() < 0)
        return QVariant();

    if (role == Qt::TextAlignmentRole)
        return Qt::AlignCenter;

    if (role == Qt::DisplayRole) {
        QVariant rowData = m_dataTable[cellIndex.row()][cellIndex.column()];
        if (digitsAfterDecimalPoint(rowData) > 3)
            rowData = QString::number(rowData.toDouble(), 'g');
//        if (cellIndex.column() >=3 && rowData > 0)
//            rowData = QString::number(rowData.toDouble(), 'f', 3);

        return rowData;
    }

    return QVariant();
}

QVariant TableModel::headerData(int section,Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        return m_header[section];

    return QVariant();
}

bool TableModel::insertRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginInsertRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; ++row)
    {
        QVector<QVariant> newRow(arrayColumns);
        m_dataTable.insert(position, newRow);
        setData(index, newRow);
    }

    endInsertRows();    
    arrayRows += rows;

    return true;
}

bool TableModel::insertRows(int position, int rows, int idStartValue, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginInsertRows(QModelIndex(), position, position + rows - 1);

    for (int i = 0; i < rows; i++)
    {
        QVector<QVariant> newRow(arrayColumns);
        newRow[0] = position + 1 + i;
        m_dataTable.insert(position + i, newRow);
        setData(index, newRow);
    }

    endInsertRows();
    arrayRows += rows;

    return true;
}

bool TableModel::removeRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginRemoveRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; ++row) {
        m_dataTable.removeAt(position);
    }

    endRemoveRows();
    arrayRows -= rows;
    return true;
}

bool TableModel::insertColumns(int position, int columns, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginInsertColumns(QModelIndex(), position, position + columns - 1);

    for (int i = 0; i < arrayRows; ++i)
    {
        m_dataTable[i].resize(arrayColumns + columns);
        //setData(index,newRow);
        m_dataTable[i][1] = 5;
        //congVectTableHeader.resize(2);
    }


    endInsertColumns();
    arrayColumns += columns;

    return true;
}

bool TableModel::setData(const QModelIndex &startIndex, const QVector<QVariant> &rowData, int role)
{
    if (startIndex.isValid() && role == Qt::DisplayRole) {
        int row = startIndex.row();

        m_dataTable.replace(row, rowData);
        QModelIndex endIndex = index(row, arrayColumns - 1, QModelIndex());
        emit(dataChanged(startIndex, endIndex)); // When reimplementing the setData() function, this signal must be emitted explicitly.

        return true;
    }

    return false;
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

QVector<QVector<QVariant> > TableModel::getDataTable()
{
    return m_dataTable;
}

void TableModel::setDataTable(QVector<QVector<QVariant> > dataTable)
{
    m_dataTable = dataTable;
}

float TableModel::sumOfColumn(int column)
{
    float sum = 0;

    for (int i = 0; i < arrayRows; i++)
        sum += m_dataTable[i][column].toFloat();

    return sum;
}

QVector<QVariant> TableModel::columnVector(int index)
{
    QVector<QVariant> column;

    column.resize(arrayRows);

    for (int i = 0; i < arrayRows; i++)
        column[i] = m_dataTable[i][index];

    return column;
}

void TableModel::setHeader(QVector<QVariant> header)
{
    m_header = header;
}

void TableModel::setRowNum(int rows)
{
    arrayRows = rows;
    m_dataTable.resize(arrayRows);
}

void TableModel::setColumnNum(int columns)
{
    arrayColumns = columns;

    if (arrayRows > 0 && columns >= 0)
    {
        arrayColumns = columns;
        for (int i = 0; i < arrayRows; i++)
            m_dataTable[i].resize(arrayColumns);
    }
}















