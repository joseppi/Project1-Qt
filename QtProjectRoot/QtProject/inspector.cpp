#include "inspector.h"
#include "ui_transform.h"
#include "ui_mesh.h"
#include <QVBoxLayout>

Inspector::Inspector(QWidget *parent) : QWidget(parent),
    uiTransform(new Ui::Transform),
    uiMesh(new Ui::Mesh)
{
    uiTransform->setupUi(transformWidget);

    uiMesh->setupUi(meshWidget);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(transformWidget);
    layout->addWidget(meshWidget);
    layout->addItem(new QSpacerItem(1,1,QSizePolicy::Expanding, QSizePolicy::Expanding));
    setLayout(layout);

}

Inspector::~Inspector()
{
    delete uiTransform;
    delete uiMesh;
}

void Inspector::OnEntitySelected(int entityId)
{
    if (entityId % 2 == 0)
    {
        meshWidget->show();
    }
    else {
        meshWidget->hide();
    }
}
