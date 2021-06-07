/********************************************************************************
** Form generated from reading UI file 'MidExam.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MIDEXAM_H
#define UI_MIDEXAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MidExamClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MidExamClass)
    {
        if (MidExamClass->objectName().isEmpty())
            MidExamClass->setObjectName(QString::fromUtf8("MidExamClass"));
        MidExamClass->resize(600, 400);
        menuBar = new QMenuBar(MidExamClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        MidExamClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MidExamClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MidExamClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(MidExamClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MidExamClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MidExamClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MidExamClass->setStatusBar(statusBar);

        retranslateUi(MidExamClass);

        QMetaObject::connectSlotsByName(MidExamClass);
    } // setupUi

    void retranslateUi(QMainWindow *MidExamClass)
    {
        MidExamClass->setWindowTitle(QCoreApplication::translate("MidExamClass", "MidExam", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MidExamClass: public Ui_MidExamClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MIDEXAM_H
