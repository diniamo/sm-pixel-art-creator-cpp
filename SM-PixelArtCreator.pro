TEMPLATE = app
TARGET = sm-pixel-art-creator

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

RC_ICONS = icon.ico
ICON = icon.ico

SOURCES += \
    form.cpp \
    main.cpp \
#    window.cpp

HEADERS += \
    form.h \
    generator.h \
    save.h \
#    window.h \

FORMS += \
    form.ui

RESOURCES += \
    resources.qrc

INCLUDEPATH += E:/Programs/opencv/build/install/include
DEPENDPATH += E:/Programs/opencv/build/install/include

LIBS += -LE:/Programs/OpenCV/build/install/x64/vc16/lib -lopencv_core453 -lopencv_imgcodecs453 -lopencv_imgproc453
