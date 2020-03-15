#include "hierarchy.h"
#include "ui_hierarchy.h"
#include "mainwindow.h"
#include "sceneview.h"
#include "qinputdialog.h"
#include "inspector.h"

#include "shapefactory.h"
#include "shape.h"


Hierarchy::Hierarchy(QWidget *parent, MainWindow *main_window) :
    QWidget(parent),
    ui(new Ui::Hierarchy)
{
    this->main_window = main_window;
    ui->setupUi(this);
    connect(ui->AddEntityBtn,SIGNAL(clicked()),SLOT(OnAddEntity()));
    connect(ui->RemoveEntityBtn,SIGNAL(clicked()),SLOT(OnRemoveEntity()));
}

Hierarchy::~Hierarchy()
{
    delete ui;
}

void Hierarchy::OnAddEntity() {


    QStringList items;
    items << tr("Rectangle") << tr("Elipse");

    bool ok;
    QString item = QInputDialog::getItem(this, tr("QInputDialog::getItem()"),
                                         tr("Shape type:"), items, 0, false, &ok);

     auto *new_item = new QListWidgetItem("NewShape");
    Shape* new_shape = nullptr;
    if (item == "Rectangle") {
        new_shape = main_window->AddShape(ShapeType::RECTANGLE);
        new_item->setText("Rectangle");
    }
    else if (item == "Elipse") {
        new_shape = main_window->AddShape(ShapeType::ELIPSE);
        new_item->setText("Elipse");
    }

    new_item->setData(Qt::UserRole, new_shape->id);

    ui->listWidget->addItem(new_item);

    main_window->scene_view->repaint();
}

void Hierarchy::OnAddEntityXML(Shape *shape)
{
    Shape *new_shape = shape;
    QString item;
    if (shape->type == ShapeType::RECTANGLE)
    {
        item.append("Rectangle");        
    }
    else if (shape->type == ShapeType::ELIPSE)
    {
        item.append("Elipse");
    }
    main_window->shape_factory->CreateShape(new_shape);

    auto *new_item = new QListWidgetItem("NewShape");

    if (item == "Rectangle") {
        new_item->setText("Rectangle");
    }
    else if (item == "Elipse") {
        new_item->setText("Elipse");
    }

    new_item->setData(Qt::UserRole, new_shape->id);

    ui->listWidget->addItem(new_item);

    main_window->scene_view->repaint();
}

void Hierarchy::OnRemoveEntity() {
    Shape* shape_to_remove = main_window->inspector->selected_shape;
    ui->listWidget->takeItem(shape_to_remove->id);
    main_window->shape_factory->shapes.removeOne(shape_to_remove);
    main_window->scene_view->repaint();
}

void Hierarchy::ClearEntities()
{
    ui->listWidget->clear();
    main_window->shape_factory->shapes.clear();
    main_window->scene_view->repaint();
}

QList<QListWidgetItem*> Hierarchy::GetListViewEntities()
{
    QList<QListWidgetItem*> list;
    int total_items = ui->listWidget->count();

    for(int i = 0;i<total_items;i++)
    {
        QListWidgetItem *it = ui->listWidget->item(i);
        list.push_back(it);
    }
    return list;
}
