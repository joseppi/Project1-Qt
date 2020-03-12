#ifndef INSPECTOR_H
#define INSPECTOR_H

#include <QWidget>

namespace Ui {
    class Transform;
    class Mesh;
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
    Ui::Transform *ui_transorm;

public slots:
    void OnCurrentItemChanged();

private:
    MainWindow* main_window;

};

#endif // INSPECTOR_H
