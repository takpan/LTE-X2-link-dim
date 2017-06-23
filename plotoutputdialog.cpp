#include "plotoutputdialog.h"
#include "ui_plotoutputdialog.h"

PlotOutputDialog::PlotOutputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlotOutputDialog)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Widget);

    etd = NULL;

    // create users table header vector:
    usersTableHeader.resize(4);
    usersTableHeader[0] = "Serv. class";
    usersTableHeader[1] = "n, min";
    usersTableHeader[2] = "step";
    usersTableHeader[3] = "n, max";

    //create and set users table model:
    usersTableModel = new TableModel(0, 4, usersTableHeader);

    ui->usersTableView->setModel(usersTableModel);
    ui->usersTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //inputTableModel->insertRows(0, 1, 1, QModelIndex());

    ui->usersTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->usersTableView->horizontalHeader()->setDefaultSectionSize(60);
    ui->usersTableView->verticalHeader()->setDefaultSectionSize(20);
    ui->usersTableView->verticalHeader()->setVisible(false);
    ui->usersTableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
//    ui->inputTableView->setColumnHidden(3, false);
//    ui->inputTableView->setColumnHidden(4, true);

    // set service class indesx:
    servClassIndex = 0;

    // initialize plot visibility:
    ui->plotShowCheckBox->setDisabled(true);
    ui->plotServClassComboBox->setDisabled(true);
    ui->scatterComboBox->setDisabled(true);

    // create colorList:
    colorList.resize(7);
    colorList[0] = "#FF0000";
    colorList[1] = "#FF8000";
    colorList[2] = "#009000";
    colorList[3] = "#00C4C4";
    colorList[4] = "#0000FF";
    colorList[5] = "#FF00FF";
    colorList[6] = "#A1A1A1";

    // create scatter vector:
    scatterShapes.resize(8);
    scatterShapes[0] = QCPScatterStyle::ssDisc;
    scatterShapes[1] = QCPScatterStyle::ssCircle;
    scatterShapes[2] = QCPScatterStyle::ssCross;
    scatterShapes[3] = QCPScatterStyle::ssPlus;
    scatterShapes[4] = QCPScatterStyle::ssSquare;
    scatterShapes[5] = QCPScatterStyle::ssStar;
    scatterShapes[6] = QCPScatterStyle::ssTriangle;
    scatterShapes[7] = QCPScatterStyle::ssTriangleInverted;

    ui->progressBar->setVisible(false);
}

PlotOutputDialog::~PlotOutputDialog()
{
    delete ui;
}

//-----------------------------------------------------------------------------
// PUBLIC SLOTS:
//-----------------------------------------------------------------------------

void PlotOutputDialog::receiveInputTableModel(TableModel *tableModel)
{
    inputTableModel = tableModel;

    ui->inputTableView->setModel(inputTableModel);
    ui->inputTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->inputTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->inputTableView->horizontalHeader()->setDefaultSectionSize(60);
    ui->inputTableView->verticalHeader()->setDefaultSectionSize(20);
    ui->inputTableView->verticalHeader()->setVisible(false);
    ui->inputTableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    if (enhModel == false)
    {
        ui->inputTableView->setColumnHidden(3, false);
        ui->inputTableView->setColumnHidden(4, true);
    }
    else if (enhModel == true)
    {
        ui->inputTableView->setColumnHidden(3, true);
        ui->inputTableView->setColumnHidden(4, false);
        //enhModel = false;
    }

    if (trunkResBool == false)
        ui->inputTableView->setColumnHidden(5, true);
    else
        ui->inputTableView->setColumnHidden(5, false);


    ui->inputTableView->setColumnHidden(7, true);

    //ui->inputTableView->setModel(inputTableModel);

    // find and store the number of service classes
    c = inputTableModel->getDataTable().size();

    // store initial data table (as it was imported)
    importedDataTable = inputTableModel->getDataTable();

    // store initial n vector (number of active users of each service class, 2nd column of data table)
    nInitialVector = inputTableModel->columnVector(1);

    // create initial n start vector:
    nStartVector = nInitialVector;

    // create initial userStepVector:
    userStepVector.resize(c);

    // fill service class combo box:
    for (int i = 0; i < c; i++)
    {
        ui->servClassComboBox->addItem(QString::number(i+1));
        ui->plotServClassComboBox->addItem(QString::number(i+1));
    }
}

