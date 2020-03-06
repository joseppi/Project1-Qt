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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mesh
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QCheckBox *checkBox;

    void setupUi(QWidget *Mesh)
    {
        if (Mesh->objectName().isEmpty())
            Mesh->setObjectName(QString::fromUtf8("Mesh"));
        Mesh->resize(125, 54);
        verticalLayout = new QVBoxLayout(Mesh);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(Mesh);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        checkBox = new QCheckBox(Mesh);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout->addWidget(checkBox);


        retranslateUi(Mesh);

        QMetaObject::connectSlotsByName(Mesh);
    } // setupUi

    void retranslateUi(QWidget *Mesh)
    {
        Mesh->setWindowTitle(QApplication::translate("Mesh", "Form", nullptr));
        label->setText(QApplication::translate("Mesh", "Mesh Renderer", nullptr));
        checkBox->setText(QApplication::translate("Mesh", "Render Mesh", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mesh: public Ui_Mesh {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESH_H
