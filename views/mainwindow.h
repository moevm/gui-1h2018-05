#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "controllers/controller.h"

#include "views/logindialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_vozr_clicked();

    void on_impr_clicked();

    void on_post_clicked();

    void on_klas_clicked();

    void on_real_clicked();

    void on_roko_clicked();

    void on_roma_clicked();

    void on_sure_clicked();

    void on_abst_clicked();

    void on_signInPushButton_clicked();

public slots:
    void onDataBaseConnected();
    void onDataBaseDisconnected();

private:
    Ui::MainWindow *ui;

    Controller* m_controller;
};

#endif // MAINWINDOW_H
