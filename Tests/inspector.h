#ifndef INSPECTOR_H
#define INSPECTOR_H

#include <QWidget>

class Shape;
class QPushButton;
class QColor;

namespace Ui {
    class Transform;
    class Properties;
}

class MainWindow;
class QListWidgetItem;

class Inspector : public QWidget
{
    Q_OBJECT

public:
    explicit Inspector(QWidget *parent = nullptr, MainWindow *main_window = nullptr);
    ~Inspector();

private:
    Ui::Properties *ui_properties;
    Ui::Transform *ui_transorm;


public slots:
    void OnCurrentItemChanged();
    void OnPosXChanged(double v);
    void OnPosYChanged(double v);
    void OnWidthChanged(double v);
    void OnHeightChanged(double v);
    void ChangeFillColor();
    void ChangeStrokeColor();
    void UpdateColorSample(QPushButton& color_sample,  QColor color);

private:
    MainWindow* main_window;
    Shape* selected_shape;

};

#endif // INSPECTOR_H
