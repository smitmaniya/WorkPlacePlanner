/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QListWidget *listWidgetItems;
    QGraphicsView *graphicsViewCanvas;
    QPushButton *buttonExport;
    QPushButton *buttonImport;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        listWidgetItems = new QListWidget(centralwidget);
        listWidgetItems->setObjectName("listWidgetItems");
        listWidgetItems->setGeometry(QRect(10, 10, 191, 461));
        listWidgetItems->setProperty("isWrapping", QVariant(false));
        graphicsViewCanvas = new QGraphicsView(centralwidget);
        graphicsViewCanvas->setObjectName("graphicsViewCanvas");
        graphicsViewCanvas->setGeometry(QRect(210, 0, 581, 511));
        buttonExport = new QPushButton(centralwidget);
        buttonExport->setObjectName("buttonExport");
        buttonExport->setGeometry(QRect(690, 520, 83, 30));
        buttonImport = new QPushButton(centralwidget);
        buttonImport->setObjectName("buttonImport");
        buttonImport->setGeometry(QRect(490, 520, 191, 29));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
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
        buttonExport->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        buttonImport->setText(QCoreApplication::translate("MainWindow", "Import Plan from XML", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
