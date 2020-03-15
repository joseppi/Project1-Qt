/********************************************************************************
** Form generated from reading UI file 'hierarchy.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HIERARCHY_H
#define UI_HIERARCHY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hierarchy
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QPushButton *AddEntityBtn;
    QPushButton *RemoveEntityBtn;

    void setupUi(QWidget *Hierarchy)
    {
        if (Hierarchy->objectName().isEmpty())
            Hierarchy->setObjectName(QString::fromUtf8("Hierarchy"));
        Hierarchy->resize(400, 300);
        verticalLayout = new QVBoxLayout(Hierarchy);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(Hierarchy);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        AddEntityBtn = new QPushButton(Hierarchy);
        AddEntityBtn->setObjectName(QString::fromUtf8("AddEntityBtn"));

        verticalLayout->addWidget(AddEntityBtn);

        RemoveEntityBtn = new QPushButton(Hierarchy);
        RemoveEntityBtn->setObjectName(QString::fromUtf8("RemoveEntityBtn"));

        verticalLayout->addWidget(RemoveEntityBtn);


        retranslateUi(Hierarchy);

        QMetaObject::connectSlotsByName(Hierarchy);
    } // setupUi

    void retranslateUi(QWidget *Hierarchy)
    {
        Hierarchy->setWindowTitle(QApplication::translate("Hierarchy", "Form", nullptr));
        AddEntityBtn->setText(QApplication::translate("Hierarchy", "AddEntity", nullptr));
        RemoveEntityBtn->setText(QApplication::translate("Hierarchy", "RemoveEntity", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Hierarchy: public Ui_Hierarchy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HIERARCHY_H
