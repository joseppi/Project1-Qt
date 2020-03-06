/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad_File;
    QAction *actionSafe_File;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuMainView;
    QMenu *menuView;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QToolBar *toolBar;
    QDockWidget *dockHierarchy;
    QWidget *dockWidgetContents;
    QDockWidget *dockProject;
    QWidget *dockWidgetContents_2;
    QDockWidget *dockInspector;
    QWidget *dockWidgetContents_3;
    QDockWidget *dockRendering;
    QWidget *dockWidgetContents_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(705, 580);
        actionLoad_File = new QAction(MainWindow);
        actionLoad_File->setObjectName(QString::fromUtf8("actionLoad_File"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/Folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoad_File->setIcon(icon);
        actionSafe_File = new QAction(MainWindow);
        actionSafe_File->setObjectName(QString::fromUtf8("actionSafe_File"));
        actionSafe_File->setIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 705, 21));
        menuMainView = new QMenu(menuBar);
        menuMainView->setObjectName(QString::fromUtf8("menuMainView"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setIconSize(QSize(18, 18));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        dockHierarchy = new QDockWidget(MainWindow);
        dockHierarchy->setObjectName(QString::fromUtf8("dockHierarchy"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        dockHierarchy->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockHierarchy);
        dockProject = new QDockWidget(MainWindow);
        dockProject->setObjectName(QString::fromUtf8("dockProject"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        dockProject->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockProject);
        dockInspector = new QDockWidget(MainWindow);
        dockInspector->setObjectName(QString::fromUtf8("dockInspector"));
        dockInspector->setMinimumSize(QSize(158, 38));
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QString::fromUtf8("dockWidgetContents_3"));
        dockInspector->setWidget(dockWidgetContents_3);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockInspector);
        dockRendering = new QDockWidget(MainWindow);
        dockRendering->setObjectName(QString::fromUtf8("dockRendering"));
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QString::fromUtf8("dockWidgetContents_4"));
        dockRendering->setWidget(dockWidgetContents_4);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockRendering);

        menuBar->addAction(menuMainView->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuMainView->addAction(actionLoad_File);
        menuMainView->addAction(actionSafe_File);
        toolBar->addAction(actionLoad_File);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionLoad_File->setText(QApplication::translate("MainWindow", "Load File", nullptr));
        actionSafe_File->setText(QApplication::translate("MainWindow", "Safe File", nullptr));
        menuMainView->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuView->setTitle(QApplication::translate("MainWindow", "View", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
        dockHierarchy->setWindowTitle(QApplication::translate("MainWindow", "Hierarchy", nullptr));
        dockProject->setWindowTitle(QApplication::translate("MainWindow", "Project", nullptr));
        dockInspector->setWindowTitle(QApplication::translate("MainWindow", "Inspector", nullptr));
        dockRendering->setWindowTitle(QApplication::translate("MainWindow", "Rendering", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
