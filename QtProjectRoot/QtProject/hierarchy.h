#ifndef HIERARCHY_H
#define HIERARCHY_H

#include <QWidget>

namespace Ui {
class Hierarchy;
}
struct Entity;
class Hierarchy : public QWidget
{
    Q_OBJECT

public:
    explicit Hierarchy(QWidget *parent = nullptr);
    ~Hierarchy();

signals:
    void entityChanged(int entityId);
    void entitySelected(int entityId);

public slots:
    void onAddEntity();
    void onRemoveEntity();
    void onEntitySelected(int row);

private:
    Ui::Hierarchy *ui;


};

#endif // HIERARCHY_H
