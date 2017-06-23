#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // create input table header vector:

    inputTableHeader.resize(8);
    inputTableHeader[0] = "Serv. class";
    inputTableHeader[1] = "n";
    inputTableHeader[2] = "Δ (sec)";
    inputTableHeader[3] = "DX2";
    inputTableHeader[4] = "DX2 enh.";
    inputTableHeader[5] = "Trunk res.";
    inputTableHeader[6] = "Pexit";
    inputTableHeader[7] = "p";
    //-----------------------------------------------------------------------------

    //create and set input table model:

    inputTableModel = new TableModel(0, 8, inputTableHeader);

    ui->inputTableView->setModel(inputTableModel);
    ui->inputTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    inputTableModel->insertRows(0, 1, 1, QModelIndex());

    ui->inputTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->inputTableView->horizontalHeader()->setDefaultSectionSize(60);
    ui->inputTableView->verticalHeader()->setDefaultSectionSize(20);
    ui->inputTableView->verticalHeader()->setVisible(false);
    ui->inputTableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->inputTableView->setColumnHidden(3, false);
    ui->inputTableView->setColumnHidden(4, true);
    ui->inputTableView->setColumnHidden(5, true);
    ui->inputTableView->setColumnHidden(7, true);

    //create and set congestion vectors table model:


    //congVectTableModel = new TableModel(0, c, congVectTableHeader);


    //congVectTableModel->insertRows(0, 1, 1, QModelIndex());

    ui->congVectorsTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->congVectorsTableView->horizontalHeader()->setDefaultSectionSize(60);
    ui->congVectorsTableView->verticalHeader()->setDefaultSectionSize(20);
    ui->congVectorsTableView->verticalHeader()->setVisible(false);
    ui->congVectorsTableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);


    ui->congProbTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->congProbTableView->horizontalHeader()->setDefaultSectionSize(120);
    ui->congProbTableView->verticalHeader()->setDefaultSectionSize(20);
    ui->congProbTableView->verticalHeader()->setVisible(false);
    ui->congProbTableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    //-----------------------------------------------------------------------------

    // initializations:

    servClassIndex = 0;
    c = 1;
    inputTableWidth = 379;
    enhModel = false;
    trunkResBool = false;

    ui->pbRadioButton->setChecked(true);
    ui->enhModelCheckBox->setChecked(false);
    ui->trunkResLineEdit->setDisabled(true);
    ui->setbRadioButton->setChecked(true);
    ui->pCongInputLineEdit->setDisabled(true);
    //-----------------------------------------------------------------------------

    ui->rLineEdit->setText("0.25");
    ui->uLineEdit->setText("12");
    ui->delayLineEdit->setText("25");
    ui->cX2LineEdit->setText("1.280");
//    ui->nLineEdit->setText("3");
//    ui->dComLineEdit->setText("80");
//    ui->dUeLineEdit->setText("0.9");
//    ui->bLineEdit->setText("100");

//    ui->inputTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
//    ui->inputTableWidget->horizontalHeader()->setDefaultSectionSize(60);
//    ui->inputTableWidget->verticalHeader()->setDefaultSectionSize(20);
//    ui->inputTableWidget->verticalHeader()->setVisible(false);
//    ui->inputTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//-----------------------------------------------------------------------------
// PRIVATE SLOTS:
//-----------------------------------------------------------------------------
void MainWindow::on_pbRadioButton_toggled(bool checked)
{
    if (checked)
    {
        ui->pCongInputLineEdit->setDisabled(true);
        ui->cX2LineEdit->setDisabled(false);
        ui->inputTableView->setColumnHidden(7, true);
        ui->congVectorsTableView->setDisabled(false);
        ui->userServClassComboBox->setDisabled(false);
        ui->cX2OutLabel->setText("");
        inputTableWidth -= 60;
        ui->inputTableView->setFixedWidth(inputTableWidth);
        ui->plotExportPushButton->setDisabled(false);
    }
    else
    {
        ui->pCongInputLineEdit->setDisabled(false);
        ui->cX2LineEdit->setDisabled(true);
        ui->inputTableView->setColumnHidden(7, false);
        ui->congVectorsTableView->setDisabled(true);
        ui->userServClassComboBox->setDisabled(true);
        inputTableWidth += 60;
        ui->inputTableView->setFixedWidth(inputTableWidth);
        ui->plotExportPushButton->setDisabled(true);
    }
}