void PlotOutputDialog::receiveGeneralParameters(bool enhModel, bool trunkResBool, int c, double r, double u, double delay, double cX2)
{
    this->enhModel = enhModel;
    this->trunkResBool = trunkResBool;
    this->c = c;
    this->r = r;
    this->u = u;
    this->delay = delay;
    this->cX2 = cX2;

    ui->KLabel->setText(QString::number(c));
    ui->RLabel->setText(QString::number(r));
    ui->uLabel->setText(QString::number(u));
    ui->CX2Label->setText(QString::number(cX2));
}

void PlotOutputDialog::receiveExportTablesPath(QString path, bool write, QString fileExt, QString delim)
{
    exportTablesPath = path;
    this->write = write;
    this->fileExt = fileExt;
    this->delim = delim;
}

//-----------------------------------------------------------------------------
// PRIVATE SLOTS:
//-----------------------------------------------------------------------------

void PlotOutputDialog::on_numOfStepsLineEdit_textChanged(const QString &arg1)
{
    int inputVal;
    bool ok;

    inputVal = arg1.toInt(&ok);
    if(!ok || inputVal < 0)
        ui->numOfStepsLineEdit->setText("");
    else
    {
        numOfSteps = inputVal;
        for (int i = 0; i < usersTableModel->getDataTable().size(); i++)
        {
            QVector<QVariant> row = usersTableModel->getDataTable()[i];
            int step = usersTableModel->getDataTable()[i][2].toInt();
            int nMin = usersTableModel->getDataTable()[i][1].toInt();
            row[3] = nMin + step * numOfSteps;
            QModelIndex index = usersTableModel->index(i, 0, QModelIndex());
            usersTableModel->setData(index, row, Qt::DisplayRole);
        }
    }
}

void PlotOutputDialog::on_servClassComboBox_currentIndexChanged(int index)
{
    int indexOfExistingItem;
    servClassIndex = index;

    int rows = usersTableModel->getDataTable().size();
    QVector<QVariant> servClassVector = usersTableModel->columnVector(0);

    if (rows > 0 && (indexOfExistingItem = searchValueInVector(servClassVector, servClassIndex + 1)) != -1)
    {
        ui->nMinLineEdit->setText(QString::number(usersTableModel->getDataTable()[indexOfExistingItem][1].toInt()));
        ui->userStepLlineEdit->setText(QString::number(usersTableModel->getDataTable()[indexOfExistingItem][2].toInt()));
    }
    else
    {
        ui->nMinLineEdit->setText("");
        ui->userStepLlineEdit->setText("");
    }
}

void PlotOutputDialog::on_nMinLineEdit_textChanged(const QString &arg1)
{
    int inputVal;
    bool ok;

    inputVal = arg1.toInt(&ok);
    if(!ok || inputVal < 0)
        ui->nMinLineEdit->setText("");
    else
        nMin = inputVal;
}

void PlotOutputDialog::on_userStepLlineEdit_textChanged(const QString &arg1)
{
    int inputVal;
    bool ok;

    inputVal = arg1.toInt(&ok);
    if(!ok || inputVal < 0)
        ui->userStepLlineEdit->setText("");
    else
        userStep = inputVal;
}

void PlotOutputDialog::on_setButton_clicked()
{
    if (ui->nMinLineEdit->text().isEmpty())
        QMessageBox::warning(this, "Error","Input n min value");
    else if (ui->userStepLlineEdit->text().isEmpty())
        QMessageBox::warning(this, "Error","Input step value");
    else
    {
        int indexOfExistingItem;
        int rows = usersTableModel->getDataTable().size();
        QVector<QVariant> inputRowVector(4);
        QVector<QVariant> servClassVector = usersTableModel->columnVector(0);

        inputRowVector[0] = servClassIndex + 1;
        inputRowVector[1] = nMin;
        inputRowVector[2] = userStep;
        inputRowVector[3] = nMin + numOfSteps * userStep;

        if (rows > 0 && (indexOfExistingItem = searchValueInVector(servClassVector, servClassIndex + 1)) != -1)
        {
            QModelIndex index = usersTableModel->index(indexOfExistingItem, 0, QModelIndex());
            usersTableModel->setData(index, inputRowVector, Qt::DisplayRole);
        }
        else
        {
            usersTableModel->insertRows(usersTableModel->getDataTable().size(), 1, QModelIndex());
            QModelIndex index = usersTableModel->index(usersTableModel->getDataTable().size() - 1, 0, QModelIndex());
            usersTableModel->setData(index, inputRowVector, Qt::DisplayRole);
        }
        QVector<QVariant> temp = inputTableModel->getDataTable()[servClassIndex];
        temp[1] = "var";
        QModelIndex index = inputTableModel->index(servClassIndex, 0, QModelIndex());
        inputTableModel->setData(index, temp, Qt::DisplayRole);

        nStartVector[servClassIndex] = nMin;    // prepare initial users' vector
        userStepVector[servClassIndex] = userStep; // prepare users' step vector

    //    if (ui->servClassComboBox->currentIndex() < c - 1)
    //        ui->servClassComboBox->setCurrentIndex(ui->servClassComboBox->currentIndex() + 1);

        if (ui->servClassComboBox->currentIndex() < c - 1)
        {
            ui->servClassComboBox->setCurrentIndex(ui->servClassComboBox->currentIndex() + 1);
            ui->nMinLineEdit->setFocus();
            ui->nMinLineEdit->selectAll();
        }
        else
        {
            ui->cX2MinLineEdit->setFocus();
            ui->cX2MinLineEdit->selectAll();
        }
    }
}

