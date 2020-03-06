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
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_2;
    QDoubleSpinBox *doubleSpinBox_3;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_5;
    QDoubleSpinBox *doubleSpinBox_6;
    QDoubleSpinBox *doubleSpinBox_4;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_12;
    QDoubleSpinBox *doubleSpinBox_10;
    QDoubleSpinBox *doubleSpinBox_11;

    void setupUi(QWidget *Transform)
    {
        if (Transform->objectName().isEmpty())
            Transform->setObjectName(QString::fromUtf8("Transform"));
        Transform->resize(236, 109);
        gridLayout = new QGridLayout(Transform);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(Transform);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 2);

        label_3 = new QLabel(Transform);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 3, 1, 2);

        label_4 = new QLabel(Transform);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 5, 1, 1);

        label = new QLabel(Transform);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(Transform);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));

        gridLayout->addWidget(doubleSpinBox, 1, 1, 1, 1);

        doubleSpinBox_2 = new QDoubleSpinBox(Transform);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));

        gridLayout->addWidget(doubleSpinBox_2, 1, 2, 1, 2);

        doubleSpinBox_3 = new QDoubleSpinBox(Transform);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));

        gridLayout->addWidget(doubleSpinBox_3, 1, 4, 1, 2);

        label_5 = new QLabel(Transform);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        doubleSpinBox_5 = new QDoubleSpinBox(Transform);
        doubleSpinBox_5->setObjectName(QString::fromUtf8("doubleSpinBox_5"));

        gridLayout->addWidget(doubleSpinBox_5, 2, 1, 1, 1);

        doubleSpinBox_6 = new QDoubleSpinBox(Transform);
        doubleSpinBox_6->setObjectName(QString::fromUtf8("doubleSpinBox_6"));

        gridLayout->addWidget(doubleSpinBox_6, 2, 2, 1, 2);

        doubleSpinBox_4 = new QDoubleSpinBox(Transform);
        doubleSpinBox_4->setObjectName(QString::fromUtf8("doubleSpinBox_4"));

        gridLayout->addWidget(doubleSpinBox_4, 2, 4, 1, 2);

        label_6 = new QLabel(Transform);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        doubleSpinBox_12 = new QDoubleSpinBox(Transform);
        doubleSpinBox_12->setObjectName(QString::fromUtf8("doubleSpinBox_12"));

        gridLayout->addWidget(doubleSpinBox_12, 3, 1, 1, 1);

        doubleSpinBox_10 = new QDoubleSpinBox(Transform);
        doubleSpinBox_10->setObjectName(QString::fromUtf8("doubleSpinBox_10"));

        gridLayout->addWidget(doubleSpinBox_10, 3, 2, 1, 2);

        doubleSpinBox_11 = new QDoubleSpinBox(Transform);
        doubleSpinBox_11->setObjectName(QString::fromUtf8("doubleSpinBox_11"));

        gridLayout->addWidget(doubleSpinBox_11, 3, 4, 1, 2);


        retranslateUi(Transform);

        QMetaObject::connectSlotsByName(Transform);
    } // setupUi

    void retranslateUi(QWidget *Transform)
    {
        Transform->setWindowTitle(QApplication::translate("Transform", "Form", nullptr));
        label_2->setText(QApplication::translate("Transform", "X", nullptr));
        label_3->setText(QApplication::translate("Transform", "Y", nullptr));
        label_4->setText(QApplication::translate("Transform", "Z", nullptr));
        label->setText(QApplication::translate("Transform", "Position", nullptr));
        label_5->setText(QApplication::translate("Transform", "Rotation", nullptr));
        label_6->setText(QApplication::translate("Transform", "Size", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Transform: public Ui_Transform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFORM_H
