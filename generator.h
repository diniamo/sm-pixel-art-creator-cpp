#ifndef GENERATOR_H
#define GENERATOR_H

#include <QString>
#include <QPair>

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>


namespace SMGenerators {
    QJsonObject* getBlock(int x, int y, QString &color, QString &shapeId)
    {
        return new QJsonObject({
                                   QPair<QString, QJsonObject>("bounds", QJsonObject(
                                   {
                                       QPair<QString, int>("x", 1),
                                       QPair<QString, int>("y", 1),
                                       QPair<QString, int>("z", 1)
                                   })),
                                  QPair<QString, QString>("color", color),
                                  QPair<QString, QJsonObject>("pos", QJsonObject(
                                  {
                                       QPair<QString, int>("x", x),
                                       QPair<QString, int>("y", y),
                                       QPair<QString, int>("z", 1)
                                  })),
                                  QPair<QString, QString>("shapeId", shapeId),
                                  QPair<QString, int>("xaxis", 1),
                                  QPair<QString, int>("zaxis", 3)
                              });
    }

    QJsonObject* getBase(QJsonArray &blocks)
    {
        return new QJsonObject({
                                   QPair<QString, QJsonArray>("bodies", QJsonArray({ QJsonObject({ QPair<QString, QJsonArray>("childs", blocks) }) })),
                                   QPair<QString, int>("version", 3)
                               });
    }

    QString* generateBlueprint(const QString& imagePath, int width, int height)
    {
        return nullptr;
    }
}

#endif // GENERATOR_H
