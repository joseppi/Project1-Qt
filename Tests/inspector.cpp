#include "inspector.h"
#include "ui_transform.h"
#include "mainwindow.h"
#include "ui_hierarchy.h"
#include "hierarchy.h"
#include "shapefactory.h"
#include "shape.h"

Inspector::Inspector(QWidget *parent, MainWindow *main_window) :
    QWidget(parent),
    ui_transorm(new Ui::Transform)
{
    QWidget *transform_widget = new QWidget;
    ui_transorm->setupUi((transform_widget));
    this->main_window =main_window;

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(transform_widget);
    layout->addItem(new QSpacerItem(1,1,QSizePolicy::Expanding,QSizePolicy::Expanding));
    setLayout(layout);

    connect(main_window->hierarchy->ui->listWidget,SIGNAL(itemSelectionChanged()),SLOT(OnCurrentItemChanged()));



}

Inspector::~Inspector()
{

}

void Inspector::OnCurrentItemChanged()
{

    QListWidgetItem* item = main_window->hierarchy->ui->listWidget->currentItem();

    //QVariant shape_info_variant = item->data(Qt::UserRole);
    QVariant qid = item->data(Qt::UserRole);
    int id = qid.toInt();
    Shape* newest_shape = main_window->shape_factory->shapes.at(id);
    //qintptr shape_pointer_as_int = shape_info_variant.toInt();
    //Shape* newest_shape = (Shape*)shape_pointer_as_int;
    ui_transorm->ScalX->setValue(newest_shape->rect.width());
}

