    #include "sceneview.h"
#include <QPainter>
#include "shapefactory.h"
#include "mainwindow.h"
#include "hierarchy.h"
#include "ui_hierarchy.h"

SceneView::SceneView(QWidget *parent, MainWindow* main_window) : QWidget(parent)
{
    this->main_window = main_window;

    connect(this->main_window->hierarchy->ui->AddEntityBtn,SIGNAL(clicked()),SLOT(OnAddEntity()));
}

void SceneView::DrawBigCircle()
{
    QColor blueColor = QColor::fromRgb(127,190,220);
    QColor whiteColor = QColor::fromRgb(255,255,255);
    QColor blackColor = QColor::fromRgb(0,0,0);


    QPainter painter(this);

    QBrush brush;
    QPen pen;

    brush.setColor((blueColor));
    brush.setStyle(Qt::BrushStyle::SolidPattern);
    pen.setStyle(Qt::PenStyle::NoPen);
    painter.setPen(pen);
    painter.setBrush(brush);

    painter.drawRect(rect());

    brush.setColor(whiteColor);
    pen.setWidth(4);
    pen.setColor(blackColor);
    pen.setStyle(Qt::PenStyle::DashLine);
    painter.setBrush(brush);
    painter.setPen(pen);

    //Draw circle
    int r = rect().width() /2;
    int w = r*2;
    int h = r*2;
    int x = rect().width() /2 - r;
    int y = rect().height() /2 - r;
    QRect circleRect(x,y,w,h);
    painter.drawEllipse(circleRect);
}

void SceneView::DrawScene()
{
    //must be called in paintevent
    QPainter painter(this);
    QColor blueColor = QColor::fromRgb(127,190,220);
    QColor whiteColor = QColor::fromRgb(255,255,255);
    QColor blackColor = QColor::fromRgb(0,0,0);
    QBrush brush;
    QPen pen;

    brush.setColor((blueColor));
    brush.setStyle(Qt::BrushStyle::SolidPattern);
    pen.setStyle(Qt::PenStyle::NoPen);
    painter.setPen(pen);
    painter.setBrush(brush);

    painter.drawRect(rect());

    //QRect rect = QRect(0,0,100,100);

    main_window->shape_factory->DrawShapeList(painter,brush,pen,rect());
}

void SceneView::paintEvent(QPaintEvent*) {

    DrawScene();

}


