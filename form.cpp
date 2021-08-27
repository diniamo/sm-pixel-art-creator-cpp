#include "form.h"
#include "ui_form.h"
#include <QDir>
#include <QPainter>
#include <QGraphicsDropShadowEffect>
#include <QMouseEvent>

Form::Form(QDir *blueprints_folder, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    setFixedSize(900, 680);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    QBitmap bmp(size());
    bmp.clear();
    QPainter painter(&bmp);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QColor(Qt::black));
    painter.setBrush(QColor(Qt::black));
    painter.drawRoundedRect(geometry(), 30.0f, 30.0f, Qt::AbsoluteSize);
    painter.drawRect(0, 0, 900, 50);
    setMask(bmp);

    int gei = 5;
    auto *glowEffects = new QGraphicsDropShadowEffect[gei];
    for(int i = 0; i < gei; i++)
    {
        glowEffects[i].setXOffset(0);
        glowEffects[i].setYOffset(0);
        glowEffects[i].setBlurRadius(15);
        glowEffects[i].setColor(QColor(255, 145, 0, 100));
    }

    int sei = 1;
    auto *shadowEffects = new QGraphicsDropShadowEffect[sei];
    for(int i = 0; i < sei; i++)
    {
        shadowEffects[i].setXOffset(0);
        shadowEffects[i].setYOffset(1);
        shadowEffects[i].setBlurRadius(15);
        shadowEffects[i].setColor(QColor(0, 0, 0));
    }


    ui->SizeFrame->setGraphicsEffect(&glowEffects[0]);
    ui->ImagePreview->setGraphicsEffect(&glowEffects[1]);
    ui->SelectImage->setGraphicsEffect(&glowEffects[2]);
    ui->Generate->setGraphicsEffect(&glowEffects[3]);
    ui->GenerateBlueprintLabel->setGraphicsEffect(&glowEffects[4]);

    ui->SizeLabel->setGraphicsEffect(&shadowEffects[0]);


    m_blueprints_folder = blueprints_folder;
}

Form::~Form()
{
    delete ui;
    delete m_blueprints_folder;
}

void Form::on_CloseButton_clicked()
{
    QApplication::exit();
}


void Form::on_MinimizeButton_clicked()
{
    setWindowState(Qt::WindowMinimized);
}

void Form::mousePressEvent(QMouseEvent *event) {
    m_nMouseClick_X_Coordinate = event->position().x();
    m_nMouseClick_Y_Coordinate = event->position().y();
}

void Form::mouseMoveEvent(QMouseEvent *event) {
    if(m_nMouseClick_Y_Coordinate > 50) return;

    auto point = event->globalPosition();
    move(point.x()-m_nMouseClick_X_Coordinate,point.y()-m_nMouseClick_Y_Coordinate);
}
