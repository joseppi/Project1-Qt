#include "mainwindow.h"

#include "ui_mainwindow.h"
#include "ui_transform.h"


#include "hierarchy.h"
#include "inspector.h"
#include "sceneview.h"

#include "QMessageBox"
#include "QFileDialog"

#include <QVBoxLayout>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    uiMainWindow(new Ui::MainWindow)
  //uiTransform(new Ui::Transform)
{
    uiMainWindow->setupUi(this);

    //QWidget *widget = new QWidget();
    //uiTransform->setupUi(widget);
    //uiMainWindow->dockInspector->setWidget(widget);

    hierarchy = new Hierarchy();
    uiMainWindow->dockHierarchy->setWidget(hierarchy);

    inspector = new Inspector();
    uiMainWindow->dockInspector->setWidget(inspector);

    // create an empty widget
    // execute setupUi
    // set the widget into the dock

    //connect(ui->b1, SIGNAL(clicked()),this, SLOT(onText1Pressed()));
    //connect(ui->b2, SIGNAL(clicked()),this, SLOT(onText2Pressed()));
    connect(uiMainWindow->actionLoad_File, SIGNAL(triggered()),this,SLOT(LoadFilePressed()));
    connect(uiMainWindow->actionSafe_File, SIGNAL(triggered()),this,SLOT(SaveFilePressed()));

    connect(hierarchy,SIGNAL(entitySelected(int)), inspector,SLOT(OnEntitySelected(int)));

    //Transform* Transform = new Transform();
    //ui->dockTransform->setWidget(Transform);

    sceneView = new SceneView();
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(sceneView);
    uiMainWindow->centralWidget->setLayout(layout);

}

MainWindow::~MainWindow()
{
    delete uiMainWindow;
    //delete uiTransform;
}

void MainWindow::LoadFilePressed()
{
    QString path = QFileDialog::getOpenFileName(this, "Open Project");
    if (!path.isEmpty())
    {
       QMessageBox::information(this, "Info", path);
    }
}

void MainWindow::SaveFilePressed()
{
    QMessageBox::StandardButton button = QMessageBox::question(
                this,
                "Exit application",
                "Do you want to exit this application without saving project?");
    if (button == QMessageBox::Yes)
    {
        qApp->exit();
    }
}

void MainWindow::onText1Pressed()
{
    //ui->text->setText("hola");
}
void MainWindow::onText2Pressed()
{
    printf("hola2");
}
