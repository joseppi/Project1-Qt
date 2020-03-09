/********************************************************************************
** Form generated from reading UI file 'mesh.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESH_H
#define UI_MESH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mesh
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;

    void setupUi(QWidget *Mesh)
    {
        if (Mesh->objectName().isEmpty())
            Mesh->setObjectName(QString::fromUtf8("Mesh"));
        Mesh->resize(347, 40);
        horizontalLayout = new QHBoxLayout(Mesh);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Mesh);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(Mesh);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);


        retranslateUi(Mesh);

        QMetaObject::connectSlotsByName(Mesh);
    } // setupUi

    void retranslateUi(QWidget *Mesh)
    {
        Mesh->setWindowTitle(QApplication::translate("Mesh", "Form", nullptr));
        label->setText(QApplication::translate("Mesh", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mesh: public Ui_Mesh {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESH_H
