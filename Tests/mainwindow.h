#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QKeyEvent>
#include <QtXml>
#include <QSettings>
#include "shape.h"

class Shape;


namespace Ui {
class MainWindow;
}

class Hierarchy;
class Inspector;
class SceneView;
class ShapeFactory;
class SaveLoad;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    ShapeFactory* shape_factory = nullptr;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Shape* AddShape(ShapeType type);    
    void keyPressEvent(QKeyEvent *event);
    QList<Shape*> ReadXML(QDomElement root, QString tagName);


public slots:
    void ActionQuitProject();
    void ActionNewProject();

public:
    Hierarchy *hierarchy = nullptr;
    Inspector *inspector = nullptr;
    SceneView *scene_view = nullptr;
    SaveLoad *save_load = nullptr;

public:
    Ui::MainWindow *ui_main = nullptr;




};

#endif // MAINWINDOW_H
