#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
//class Transform;

}

class Hierarchy;
class Inspector;
class SceneView;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *uiMainWindow;

    //Ui::Transform *uiTransform;
    //Ui::Mesh *uiMesh;

    Hierarchy *hierarchy;
    Inspector *inspector;
    SceneView *sceneView;


public slots:
    void onText1Pressed();
    void onText2Pressed();
    void LoadFilePressed();
    void SaveFilePressed();
};

#endif // MAINWINDOW_H
