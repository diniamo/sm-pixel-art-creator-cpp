#include <QApplication>
#include <QPushButton>
#include <QDir>
#include <QStandardPaths>
#include <QUuid>

//#include <window.h>
#include <form.h>


int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QDir* userFolder = new QDir(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));
    userFolder->cd("../Axolot Games/Scrap Mechanic/User");
    if(!userFolder->exists() || !userFolder->isReadable()) {
        qFatal("User folder not found or cannot be read. Program will terminate.");
        QApplication::exit();
    }

    userFolder->setSorting(QDir::Time);
    userFolder->setFilter(QDir::Dirs | QDir::NoDotAndDotDot);

    userFolder->cd(userFolder->entryList().first());
    userFolder->cd("Blueprints");

    //Window window(userFolder);
    //window.show();
    Form form(userFolder);
    form.show();

    return app.exec();
}
