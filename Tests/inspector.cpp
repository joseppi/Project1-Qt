#include "inspector.h"
#include "ui_transform.h"
#include "ui_mesh.h"

Inspector::Inspector(QWidget *parent) :
    QWidget(parent),
    ui_transorm(new Ui::Transform),
    ui_mesh(new Ui::Mesh)
{
    QWidget *transform_widget = new QWidget;
    ui_transorm->setupUi((transform_widget));

    mesh_widget = new QWidget;
    ui_mesh->setupUi(mesh_widget);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(transform_widget);
    layout->addWidget(mesh_widget);
    layout->addItem(new QSpacerItem(1,1,QSizePolicy::Expanding,QSizePolicy::Expanding));
    setLayout(layout);

}

Inspector::~Inspector()
{

}


void Inspector::OnEntitySelected(int entityId) {
    if (entityId % 2 == 0){
        mesh_widget->show();
    }
    else {
        mesh_widget->hide();
    }
}
