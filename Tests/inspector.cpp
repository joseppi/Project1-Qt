#include "inspector.h"
#include "ui_transform.h"
#include "ui_properties.h"
#include "mainwindow.h"
#include "ui_hierarchy.h"
#include "hierarchy.h"
#include "shapefactory.h"
#include "shape.h"
#include "sceneview.h"
#include "QColorDialog"

Inspector::Inspector(QWidget *parent, MainWindow *main_window) :
    QWidget(parent),
    ui_properties(new Ui::Properties),
    ui_transorm(new Ui::Transform)

{
    QVBoxLayout *layout = new QVBoxLayout();

    QWidget *transform_widget = new QWidget;
    ui_transorm->setupUi((transform_widget));
    layout->addWidget(transform_widget);
    layout->addItem(new QSpacerItem(1,1,QSizePolicy::Expanding,QSizePolicy::Expanding));

    QWidget *properties_widget = new QWidget;
    ui_properties->setupUi((properties_widget));
    layout->addWidget(properties_widget);
    layout->addItem(new QSpacerItem(1,1,QSizePolicy::Expanding,QSizePolicy::Expanding));





    this->main_window =main_window;



    setLayout(layout);

    connect(main_window->hierarchy->ui->listWidget,SIGNAL(itemSelectionChanged()),SLOT(OnCurrentItemChanged()));

    //Couldnt make it work with simpler sintax
    connect(ui_transorm->PosX, QOverload<double>::of(&QDoubleSpinBox::valueChanged),[=](double d){OnPosXChanged(d);});
    connect(ui_transorm->PosY, QOverload<double>::of(&QDoubleSpinBox::valueChanged),[=](double d){OnPosYChanged(d);});
    connect(ui_transorm->ScalX, QOverload<double>::of(&QDoubleSpinBox::valueChanged),[=](double d){OnWidthChanged(d);});
    connect(ui_transorm->ScalY, QOverload<double>::of(&QDoubleSpinBox::valueChanged),[=](double d){OnHeightChanged(d);});

    connect(ui_properties->FillColorSample,SIGNAL(clicked()),SLOT(ChangeFillColor()));
    connect(ui_properties->StrokeColorSample,SIGNAL(clicked()),SLOT(ChangeStrokeColor()));

    selected_shape = nullptr;

}

Inspector::~Inspector()
{

}

void Inspector::OnPosXChanged(double v)
{
    if (selected_shape)
        selected_shape->rect.moveLeft(v);

        main_window->scene_view->repaint();
}

void Inspector::OnPosYChanged(double v)
{
    if (selected_shape)
        selected_shape->rect.moveTop(v);
        main_window->scene_view->repaint();
}

void Inspector::OnWidthChanged(double v)
{
    if (selected_shape)
        selected_shape->rect.setWidth(v);
    main_window->scene_view->repaint();
}

void Inspector::OnHeightChanged(double v)
{
    if (selected_shape)
        selected_shape->rect.setHeight(v);
    main_window->scene_view->repaint();
}

void Inspector::ChangeFillColor()
{
    QColor new_color = QColorDialog::getColor();
    selected_shape->fill_color = new_color;
    main_window->scene_view->repaint();
    UpdateColorSample(*ui_properties->FillColorSample,selected_shape->fill_color);

}

void Inspector::ChangeStrokeColor()
{
    QColor new_color = QColorDialog::getColor();
    selected_shape->stroke_color = new_color;
    main_window->scene_view->repaint();
    UpdateColorSample(*ui_properties->StrokeColorSample,selected_shape->stroke_color);
}

void Inspector::UpdateColorSample(QPushButton &color_sample, QColor color)
{
    QPalette pal = color_sample.palette();
    pal.setColor(QPalette::Button, color);
    color_sample.setFlat(true);
    color_sample.setAutoFillBackground(true);
    color_sample.setPalette(pal);
    color_sample.update();
}

void Inspector::OnCurrentItemChanged()
{

    QListWidgetItem* item = main_window->hierarchy->ui->listWidget->currentItem();

    //QVariant shape_info_variant = item->data(Qt::UserRole);
    QVariant qid = item->data(Qt::UserRole);
    int id = qid.toInt();
    selected_shape = main_window->shape_factory->shapes.at(id);
    //qintptr shape_pointer_as_int = shape_info_variant.toInt();
    //Shape* newest_shape = (Shape*)shape_pointer_as_int;
    ui_transorm->ScalX->setValue(selected_shape->rect.width());
    ui_transorm->ScalY->setValue(selected_shape->rect.height());
    ui_transorm->PosX->setValue(selected_shape->rect.x());
    ui_transorm->PosY->setValue(selected_shape->rect.y());




    UpdateColorSample(*ui_properties->FillColorSample,selected_shape->fill_color);
    UpdateColorSample(*ui_properties->StrokeColorSample,selected_shape->stroke_color);

}





