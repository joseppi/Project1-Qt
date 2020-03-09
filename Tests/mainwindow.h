#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class Hierarchy;
class Inspector;
class SceneView;
class ShapeFactory;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    ShapeFactory* shape_factory = nullptr;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void AddShape();
public slots:
    void ActionQuitProject();
    void ActionLoadProject();
    void ActionSaveProject();
    void ActionNewProject();

private:
    Ui::MainWindow *ui_main;

    Hierarchy *hierarchy;
    Inspector *inspector;
    SceneView *scene_view;
};

#endif // MAINWINDOW_H
