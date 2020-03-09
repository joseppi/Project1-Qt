#include "hierarchy.h"
#include "ui_hierarchy.h"
#include "shapefactory.h"
#include "mainwindow.h"

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

    ui->listWidget->addItem("Entity");
    main_window->AddShape();

}

void Hierarchy::OnRemoveEntity() {
    int row = ui->listWidget->currentRow();
    ui->listWidget->takeItem(row);
}

void Hierarchy::OnEntitySelected() {

}
