#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDataWidgetMapper>
#include <QtCore/qmath.h>
#include "tablemodel.h"
#include "mathfunctions.h"
#include "plotoutputdialog.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    PlotOutputDialog* pod;

    QVector<double> convertQVariantToDouble(const QVector<QVariant> &qVarVector);

    QVector<QVariant> convertIntToQVariant(const QVector<int> &intVector);

    void refreshInputTable();

signals:
    //void passInputTable(QVector<QVector<QVariant>> dataTable, QVector<QVariant> header);
    void passInputTableModel(TableModel *tableModel);

    void passGeneralParameters(bool enhModel, bool trunkResBool, int c, double r, double u, double delay, double cX2);

private slots:
    void on_pbRadioButton_toggled(bool checked);

    void on_calculatePushButton_clicked();

    void on_rLineEdit_textChanged(const QString &arg1);

    void on_uLineEdit_textChanged(const QString &arg1);

    void on_dComLineEdit_textChanged(const QString &arg1);

    void on_bLineEdit_textChanged(const QString &arg1);

    void on_qLineEdit_textChanged(const QString &arg1);

    void on_delayLineEdit_textChanged(const QString &arg1);

    void on_setbRadioButton_toggled(bool checked);

    void on_cSpinBox_valueChanged(int arg1);

    void on_nLineEdit_textChanged(const QString &arg1);

    void on_dUeLineEdit_textChanged(const QString &arg1);

    void on_pCongInputLineEdit_textChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_servClassComboBox_currentIndexChanged(int index);

    void on_userServClassComboBox_currentIndexChanged(int index);

    void on_enhModelCheckBox_toggled(bool checked);

    void on_cX2LineEdit_textChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_firstValPlotLineEdit_textChanged(const QString &arg1);

    void on_stepLineEdit_textChanged(const QString &arg1);

    void on_numOfStepsLineEdit_textChanged(const QString &arg1);

    void on_plotExportPushButton_clicked();

    void on_rLineEdit_returnPressed();

    void on_uLineEdit_returnPressed();

    void on_delayLineEdit_returnPressed();

    void on_cX2LineEdit_returnPressed();

    void on_nLineEdit_returnPressed();

    void on_dUeLineEdit_returnPressed();

    void on_dComLineEdit_returnPressed();

    void on_bLineEdit_returnPressed();

    void on_qLineEdit_returnPressed();

    void on_pCongInputLineEdit_returnPressed();

    void on_setMaxDurationPushButton_clicked();

    void on_trunkResCheckBox_toggled(bool checked);

    void on_trunkResLineEdit_textChanged(const QString &arg1);

    void on_trunkResLineEdit_returnPressed();

private:
    QDataWidgetMapper *inputDataMapper;
    TableModel *inputTableModel, *congProbTableModel;
    QVector<TableModel*> congVectTableModel;
    Ui::MainWindow *ui;
    int servClassIndex, n, k, c, plotNumOfSteps, inputTableWidth;
    double r, u, dCom, dComMax, pExit, pStay, delay, q, ueThroughput, dX2, dX2Enh, trunkRes, pCong, cX2, b, dUe, plotFirstVal, plotStep;
    QVector<QVariant> inputTableHeader, congVectTableHeader, congProbTableHeader;
    bool enhModel, trunkResBool;
};

#endif // MAINWINDOW_H