void MainWindow::on_enhModelCheckBox_toggled(bool checked)
{
    bool temp = ui->setbRadioButton->isChecked();

    if (checked)
    {
        ui->setbRadioButton->setDisabled(true);
        ui->setQdRadioButton->setDisabled(true);
        ui->bLineEdit->setDisabled(true);
        ui->qLineEdit->setDisabled(true);
        ui->inputTableView->setColumnHidden(3, true);
        ui->inputTableView->setColumnHidden(4, false);
        enhModel = true;
    }
    else
    {
        ui->setbRadioButton->setDisabled(false);
        ui->setQdRadioButton->setDisabled(false);

        if (temp)
        {
            ui->bLineEdit->setDisabled(false);
            ui->qLineEdit->setDisabled(true);
        }
        else
        {
            ui->bLineEdit->setDisabled(true);
            ui->qLineEdit->setDisabled(false);
        }

        ui->inputTableView->setColumnHidden(3, false);
        ui->inputTableView->setColumnHidden(4, true);

        enhModel = false;
    }
}

void MainWindow::on_trunkResCheckBox_toggled(bool checked)
{
    if (checked)
    {
        ui->trunkResLineEdit->setDisabled(false);
        inputTableWidth += 60;
        ui->inputTableView->setFixedWidth(inputTableWidth);
        ui->inputTableView->setColumnHidden(5, false);
        trunkResBool = true;
    }
    else
    {
        ui->trunkResLineEdit->setDisabled(true);
        inputTableWidth -= 60;
        ui->inputTableView->setFixedWidth(inputTableWidth);
        ui->inputTableView->setColumnHidden(5, true);
        ui->trunkResLineEdit->setText("");
        trunkResBool = false;
    }
}

void MainWindow::on_cSpinBox_valueChanged(int arg1)
{
    int temp;

    temp = servClassIndex;  // store temporarily service class index
    ui->servClassComboBox->clear();
    ui->userServClassComboBox->clear();

    for (int i = 1; i <= arg1; i++)
    {
        ui->servClassComboBox->addItem(QString::number(i));
        ui->userServClassComboBox->addItem(QString::number(i));
    }

    if (arg1 - c > 0)
    {
        inputTableModel->insertRows(c, arg1 - c, 1);
    }
    else if (arg1 - c < 0)
        inputTableModel->removeRows(arg1, c - arg1, QModelIndex());
    // do nothing if arg1 - c = 0

    ui->servClassComboBox->setCurrentIndex(temp);    // assign to selServClassComboBox its previous value

    c = arg1;


    //inputTableModel->dataTable.resize(arg1);
}

void MainWindow::on_rLineEdit_textChanged(const QString &arg1)
{
    double inputVal;
    bool ok;

    inputVal = arg1.toDouble(&ok);
    if(!ok || inputVal < 0)
    {
        ui->rLineEdit->setText("");
        ui->maxDResLabel->setText("");
    }
    else
    {
        r = inputVal;
        if (!ui->uLineEdit->text().isEmpty())
        {
            dComMax = 3600 * (M_PI * r) / (2 * u);
            ui->maxDResLabel->setText(QString::number(dComMax, 'f', 2));
        }

        refreshInputTable();
        ui->rLineEdit->setFocus();
    }
}

void MainWindow::on_uLineEdit_textChanged(const QString &arg1)
{
    double inputVal;
    bool ok;

    inputVal = arg1.toDouble(&ok);
    if(!ok || inputVal < 0)
    {
        ui->uLineEdit->setText("");
        ui->maxDResLabel->setText("");
    }
    else
    {
        u = inputVal;
        if (!ui->rLineEdit->text().isEmpty())
        {
            dComMax = 3600 * (M_PI * r) / (2 * u);
            ui->maxDResLabel->setText(QString::number(dComMax, 'f', 2));
        }

        refreshInputTable();
        ui->uLineEdit->setFocus();
    }
}

