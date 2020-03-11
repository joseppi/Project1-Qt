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



    hierarchy = new Hierarchy(nullptr,this);
    inspector = new Inspector();
    scene_view = new SceneView(nullptr,this);


    ui_main->dockBase->setWidget(hierarchy);
    ui_main->dockInspector->setWidget(inspector);


    //Shape management
    shape_factory = new ShapeFactory();


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
    ListElements(root,"Book","Name");

}


void MainWindow::ActionSaveProject() {
    //Get File Path
    QString path = QFileDialog::getSaveFileName(this, "Save Project");
    QList<QListWidgetItem*> list = hierarchy->GetListViewEntities();

    //Create stream
    QString output;
    QDomDocument document;

    //Make root element
    QDomElement root = document.createElement("Books");

    //Add some elements
    for(int i = 0; i < 10; i++)
    {
        QDomElement node = document.createElement("Book");
        node.setAttribute("Name", "My Book" + QString::number(i));
        node.setAttribute("ID", QString::number(i));
        root.appendChild(node);
    }

    //Add it to the document
    document.appendChild(root);

    //Write to file
    QString final_path = path;
    final_path.append(".txt");
    QFile file(final_path);
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
        QListWidgetItem* item = list.first();
        QMessageBox::information(this, "Item info: ", item->text());
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

void MainWindow::AddShape()
{
    shape_factory->CreateShape(RECTANGLE);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_S)
    {
        qDebug("s");
    }
}

void MainWindow::ListElements(QDomElement root, QString tagName, QString attribute)
{
    QDomNodeList items = root.elementsByTagName(tagName);
    qDebug() << "Total items = "<< items.count();
    for (int i = 0; i<items.count(); i++)
    {
        QDomNode itemnode = items.at(i);

        //convert to element
        if (itemnode.isElement())
        {
            QDomElement itemele = itemnode.toElement();
            qDebug() << itemele.attribute(attribute);

        }
    }
}
