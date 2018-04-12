#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QMessageBox>

#include "controllers/controller.h"
#include "views/admindialog.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(Controller* controller, QWidget *parent = 0);
    ~LoginDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::LoginDialog *ui;
    Controller* m_controller;
};

#endif // LOGINDIALOG_H