void MainWindow::on_delayLineEdit_textChanged(const QString &arg1)
{
    double inputVal;
    bool ok;

    inputVal = arg1.toDouble(&ok);
    if(!ok || inputVal < 0)
        ui->delayLineEdit->setText("");
    else
    {
        delay = inputVal;
        dX2 = b * (dUe / 1000) / delay;
        //ui->dX2LineEdit->setText(QString::number(dX2, 'f', 0));
    }
}

void MainWindow::on_cX2LineEdit_textChanged(const QString &arg1)
{
    double inputVal;
    bool ok;

    inputVal = arg1.toDouble(&ok);
    if(!ok || inputVal < 0)
        ui->cX2LineEdit->setText("");
    else
        cX2 = inputVal;
}

void MainWindow::on_servClassComboBox_currentIndexChanged(int index)
{
    double dComTemp, bTemp, dUeTemp, dX2Temp;
    servClassIndex = index;
    if (index != -1 && index <= inputTableModel->getDataTable().size())
    {
        dUeTemp = inputTableModel->getDataTable()[index][4].toDouble();
        dX2Temp = inputTableModel->getDataTable()[index][3].toDouble();
        dComTemp = inputTableModel->getDataTable()[index][2].toDouble();
        if (delay != 0 && dUeTemp != 0)
            bTemp = (dX2Temp * (delay / 1000) / dUeTemp) * 1000;
        else
            bTemp = 0;

        if (inputTableModel->getDataTable()[index][1].isValid())
            ui->nLineEdit->setText(QString::number(inputTableModel->getDataTable()[index][1].toInt()));
        else
            ui->nLineEdit->setText("");

        if (inputTableModel->getDataTable()[index][2].isValid())
            ui->dComLineEdit->setText(QString::number(dComTemp));
        else
            ui->dComLineEdit->setText("");

        if (ui->enhModelCheckBox->isChecked())
        {
            if (inputTableModel->getDataTable()[index][4].isValid())
                ui->dUeLineEdit->setText(QString::number(inputTableModel->getDataTable()[index][4].toDouble()));
            else
                ui->dUeLineEdit->setText("");
        }
        else
        {
            if (inputTableModel->getDataTable()[index][3].isValid())
            {
                ui->bLineEdit->setText(QString::number(bTemp));
                ui->dUeLineEdit->setText(QString::number(dUeTemp));
            }
            else
            {
                ui->bLineEdit->setText("");
                ui->dUeLineEdit->setText("");
            }
        }

        if (ui->cx2RadioButton->isChecked())
        {
            if (inputTableModel->getDataTable()[index][7].isValid())
                ui->pCongInputLineEdit->setText(QString::number(inputTableModel->getDataTable()[index][7].toDouble()));
            else
                ui->pCongInputLineEdit->setText("");
        }

        if (ui->trunkResCheckBox->isChecked())
        {
            if (inputTableModel->getDataTable()[index][5].isValid())
                ui->trunkResLineEdit->setText(QString::number(inputTableModel->getDataTable()[index][5].toDouble()));
            else
                ui->trunkResLineEdit->setText("");
        }

        ui->qLineEdit->setText("");
    }
}

void MainWindow::on_nLineEdit_textChanged(const QString &arg1)
{
    int inputVal;
    bool ok;

    inputVal = arg1.toInt(&ok);
    if(!ok || inputVal < 0)
        ui->nLineEdit->setText("");
    else
        n = inputVal;
}

void MainWindow::on_dUeLineEdit_textChanged(const QString &arg1)
{
    double inputVal;
    bool ok;

    inputVal = arg1.toDouble(&ok);
    if(!ok || inputVal < 0)
        ui->dUeLineEdit->setText("");
    else
    {
        dUe = inputVal;
        dX2 = b * dUe / delay;
        dX2Enh = dUe;
    }
}

void MainWindow::on_trunkResLineEdit_textChanged(const QString &arg1)
{
    double inputVal;
    bool ok;

    inputVal = arg1.toDouble(&ok);
    if(!ok || inputVal < 0)
        ui->trunkResLineEdit->setText("");
    else
        trunkRes = inputVal;
}

