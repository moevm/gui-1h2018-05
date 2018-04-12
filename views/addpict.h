#ifndef ADDPICT_H
#define ADDPICT_H

#include <QDialog>
#include <QFileDialog>

#include "controllers/controller.h"

namespace Ui {
class AddPict;
}

class AddPict : public QDialog
{
    Q_OBJECT

public:
    explicit AddPict(Controller* controller, QWidget *parent = 0);
    ~AddPict();

private slots:
    void on_backGame_clicked();

    void on_pushButton_clicked();

private:
    Ui::AddPict *ui;
    Controller* m_controller;
    QString m_imagePath;
};

#endif // ADDPICT_H
