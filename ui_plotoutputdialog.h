/********************************************************************************
** Form generated from reading UI file 'plotoutputdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTOUTPUTDIALOG_H
#define UI_PLOTOUTPUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "plotgraphs.h"

QT_BEGIN_NAMESPACE

class Ui_PlotOutputDialog
{
public:
    QGridLayout *gridLayout_7;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QLineEdit *numOfStepsLineEdit;
    QGroupBox *groupBox;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QComboBox *servClassComboBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *nMinLineEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *userStepLlineEdit;
    QPushButton *removeButton;
    QPushButton *setButton;
    QTableView *usersTableView;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_5;
    QLineEdit *cX2MinLineEdit;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    QLineEdit *cX2StepLlineEdit;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_9;
    QLabel *cX2MaxLabel;
    QGroupBox *groupBox_4;
    QTableView *inputTableView;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_9;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_12;
    QLabel *KLabel;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_13;
    QLabel *RLabel;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_14;
    QLabel *uLabel;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_10;
    QLabel *CX2Label;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout;
    PlotGraphs *plotWidget;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_8;
    QLabel *servClassLabel;
    QComboBox *plotServClassComboBox;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *plotShowCheckBox;
    QLabel *label_11;
    QComboBox *scatterComboBox;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *rescalePushButton;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *exportPushButton;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_3;
    QTableView *xAxisTableView;
    QTableView *congProbTableView;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *exportTablesPushButton;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *backPushButton;
    QSpacerItem *horizontalSpacer_9;
    QProgressBar *progressBar;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *plotPushButton;

    void setupUi(QDialog *PlotOutputDialog)
    {
        if (PlotOutputDialog->objectName().isEmpty())
            PlotOutputDialog->setObjectName(QStringLiteral("PlotOutputDialog"));
        PlotOutputDialog->resize(1178, 793);
        QIcon icon;
        icon.addFile(QStringLiteral("logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        PlotOutputDialog->setWindowIcon(icon);
        gridLayout_7 = new QGridLayout(PlotOutputDialog);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        scrollArea = new QScrollArea(PlotOutputDialog);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1160, 775));
        gridLayout_8 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        groupBox_3 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(491, 301));
        groupBox_3->setMaximumSize(QSize(491, 301));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        groupBox_3->setFont(font);
        layoutWidget_4 = new QWidget(groupBox_3);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(20, 30, 171, 22));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget_4);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);

        horizontalLayout_8->addWidget(label_8);

        numOfStepsLineEdit = new QLineEdit(layoutWidget_4);
        numOfStepsLineEdit->setObjectName(QStringLiteral("numOfStepsLineEdit"));
        numOfStepsLineEdit->setMinimumSize(QSize(50, 0));
        numOfStepsLineEdit->setMaximumSize(QSize(50, 16777215));
        numOfStepsLineEdit->setFont(font);

        horizontalLayout_8->addWidget(numOfStepsLineEdit);

        groupBox = new QGroupBox(groupBox_3);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 70, 471, 151));
        QFont font1;
        font1.setPointSize(8);
        font1.setBold(false);
        font1.setWeight(50);
        groupBox->setFont(font1);
        layoutWidget_2 = new QWidget(groupBox);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 20, 176, 91));
        verticalLayout = new QVBoxLayout(layoutWidget_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label = new QLabel(layoutWidget_2);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        horizontalLayout_4->addWidget(label);

        servClassComboBox = new QComboBox(layoutWidget_2);
        servClassComboBox->setObjectName(QStringLiteral("servClassComboBox"));
        servClassComboBox->setMinimumSize(QSize(50, 0));
        servClassComboBox->setMaximumSize(QSize(50, 16777215));
        servClassComboBox->setFont(font);

        horizontalLayout_4->addWidget(servClassComboBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_4 = new QLabel(layoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        horizontalLayout_5->addWidget(label_4);

        nMinLineEdit = new QLineEdit(layoutWidget_2);
        nMinLineEdit->setObjectName(QStringLiteral("nMinLineEdit"));
        nMinLineEdit->setMinimumSize(QSize(50, 0));
        nMinLineEdit->setMaximumSize(QSize(50, 16777215));
        nMinLineEdit->setFont(font);

        horizontalLayout_5->addWidget(nMinLineEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(layoutWidget_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        horizontalLayout_6->addWidget(label_6);

        userStepLlineEdit = new QLineEdit(layoutWidget_2);
        userStepLlineEdit->setObjectName(QStringLiteral("userStepLlineEdit"));
        userStepLlineEdit->setMinimumSize(QSize(50, 0));
        userStepLlineEdit->setMaximumSize(QSize(50, 16777215));
        userStepLlineEdit->setFont(font);

        horizontalLayout_6->addWidget(userStepLlineEdit);


        verticalLayout->addLayout(horizontalLayout_6);

        removeButton = new QPushButton(groupBox);
        removeButton->setObjectName(QStringLiteral("removeButton"));
        removeButton->setGeometry(QRect(10, 120, 75, 23));
        removeButton->setMinimumSize(QSize(75, 0));
        removeButton->setMaximumSize(QSize(75, 16777215));
        removeButton->setFont(font);
        removeButton->setFocusPolicy(Qt::NoFocus);
        setButton = new QPushButton(groupBox);
        setButton->setObjectName(QStringLiteral("setButton"));
        setButton->setGeometry(QRect(110, 120, 75, 23));
        setButton->setMinimumSize(QSize(75, 0));
        setButton->setMaximumSize(QSize(75, 16777215));
        setButton->setFont(font);
        setButton->setFocusPolicy(Qt::NoFocus);
        setButton->setContextMenuPolicy(Qt::DefaultContextMenu);
        usersTableView = new QTableView(groupBox);
        usersTableView->setObjectName(QStringLiteral("usersTableView"));
        usersTableView->setGeometry(QRect(200, 20, 259, 121));
        usersTableView->setFocusPolicy(Qt::WheelFocus);
        groupBox_2 = new QGroupBox(groupBox_3);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 230, 471, 61));
        groupBox_2->setFont(font);
        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 451, 24));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        horizontalLayout_9->addWidget(label_5);

        cX2MinLineEdit = new QLineEdit(layoutWidget);
        cX2MinLineEdit->setObjectName(QStringLiteral("cX2MinLineEdit"));
        cX2MinLineEdit->setMinimumSize(QSize(50, 0));
        cX2MinLineEdit->setMaximumSize(QSize(50, 16777215));
        cX2MinLineEdit->setFont(font);

        horizontalLayout_9->addWidget(cX2MinLineEdit);


        horizontalLayout_2->addLayout(horizontalLayout_9);

        horizontalSpacer = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(30, 0));
        label_7->setMaximumSize(QSize(30, 16777215));
        label_7->setFont(font);

        horizontalLayout_3->addWidget(label_7);

        cX2StepLlineEdit = new QLineEdit(layoutWidget);
        cX2StepLlineEdit->setObjectName(QStringLiteral("cX2StepLlineEdit"));
        cX2StepLlineEdit->setMinimumSize(QSize(50, 0));
        cX2StepLlineEdit->setMaximumSize(QSize(50, 16777215));
        cX2StepLlineEdit->setFont(font);

        horizontalLayout_3->addWidget(cX2StepLlineEdit);


        horizontalLayout_2->addLayout(horizontalLayout_3);

        horizontalSpacer_2 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);

        horizontalLayout->addWidget(label_9);

        cX2MaxLabel = new QLabel(layoutWidget);
        cX2MaxLabel->setObjectName(QStringLiteral("cX2MaxLabel"));
        cX2MaxLabel->setMinimumSize(QSize(50, 0));
        cX2MaxLabel->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(cX2MaxLabel);


        horizontalLayout_2->addLayout(horizontalLayout);


        gridLayout_2->addWidget(groupBox_3, 0, 0, 1, 1);

        groupBox_4 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setMinimumSize(QSize(341, 301));
        groupBox_4->setMaximumSize(QSize(1000, 301));
        groupBox_4->setFont(font);
        inputTableView = new QTableView(groupBox_4);
        inputTableView->setObjectName(QStringLiteral("inputTableView"));
        inputTableView->setGeometry(QRect(10, 80, 319, 211));
        inputTableView->setFocusPolicy(Qt::WheelFocus);
        layoutWidget1 = new QWidget(groupBox_4);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 20, 241, 52));
        gridLayout_9 = new QGridLayout(layoutWidget1);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_9->setHorizontalSpacing(30);
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_12 = new QLabel(layoutWidget1);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMinimumSize(QSize(0, 20));
        label_12->setMaximumSize(QSize(17, 25));
        label_12->setFont(font);

        horizontalLayout_7->addWidget(label_12);

        KLabel = new QLabel(layoutWidget1);
        KLabel->setObjectName(QStringLiteral("KLabel"));
        KLabel->setMinimumSize(QSize(40, 0));
        KLabel->setMaximumSize(QSize(1000, 16777215));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        KLabel->setFont(font2);
        KLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(KLabel);


        gridLayout_9->addLayout(horizontalLayout_7, 0, 0, 1, 1);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_13 = new QLabel(layoutWidget1);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setMinimumSize(QSize(0, 20));
        label_13->setMaximumSize(QSize(40, 25));
        label_13->setFont(font);

        horizontalLayout_13->addWidget(label_13);

        RLabel = new QLabel(layoutWidget1);
        RLabel->setObjectName(QStringLiteral("RLabel"));
        RLabel->setMinimumSize(QSize(40, 0));
        RLabel->setMaximumSize(QSize(1000, 16777215));
        RLabel->setFont(font2);
        RLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_13->addWidget(RLabel);


        gridLayout_9->addLayout(horizontalLayout_13, 0, 1, 1, 1);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_14 = new QLabel(layoutWidget1);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setMinimumSize(QSize(0, 20));
        label_14->setMaximumSize(QSize(70, 25));
        label_14->setFont(font);

        horizontalLayout_14->addWidget(label_14);

        uLabel = new QLabel(layoutWidget1);
        uLabel->setObjectName(QStringLiteral("uLabel"));
        uLabel->setMinimumSize(QSize(40, 0));
        uLabel->setMaximumSize(QSize(1000, 16777215));
        uLabel->setFont(font2);
        uLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_14->addWidget(uLabel);


        gridLayout_9->addLayout(horizontalLayout_14, 1, 0, 1, 1);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(0, 20));
        label_10->setMaximumSize(QSize(75, 25));
        label_10->setFont(font);

        horizontalLayout_15->addWidget(label_10);

        CX2Label = new QLabel(layoutWidget1);
        CX2Label->setObjectName(QStringLiteral("CX2Label"));
        CX2Label->setMinimumSize(QSize(30, 0));
        CX2Label->setMaximumSize(QSize(35, 16777215));
        CX2Label->setFont(font2);
        CX2Label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_15->addWidget(CX2Label);


        gridLayout_9->addLayout(horizontalLayout_15, 1, 1, 1, 1);


        gridLayout_2->addWidget(groupBox_4, 0, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 0, 0, 1, 1);

        groupBox_6 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setMinimumSize(QSize(841, 411));
        gridLayout = new QGridLayout(groupBox_6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        plotWidget = new PlotGraphs(groupBox_6);
        plotWidget->setObjectName(QStringLiteral("plotWidget"));

        gridLayout->addWidget(plotWidget, 0, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalSpacer_8 = new QSpacerItem(118, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_8);

        servClassLabel = new QLabel(groupBox_6);
        servClassLabel->setObjectName(QStringLiteral("servClassLabel"));
        servClassLabel->setMinimumSize(QSize(65, 20));
        servClassLabel->setMaximumSize(QSize(65, 20));
        servClassLabel->setFont(font);

        horizontalLayout_11->addWidget(servClassLabel);

        plotServClassComboBox = new QComboBox(groupBox_6);
        plotServClassComboBox->setObjectName(QStringLiteral("plotServClassComboBox"));
        plotServClassComboBox->setMinimumSize(QSize(50, 20));
        plotServClassComboBox->setMaximumSize(QSize(50, 20));
        plotServClassComboBox->setFont(font);

        horizontalLayout_11->addWidget(plotServClassComboBox);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_3);

        plotShowCheckBox = new QCheckBox(groupBox_6);
        plotShowCheckBox->setObjectName(QStringLiteral("plotShowCheckBox"));
        plotShowCheckBox->setMinimumSize(QSize(48, 17));
        plotShowCheckBox->setMaximumSize(QSize(48, 17));
        plotShowCheckBox->setFont(font);

        horizontalLayout_11->addWidget(plotShowCheckBox);

        label_11 = new QLabel(groupBox_6);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font);

        horizontalLayout_11->addWidget(label_11);

        scatterComboBox = new QComboBox(groupBox_6);
        scatterComboBox->setObjectName(QStringLiteral("scatterComboBox"));
        scatterComboBox->setMinimumSize(QSize(50, 20));
        scatterComboBox->setMaximumSize(QSize(50, 20));
        scatterComboBox->setFont(font);

        horizontalLayout_11->addWidget(scatterComboBox);

        horizontalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_5);

        rescalePushButton = new QPushButton(groupBox_6);
        rescalePushButton->setObjectName(QStringLiteral("rescalePushButton"));
        rescalePushButton->setMinimumSize(QSize(50, 23));
        rescalePushButton->setMaximumSize(QSize(50, 23));
        rescalePushButton->setFont(font);
        rescalePushButton->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_11->addWidget(rescalePushButton);

        horizontalSpacer_7 = new QSpacerItem(70, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_7);

        exportPushButton = new QPushButton(groupBox_6);
        exportPushButton->setObjectName(QStringLiteral("exportPushButton"));
        exportPushButton->setMinimumSize(QSize(75, 23));
        exportPushButton->setMaximumSize(QSize(75, 23));
        exportPushButton->setFont(font);
        exportPushButton->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_11->addWidget(exportPushButton);


        gridLayout->addLayout(horizontalLayout_11, 1, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_6, 1, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 0, 0, 1, 1);

        groupBox_5 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setMinimumSize(QSize(279, 711));
        groupBox_5->setMaximumSize(QSize(550, 16777215));
        groupBox_5->setFont(font);
        gridLayout_3 = new QGridLayout(groupBox_5);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        xAxisTableView = new QTableView(groupBox_5);
        xAxisTableView->setObjectName(QStringLiteral("xAxisTableView"));

        gridLayout_3->addWidget(xAxisTableView, 0, 0, 1, 1);

        congProbTableView = new QTableView(groupBox_5);
        congProbTableView->setObjectName(QStringLiteral("congProbTableView"));

        gridLayout_3->addWidget(congProbTableView, 1, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_6);

        exportTablesPushButton = new QPushButton(groupBox_5);
        exportTablesPushButton->setObjectName(QStringLiteral("exportTablesPushButton"));
        exportTablesPushButton->setMinimumSize(QSize(75, 23));
        exportTablesPushButton->setMaximumSize(QSize(75, 23));
        exportTablesPushButton->setFont(font);
        exportTablesPushButton->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_10->addWidget(exportTablesPushButton);


        gridLayout_3->addLayout(horizontalLayout_10, 2, 0, 1, 1);


        gridLayout_5->addWidget(groupBox_5, 0, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 0, 0, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        backPushButton = new QPushButton(scrollAreaWidgetContents);
        backPushButton->setObjectName(QStringLiteral("backPushButton"));
        backPushButton->setMinimumSize(QSize(75, 23));
        backPushButton->setMaximumSize(QSize(75, 23));
        backPushButton->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_12->addWidget(backPushButton);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_9);

        progressBar = new QProgressBar(scrollAreaWidgetContents);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        horizontalLayout_12->addWidget(progressBar);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_4);

        plotPushButton = new QPushButton(scrollAreaWidgetContents);
        plotPushButton->setObjectName(QStringLiteral("plotPushButton"));
        plotPushButton->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_12->addWidget(plotPushButton);


        gridLayout_6->addLayout(horizontalLayout_12, 1, 0, 1, 1);


        gridLayout_8->addLayout(gridLayout_6, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_7->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(PlotOutputDialog);

        QMetaObject::connectSlotsByName(PlotOutputDialog);
    } // setupUi

    void retranslateUi(QDialog *PlotOutputDialog)
    {
        PlotOutputDialog->setWindowTitle(QApplication::translate("PlotOutputDialog", "BKR model (Plot - Export)", 0));
        groupBox_3->setTitle(QApplication::translate("PlotOutputDialog", "Plot Parameters", 0));
        label_8->setText(QApplication::translate("PlotOutputDialog", "Number of steps:", 0));
        groupBox->setTitle(QApplication::translate("PlotOutputDialog", "x-axis (define users' distributions)", 0));
        label->setText(QApplication::translate("PlotOutputDialog", "Select service class:", 0));
        label_4->setText(QApplication::translate("PlotOutputDialog", "n, min value:", 0));
        label_6->setText(QApplication::translate("PlotOutputDialog", "Step:", 0));
        removeButton->setText(QApplication::translate("PlotOutputDialog", "Remove", 0));
        setButton->setText(QApplication::translate("PlotOutputDialog", "Set", 0));
        groupBox_2->setTitle(QApplication::translate("PlotOutputDialog", "x-axis (define bandwidth)", 0));
        label_5->setText(QApplication::translate("PlotOutputDialog", "CX2, min value:", 0));
        label_7->setText(QApplication::translate("PlotOutputDialog", "Step:", 0));
        label_9->setText(QApplication::translate("PlotOutputDialog", "CX2, max value:", 0));
        cX2MaxLabel->setText(QString());
        groupBox_4->setTitle(QApplication::translate("PlotOutputDialog", "Input parameters", 0));
        label_12->setText(QApplication::translate("PlotOutputDialog", "K:", 0));
        KLabel->setText(QString());
        label_13->setText(QApplication::translate("PlotOutputDialog", "R (km):", 0));
        RLabel->setText(QString());
        label_14->setText(QApplication::translate("PlotOutputDialog", "u (km/h):", 0));
        uLabel->setText(QString());
        label_10->setText(QApplication::translate("PlotOutputDialog", "CX2 (Mbps):", 0));
        CX2Label->setText(QString());
        groupBox_6->setTitle(QApplication::translate("PlotOutputDialog", "Plot", 0));
        servClassLabel->setText(QApplication::translate("PlotOutputDialog", "Service class:", 0));
        plotShowCheckBox->setText(QApplication::translate("PlotOutputDialog", "show", 0));
        label_11->setText(QApplication::translate("PlotOutputDialog", "Scatter shape:", 0));
        scatterComboBox->clear();
        scatterComboBox->insertItems(0, QStringList()
         << QApplication::translate("PlotOutputDialog", "\342\227\217", 0)
         << QApplication::translate("PlotOutputDialog", "o", 0)
         << QApplication::translate("PlotOutputDialog", "x", 0)
         << QApplication::translate("PlotOutputDialog", "+", 0)
         << QApplication::translate("PlotOutputDialog", "\342\226\241", 0)
         << QApplication::translate("PlotOutputDialog", "*", 0)
         << QApplication::translate("PlotOutputDialog", "\316\224", 0)
         << QApplication::translate("PlotOutputDialog", "\342\210\207", 0)
        );
        rescalePushButton->setText(QApplication::translate("PlotOutputDialog", "Rescale", 0));
        exportPushButton->setText(QApplication::translate("PlotOutputDialog", "Export", 0));
        groupBox_5->setTitle(QApplication::translate("PlotOutputDialog", "Output tables", 0));
        exportTablesPushButton->setText(QApplication::translate("PlotOutputDialog", "Export", 0));
        backPushButton->setText(QApplication::translate("PlotOutputDialog", "< Back", 0));
        plotPushButton->setText(QApplication::translate("PlotOutputDialog", "Plot", 0));
    } // retranslateUi

};

namespace Ui {
    class PlotOutputDialog: public Ui_PlotOutputDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTOUTPUTDIALOG_H
