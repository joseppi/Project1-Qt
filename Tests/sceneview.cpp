#include "sceneview.h"
#include <QPainter>

SceneView::SceneView(QWidget *parent) : QWidget(parent)
{

}

void SceneView::paintEvent(QPaintEvent*) {
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
