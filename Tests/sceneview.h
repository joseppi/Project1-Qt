#ifndef SCENEVIEW_H
#define SCENEVIEW_H

#include <QWidget>

class MainWindow;

class SceneView : public QWidget
{
    Q_OBJECT
   public:
    MainWindow* main_window;

public:
    explicit SceneView(QWidget *parent = nullptr, MainWindow* main_window = nullptr);
    void DrawBigCircle();
    void DrawScene();

public slots:
    void paintEvent(QPaintEvent *) override;
};

#endif // SCENEVIEW_H
