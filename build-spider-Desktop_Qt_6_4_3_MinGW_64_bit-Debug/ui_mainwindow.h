/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *siteLabel;
    QComboBox *siteCombo;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *checkBox;
    QComboBox *parametersCombo;
    QSpacerItem *horizontalSpacer;
    QPushButton *pbtSearch;
    QTableView *tableView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        siteLabel = new QLabel(centralwidget);
        siteLabel->setObjectName("siteLabel");

        horizontalLayout->addWidget(siteLabel);

        siteCombo = new QComboBox(centralwidget);
        siteCombo->setObjectName("siteCombo");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(siteCombo->sizePolicy().hasHeightForWidth());
        siteCombo->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(siteCombo);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName("checkBox");
        QFont font;
        font.setBold(true);
        checkBox->setFont(font);

        horizontalLayout->addWidget(checkBox);

        parametersCombo = new QComboBox(centralwidget);
        parametersCombo->setObjectName("parametersCombo");
        sizePolicy.setHeightForWidth(parametersCombo->sizePolicy().hasHeightForWidth());
        parametersCombo->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(parametersCombo);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pbtSearch = new QPushButton(centralwidget);
        pbtSearch->setObjectName("pbtSearch");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pbtSearch->sizePolicy().hasHeightForWidth());
        pbtSearch->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        pbtSearch->setFont(font1);

        horizontalLayout->addWidget(pbtSearch);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        QFont font2;
        font2.setBold(false);
        tableView->setFont(font2);

        gridLayout->addWidget(tableView, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        siteLabel->setText(QCoreApplication::translate("MainWindow", "WebSite", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "apply parameters", nullptr));
        pbtSearch->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
