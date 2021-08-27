#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui
{
    class Form;
}

class QRegion;
class QDir;
class Form : public QWidget
{
    Q_OBJECT

    public:
        explicit Form(QDir *blueprints_folder, QWidget *parent = nullptr);
        ~Form();

private slots:
    void on_CloseButton_clicked();
    void on_MinimizeButton_clicked();

private:
        Ui::Form *ui;

        QDir *m_blueprints_folder;

        void mousePressEvent(QMouseEvent *event);
        void mouseMoveEvent(QMouseEvent *event);
        int m_nMouseClick_X_Coordinate;
        int m_nMouseClick_Y_Coordinate;
};

#endif // FORM_H
