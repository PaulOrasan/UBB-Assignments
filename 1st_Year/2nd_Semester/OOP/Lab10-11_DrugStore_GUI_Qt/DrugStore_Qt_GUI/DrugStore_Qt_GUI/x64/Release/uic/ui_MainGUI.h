/********************************************************************************
** Form generated from reading UI file 'MainGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINGUI_H
#define UI_MAINGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainGUIClass
{
public:

    void setupUi(QWidget *MainGUIClass)
    {
        if (MainGUIClass->objectName().isEmpty())
            MainGUIClass->setObjectName(QString::fromUtf8("MainGUIClass"));
        MainGUIClass->resize(600, 400);

        retranslateUi(MainGUIClass);

        QMetaObject::connectSlotsByName(MainGUIClass);
    } // setupUi

    void retranslateUi(QWidget *MainGUIClass)
    {
        MainGUIClass->setWindowTitle(QCoreApplication::translate("MainGUIClass", "MainGUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainGUIClass: public Ui_MainGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINGUI_H
