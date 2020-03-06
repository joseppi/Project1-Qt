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
    QPushButton *buttonAddEntity;
    QPushButton *buttonRemoveEntity;

    void setupUi(QWidget *Hierarchy)
    {
        if (Hierarchy->objectName().isEmpty())
            Hierarchy->setObjectName(QString::fromUtf8("Hierarchy"));
        Hierarchy->resize(216, 424);
        verticalLayout = new QVBoxLayout(Hierarchy);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(Hierarchy);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        buttonAddEntity = new QPushButton(Hierarchy);
        buttonAddEntity->setObjectName(QString::fromUtf8("buttonAddEntity"));

        verticalLayout->addWidget(buttonAddEntity);

        buttonRemoveEntity = new QPushButton(Hierarchy);
        buttonRemoveEntity->setObjectName(QString::fromUtf8("buttonRemoveEntity"));

        verticalLayout->addWidget(buttonRemoveEntity);


        retranslateUi(Hierarchy);

        QMetaObject::connectSlotsByName(Hierarchy);
    } // setupUi

    void retranslateUi(QWidget *Hierarchy)
    {
        Hierarchy->setWindowTitle(QApplication::translate("Hierarchy", "Form", nullptr));
        buttonAddEntity->setText(QApplication::translate("Hierarchy", "Add Entity", nullptr));
        buttonRemoveEntity->setText(QApplication::translate("Hierarchy", "Remove Entity", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Hierarchy: public Ui_Hierarchy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HIERARCHY_H