void MainWindow::on_dComLineEdit_textChanged(const QString &arg1)
{
    double inputVal;
    bool ok;

    inputVal = arg1.toDouble(&ok);
    if(!ok || inputVal < 0)
        ui->dComLineEdit->setText("");
    else
        dCom = inputVal;
}

void MainWindow::on_setMaxDurationPushButton_clicked()
{
    ui->dComLineEdit->setText(QString::number(dComMax, 'g'));
    dCom = dComMax;
}

void MainWindow::on_setbRadioButton_toggled(bool checked)
{
    if (checked)
    {
        ui->bLineEdit->setEnabled(true);
        ui->qLineEdit->setEnabled(false);
        ui->qLineEdit->setText("");
    }
    else
    {
        ui->bLineEdit->setEnabled(false);
        ui->qLineEdit->setEnabled(true);
    }
}

void MainWindow::on_bLineEdit_textChanged(const QString &arg1)
{
    double inputVal;
    bool ok;

    inputVal = arg1.toDouble(&ok);
    if(!ok || inputVal < 0)
        ui->bLineEdit->setText("");
    else
    {
        b = inputVal;
        dX2 = b * dUe / delay;
    }
}

void MainWindow::on_qLineEdit_textChanged(const QString &arg1)
{
    double inputVal;
    bool ok;

    inputVal = arg1.toDouble(&ok);
    if(!ok || inputVal < 0)
        ui->qLineEdit->setText("");
    else
    {   
        q = inputVal;
        if (!ui->dUeLineEdit->text().isEmpty())
        {
            b = (q / dUe);
            ui->bLineEdit->setText(QString::number(b, 'f', 2));
        }
    }
}

void MainWindow::on_pCongInputLineEdit_textChanged(const QString &arg1)
{
    double inputVal;
    bool ok;

    inputVal = arg1.toDouble(&ok);
    if(!ok || inputVal < 0 || inputVal > 1)
        ui->pCongInputLineEdit->setText("");
    else
        pCong = inputVal;
}

void MainWindow::on_firstValPlotLineEdit_textChanged(const QString &arg1)
{
    double inputVal;
    bool ok;

    inputVal = arg1.toDouble(&ok);
    if(!ok || inputVal < 0 || inputVal > 1)
        ui->pCongInputLineEdit->setText("");
    else
        pCong = inputVal;
}

void MainWindow::on_stepLineEdit_textChanged(const QString &arg1)
{

}

void MainWindow::on_numOfStepsLineEdit_textChanged(const QString &arg1)
{

}

void MainWindow::on_pushButton_clicked()
{
    if (ui->nLineEdit->text().isEmpty())
        QMessageBox::warning(this, "Error","Input n");
    else if (ui->dUeLineEdit->text().isEmpty())
        QMessageBox::warning(this, "Error","Input d");
    else if (ui->dComLineEdit->text().isEmpty())
        QMessageBox::warning(this, "Error","Input Δ");
    else if (!ui->enhModelCheckBox->isChecked() && ui->setbRadioButton->isChecked() && ui->bLineEdit->text().isEmpty())
        QMessageBox::warning(this, "Error","Input β");
    else if (!ui->enhModelCheckBox->isChecked() && ui->setQdRadioButton->isChecked() && ui->qLineEdit->text().isEmpty())
        QMessageBox::warning(this, "Error","Input Q");
    else if (ui->cx2RadioButton->isChecked() && ui->pCongInputLineEdit->text().isEmpty())
        QMessageBox::warning(this, "Error","Input p");
    else
    {
        if (dCom - dComMax >= 0.01)
            QMessageBox::warning(this, "Warning","Δ exceeds max. acceptable value.");

        QVector<QVariant> inputRowVector(8);
        QModelIndex index = inputTableModel->index(servClassIndex, 0, QModelIndex());

        inputRowVector[0] = servClassIndex + 1;
        inputRowVector[1] = n;
        inputRowVector[2] = dCom;

        if (dX2 > 0.000001)
            inputRowVector[3] = dX2;
        else
            dX2 = 0;

        inputRowVector[4] = dX2Enh;

        if (ui->trunkResCheckBox->isChecked())
            inputRowVector[5] = trunkRes;
        else
            inputRowVector[5] = inputTableModel->getDataTable()[servClassIndex][5];


        pExit = (2 * u * (dCom / 3600)) / (M_PI * r);
        if (pExit > 1)
            pExit = 1;

        inputRowVector[6] = pExit;

        if (ui->cx2RadioButton->isChecked())
            inputRowVector[7] = (double)pCong;
        else
            inputRowVector[7] = inputTableModel->getDataTable()[servClassIndex][7];

        inputTableModel->setData(index, inputRowVector, Qt::DisplayRole);

        // service class combo box increament and new focus:
        if (ui->servClassComboBox->currentIndex() < c - 1)
        {
            ui->servClassComboBox->setCurrentIndex(ui->servClassComboBox->currentIndex() + 1);
            ui->nLineEdit->setFocus();
            ui->nLineEdit->selectAll();
        }   
    }
}

