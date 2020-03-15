#include "saveload.h"
#include "shapefactory.h"
#include "mainwindow.h"
#include <QtXml>


SaveLoad::SaveLoad(QWidget *parent, MainWindow* main_window) : QWidget(parent)
{
    this->main_window = main_window;
}

void SaveLoad::ActionSaveProject() {
    //Get File Path
    //QString path = QFileDialog::getSaveFileName(this, "Save Project");
    QString path = QDir::currentPath() + "/Save.txt";
    QList<Shape*> list = main_window->shape_factory->GetShapes();

    //Create stream
    QString output;
    QDomDocument document;

    //Make root element
    QDomElement root = document.createElement("Entities");


    //Add some elements
    for(int i = 0; i < list.length(); i++)
    {
        QDomElement node_shapes = document.createElement("Shape");
        node_shapes.setAttribute("id", QString::number(i));

        ShapeType type = list[i]->type;
        node_shapes.setAttribute("Type", QString::number(type));

        //Save Rectangle
        QRect ret = list[i]->rect;
        QDomElement node_rect = document.createElement("rect");
        node_rect.setAttribute("x",ret.x());
        node_rect.setAttribute("y",ret.y());
        node_rect.setAttribute("h",ret.height());
        node_rect.setAttribute("w",ret.width());
        node_shapes.appendChild(node_rect);

        //Save ColorFill
        QColor colorFill;
        colorFill = list[i]->fill_color;
        QDomElement node_color_fill = document.createElement("colorFill");
        node_color_fill.setAttribute("r", colorFill.red());
        node_color_fill.setAttribute("g", colorFill.green());
        node_color_fill.setAttribute("b", colorFill.blue());
        node_color_fill.setAttribute("a", colorFill.alpha());
        node_shapes.appendChild(node_color_fill);

        //Save ColorStroke
        QColor colorStroke;
        colorStroke = list[i]->stroke_color;
        QDomElement node_color_stroke = document.createElement("colorStroke");
        node_color_stroke.setAttribute("r", colorStroke.red());
        node_color_stroke.setAttribute("g", colorStroke.green());
        node_color_stroke.setAttribute("b", colorStroke.blue());
        node_color_stroke.setAttribute("a", colorStroke.alpha());
        node_shapes.appendChild(node_color_stroke);





        root.appendChild(node_shapes);
    }

    //Add it to the document
    document.appendChild(root);

    //Write to file

    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Failed to save file for writting";
    }
    else
    {
        QTextStream stream(&file);
        stream << document.toString();
        file.close();
        qDebug() << "Finished";
    }

    if (!path.isEmpty())
    {

       //QMessageBox::information(this, "Info Save", path);
       if (!list.isEmpty())
       {
        qDebug () << path;
       }

    }
}

void SaveLoad::ActionLoadProject() {
    //QString path = QFileDialog::getOpenFileName(this, "Open Project");
    QString path = QDir::currentPath() + "/Save.txt";
    if (!path.isEmpty())
    {
       //QMessageBox::information(this, "Info Load", path);
    }

    QDomDocument document;

    //Load the file
    QFile file(path);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file";
    }
    else
    {
        if (!document.setContent(&file))
        {
            qDebug() << "Failed to load document";
        }
        file.close();
    }

    //get the root element
    QDomElement root = document.firstChildElement();

    //List of the Elements(root,tagname,attribute)
    QList<Shape*> shapeList = ReadXML(root,"Shape");

}

QList<Shape*> SaveLoad::ReadXML(QDomElement root, QString tagName)
{
    QList<Shape*> ret;
    QDomNodeList items = root.elementsByTagName(tagName);
    qDebug() << "Total items = "<< items.count();

    for (int i = 0; i < items.count(); i++)
    {
        QDomNode itemnode = items.at(i);
        if (itemnode.isElement())
        {
            Shape new_shape;
            QDomElement shapes = itemnode.toElement();

            new_shape.id = shapes.attribute("id").toInt();
            new_shape.type =(ShapeType)shapes.attribute("Type").toInt();

            //Get Attributes from Rect
            QDomNodeList rect_items = shapes.elementsByTagName("rect");
            QRect rect;
            for (int i = 0; i < rect_items.count(); i++)
            {
                QDomNode rectItemNode = rect_items.at(i);
                if (rectItemNode.isElement())
                {
                    QDomElement rectelement = rectItemNode.toElement();
                    rect.setRect(
                                rectelement.attribute("x").toInt(),
                                rectelement.attribute("y").toInt(),
                                rectelement.attribute("h").toInt(),
                                rectelement.attribute("w").toInt());
                }
            }
            new_shape.rect = rect;

            //Get Attributes from ColorFill
            QDomNodeList color_fill_items = shapes.elementsByTagName("colorFill");
            QColor colorFill;
            for (int i = 0; i < color_fill_items.count(); i++)
            {
                QDomNode colorItemNode = color_fill_items.at(i);
                if (colorItemNode.isElement())
                {
                    QDomElement colorelement = colorItemNode.toElement();
                    colorFill.setRgb(
                                colorelement.attribute("r").toInt(),
                                colorelement.attribute("g").toInt(),
                                colorelement.attribute("b").toInt(),
                                colorelement.attribute("a").toInt());
                }
            }

            //Get Attributes from ColorFill
            QDomNodeList color_stroke_items = shapes.elementsByTagName("colorStroke");
            QColor colorStroke;
            for (int i = 0; i < color_stroke_items.count(); i++)
            {
                QDomNode colorItemNode = color_stroke_items.at(i);
                if (colorItemNode.isElement())
                {
                    QDomElement colorelement = colorItemNode.toElement();
                    colorStroke.setRgb(
                                colorelement.attribute("r").toInt(),
                                colorelement.attribute("g").toInt(),
                                colorelement.attribute("b").toInt(),
                                colorelement.attribute("a").toInt());
                }
            }
            //qDebug() << QString::number(colorStroke.red());
            //qDebug() << QString::number(colorStroke.green());
            //qDebug() << QString::number(colorStroke.blue());
            //qDebug() << QString::number(colorStroke.alpha());

            new_shape.fill_color = colorStroke;
            ret.push_back(&new_shape);
        }
    }
    return ret;
}

void SaveLoad::ActionLoadLayout()
{
    QSettings settings("Pipo", "Cute Engine");
    main_window->restoreState(settings.value("dockpos").toByteArray());

    qDebug() << this->geometry().width();

    qDebug("loadLayout");
}

void SaveLoad::ActionSaveLayout()
{
    QSettings settings("Pipo", "Cute Engine");
    settings.setValue("dockpos",main_window->saveState());

    qDebug("saveLayout");
}
