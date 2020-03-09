#include <QtWidgets>
#include <QCommandLineParser>


#if defined(QT_PRINTSUPPORT_LIB)
#include <QtPrintSupport/qtprintsupportglobal.h>
#if QT_CONFIG(printdialog)
#include <QtPrintSupport>
#endif
#endif

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hierarchy.h"
#include "inspector.h"
#include "sceneview.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui_main(new Ui::MainWindow)
{
    ui_main->setupUi(this);

    // Toolbar
    connect(ui_main->actionQuit,SIGNAL(triggered()),SLOT(ActionQuitProject()));
    connect(ui_main->actionLoad,SIGNAL(triggered()),SLOT(ActionLoadProject()));
    connect(ui_main->actionSave,SIGNAL(triggered()),SLOT(ActionSaveProject()));
    connect(ui_main->actionNew,SIGNAL(triggered()),SLOT(ActionNewProject()));



    hierarchy = new Hierarchy();
    inspector = new Inspector();
    scene_view = new SceneView();

    ui_main->dockBase->setWidget(hierarchy);
    ui_main->dockInspector->setWidget(inspector);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(scene_view);

    ui_main->centralWidget->setLayout(layout);

}

void MainWindow::ActionQuitProject() {
    QMessageBox::StandardButton button = QMessageBox::question(
                this,
                "Exit",                             //Message Box Title
                "Are you sure you want to Quit?"    //Message Box Text
    );
    if (button == QMessageBox::Yes)
    {
        qApp->exit();
    }

}

void MainWindow::ActionLoadProject() {
    QString path = QFileDialog::getOpenFileName(this, "Open Project");
    if (!path.isEmpty())
    {
       QMessageBox::information(this, "Info Load", path);
    }

}

void MainWindow::ActionSaveProject() {
    QString path = QFileDialog::getOpenFileName(this, "Open Project");
    QList<QListWidgetItem*> list = hierarchy->GetListViewEntities();
    QCommandLineParser parser;
    parser.setApplicationDescription("Test helper");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("source", QCoreApplication::translate("main", "Source file to copy."));
    parser.addPositionalArgument("destination", QCoreApplication::translate("main", "Destination directory."));

    if (!path.isEmpty())
    {

       //QMessageBox::information(this, "Info Save", path);
       if (!list.isEmpty())
       {
        QListWidgetItem* item = list.first();
        QMessageBox::information(this, "Item info: ", item->text());
        QStringList str;
        str.push_back(item->text());

        // An option with a value
        QCommandLineOption targetDirectoryOption(QStringList() << "t" << "target-directory",
                QCoreApplication::translate("main", "Copy all source files into <directory>."),
                QCoreApplication::translate("main", "directory"));
        parser.addOption(targetDirectoryOption);

        parser.process(str);

       }

    }


}

void MainWindow::ActionNewProject(){

    QString path = QFileDialog::getOpenFileName(this, "New Project");
    if (!path.isEmpty())
    {
       QMessageBox::information(this, "Info Load", path);
    }
}


MainWindow::~MainWindow()
{
    delete ui_main;
}
