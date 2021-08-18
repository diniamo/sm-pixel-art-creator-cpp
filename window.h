#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class QDir;
class QHBoxLayout;
class QVBoxLayout;
class QPushButton;
class QLabel;
class QLineEdit;
class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QDir* user_folder, QWidget *parent = nullptr);
    ~Window();

private:
   QDir *m_user_folder;

private:
    QVBoxLayout *m_all_input_box;

    QHBoxLayout *m_image_box;
    QPushButton *m_open_image;
    QLabel *m_image_label;

    QVBoxLayout *m_size_box;
    QHBoxLayout *m_input_box1;
    QHBoxLayout *m_input_box2;
    QLabel *m_input_width_label;
    QLineEdit *m_input_width_input;
    QLabel *m_input_height_label;
    QLineEdit *m_input_height_input;

    QPushButton *m_generate;


private slots:
    void imageButtonClicked();
    void generateClicked();
};

#endif // WINDOW_H
