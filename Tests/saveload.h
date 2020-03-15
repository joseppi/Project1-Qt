#ifndef SAVELOAD_H
#define SAVELOAD_H

#include <QtXml>
#include <QtWidgets>
#include <QMainWindow>

#include "shapefactory.h"

class MainWindow;


class SaveLoad : public QWidget
{
    Q_OBJECT
public:
    MainWindow* main_window = nullptr;

public:
    explicit SaveLoad(QWidget *parent, MainWindow* main_window);
    QList<Shape*> ReadXML(QDomElement root, QString tagName);

public slots:
    void ActionSaveProject();
    void ActionLoadProject();
    void ActionLoadLayout();
    void ActionSaveLayout();


};

#endif // SAVELOAD_H
