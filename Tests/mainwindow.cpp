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


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui_main(new Ui::MainWindow)
{


    ui_main->setupUi(this);


    connect(ui_main->actionLoad,SIGNAL(triggered()),SLOT(ActionOneSlot()));


    hierarchy = new Hierarchy();
    inspector = new Inspector();
    scene_view = new SceneView();

    ui_main->dockBase->setWidget(hierarchy);
    ui_main->dockInspector->setWidget(inspector);


    //connect((hierarchy),SIGNAL())

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(scene_view);

    ui_main->centralWidget->setLayout(layout);

}

void MainWindow::ActionOneSlot() {
    QMessageBox::StandardButton button = QMessageBox::question(
                this,
                "Exit",
                "Suck my ****"
    );
    if (button == QMessageBox::Yes)
    {
        qApp->exit();
    }

}


MainWindow::~MainWindow()
{
    delete ui_main;
}
