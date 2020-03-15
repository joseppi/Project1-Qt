#include <QtWidgets>


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
#include "shapefactory.h"
#include "rectangle.h"
#include "saveload.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui_main(new Ui::MainWindow)
{
    ui_main->setupUi(this);

    hierarchy = new Hierarchy(nullptr,this);
    inspector = new Inspector(nullptr,this);
    scene_view = new SceneView(nullptr,this);
    save_load = new SaveLoad(nullptr,this);

    // Toolbar
    connect(ui_main->actionQuit,SIGNAL(triggered()),SLOT(ActionQuitProject()));
    connect(ui_main->actionNew,SIGNAL(triggered()),SLOT(ActionNewProject()));
    connect(ui_main->actionLoad,SIGNAL(triggered()),save_load, SLOT(ActionLoadProject()));
    connect(ui_main->actionSave,SIGNAL(triggered()),save_load, SLOT(ActionSaveProject()));
    connect(ui_main->actionLoadLayout,SIGNAL(triggered()),save_load, SLOT(ActionLoadLayout()));
    connect(ui_main->actionSaveLayout,SIGNAL(triggered()),save_load, SLOT(ActionSaveLayout()));

    ui_main->dockBase->setWidget(hierarchy);
    ui_main->dockInspector->setWidget(inspector);


    //Shape management
    shape_factory = new ShapeFactory();


    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(scene_view);

    ui_main->centralWidget->setLayout(layout);
    qDebug() << this->geometry().width();

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

Shape* MainWindow::AddShape()
{
    return shape_factory->CreateShape(RECTANGLE);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_S)
    {
        qDebug("s");
    }
}


