#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QtXml>

class Shape;


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
    Shape* AddShape();
    void keyPressEvent(QKeyEvent *event);
    void ListElements(QDomElement root, QString tagName, QString attribute);

public slots:
    void ActionQuitProject();
    void ActionLoadProject();
    void ActionSaveProject();
    void ActionNewProject();

public:
    Hierarchy *hierarchy;
    Inspector *inspector;
    SceneView *scene_view;

private:
    Ui::MainWindow *ui_main;




};

#endif // MAINWINDOW_H
