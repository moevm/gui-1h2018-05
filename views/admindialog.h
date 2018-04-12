#ifndef ADMINDIALOG_H
#define ADMINDIALOG_H

#include <QDialog>

#include "controllers/controller.h"
#include "views/addpict.h"
#include "views/addartistdialog.h"

namespace Ui {
class AdminDialog;
}

class AdminDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AdminDialog(Controller* controller, QWidget *parent = 0);
    ~AdminDialog();

private slots:
    void on_addPicturePushButton_clicked();

    void on_addArtistPushButton_clicked();

private:
    Ui::AdminDialog *ui;
    Controller* m_controller;
};

#endif // ADMINDIALOG_H
