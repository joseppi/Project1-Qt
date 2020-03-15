#ifndef HIERARCHY_H
#define HIERARCHY_H

#include <QWidget>
#include <QListWidget>


class MainWindow;
class Shape;

namespace Ui {
class Hierarchy;
}

class Hierarchy : public QWidget
{
    Q_OBJECT


public:
    explicit Hierarchy(QWidget *parent = nullptr, MainWindow* main_window = nullptr);
    void OnAddEntityXML(Shape* shape);
    ~Hierarchy();

public slots:
    void OnAddEntity();    
    void OnRemoveEntity();    
    void ClearEntities();
    QList<QListWidgetItem*> GetListViewEntities();

public:
    Ui::Hierarchy *ui;
private:
    MainWindow* main_window;

signals:
    void entityChanged(int id);
};

#endif // HIERARCHY_H
