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
    QLabel *label_6;
    QDoubleSpinBox *PosZ;
    QDoubleSpinBox *ScalX;
    QLabel *label_3;
    QDoubleSpinBox *ScalZ;
    QLabel *label_5;
    QDoubleSpinBox *PosX;
    QDoubleSpinBox *ScalY;
    QLabel *label;
    QLabel *label_4;
    QDoubleSpinBox *PosY;
    QLabel *label_2;

    void setupUi(QWidget *Transform)
    {
        if (Transform->objectName().isEmpty())
            Transform->setObjectName(QString::fromUtf8("Transform"));
        Transform->resize(657, 118);
        gridLayout = new QGridLayout(Transform);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_6 = new QLabel(Transform);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 3, 1, 1);

        PosZ = new QDoubleSpinBox(Transform);
        PosZ->setObjectName(QString::fromUtf8("PosZ"));

        gridLayout->addWidget(PosZ, 2, 3, 1, 1);

        ScalX = new QDoubleSpinBox(Transform);
        ScalX->setObjectName(QString::fromUtf8("ScalX"));
        ScalX->setMaximum(1000.000000000000000);

        gridLayout->addWidget(ScalX, 3, 1, 1, 1);

        label_3 = new QLabel(Transform);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        ScalZ = new QDoubleSpinBox(Transform);
        ScalZ->setObjectName(QString::fromUtf8("ScalZ"));
        ScalZ->setMaximum(1000.000000000000000);

        gridLayout->addWidget(ScalZ, 3, 3, 1, 1);

        label_5 = new QLabel(Transform);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 1, 2, 1, 1);

        PosX = new QDoubleSpinBox(Transform);
        PosX->setObjectName(QString::fromUtf8("PosX"));
        PosX->setMaximum(1000.000000000000000);

        gridLayout->addWidget(PosX, 2, 1, 1, 1);

        ScalY = new QDoubleSpinBox(Transform);
        ScalY->setObjectName(QString::fromUtf8("ScalY"));
        ScalY->setMaximum(1000.000000000000000);

        gridLayout->addWidget(ScalY, 3, 2, 1, 1);

        label = new QLabel(Transform);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 3, 0, 1, 1);

        label_4 = new QLabel(Transform);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 1, 1, 1);

        PosY = new QDoubleSpinBox(Transform);
        PosY->setObjectName(QString::fromUtf8("PosY"));
        PosY->setMaximum(1000.000000000000000);

        gridLayout->addWidget(PosY, 2, 2, 1, 1);

        label_2 = new QLabel(Transform);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        font.setStrikeOut(false);
        font.setKerning(true);
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 0, 1, 1, 3);


        retranslateUi(Transform);

        QMetaObject::connectSlotsByName(Transform);
    } // setupUi

    void retranslateUi(QWidget *Transform)
    {
        Transform->setWindowTitle(QApplication::translate("Transform", "Form", nullptr));
        label_6->setText(QApplication::translate("Transform", "Z", nullptr));
        label_3->setText(QApplication::translate("Transform", "Position", nullptr));
        label_5->setText(QApplication::translate("Transform", "Y", nullptr));
        label->setText(QApplication::translate("Transform", "Size", nullptr));
        label_4->setText(QApplication::translate("Transform", "X", nullptr));
        label_2->setText(QApplication::translate("Transform", "Transform", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Transform: public Ui_Transform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFORM_H