void MainWindow::on_calculatePushButton_clicked()
{
        //pStay = (1 / M_PI ) * (2*acos((u * dCom) / (2 * r)) - (u * dCom / r) * sqrt(1 - pow(((u * dCom) / (2 * r)), 2)));

//        pStay = 1 - ((2 * u * (dCom / 3600)) / (M_PI * r));

//        pExit = 1 - pStay;

        // create congestion vectors table header vector:

    if (ui->rLineEdit->text().isEmpty())
        QMessageBox::warning(this, "Error","Input R");
    else if (ui->uLineEdit->text().isEmpty())
        QMessageBox::warning(this, "Error","Input u");
    else if (ui->delayLineEdit->text().isEmpty())
        QMessageBox::warning(this, "Error","Input δ");
    else if (ui->pbRadioButton->isChecked() && ui->cX2LineEdit->text().isEmpty())
        QMessageBox::warning(this, "Error","Input CX2");
    else
    {
        QVector<QVariant> congProb, dX2Vector, trunkResVector;
        QVector<QVector<QVector<QVariant> > > congVectors;
        QVector<QVariant> nVector = inputTableModel->columnVector(1);
        QVector<QVariant> dComVector = inputTableModel->columnVector(2);
        QVector<QVariant> pExitVector = inputTableModel->columnVector(6);

        if (!ui->enhModelCheckBox->isChecked())
            dX2Vector = inputTableModel->columnVector(3);
        else
            dX2Vector = inputTableModel->columnVector(4);

        if (ui->trunkResCheckBox->isChecked())
            trunkResVector = inputTableModel->columnVector(5);

        if (ui->pbRadioButton->isChecked())
        {
            congVectTableHeader.resize(c + 1);

            for (int i = 0; i < c; i++)
                congVectTableHeader[i] = "n" + QString::number(i + 1);

            congVectTableHeader[c] = "CX2 sum";

            congVectTableModel.clear();
            congVectTableModel.resize(c);
            congVectors.resize(c);

            for (int i = 0; i < c; i++)
            {
                double cX2arg;
                QVector<QVariant> nVectorCurrUser = nVector;
                nVectorCurrUser[i] = nVectorCurrUser[i].toInt() - 1;
                congVectTableModel[i] = NULL;
                congVectTableModel[i] = new TableModel();
                congVectTableModel[i]->setHeader(congVectTableHeader);

                if (ui->trunkResCheckBox->isChecked())
                    cX2arg = cX2 - trunkResVector[i].toDouble();
                else
                    cX2arg = cX2;

                congestion_k_Vectors(nVectorCurrUser, dX2Vector, cX2arg, i, 0, congVectors[i]);
                congVectTableModel[i]->setRowNum(0);
                congVectTableModel[i]->setColumnNum(c + 1);
                if (congVectors[i].size() > 0)
                {
                    congVectTableModel[i]->insertRows(0, congVectors[i].size());

                    for (int j = 0; j < congVectors[i].size(); j++)
                    {
                        QModelIndex index = congVectTableModel[i]->index(j, 0, QModelIndex());
                        //QVector<QVariant> tak = convertIntToQVariant(congVectors[i][j]);
                        congVectTableModel[i]->setData(index, congVectors[i][j], Qt::DisplayRole);
                    }
                }
            }

            //ui->congVectorsTableView->reset();

            ui->congVectorsTableView->setModel(congVectTableModel[ui->userServClassComboBox->currentIndex()]);
            ui->congVectorsTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

            // fill congestion probabilities table:
            congProbTableHeader.resize(2);
            congVectTableHeader[0] = "serv. class";
            congVectTableHeader[1] = "Pb";

            congProbTableModel = NULL;
            congProbTableModel = new TableModel(c, 2, congVectTableHeader);

            congProb.resize(2);

            for (int i = 0; i < c; i++)
            {
                float p = (pExitVector[i].toFloat()) * delay / ((dComVector[i].toFloat()) * 1000);
                QVector<QVariant> nVectorCurrUser = nVector;
                nVectorCurrUser[i] = nVectorCurrUser[i].toInt() - 1;
                congProb[0] = i + 1;
                congProb[1] = (double)(pExitVector[i].toFloat()) * congestionProbability(nVectorCurrUser, congVectors[i], p) ;
                QModelIndex index = congProbTableModel->index(i, 0, QModelIndex());
                congProbTableModel->setData(index, congProb, Qt::DisplayRole);
            }

            ui->congProbTableView->setModel(congProbTableModel);
        }
        else if(ui->cx2RadioButton->isChecked())
        {
            int maxdX2indexPos;
            double cX2Search;
            QVector<QVariant> trunkResVector;

            if (ui->trunkResCheckBox->isChecked())
                trunkResVector = inputTableModel->columnVector(5);

            congVectTableHeader.resize(c + 1);

            for (int i = 0; i < c; i++)
                congVectTableHeader[i] = "C" + QString::number(i + 1);

            congVectTableHeader[c] = "CX2 sum";

            QVariant maxdX2 = *std::max_element(dX2Vector.begin(), dX2Vector.end());    // start with this value
            QVariant mindX2 = *std::min_element(dX2Vector.begin(), dX2Vector.end());    // add this value in each step

            if (!ui->trunkResCheckBox->isChecked())
                cX2Search = maxdX2.toDouble();
            else
            {
                maxdX2indexPos = dX2Vector.indexOf(maxdX2);     // !!! check what happens if more than 1 service classes have the same DX2 !!!
                cX2Search = maxdX2.toDouble() + trunkResVector[maxdX2indexPos].toDouble();
            }

            QVector<QVariant> pVector = inputTableModel->columnVector(7);

            congVectTableModel.clear();
            congVectTableModel.resize(c);

            bool cX2Found = false;
            int iter = 0;

            while (cX2Found == false)
            {
                congVectors.resize(0);
                congVectors.resize(c);
                for (int i = 0; i < c; i++)
                {
                    double cX2SearchArg;
                    QVector<QVariant> nVectorCurrUser = nVector;
                    nVectorCurrUser[i] = nVectorCurrUser[i].toInt() - 1;

                    if (ui->trunkResCheckBox->isChecked())
                        cX2SearchArg = cX2Search - trunkResVector[i].toDouble();     // define different CX2 value for each service class (because of trunk reservation)
                    else
                        cX2SearchArg = cX2Search;   // define uniform CX2 value for all service classes (no trunk reservation)

                    congestion_k_Vectors(nVectorCurrUser, dX2Vector, cX2SearchArg, i, 0, congVectors[i]);
                }

                // calculate congestion probabilities:

                congProb.resize(c);

                for (int i = 0; i < c; i++)
                {
                    float p = (pExitVector[i].toFloat()) * delay / ((dComVector[i].toFloat()) * 1000);
                    QVector<QVariant> nVectorCurrUser = nVector;
                    nVectorCurrUser[i] = nVectorCurrUser[i].toInt() - 1;
                    congProb[i] = (double)(pExitVector[i].toFloat()) * congestionProbability(nVectorCurrUser, congVectors[i], p) ;
                }

                cX2Found = true;

                for (int i = 0; i < c; i++)
                {
                    if (congProb[i].toDouble() > pVector[i].toDouble())
                    {
                        cX2Found = false;
                        break;
                    }
                }

                if (cX2Found == true && iter == 0)
                {
                    cX2Found = false;
                    cX2Search = mindX2.toDouble();
                }

                if (cX2Found == false)
                    cX2Search += mindX2.toDouble();
                else
                {
                    congProbTableHeader.resize(2);
                    congVectTableHeader[0] = "serv. class";
                    congVectTableHeader[1] = "Pb";

                    congProbTableModel = NULL;
                    congProbTableModel = new TableModel(c, 2, congVectTableHeader);

                    // fill congestion probabilities table:
                    QVector<QVariant> congVectorTable(2);

                    for (int i = 0; i < c; i++)
                    {
                        congVectorTable[0] = i + 1;
                        congVectorTable[1] = congProb[i];
                        QModelIndex index = congProbTableModel->index(i, 0, QModelIndex());
                        congProbTableModel->setData(index, congVectorTable, Qt::DisplayRole);
                    }

                    ui->congProbTableView->setModel(congProbTableModel);
                    ui->cX2OutLabel->setText(QString::number(cX2Search));
                }
                iter++;
            }
        }
    }
}

