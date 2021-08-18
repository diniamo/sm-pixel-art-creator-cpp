#include "window.h"
#include "generator.h"
#include "save.h"
#include <QDir>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QFileDialog>
#include <QGuiApplication>
#include <QMessageBox>
#include <QDebug>


Window::Window(QDir* blueprints_folder, QWidget *parent) : QWidget(parent)
{
    setWindowTitle("SM Pixel Art Creator");
    setFixedSize(200, 125);
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);

    m_blueprints_folder = blueprints_folder;


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
    m_input_width_input = new QLineEdit("128");
    m_input_height_label = new QLabel("Height: ");
    m_input_height_input = new QLineEdit("128");

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
    connect(m_generate, SIGNAL(clicked()), this, SLOT(generateClicked()));
}
Window::~Window()
{
    delete m_blueprints_folder;
}

void Window::imageButtonClicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Open image", QDir::homePath());
    m_image_label->setText(file_name);
    qDebug() << file_name;
    setFixedSize(geometry().width() + qMax(0, file_name.length()-12)*5, geometry().height());
    updateGeometry();
}

void Window::generateClicked()
{
    using namespace SMGenerators;
    using namespace SMSaving;

    //QClipboard *cb = QGuiApplication::clipboard();


    QString uuid = generateUuid();
    qDebug() << uuid;

    QString *blueprint = generateBlueprint(m_image_label->text(), m_input_width_input->text().toInt(), m_input_height_input->text().toInt());
    QString *description = generateDescription(uuid);

    //cb->setText(*blueprint);
    saveBlueprint(blueprint, description, uuid, *m_blueprints_folder);

    delete blueprint;
    delete description;


    QMessageBox doneBox(QMessageBox::Icon::Information, "Done!", "Generation done.", QMessageBox::NoButton, this);
    doneBox.exec();
}
