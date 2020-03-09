/********************************************************************************
** Form generated from reading UI file 'transform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFORM_H
#define UI_TRANSFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Transform
{
public:
    QGridLayout *gridLayout;
    QDoubleSpinBox *PosY;
    QLabel *label_3;
    QDoubleSpinBox *PosZ;
    QDoubleSpinBox *RotX;
    QLabel *label_4;
    QDoubleSpinBox *ScalY;
    QLabel *label_6;
    QDoubleSpinBox *RotY;
    QDoubleSpinBox *ScalZ;
    QLabel *label_2;
    QDoubleSpinBox *RotZ;
    QLabel *label_5;
    QDoubleSpinBox *ScalX;
    QDoubleSpinBox *PosX;
    QLabel *label;

    void setupUi(QWidget *Transform)
    {
        if (Transform->objectName().isEmpty())
            Transform->setObjectName(QString::fromUtf8("Transform"));
        Transform->resize(657, 118);
        gridLayout = new QGridLayout(Transform);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        PosY = new QDoubleSpinBox(Transform);
        PosY->setObjectName(QString::fromUtf8("PosY"));

        gridLayout->addWidget(PosY, 1, 2, 1, 1);

        label_3 = new QLabel(Transform);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        PosZ = new QDoubleSpinBox(Transform);
        PosZ->setObjectName(QString::fromUtf8("PosZ"));

        gridLayout->addWidget(PosZ, 1, 3, 1, 1);

        RotX = new QDoubleSpinBox(Transform);
        RotX->setObjectName(QString::fromUtf8("RotX"));

        gridLayout->addWidget(RotX, 2, 1, 1, 1);

        label_4 = new QLabel(Transform);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 1, 1, 1);

        ScalY = new QDoubleSpinBox(Transform);
        ScalY->setObjectName(QString::fromUtf8("ScalY"));

        gridLayout->addWidget(ScalY, 3, 2, 1, 1);

        label_6 = new QLabel(Transform);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 0, 3, 1, 1);

        RotY = new QDoubleSpinBox(Transform);
        RotY->setObjectName(QString::fromUtf8("RotY"));

        gridLayout->addWidget(RotY, 2, 2, 1, 1);

        ScalZ = new QDoubleSpinBox(Transform);
        ScalZ->setObjectName(QString::fromUtf8("ScalZ"));

        gridLayout->addWidget(ScalZ, 3, 3, 1, 1);

        label_2 = new QLabel(Transform);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        RotZ = new QDoubleSpinBox(Transform);
        RotZ->setObjectName(QString::fromUtf8("RotZ"));

        gridLayout->addWidget(RotZ, 2, 3, 1, 1);

        label_5 = new QLabel(Transform);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 2, 1, 1);

        ScalX = new QDoubleSpinBox(Transform);
        ScalX->setObjectName(QString::fromUtf8("ScalX"));

        gridLayout->addWidget(ScalX, 3, 1, 1, 1);

        PosX = new QDoubleSpinBox(Transform);
        PosX->setObjectName(QString::fromUtf8("PosX"));

        gridLayout->addWidget(PosX, 1, 1, 1, 1);

        label = new QLabel(Transform);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 3, 0, 1, 1);


        retranslateUi(Transform);

        QMetaObject::connectSlotsByName(Transform);
    } // setupUi

    void retranslateUi(QWidget *Transform)
    {
        Transform->setWindowTitle(QApplication::translate("Transform", "Form", nullptr));
        label_3->setText(QApplication::translate("Transform", "Position", nullptr));
        label_4->setText(QApplication::translate("Transform", "X", nullptr));
        label_6->setText(QApplication::translate("Transform", "Z", nullptr));
        label_2->setText(QApplication::translate("Transform", "Rotation", nullptr));
        label_5->setText(QApplication::translate("Transform", "Y", nullptr));
        label->setText(QApplication::translate("Transform", "Scale", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Transform: public Ui_Transform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFORM_H