void MainWindow::on_userServClassComboBox_currentIndexChanged(int index)
{
    if (index != -1 && congVectTableModel.size() - 1 >= index)
        ui->congVectorsTableView->setModel(congVectTableModel[index]);
}

void MainWindow::on_plotExportPushButton_clicked()
{
    if (ui->rLineEdit->text().isEmpty())
        QMessageBox::warning(this, "Error","Input R");
    else if (ui->uLineEdit->text().isEmpty())
        QMessageBox::warning(this, "Error","Input u");
    else if (ui->delayLineEdit->text().isEmpty())
        QMessageBox::warning(this, "Error","Input δ");
    else if (ui->pbRadioButton->isChecked() && ui->cX2LineEdit->text().isEmpty())
        QMessageBox::warning(this, "Error","Input CX2");
    else
    {
        pod = new PlotOutputDialog;

        connect(this, SIGNAL(passInputTableModel(TableModel*)),
                pod, SLOT(receiveInputTableModel(TableModel*)));

        connect(this, SIGNAL(passGeneralParameters(bool, bool, int, double, double, double, double)),
                pod, SLOT(receiveGeneralParameters(bool, bool, int, double, double, double, double)));

        emit passGeneralParameters(enhModel, trunkResBool, c, r, u, delay, cX2);
        emit passInputTableModel(inputTableModel);

        pod->exec();
    }
}

