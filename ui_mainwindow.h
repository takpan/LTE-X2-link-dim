/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_14;
    QComboBox *servClassComboBox;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_16;
    QLineEdit *nLineEdit;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_17;
    QLineEdit *dUeLineEdit;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_20;
    QLineEdit *trunkResLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *dComLineEdit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QLabel *maxDResLabel;
    QPushButton *setMaxDurationPushButton;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_8;
    QRadioButton *setbRadioButton;
    QRadioButton *setQdRadioButton;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_13;
    QLineEdit *bLineEdit;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_12;
    QLineEdit *qLineEdit;
    QFrame *line;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_18;
    QLineEdit *pCongInputLineEdit;
    QFrame *line_3;
    QTableView *inputTableView;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_19;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QGroupBox *groupBox_4;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_19;
    QSpinBox *cSpinBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *rLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *uLineEdit;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_11;
    QLineEdit *delayLineEdit;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_21;
    QLineEdit *cX2LineEdit;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_15;
    QRadioButton *pbRadioButton;
    QRadioButton *cx2RadioButton;
    QCheckBox *enhModelCheckBox;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *trunkResCheckBox;
    QGroupBox *groupBox_6;
    QGroupBox *groupBox_2;
    QTableView *congProbTableView;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_5;
    QLabel *cX2OutLabel;
    QGroupBox *groupBox_5;
    QTableView *congVectorsTableView;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QComboBox *userServClassComboBox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer;
    QPushButton *calculatePushButton;
    QPushButton *plotExportPushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QButtonGroup *buttonGroup_3;
    QButtonGroup *buttonGroup_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(812, 827);
        MainWindow->setMinimumSize(QSize(500, 0));
        MainWindow->setMaximumSize(QSize(812, 827));
        QIcon icon;
        icon.addFile(QStringLiteral("logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 794, 756));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(481, 721));
        groupBox->setMaximumSize(QSize(481, 721));
        QFont font;
        font.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font.setBold(false);
        font.setWeight(50);
        groupBox->setFont(font);
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 240, 461, 471));
        groupBox_3->setMinimumSize(QSize(461, 0));
        groupBox_3->setMaximumSize(QSize(461, 16777215));
        QFont font1;
        font1.setFamily(QStringLiteral("MS Shell Dlg 2"));
        groupBox_3->setFont(font1);
        layoutWidget = new QWidget(groupBox_3);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 441, 306));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        QFont font2;
        font2.setBold(false);
        font2.setWeight(50);
        label_14->setFont(font2);

        horizontalLayout_4->addWidget(label_14);

        servClassComboBox = new QComboBox(layoutWidget);
        servClassComboBox->setObjectName(QStringLiteral("servClassComboBox"));
        servClassComboBox->setMinimumSize(QSize(0, 0));
        servClassComboBox->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_4->addWidget(servClassComboBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setMinimumSize(QSize(0, 20));
        label_16->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_14->addWidget(label_16);

        nLineEdit = new QLineEdit(layoutWidget);
        nLineEdit->setObjectName(QStringLiteral("nLineEdit"));
        nLineEdit->setMinimumSize(QSize(50, 0));
        nLineEdit->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_14->addWidget(nLineEdit);


        verticalLayout->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_17 = new QLabel(layoutWidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setMinimumSize(QSize(0, 20));
        label_17->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_15->addWidget(label_17);

        dUeLineEdit = new QLineEdit(layoutWidget);
        dUeLineEdit->setObjectName(QStringLiteral("dUeLineEdit"));
        dUeLineEdit->setMinimumSize(QSize(50, 0));
        dUeLineEdit->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_15->addWidget(dUeLineEdit);


        verticalLayout->addLayout(horizontalLayout_15);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        label_20 = new QLabel(layoutWidget);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setMinimumSize(QSize(0, 20));
        label_20->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_20->addWidget(label_20);

        trunkResLineEdit = new QLineEdit(layoutWidget);
        trunkResLineEdit->setObjectName(QStringLiteral("trunkResLineEdit"));
        trunkResLineEdit->setMinimumSize(QSize(50, 0));
        trunkResLineEdit->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_20->addWidget(trunkResLineEdit);


        verticalLayout->addLayout(horizontalLayout_20);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(0, 20));
        label_3->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_3->addWidget(label_3);

        dComLineEdit = new QLineEdit(layoutWidget);
        dComLineEdit->setObjectName(QStringLiteral("dComLineEdit"));
        dComLineEdit->setMinimumSize(QSize(50, 0));
        dComLineEdit->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(dComLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(0, 20));
        label_8->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_7->addWidget(label_8);

        maxDResLabel = new QLabel(layoutWidget);
        maxDResLabel->setObjectName(QStringLiteral("maxDResLabel"));
        maxDResLabel->setMinimumSize(QSize(0, 20));
        maxDResLabel->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_7->addWidget(maxDResLabel);

        setMaxDurationPushButton = new QPushButton(layoutWidget);
        setMaxDurationPushButton->setObjectName(QStringLiteral("setMaxDurationPushButton"));
        setMaxDurationPushButton->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_7->addWidget(setMaxDurationPushButton);


        verticalLayout->addLayout(horizontalLayout_7);

        line_2 = new QFrame(layoutWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        setbRadioButton = new QRadioButton(layoutWidget);
        buttonGroup_2 = new QButtonGroup(MainWindow);
        buttonGroup_2->setObjectName(QStringLiteral("buttonGroup_2"));
        buttonGroup_2->addButton(setbRadioButton);
        setbRadioButton->setObjectName(QStringLiteral("setbRadioButton"));
        setbRadioButton->setMinimumSize(QSize(0, 20));
        setbRadioButton->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_8->addWidget(setbRadioButton);

        setQdRadioButton = new QRadioButton(layoutWidget);
        buttonGroup_2->addButton(setQdRadioButton);
        setQdRadioButton->setObjectName(QStringLiteral("setQdRadioButton"));
        setQdRadioButton->setMinimumSize(QSize(0, 20));
        setQdRadioButton->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_8->addWidget(setQdRadioButton);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setMinimumSize(QSize(0, 20));
        label_13->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_11->addWidget(label_13);

        bLineEdit = new QLineEdit(layoutWidget);
        bLineEdit->setObjectName(QStringLiteral("bLineEdit"));
        bLineEdit->setMinimumSize(QSize(50, 0));
        bLineEdit->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_11->addWidget(bLineEdit);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMinimumSize(QSize(0, 20));
        label_12->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_10->addWidget(label_12);

        qLineEdit = new QLineEdit(layoutWidget);
        qLineEdit->setObjectName(QStringLiteral("qLineEdit"));
        qLineEdit->setMinimumSize(QSize(50, 0));
        qLineEdit->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_10->addWidget(qLineEdit);


        verticalLayout->addLayout(horizontalLayout_10);

        line = new QFrame(layoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_18 = new QLabel(layoutWidget);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setMinimumSize(QSize(0, 20));
        label_18->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_16->addWidget(label_18);

        pCongInputLineEdit = new QLineEdit(layoutWidget);
        pCongInputLineEdit->setObjectName(QStringLiteral("pCongInputLineEdit"));
        pCongInputLineEdit->setMinimumSize(QSize(50, 0));
        pCongInputLineEdit->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_16->addWidget(pCongInputLineEdit);


        verticalLayout->addLayout(horizontalLayout_16);

        line_3 = new QFrame(layoutWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        inputTableView = new QTableView(groupBox_3);
        inputTableView->setObjectName(QStringLiteral("inputTableView"));
        inputTableView->setGeometry(QRect(10, 330, 439, 101));
        inputTableView->setMinimumSize(QSize(379, 0));
        inputTableView->setMaximumSize(QSize(439, 16777215));
        layoutWidget1 = new QWidget(groupBox_3);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 440, 441, 25));
        horizontalLayout_19 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        horizontalLayout_19->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_2);

        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(75, 23));
        pushButton->setMaximumSize(QSize(75, 23));

        horizontalLayout_19->addWidget(pushButton);

        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 60, 461, 171));
        groupBox_4->setMinimumSize(QSize(461, 171));
        groupBox_4->setMaximumSize(QSize(461, 171));
        QFont font3;
        font3.setPointSize(8);
        font3.setKerning(true);
        groupBox_4->setFont(font3);
        layoutWidget2 = new QWidget(groupBox_4);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 20, 441, 141));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        label_19 = new QLabel(layoutWidget2);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setMinimumSize(QSize(0, 20));
        label_19->setMaximumSize(QSize(16777215, 16777215));
        QFont font4;
        font4.setFamily(QStringLiteral("Arial"));
        label_19->setFont(font4);

        horizontalLayout_17->addWidget(label_19);

        cSpinBox = new QSpinBox(layoutWidget2);
        cSpinBox->setObjectName(QStringLiteral("cSpinBox"));
        cSpinBox->setMaximumSize(QSize(50, 16777215));
        cSpinBox->setMinimum(1);

        horizontalLayout_17->addWidget(cSpinBox);


        verticalLayout_2->addLayout(horizontalLayout_17);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget2);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 20));
        label->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(label);

        rLineEdit = new QLineEdit(layoutWidget2);
        rLineEdit->setObjectName(QStringLiteral("rLineEdit"));
        rLineEdit->setMinimumSize(QSize(50, 0));
        rLineEdit->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(rLineEdit);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 20));
        label_2->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_2->addWidget(label_2);

        uLineEdit = new QLineEdit(layoutWidget2);
        uLineEdit->setObjectName(QStringLiteral("uLineEdit"));
        uLineEdit->setMinimumSize(QSize(50, 0));
        uLineEdit->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_2->addWidget(uLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_11 = new QLabel(layoutWidget2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMinimumSize(QSize(0, 20));
        label_11->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_9->addWidget(label_11);

        delayLineEdit = new QLineEdit(layoutWidget2);
        delayLineEdit->setObjectName(QStringLiteral("delayLineEdit"));
        delayLineEdit->setMinimumSize(QSize(50, 0));
        delayLineEdit->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_9->addWidget(delayLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        label_21 = new QLabel(layoutWidget2);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setMinimumSize(QSize(0, 20));
        label_21->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_18->addWidget(label_21);

        cX2LineEdit = new QLineEdit(layoutWidget2);
        cX2LineEdit->setObjectName(QStringLiteral("cX2LineEdit"));
        cX2LineEdit->setMinimumSize(QSize(50, 0));
        cX2LineEdit->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_18->addWidget(cX2LineEdit);


        verticalLayout_2->addLayout(horizontalLayout_18);

        layoutWidget_5 = new QWidget(groupBox);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(20, 20, 451, 25));
        horizontalLayout_13 = new QHBoxLayout(layoutWidget_5);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        label_15 = new QLabel(layoutWidget_5);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setMinimumSize(QSize(0, 20));

        horizontalLayout_13->addWidget(label_15);

        pbRadioButton = new QRadioButton(layoutWidget_5);
        buttonGroup_3 = new QButtonGroup(MainWindow);
        buttonGroup_3->setObjectName(QStringLiteral("buttonGroup_3"));
        buttonGroup_3->addButton(pbRadioButton);
        pbRadioButton->setObjectName(QStringLiteral("pbRadioButton"));
        pbRadioButton->setMinimumSize(QSize(0, 20));
        pbRadioButton->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_13->addWidget(pbRadioButton);

        cx2RadioButton = new QRadioButton(layoutWidget_5);
        buttonGroup_3->addButton(cx2RadioButton);
        cx2RadioButton->setObjectName(QStringLiteral("cx2RadioButton"));
        cx2RadioButton->setMinimumSize(QSize(0, 20));

        horizontalLayout_13->addWidget(cx2RadioButton);

        enhModelCheckBox = new QCheckBox(layoutWidget_5);
        enhModelCheckBox->setObjectName(QStringLiteral("enhModelCheckBox"));

        horizontalLayout_13->addWidget(enhModelCheckBox);

        horizontalSpacer_3 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_3);

        trunkResCheckBox = new QCheckBox(layoutWidget_5);
        trunkResCheckBox->setObjectName(QStringLiteral("trunkResCheckBox"));

        horizontalLayout_13->addWidget(trunkResCheckBox);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_6 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setMinimumSize(QSize(301, 721));
        groupBox_6->setMaximumSize(QSize(16777215, 721));
        groupBox_2 = new QGroupBox(groupBox_6);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 20, 281, 251));
        groupBox_2->setMinimumSize(QSize(0, 251));
        groupBox_2->setMaximumSize(QSize(281, 251));
        congProbTableView = new QTableView(groupBox_2);
        congProbTableView->setObjectName(QStringLiteral("congProbTableView"));
        congProbTableView->setGeometry(QRect(10, 20, 259, 191));
        layoutWidget3 = new QWidget(groupBox_2);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 220, 171, 20));
        horizontalLayout_12 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget3);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_12->addWidget(label_5);

        cX2OutLabel = new QLabel(layoutWidget3);
        cX2OutLabel->setObjectName(QStringLiteral("cX2OutLabel"));

        horizontalLayout_12->addWidget(cX2OutLabel);

        groupBox_5 = new QGroupBox(groupBox_6);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 280, 281, 431));
        groupBox_5->setMinimumSize(QSize(0, 0));
        groupBox_5->setMaximumSize(QSize(281, 16777215));
        congVectorsTableView = new QTableView(groupBox_5);
        congVectorsTableView->setObjectName(QStringLiteral("congVectorsTableView"));
        congVectorsTableView->setGeometry(QRect(10, 50, 259, 371));
        layoutWidget4 = new QWidget(groupBox_5);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 20, 191, 28));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget4);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_5->addWidget(label_4);

        userServClassComboBox = new QComboBox(layoutWidget4);
        userServClassComboBox->setObjectName(QStringLiteral("userServClassComboBox"));
        userServClassComboBox->setMinimumSize(QSize(50, 0));
        userServClassComboBox->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_5->addWidget(userServClassComboBox);


        gridLayout->addWidget(groupBox_6, 0, 1, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(scrollAreaWidgetContents);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(91, 16));
        label_6->setMaximumSize(QSize(91, 16));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_6);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        calculatePushButton = new QPushButton(scrollAreaWidgetContents);
        calculatePushButton->setObjectName(QStringLiteral("calculatePushButton"));
        calculatePushButton->setMinimumSize(QSize(0, 23));
        calculatePushButton->setMaximumSize(QSize(16777215, 23));

        horizontalLayout_6->addWidget(calculatePushButton);

        plotExportPushButton = new QPushButton(scrollAreaWidgetContents);
        plotExportPushButton->setObjectName(QStringLiteral("plotExportPushButton"));

        horizontalLayout_6->addWidget(plotExportPushButton);


        gridLayout->addLayout(horizontalLayout_6, 1, 0, 1, 2);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_3->addWidget(scrollArea, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 812, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "BKR model", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Input data", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Set service class parameters", 0));
        label_14->setText(QApplication::translate("MainWindow", "Service class:", 0));
        servClassComboBox->clear();
        servClassComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", 0)
        );
        label_16->setText(QApplication::translate("MainWindow", "Expected max. number of UE, N:", 0));
        label_17->setText(QApplication::translate("MainWindow", "UE's throughput, d (Mb/s):", 0));
        label_20->setText(QApplication::translate("MainWindow", "Trunk reservation, t (Mb/sec):", 0));
        label_3->setText(QApplication::translate("MainWindow", "Duration of the communiaction, \316\224 (s):", 0));
        label_8->setText(QApplication::translate("MainWindow", "* Max. acceptable value for \316\224 =", 0));
        maxDResLabel->setText(QString());
        setMaxDurationPushButton->setText(QApplication::translate("MainWindow", "Set max. value", 0));
        setbRadioButton->setText(QApplication::translate("MainWindow", "Set \316\262", 0));
        setQdRadioButton->setText(QApplication::translate("MainWindow", "Set Q", 0));
        label_13->setText(QApplication::translate("MainWindow", "Period during which data are stored, \316\262 (ms):", 0));
        label_12->setText(QApplication::translate("MainWindow", "Buffer size and data in transit, Q (Mb):", 0));
        label_18->setText(QApplication::translate("MainWindow", "Max. congestion probability, p:", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Set", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Set general parameters", 0));
        label_19->setText(QApplication::translate("MainWindow", "Number of service classes, K:", 0));
        label->setText(QApplication::translate("MainWindow", "Cell radius, R (km):", 0));
        label_2->setText(QApplication::translate("MainWindow", "UE velocity, u (km/h):", 0));
        label_11->setText(QApplication::translate("MainWindow", "Delay constraint, \316\264 (ms):", 0));
        label_21->setText(QApplication::translate("MainWindow", "X2 link capacity, CX2 (Mb/s):", 0));
        label_15->setText(QApplication::translate("MainWindow", "Calculate:", 0));
        pbRadioButton->setText(QApplication::translate("MainWindow", "Pb", 0));
        cx2RadioButton->setText(QApplication::translate("MainWindow", "CX2", 0));
        enhModelCheckBox->setText(QApplication::translate("MainWindow", "Enhanced model", 0));
        trunkResCheckBox->setText(QApplication::translate("MainWindow", "Trunk reservation", 0));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "Output results", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Blocking probabilities", 0));
        label_5->setText(QApplication::translate("MainWindow", "CX2:", 0));
        cX2OutLabel->setText(QString());
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Congestion vectors", 0));
        label_4->setText(QApplication::translate("MainWindow", "UE's service class:", 0));
        userServClassComboBox->clear();
        userServClassComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", 0)
        );
        label_6->setText(QApplication::translate("MainWindow", "\302\251 Panagoulias P.", 0));
        calculatePushButton->setText(QApplication::translate("MainWindow", "Calculate", 0));
        plotExportPushButton->setText(QApplication::translate("MainWindow", "Plot/Export >", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