void PlotOutputDialog::on_removeButton_clicked()
{
    QVector<QVariant> servClassVector = usersTableModel->columnVector(0);
    int indexOfRowToRemove = searchValueInVector(servClassVector, servClassIndex + 1);

    if (indexOfRowToRemove != -1)
    {
        usersTableModel->removeRow(indexOfRowToRemove, QModelIndex());  // remove row
        QVector<QVariant> temp = inputTableModel->getDataTable()[servClassIndex];   // restore n value of this service class
        temp[1] = nInitialVector[servClassIndex];
        QModelIndex index = inputTableModel->index(servClassIndex, 0, QModelIndex());
        inputTableModel->setData(index, temp, Qt::DisplayRole);
        ui->nMinLineEdit->setText("");
        ui->userStepLlineEdit->setText("");
    }
}

void PlotOutputDialog::on_cX2MinLineEdit_textChanged(const QString &arg1)
{
    double inputVal;
    bool ok;

    inputVal = arg1.toDouble(&ok);
    if(!ok || inputVal < 0)
        ui->cX2MinLineEdit->setText("");
    else
        cX2Min = inputVal;
}

void PlotOutputDialog::on_cX2StepLlineEdit_textChanged(const QString &arg1)
{
    double inputVal;
    bool ok;

    inputVal = arg1.toDouble(&ok);
    if(!ok || inputVal < 0)
        ui->cX2StepLlineEdit->setText("");
    else
        cX2Step = inputVal;
}

void PlotOutputDialog::on_plotPushButton_clicked()
{
    //ui->progressBar->setValue(10);
    ui->progressBar->setVisible(true);
    if (ui->numOfStepsLineEdit->text().isEmpty())
        QMessageBox::warning(this, "Error","Input the number of the steps");
    else if (ui->cX2MinLineEdit->text().isEmpty())
        QMessageBox::warning(this, "Error","Input min CX2 value");
    else if (ui->cX2StepLlineEdit->text().isEmpty())
        QMessageBox::warning(this, "Error","Input CX2 step");
    else
    {

        // create x-axis table header vector:
        xAxisTableHeader.resize(c + 2);
        xAxisTableHeader[0] = "Step";
        for (int i = 1; i <= c; i++)
            xAxisTableHeader[i] = "n" + QString::number(i);

        xAxisTableHeader[c + 1] = "CX2";

        //create and set users table model:
        xAxisTabeModel = new TableModel(0, c + 2, xAxisTableHeader);

        ui->xAxisTableView->setModel(xAxisTabeModel);
        ui->xAxisTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        //inputTableModel->insertRows(0, 1, 1, QModelIndex());

        ui->xAxisTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->xAxisTableView->horizontalHeader()->setDefaultSectionSize(60);
        ui->xAxisTableView->verticalHeader()->setDefaultSectionSize(20);
        ui->xAxisTableView->verticalHeader()->setVisible(false);
        ui->xAxisTableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);


        // create congestion probabilities table header vector:
        congProbTableHeader.resize(c + 1);
        congProbTableHeader[0] = "Step";
        for (int i = 1; i <= c; i++)
            congProbTableHeader[i] = "Pb" + QString::number(i);

        //create and set congestion probabilities table model:
        congProbTableModel = new TableModel(0, c + 1, congProbTableHeader);

        ui->congProbTableView->setModel(congProbTableModel);
        ui->congProbTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        //inputTableModel->insertRows(0, 1, 1, QModelIndex());

        ui->congProbTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->congProbTableView->horizontalHeader()->setDefaultSectionSize(80);
        ui->congProbTableView->verticalHeader()->setDefaultSectionSize(20);
        ui->congProbTableView->verticalHeader()->setVisible(false);
        ui->congProbTableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);


        QModelIndex index;
        double cX2Current;
        //QVector<QVariant> nStartVector = usersTableModel->columnVector(1);

        for (int i = 0; i <= numOfSteps; i++)
        {
            ui->progressBar->setValue(((i*99)/numOfSteps));
            QVector<QVariant> xAxisRowVector, nCurrentVector, congProbVector, dX2Vector;
            index = xAxisTabeModel->index(i, 0, QModelIndex());
            xAxisTabeModel->insertRows(i, 1, index);

            xAxisRowVector.append(i);

            for (int j = 0; j < c; j++)
            {
                nCurrentVector.append(nStartVector[j].toInt() + i * userStepVector[j].toInt());
                xAxisRowVector.append(nStartVector[j].toInt() + i * userStepVector[j].toInt());
            }

            cX2Current = cX2Min + i * cX2Step;
            xAxisRowVector.append(cX2Current);
            index = xAxisTabeModel->index(i, 0, QModelIndex());
            xAxisTabeModel->setData(index, xAxisRowVector, Qt::DisplayRole);

            if (enhModel == false)
                dX2Vector = inputTableModel->columnVector(3);
            else
                dX2Vector = inputTableModel->columnVector(4);

            congProbVector = calculateCongestionProbabilities(nCurrentVector, dX2Vector, inputTableModel->columnVector(5), inputTableModel->columnVector(2), inputTableModel->columnVector(6), delay, cX2Current, trunkResBool);
            congProbVector.insert(0, i);
            index = congProbTableModel->index(i, 0, QModelIndex());
            congProbTableModel->insertRows(i, 1, index);
            index = congProbTableModel->index(i, 0, QModelIndex());
            congProbTableModel->setData(index, congProbVector, Qt::DisplayRole);
        }

        QVector<QVector<double> > congProbArray = createCongProbArray(congProbTableModel);
        ui->plotWidget->createGraph(congProbArray, colorList);

        ui->plotServClassComboBox->setEnabled(true);
        ui->plotShowCheckBox->setEnabled(true);
        ui->plotShowCheckBox->setChecked(true);
        ui->scatterComboBox->setEnabled(true);
        ui->progressBar->setValue(100);
    }
    ui->progressBar->setVisible(false);
}

