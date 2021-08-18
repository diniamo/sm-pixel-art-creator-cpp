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

    QJsonObject getBlock(int x, int y, const QString &color, const QString &shapeId)
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

    QJsonObject getBase(QJsonArray &blocks)
    {
        return QJsonObject({
                                   { str("bodies"), QJsonArray({ QJsonObject({ { str("childs"), blocks } }) }) },
                                   { str("version"), 3 }
                               });
    }

    const str rgb2hex(int r, int g, int b, bool with_head)
    {
      std::stringstream ss;
      if (with_head)
        ss << "#";
      ss << std::hex << (r << 16 | g << 8 | b );
      return str::fromStdString(ss.str());
    }

    QString* generateBlueprint(const QString& imagePath, int width, int height)
    {
        using namespace cv;

        QJsonArray blocks;

        Mat image = imread(imagePath.toStdString());
        Mat resized;
        resize(image, resized, Size(width, height), INTER_LINEAR);


        unsigned char *input = (unsigned char*)(resized.data);
        for(int j = 0; j < resized.rows ;j++){
            for(int i = 0; i < resized.cols; i++){
                unsigned char b = input[resized.step * j + i ] ;
                unsigned char g = input[resized.step * j + i + 1];
                unsigned char r = input[resized.step * j + i + 2];

                blocks.append(getBlock(j, i, rgb2hex(r, g, b, false), str("628b2d61-5ceb-43e9-8334-a4135566df7a")));
            }
        }

        QString* jsonString = new QString(QJsonDocument(blocks).toJson());

        return jsonString;
    }

    QString* generateDescription(const QString& uuid)
    {
        return new QString(QJsonDocument(QJsonObject({
                                   { str("description"), str("Generated with SM Pixel Art Creator by diniamo.") },
                                   QPair<QString, QString>{ str("localId"), uuid },
                                   QPair<QString, QString>{ str("name"), uuid },
                                   { str("type"), str("Blueprint") },
                                   { str("version"), 0 }
                              })).toJson());
    }
}

#endif // GENERATOR_H
