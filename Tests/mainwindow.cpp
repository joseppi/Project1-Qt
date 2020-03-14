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
    connect(ui_main->actionLoadLayout,SIGNAL(triggered()),SLOT(ActionLoadLayout()));
    connect(ui_main->actionSaveLayout,SIGNAL(triggered()),SLOT(ActionSaveLayout()));


    hierarchy = new Hierarchy(nullptr,this);
    inspector = new Inspector(nullptr,this);
    scene_view = new SceneView(nullptr,this);


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

void MainWindow::ActionSaveProject() {
    //Get File Path
    //QString path = QFileDialog::getSaveFileName(this, "Save Project");
    QString path = QDir::currentPath() + "/Save.txt";
    QList<Shape*> list = shape_factory->shapes;

    //Create stream
    QString output;
    QDomDocument document;

    //Make root element
    QDomElement root = document.createElement("Entities");


    //Add some elements
    for(int i = 0; i < list.length(); i++)
    {
        QDomElement node_shapes = document.createElement("Shape");
        node_shapes.setAttribute("id", QString::number(i));

        ShapeType type = list[i]->type;
        node_shapes.setAttribute("Type", QString::number(type));

        QRect ret = list[i]->rect;
        node_shapes.setAttribute("x",ret.x());
        node_shapes.setAttribute("y",ret.y());
        node_shapes.setAttribute("h",ret.height());
        node_shapes.setAttribute("w",ret.width());




        root.appendChild(node_shapes);
    }

    //Add it to the document
    document.appendChild(root);

    //Write to file

    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Failed to save file for writting";
    }
    else
    {
        QTextStream stream(&file);
        stream << document.toString();
        file.close();
        qDebug() << "Finished";
    }

    if (!path.isEmpty())
    {

       //QMessageBox::information(this, "Info Save", path);
       if (!list.isEmpty())
       {
        qDebug () << path;
       }

    }
}

void MainWindow::ActionLoadProject() {
    //QString path = QFileDialog::getOpenFileName(this, "Open Project");
    QString path = QDir::currentPath() + "/Save.txt";
    if (!path.isEmpty())
    {
       //QMessageBox::information(this, "Info Load", path);
    }

    QDomDocument document;

    //Load the file
    QFile file(path);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file";
    }
    else
    {
        if (!document.setContent(&file))
        {
            qDebug() << "Failed to load document";
        }
        file.close();
    }

    //get the root element
    QDomElement root = document.firstChildElement();

    //List of the Elements(root,tagname,attribute)
    QList<Shape*> shapeList = ListElements(root,"Shape");

}

QList<Shape*> MainWindow::ListElements(QDomElement root, QString tagName)
{
    QList<Shape*> ret;
    QDomNodeList items = root.elementsByTagName(tagName);
    qDebug() << "Total items = "<< items.count();
    for (int i = 0; i < items.count(); i++)
    {
        QDomNode itemnode = items.at(i);
        //convert to element
        if (itemnode.isElement())
        {
            Shape new_shape;
            QDomElement itemele = itemnode.toElement();

            new_shape.id = itemele.attribute("id").toInt();
            new_shape.type =(ShapeType)itemele.attribute("Type").toInt();
            QRect rect;
            rect.setRect(
                        itemele.attribute("x").toInt(),
                        itemele.attribute("y").toInt(),
                        itemele.attribute("h").toInt(),
                        itemele.attribute("w").toInt());
            new_shape.rect = rect;

            ret.push_back(&new_shape);
        }
    }
    return ret;
}

void MainWindow::ActionNewProject(){

    QString path = QFileDialog::getOpenFileName(this, "New Project");
    if (!path.isEmpty())
    {
       QMessageBox::information(this, "Info Load", path);
    }
}

void MainWindow::ActionLoadLayout()
{
    QSettings settings("Pipo", "Cute Engine");
    this->restoreState(settings.value("dockpos").toByteArray());

    qDebug() << this->geometry().width();

    qDebug("loadLayout");
}

void MainWindow::ActionSaveLayout()
{
    QSettings settings("Pipo", "Cute Engine");
    settings.setValue("dockpos",this->saveState());

    qDebug("saveLayout");
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


