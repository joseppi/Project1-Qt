#ifndef SAVELOAD_H
#define SAVELOAD_H

#include <QtXml>
#include <QtWidgets>
#include <QMainWindow>

#include "shape.h"

class MainWindow;


class SaveLoad : public QWidget
{
    Q_OBJECT
public:
    MainWindow* main_window = nullptr;

public:
    explicit SaveLoad(QWidget *parent, MainWindow* main_window);
    void ReadXML(QDomElement root, QString tagName);
    void ClearScene();

public slots:
    void ActionSaveProject();
    void ActionLoadProject();
    void ActionLoadLayout();
    void ActionSaveLayout();

private:
    QList<Shape*> shapeList;


};

#endif // SAVELOAD_H
