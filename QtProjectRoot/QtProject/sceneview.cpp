#include "sceneview.h"

#include <QPainter>

SceneView::SceneView(QWidget *parent)
{

}

QSize SceneView::sizeHint() const
{
    return QSize(256, 256);
}

QSize SceneView::minimumSizeHint() const
{
    return QSize(64, 64);
}

void SceneView::paintEvent(QPaintEvent *event)
{
    QColor blueColor = QColor::fromRgb(127,190,220);
    QColor whiteColor = QColor::fromRgb(255,255,255);
    QColor blackColor = QColor::fromRgb(0,0,0);

    //Prepare the painter for this widget
    QPainter painter(this);

    QBrush brush;
    QPen pen;

    // Brush/pen configuration
    brush.setColor(blueColor);
    brush.setStyle(Qt::BrushStyle::SolidPattern);
    pen.setStyle(Qt::PenStyle::NoPen);
    painter.setBrush(brush);
    painter.setPen(pen);

    //Paint Background
    painter.drawRect(rect());

    // Brush/pen configuration
    brush.setColor(whiteColor);
    brush.setStyle(Qt::BrushStyle::SolidPattern);
    pen.setStyle(Qt::PenStyle::NoPen);
    pen.setColor(blackColor);
    painter.setBrush(brush);
    painter.setPen(pen);

    // Draw circle
    int r = 64;
    int w = r * 2;
    int h = r * 2;
    int x = rect().width() / 2 - r;
    int y = rect().height() / 2 - r;
    QRect circleRect(x, y, w, h);
    painter.drawEllipse(circleRect);
}
