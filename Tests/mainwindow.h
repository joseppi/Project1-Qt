#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QKeyEvent>
#include <QtXml>
#include <QSettings>


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
    Shape* AddShape();
    void keyPressEvent(QKeyEvent *event);
    QList<Shape*> ReadXML(QDomElement root, QString tagName);


public slots:
    void ActionQuitProject();
    void ActionNewProject();

public:
    Hierarchy *hierarchy;
    Inspector *inspector;
    SceneView *scene_view;
    SaveLoad *save_load;

public:
    Ui::MainWindow *ui_main;




};

#endif // MAINWINDOW_H
