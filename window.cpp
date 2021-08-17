#include "window.h"
#include <QHBoxLayout>
#include <QVboxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QFileDialog>
#include <QDebug>


Window::Window(QWidget *parent) : QWidget(parent)
{
    setFixedSize(200, 125);


    m_image_box = new QHBoxLayout(nullptr);
    m_image_box->setAlignment(Qt::AlignTop);

    m_open_image = new QPushButton("Open image", nullptr);
    m_image_label = new QLabel("", nullptr);
    m_image_box->addWidget(m_open_image);
    m_image_box->addWidget(m_image_label);


    m_size_box = new QVBoxLayout(nullptr);
    m_input_box1 = new QHBoxLayout(nullptr);
    m_input_box2 = new QHBoxLayout(nullptr);

    m_input_width_label = new QLabel("Width: ");
    m_input_width_input = new QLineEdit();
    m_input_height_label = new QLabel("Height: ");
    m_input_height_input = new QLineEdit();

    m_input_box1->addWidget(m_input_width_label);
    m_input_box1->addWidget(m_input_width_input);
    m_input_box2->addWidget(m_input_height_label);
    m_input_box2->addWidget(m_input_height_input);

    m_size_box->addLayout(m_input_box1);
    m_size_box->addLayout(m_input_box2);


    m_generate = new QPushButton("Generate", nullptr);


    m_all_input_box = new QVBoxLayout(this);
    m_all_input_box->setAlignment(Qt::AlignTop);

    m_all_input_box->addLayout(m_image_box);
    m_all_input_box->addLayout(m_size_box);
    m_all_input_box->addWidget(m_generate);


    connect(m_open_image, SIGNAL(clicked()), this, SLOT(imageButtonClicked()));
}

void Window::imageButtonClicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Open image", QDir::homePath());
    m_image_label->setText(file_name);
    qDebug() << file_name;
    setFixedSize(geometry().width() + qMax(0, file_name.length()-12)*5, geometry().height());
    updateGeometry();
}
