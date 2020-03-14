#include "hierarchy.h"
#include "ui_hierarchy.h"
#include "shapefactory.h"
#include "mainwindow.h"
#include "sceneview.h"
Hierarchy::Hierarchy(QWidget *parent, MainWindow *main_window) :
    QWidget(parent),
    ui(new Ui::Hierarchy)
{
    this->main_window = main_window;
    ui->setupUi(this);
    connect(ui->AddEntityBtn,SIGNAL(clicked()),SLOT(OnAddEntity()));
}

Hierarchy::~Hierarchy()
{
    delete ui;
}

void Hierarchy::OnAddEntity() {
    Shape* new_shape = main_window->AddShape();


    auto *new_item = new QListWidgetItem("NewShape");

    //qintptr shape_info = (qintptr)new_shape;
    //QVariant shape_info_variant;
    //shape_info_variant.setValue(5);
    //new_item->setData(Qt::UserRole, shape_info_variant);
    new_item->setData(Qt::UserRole, new_shape->id);


    ui->listWidget->addItem(new_item);

    main_window->scene_view->repaint();
}

void Hierarchy::OnRemoveEntity() {
    int row = ui->listWidget->currentRow();
    ui->listWidget->takeItem(row);
}

void Hierarchy::OnEntitySelected() {

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