void PlotOutputDialog::on_plotServClassComboBox_currentIndexChanged(int index)
{
    if (ui->plotWidget->graphCount() > 0)
    {
        if(ui->plotWidget->graph(index)->visible())
            ui->plotShowCheckBox->setChecked(true);
        else
            ui->plotShowCheckBox->setChecked(false);

        ui->scatterComboBox->setCurrentIndex(scatterShapes.indexOf(ui->plotWidget->graph(index)->scatterStyle().shape()));
    }
}

void PlotOutputDialog::on_plotShowCheckBox_toggled(bool checked)
{
    if(checked && ui->plotWidget->graphCount() > 0)
    {
        ui->plotWidget->graph(ui->plotServClassComboBox->currentIndex())->setVisible(true);
        ui->plotWidget->replot();
    }
    else
    {
        ui->plotWidget->graph(ui->plotServClassComboBox->currentIndex())->setVisible(false);
        ui->plotWidget->replot();
    }
}

void PlotOutputDialog::on_scatterComboBox_currentIndexChanged(int index)
{
    ui->plotWidget->graph(ui->plotServClassComboBox->currentIndex())->setScatterStyle(QCPScatterStyle(scatterShapes[index], 6));
    //ui->plotWidget->graph(ui->plotServClassComboBox->currentIndex())->setScatterStyle(QCPScatterStyle(scatterShapes.at(index), 6));
    ui->plotWidget->replot();
}

void PlotOutputDialog::on_rescalePushButton_clicked()
{
    ui->plotWidget->rescaleAxes(true);
    ui->plotWidget->axisRect()->setAutoMargins(QCP::msNone);
    //ui->plotWidget->axisRect()->setMargins(QMargins(50,20,100,15));
    //ui->plotWidget->plotLayout()->setMargins(*(new QMargins(10,20,30,50)));
    //ui->plotWidget->xAxis->setRangeUpper((ui->plotWidget->xAxis->range()).upper + 1);
    //ui->plotWidget->yAxis->setRangeUpper((ui->plotWidget->yAxis->range()).upper + 0.05*(ui->plotWidget->yAxis->range()).upper);
    ui->plotWidget->replot();
}

void PlotOutputDialog::on_backPushButton_clicked()
{
    QVector<QVariant> temp;
    QModelIndex index;

    for (int i = 0; i < c; i++)
    {
        temp = inputTableModel->getDataTable()[i];
        temp[1] = nInitialVector[i];
        index = inputTableModel->index(i, 0, QModelIndex());
        inputTableModel->setData(index, temp, Qt::DisplayRole);
    }

    this->close();
}

