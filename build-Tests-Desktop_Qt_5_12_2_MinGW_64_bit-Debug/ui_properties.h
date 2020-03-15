/********************************************************************************
** Form generated from reading UI file 'properties.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROPERTIES_H
#define UI_PROPERTIES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Properties
{
public:
    QFormLayout *formLayout;
    QLabel *label_3;
    QPushButton *StrokeColorSample;
    QLabel *label;
    QLabel *label_2;
    QPushButton *FillColorSample;
    QLabel *label_4;
    QSpinBox *StrokeWidth;
    QLabel *label_5;
    QComboBox *StyleSelect;

    void setupUi(QWidget *Properties)
    {
        if (Properties->objectName().isEmpty())
            Properties->setObjectName(QString::fromUtf8("Properties"));
        Properties->resize(400, 170);
        Properties->setMinimumSize(QSize(100, 100));
        formLayout = new QFormLayout(Properties);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_3 = new QLabel(Properties);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_3);

        StrokeColorSample = new QPushButton(Properties);
        StrokeColorSample->setObjectName(QString::fromUtf8("StrokeColorSample"));

        formLayout->setWidget(8, QFormLayout::FieldRole, StrokeColorSample);

        label = new QLabel(Properties);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, label);

        label_2 = new QLabel(Properties);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_2);

        FillColorSample = new QPushButton(Properties);
        FillColorSample->setObjectName(QString::fromUtf8("FillColorSample"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(170, 85, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush);
        QBrush brush2(QColor(0, 255, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        QBrush brush3(QColor(127, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush3);
        QBrush brush4(QColor(170, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush5(QColor(255, 255, 255, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush5);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush5);
        QBrush brush6(QColor(255, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(255, 127, 127, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush9(QColor(0, 0, 0, 128));
        brush9.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush9);
#endif
        FillColorSample->setPalette(palette);

        formLayout->setWidget(7, QFormLayout::FieldRole, FillColorSample);

        label_4 = new QLabel(Properties);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_4);

        StrokeWidth = new QSpinBox(Properties);
        StrokeWidth->setObjectName(QString::fromUtf8("StrokeWidth"));

        formLayout->setWidget(6, QFormLayout::FieldRole, StrokeWidth);

        label_5 = new QLabel(Properties);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

        StyleSelect = new QComboBox(Properties);
        StyleSelect->setObjectName(QString::fromUtf8("StyleSelect"));

        formLayout->setWidget(5, QFormLayout::FieldRole, StyleSelect);


        retranslateUi(Properties);

        QMetaObject::connectSlotsByName(Properties);
    } // setupUi

    void retranslateUi(QWidget *Properties)
    {
        Properties->setWindowTitle(QApplication::translate("Properties", "Form", nullptr));
        label_3->setText(QApplication::translate("Properties", "StroKe Color:", nullptr));
        StrokeColorSample->setText(QString());
        label->setText(QApplication::translate("Properties", "Properties", nullptr));
        label_2->setText(QApplication::translate("Properties", "Fill Color:", nullptr));
        FillColorSample->setText(QString());
        label_4->setText(QApplication::translate("Properties", "Stroke Thickness", nullptr));
        label_5->setText(QApplication::translate("Properties", "Stroke Style:", nullptr));
        StyleSelect->setCurrentText(QString());
    } // retranslateUi

};

namespace Ui {
    class Properties: public Ui_Properties {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROPERTIES_H
