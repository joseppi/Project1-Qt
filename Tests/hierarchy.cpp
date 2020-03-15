#include "hierarchy.h"
#include "ui_hierarchy.h"
#include "shapefactory.h"
#include "mainwindow.h"
#include "sceneview.h"
#include "qinputdialog.h"
#include "inspector.h"

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

    //qintptr shape_info = (qintptr)new_shape;
    //QVariant shape_info_variant;
    //shape_info_variant.setValue(5);
    //new_item->setData(Qt::UserRole, shape_info_variant);
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
