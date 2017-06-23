#ifndef PLOTOUTPUTDIALOG_H
#define PLOTOUTPUTDIALOG_H

#include "tablemodel.h"
#include "mathfunctions.h"
#include "plotgraphs.h"
#include "exportdialog.h"

#include <QDialog>

namespace Ui {
class PlotOutputDialog;
}

class PlotOutputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PlotOutputDialog(QWidget *parent = 0);
    ~PlotOutputDialog();

    int searchValueInVector(const QVector<QVariant> &vector, const int &value);

    QVector<QVector<double> > createCongProbArray(TableModel *congProbTableModel);

    //QVector<QVariant> findStartVector(const QVector<QVector<QVariant>> &usersArray, const QVector<QVariant> &nInitialVector);

public slots:
    //void receiveInputTable(QVector<QVector<QVariant>> inputDataTable, QVector<QVariant> inputTableHeader);
    void receiveInputTableModel(TableModel *tableModel);

    void receiveGeneralParameters(bool enhModel, bool trunkResBool, int c, double r, double u, double delay, double cX2);

    void receiveExportTablesPath(QString path, bool write, QString fileExt, QString delim);

private slots:
    void on_numOfStepsLineEdit_textChanged(const QString &arg1);

    void on_nMinLineEdit_textChanged(const QString &arg1);

    void on_userStepLlineEdit_textChanged(const QString &arg1);

    void on_cX2MinLineEdit_textChanged(const QString &arg1);

    void on_cX2StepLlineEdit_textChanged(const QString &arg1);

    void on_setButton_clicked();

    void on_removeButton_clicked();

    void on_servClassComboBox_currentIndexChanged(int index);

    void on_plotPushButton_clicked();

    void on_plotServClassComboBox_currentIndexChanged(int index);

    void on_plotShowCheckBox_toggled(bool checked);

    void on_scatterComboBox_currentIndexChanged(int index);

    void on_rescalePushButton_clicked();

    void on_backPushButton_clicked();

    void on_numOfStepsLineEdit_returnPressed();

    void on_nMinLineEdit_returnPressed();

    void on_userStepLlineEdit_returnPressed();

    void on_cX2MinLineEdit_returnPressed();

    void on_exportTablesPushButton_clicked();

    void on_PlotOutputDialog_rejected();

private:
    Ui::PlotOutputDialog *ui;

    TableModel *inputTableModel, *usersTableModel, *copyOfInputTableModel, *xAxisTabeModel, *congProbTableModel;
    int c, numOfSteps, nMin, userStep, servClassIndex;
    double r, u, delay, cX2, cX2Min, cX2Step;
    QVector<QVariant> usersTableHeader, xAxisTableHeader, congProbTableHeader, nInitialVector, nStartVector, userStepVector;
    QVector<QVector<QVariant> > importedDataTable;
    bool enhModel, write, trunkResBool;
    QVector<QString> colorList;
    QVector<QCPScatterStyle::ScatterShape> scatterShapes;
    ExportDialog *etd;
    QString path, fileExt, delim, exportTablesPath;
};

#endif // PLOTOUTPUTDIALOG_H
