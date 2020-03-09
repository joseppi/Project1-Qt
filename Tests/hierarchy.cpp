#include "hierarchy.h"
#include "ui_hierarchy.h"

Hierarchy::Hierarchy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hierarchy)
{
    ui->setupUi(this);
    connect(ui->AddEntityBtn,SIGNAL(clicked()),SLOT(OnAddEntity()));
}

Hierarchy::~Hierarchy()
{
    delete ui;
}

void Hierarchy::OnAddEntity() {

    ui->listWidget->addItem("Entity1");
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
