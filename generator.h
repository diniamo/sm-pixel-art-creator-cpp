#ifndef GENERATOR_H
#define GENERATOR_H

#include <QString>
#include <QPair>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonDocument>


namespace SMGenerators {
    typedef QString str;

    QJsonObject getBlock(int x, int y, QString const &color, QString const &shapeId)
    {   
        return QJsonObject({
                                 { str("bounds"), QJsonObject(
                                   {
                                       { str("x"), 1 },
                                       { str("y"), 1 },
                                       { str("z"), 1 }
                                   })
                                 },
                                 { str("color"), color },
                                 { str("pos"), QJsonObject(
                                  {
                                       { str("x"), x },
                                       { str("y"), y },
                                       { str("z"), 1 }
                                  })
                                 },
                                 { str("shapeId"), shapeId },
                                 { str("xaxis"), 1 },
                                 { str("zaxis"), 3 }
                              });
    }

    QJsonObject getBase(QJsonArray const &blocks)
    {
        return QJsonObject({
                                   { str("bodies"), QJsonArray({ QJsonObject({ { str("childs"), blocks } }) }) },
                                   { str("version"), 2 }
                               });
    }

    QString generateDescription(QString const &uuid)
    {
        return QString(QJsonDocument(QJsonObject({
                                   { str("description"), str("Generated with SM Pixel Art Creator by diniamo.") },
                                   QPair<QString, QString>{ str("localId"), uuid },
                                   QPair<QString, QString>{ str("name"), uuid },
                                   { str("type"), str("Blueprint") },
                                   { str("version"), 0 }
                              })).toJson());
    }

    const str rgb2hex(int r, int g, int b, bool with_head)
    {
        char hexcol[16];
        std::snprintf(hexcol, sizeof hexcol, "%02x%02x%02x", r, g, b);

        return (with_head ? "#" : "") + str(hexcol);
    }

    struct GeneratedBlueprint
    {
        QString blueprint;
        QString description;
        cv::Mat icon;
    };

    GeneratedBlueprint* generateBlueprint(QString const &imagePath, const QString& uuid, int width, int height)
    {
        using namespace cv;

        QJsonArray blocks;

        Mat image = imread(imagePath.toStdString());
        Mat resized;
        resize(image, resized, Size(width, height), INTER_AREA);

        unsigned char *input = (unsigned char*)(resized.data);
        for(int j = 0; j < resized.cols ;j++){
            for(int i = 0; i < resized.rows; i++){
                unsigned char b = input[resized.step * i + j*3] ;
                unsigned char g = input[resized.step * i + j*3 + 1];
                unsigned char r = input[resized.step * i + j*3 + 2];

                // qDebug() << '(' << r << ',' << g << ',' << b << ')' << " at (" << j << ',' << i << ')' << " hex: " << rgb2hex(r, g, b, true);

                blocks.append(getBlock(j, i, rgb2hex(r, g, b, false), str("628b2d61-5ceb-43e9-8334-a4135566df7a")));
            }
        }

        Mat icon;
        resize(resized, icon, Size(128, 128), INTER_AREA);

        return new GeneratedBlueprint{
            QString(QJsonDocument(getBase(blocks)).toJson(QJsonDocument::Compact)),
            generateDescription(uuid),
            icon
        };
    }
}

#endif // GENERATOR_H