void PlotOutputDialog::on_exportTablesPushButton_clicked()
{
    if (etd == NULL)
        etd = new ExportDialog();

    QObject::connect(etd, SIGNAL(returnPath(QString, bool, QString, QString)), this, SLOT(receiveExportTablesPath(QString, bool, QString , QString)));

    etd->exec();

    if(etd->result() == QDialog::Accepted && write == true)
    {
        QFile file(exportTablesPath);
        if(file.open(QFile::WriteOnly | QFile::Truncate | QIODevice::Text))     // Truncate = delete existing content
        {
            QTextStream stream(&file);

            stream << "C =" << delim << c << delim << " service classes" << endl;
            stream << "R =" << delim << r << delim << " km" << endl;
            stream << "u =" << delim << u << delim << " km/h" << endl;
            stream << "delay =" << delim << delay << delim << " ms" << endl;
            stream << "CX2 =" << delim << cX2 << delim << " Mb/s" << endl;
            stream << endl;

            if(fileExt == ".txt")
            {
                stream << "step" << delim;
                for (int i = 1; i <= c; i++)
                    stream << "n" << i << delim;

                stream << "CX2" << delim;

                for (int i = 1; i <= c; i++)
                    stream << "Pb" << i << delim;

                stream << endl;
                stream << "--------------------------------------------";

            }
            else if (fileExt == ".csv")
            {
                stream << "step" << delim;
                for (int i = 1; i <= c; i++)
                    stream << "n" << i << delim;

                stream << "CX2" << delim;

                for (int i = 1; i <= c; i++)
                    stream << "Pb" << i << delim;
            }


            for (int i = 0; i <= numOfSteps; i++)
            {
                stream << endl << i << delim;

                for (int j = 1; j <= c + 1; j++)
                    stream << xAxisTabeModel->getDataTable()[i][j].toDouble() << delim;

                for (int j = 1; j <= c; j++)
                    stream << congProbTableModel->getDataTable()[i][j].toDouble() << delim;
            }
        }
    }

}

void PlotOutputDialog::on_PlotOutputDialog_rejected()
{
    QVector<QVariant> temp;
    QModelIndex index;

    for (int i = 0; i < c; i++)
    {
        temp = inputTableModel->getDataTable()[i];
        temp[1] = nInitialVector[i];
        index = inputTableModel->index(i, 0, QModelIndex());
        inputTableModel->setData(index, temp, Qt::DisplayRole);
    }
}

//-----------------------------------------------------------------------------
// PUBLIC:
//-----------------------------------------------------------------------------
int PlotOutputDialog::searchValueInVector(const QVector<QVariant> &vector, const int &value)
{
    int row, index;

    index = -1;

    row = 0;
    while (index == -1 && row < vector.size())
    {
        if(vector[row].toInt() == value)
            index = row;

        row++;
    }
    return index;
}

QVector<QVector<double> > PlotOutputDialog::createCongProbArray(TableModel *congProbTableModel)
{
    QVector<QVector<double> > congProbArray;
    int numOfCongArrayColumns = congProbTableModel->getDataTable()[0].size();
    int numOfColumnItems = congProbTableModel->getDataTable().size();

    congProbArray.resize(numOfCongArrayColumns - 1);

    for (int i = 1; i < numOfCongArrayColumns; i++)
    {
        for (int j = 0; j < numOfColumnItems; j++)
            congProbArray[i - 1].append(congProbTableModel->getDataTable()[j][i].toDouble());
    }
    return congProbArray;
}

//QVector<QVariant> PlotOutputDialog::findStartVector(const QVector<QVector<QVariant>> &usersArray, const QVector<QVariant> &nInitialVector)
//{
//    QVector<QVariant> nStartVector;

//    for (int i = 0; i < nInitialVector.size(); i++)
//    {
//        if (searchValueInVector())
//    }

//}

//-----------------------------------------------------------------------------
// SET NEXT FOCUS:
//-----------------------------------------------------------------------------

void PlotOutputDialog::on_numOfStepsLineEdit_returnPressed()
{
    ui->nMinLineEdit->setFocus();
    ui->nMinLineEdit->selectAll();
}

void PlotOutputDialog::on_nMinLineEdit_returnPressed()
{
    ui->userStepLlineEdit->setFocus();
    ui->userStepLlineEdit->selectAll();
}

void PlotOutputDialog::on_userStepLlineEdit_returnPressed()
{
    ui->setButton->click();
}

void PlotOutputDialog::on_cX2MinLineEdit_returnPressed()
{
    ui->cX2StepLlineEdit->setFocus();
    ui->cX2StepLlineEdit->selectAll();
}


