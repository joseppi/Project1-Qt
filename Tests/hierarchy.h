#ifndef HIERARCHY_H
#define HIERARCHY_H

#include <QWidget>
#include <QListWidget>

namespace Ui {
class Hierarchy;
}

class Hierarchy : public QWidget
{
    Q_OBJECT

public:
    explicit Hierarchy(QWidget *parent = nullptr);
    ~Hierarchy();

public slots:
    void OnAddEntity();
    void OnRemoveEntity();
    void OnEntitySelected();
    QList<QListWidgetItem*> GetListViewEntities();

private:
    Ui::Hierarchy *ui;

signals:
    void entityChanged(int id);
};

#endif // HIERARCHY_H