//void MainWindow::on_plotComboBox_currentIndexChanged(int index)
//{
//    if (index == 0)
//    {
//        ui->firstValLabel->setText("First value of multiplicative coefficient:");
//        ui->plotWidget->yAxis->setLabel("Number of active users");
//        ui->plotWidget->xAxis->setLabel("Blocking probability");
////        ui->plotWidget->createGraph(pbOut, colorList);
////        ui->plotServClassComboBox->setVisible(true);
////        ui->servClassLabel->setVisible(true);
////        ui->plotShowCheckBox->setVisible(true);
////        ui->plotShowCheckBox->setChecked(true);
//        ui->plotWidget->replot();
//    }
//    else if (index == 1)
//    {
//        ui->firstValLabel->setText("First value of bandwidth:");
//        ui->plotWidget->yAxis->setLabel("Congestion probability");
//        ui->plotWidget->xAxis->setLabel("X2 bandwidth");
////        ui->plotWidget->createGraph(eArray, colorList);
////        ui->plotServClassComboBox->setVisible(true);
////        ui->servClassLabel->setVisible(true);
////        ui->plotShowCheckBox->setVisible(true);
////        ui->plotShowCheckBox->setChecked(true);
//        ui->plotWidget->replot();
//    }
//    else if (index == 2)
//    {
//        ui->firstValLabel->setText("First value of cong. probability:");
//        ui->plotWidget->yAxis->setLabel("X2 bandwidth");
//        ui->plotWidget->xAxis->setLabel("Max. congestion probability");
////        ui->plotWidget->createUGraph(linkUt);
////        ui->plotServClassComboBox->setVisible(false);
////        ui->plotServClassComboBox->setCurrentIndex(0);
////        ui->servClassLabel->setVisible(false);
////        ui->plotShowCheckBox->setVisible(false);
//        ui->plotWidget->replot();
//    }
//}

