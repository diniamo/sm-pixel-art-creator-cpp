TEMPLATE = app
TARGET = sm-pixel-art-creator

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    window.cpp

HEADERS += \
    generator.h \
    save.h \
    window.h \

INCLUDEPATH += E:/Programs/opencv/build/install/include
DEPENDPATH += E:/Programs/opencv/build/install/include

LIBS += -LE:/Programs/OpenCV/build/install/x64/vc16/lib -lopencv_core453 -lopencv_imgcodecs453 -lopencv_imgproc453
