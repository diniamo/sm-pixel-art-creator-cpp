#ifndef SAVE_H
#define SAVE_H

#include <QUuid>
#include <QDir>
#include <QIODevice>
#include <QString>
#include <random>
#include <sstream>

namespace SMSaving {
    static std::random_device              rd;
    static std::mt19937                    gen(rd());
    static std::uniform_int_distribution<> dis(0, 15);
    static std::uniform_int_distribution<> dis2(8, 11);
    QString generateUuid()
    {
        std::stringstream ss;
        int i;
        ss << std::hex;
        for (i = 0; i < 8; i++) {
            ss << dis(gen);
        }
        ss << "-";
        for (i = 0; i < 4; i++) {
            ss << dis(gen);
        }
        ss << "-4";
        for (i = 0; i < 3; i++) {
            ss << dis(gen);
        }
        ss << "-";
        ss << dis2(gen);
        for (i = 0; i < 3; i++) {
            ss << dis(gen);
        }
        ss << "-";
        for (i = 0; i < 12; i++) {
            ss << dis(gen);
        };
        return QString::fromStdString(ss.str());
    }

    bool saveBlueprint(QString* blueprint, QString* description, const QString& uuid, QDir& blueprintsFolder)
    {
        blueprintsFolder.mkdir(uuid);
        blueprintsFolder.cd(uuid);

        QFile bpFile(blueprintsFolder.absoluteFilePath("blueprint.json"));
        QFile descFile(blueprintsFolder.absoluteFilePath("description.json"));

        if(!bpFile.open(QIODevice::WriteOnly)) return false;
        QTextStream bOut(&bpFile);
        bOut << *blueprint;

        if(!descFile.open(QIODevice::WriteOnly)) return false;
        QTextStream dOut(&descFile);
        dOut << *description;

        return true;
    }
}

#endif // SAVE_H