//-----------------------------------------------------------------------------
// CUSTOM FUNCTIONS:
//-----------------------------------------------------------------------------

QVector<double> MainWindow::convertQVariantToDouble(const QVector<QVariant> &qVarVector)
{
    QVector<double> qDoubleVector;
    int size = qVarVector.size();

    qDoubleVector.resize(size);

    for (int i = 0; i < size; i++)
        qDoubleVector[i] = qVarVector[i].toDouble();

    return qDoubleVector;
}

QVector<QVariant> MainWindow::convertIntToQVariant(const QVector<int> &intVector)
{
    QVector<QVariant> qVarVector;
    int size = intVector.size();

    qVarVector.resize(size);

    for (int i = 0; i < size; i++)
        qVarVector[i] = (QVariant)intVector[i];

    return qVarVector;

}

void MainWindow::on_pushButton_2_clicked()
{
    ui->nLineEdit->setText("2");
    ui->dComLineEdit->setText("30");
    ui->dUeLineEdit->setText("0.6");
    ui->bLineEdit->setText("100");
}

void MainWindow::refreshInputTable()
{
    int temp = ui->servClassComboBox->currentIndex();

    for (int i = 0; i < c; i++)
    {
        ui->servClassComboBox->setCurrentIndex(i);
        if (ui->dComLineEdit->text() != "")
            ui->pushButton->click();
    }

    ui->servClassComboBox->setCurrentIndex(temp);
}

//-----------------------------------------------------------------------------
// SET NEXT FOCUS:
//-----------------------------------------------------------------------------

void MainWindow::on_rLineEdit_returnPressed()
{
    ui->uLineEdit->setFocus();
    ui->uLineEdit->selectAll();
}

void MainWindow::on_uLineEdit_returnPressed()
{
    ui->delayLineEdit->setFocus();
    ui->delayLineEdit->selectAll();
}

void MainWindow::on_delayLineEdit_returnPressed()
{
    ui->cX2LineEdit->setFocus();
    ui->cX2LineEdit->selectAll();
}

void MainWindow::on_cX2LineEdit_returnPressed()
{
    ui->nLineEdit->setFocus();
    ui->nLineEdit->selectAll();
}

void MainWindow::on_nLineEdit_returnPressed()
{
    ui->dUeLineEdit->setFocus();
    ui->dUeLineEdit->selectAll();
}

void MainWindow::on_dUeLineEdit_returnPressed()
{
    if (!ui->trunkResCheckBox->isChecked())
    {
        ui->dComLineEdit->setFocus();
        ui->dComLineEdit->selectAll();
    }
    else
    {
        ui->trunkResLineEdit->setFocus();
        ui->trunkResLineEdit->selectAll();
    }
}

void MainWindow::on_trunkResLineEdit_returnPressed()
{
    ui->dComLineEdit->setFocus();
    ui->dComLineEdit->selectAll();
}

void MainWindow::on_dComLineEdit_returnPressed()
{
    if (!ui->enhModelCheckBox->isChecked())
    {
        if (ui->setbRadioButton->isChecked())
        {
            ui->bLineEdit->setFocus();
            ui->bLineEdit->selectAll();
        }
        else
        {
            ui->qLineEdit->setFocus();
            ui->qLineEdit->selectAll();
        }
    }
    else if (ui->cx2RadioButton->isChecked())
    {
        ui->pCongInputLineEdit->setFocus();
        ui->pCongInputLineEdit->selectAll();
    }
    else
        ui->pushButton->click();
}

void MainWindow::on_bLineEdit_returnPressed()
{
    if (ui->cx2RadioButton->isChecked())
    {
        ui->pCongInputLineEdit->setFocus();
        ui->pCongInputLineEdit->selectAll();
    }
    else
        ui->pushButton->click();
}

void MainWindow::on_qLineEdit_returnPressed()
{
    if (ui->cx2RadioButton->isChecked())
    {
        ui->pCongInputLineEdit->setFocus();
        ui->pCongInputLineEdit->selectAll();
    }
    else
        ui->pushButton->click();
}

void MainWindow::on_pCongInputLineEdit_returnPressed()
{
    ui->pushButton->click();
}
