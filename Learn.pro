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

#INCLUDEPATH += E:/Programs/opencv/build/install/include
#DEPENDPATH += E:/Programs/opencv/build/install/include

#LIBS += -LE:/Programs/OpenCV/build/install/x64/vc16/lib -lopencv_core453 -lopencv_imgcodecs453 -lopencv_imgproc453 -lopencv_features2d453

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../Programs/OpenCV/opencv_4.5.3/build/x64/vc15/lib/ -lopencv_world453
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../Programs/OpenCV/opencv_4.5.3/build/x64/vc15/lib/ -lopencv_world453d

INCLUDEPATH += $$PWD/../../../../../Programs/OpenCV/opencv_4.5.3/build/include
DEPENDPATH += $$PWD/../../../../../Programs/OpenCV/opencv_4.5.3/build/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../Programs/OpenCV/opencv_4.5.3/build/x64/vc15/lib/opencv_world453.lib
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../Programs/OpenCV/opencv_4.5.3/build/x64/vc15/lib/opencv_world453d.lib
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../Programs/OpenCV/opencv_4.5.3/build/x64/vc15/lib/opencv_world453.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../Programs/OpenCV/opencv_4.5.3/build/x64/vc15/lib/opencv_world453d.lib
