/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *dothething;
    QLabel *label;
    QLineEdit *oldListTextbox;
    QPushButton *browseOldList;
    QLabel *label_2;
    QLineEdit *newListTextbox;
    QPushButton *browseNewList;
    QCheckBox *inclHeadersPrev;
    QCheckBox *inclHeadersNew;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QSpinBox *apiColPrevList;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QSpinBox *apiColNewList;
    QPushButton *browseAddLoc;
    QLabel *label_4;
    QLineEdit *addDownloadLoc;
    QLabel *label_6;
    QLineEdit *delDownloadLoc;
    QPushButton *browseDelLoc;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(807, 420);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        dothething = new QPushButton(centralwidget);
        dothething->setObjectName("dothething");
        dothething->setGeometry(QRect(550, 340, 141, 24));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 40, 121, 29));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        oldListTextbox = new QLineEdit(centralwidget);
        oldListTextbox->setObjectName("oldListTextbox");
        oldListTextbox->setGeometry(QRect(30, 70, 231, 24));
        browseOldList = new QPushButton(centralwidget);
        browseOldList->setObjectName("browseOldList");
        browseOldList->setGeometry(QRect(270, 70, 71, 24));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 200, 121, 20));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        newListTextbox = new QLineEdit(centralwidget);
        newListTextbox->setObjectName("newListTextbox");
        newListTextbox->setGeometry(QRect(30, 230, 231, 24));
        browseNewList = new QPushButton(centralwidget);
        browseNewList->setObjectName("browseNewList");
        browseNewList->setGeometry(QRect(270, 230, 71, 24));
        inclHeadersPrev = new QCheckBox(centralwidget);
        inclHeadersPrev->setObjectName("inclHeadersPrev");
        inclHeadersPrev->setGeometry(QRect(40, 140, 151, 22));
        inclHeadersPrev->setChecked(true);
        inclHeadersNew = new QCheckBox(centralwidget);
        inclHeadersNew->setObjectName("inclHeadersNew");
        inclHeadersNew->setGeometry(QRect(40, 300, 151, 22));
        inclHeadersNew->setChecked(true);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(40, 110, 171, 27));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        horizontalLayout->addWidget(label_3);

        apiColPrevList = new QSpinBox(layoutWidget);
        apiColPrevList->setObjectName("apiColPrevList");
        apiColPrevList->setValue(2);

        horizontalLayout->addWidget(apiColPrevList);

        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(40, 270, 171, 27));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget_2);
        label_5->setObjectName("label_5");

        horizontalLayout_3->addWidget(label_5);

        apiColNewList = new QSpinBox(layoutWidget_2);
        apiColNewList->setObjectName("apiColNewList");
        apiColNewList->setValue(2);

        horizontalLayout_3->addWidget(apiColNewList);

        browseAddLoc = new QPushButton(centralwidget);
        browseAddLoc->setObjectName("browseAddLoc");
        browseAddLoc->setGeometry(QRect(700, 70, 71, 24));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(460, 40, 171, 29));
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        addDownloadLoc = new QLineEdit(centralwidget);
        addDownloadLoc->setObjectName("addDownloadLoc");
        addDownloadLoc->setGeometry(QRect(460, 70, 231, 24));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(460, 120, 171, 29));
        label_6->setAlignment(Qt::AlignmentFlag::AlignCenter);
        delDownloadLoc = new QLineEdit(centralwidget);
        delDownloadLoc->setObjectName("delDownloadLoc");
        delDownloadLoc->setGeometry(QRect(460, 150, 231, 24));
        browseDelLoc = new QPushButton(centralwidget);
        browseDelLoc->setObjectName("browseDelLoc");
        browseDelLoc->setGeometry(QRect(700, 150, 71, 24));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        dothething->setText(QCoreApplication::translate("MainWindow", "Output Filtered Lists", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Previous List Filepath", nullptr));
        oldListTextbox->setText(QString());
        browseOldList->setText(QCoreApplication::translate("MainWindow", "Browse...", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Updated List Filepath", nullptr));
        newListTextbox->setText(QString());
        browseNewList->setText(QCoreApplication::translate("MainWindow", "Browse...", nullptr));
        inclHeadersPrev->setText(QCoreApplication::translate("MainWindow", "Data includes headers", nullptr));
        inclHeadersNew->setText(QCoreApplication::translate("MainWindow", "Data includes headers", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "API Column:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "API Column:", nullptr));
        browseAddLoc->setText(QCoreApplication::translate("MainWindow", "Browse...", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Additions Download Location", nullptr));
        addDownloadLoc->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "Deletions Download Location", nullptr));
        delDownloadLoc->setText(QString());
        browseDelLoc->setText(QCoreApplication::translate("MainWindow", "Browse...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
