#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "studywindow.h"
#include "gamewindow.h"
#include "addpicture.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    StudyWindow window;
    window.setModal(true);
    window.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    StudyWindow window;
    window.setModal(true);
    window.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    StudyWindow window;
    window.setModal(true);
    window.exec();
}

void MainWindow::on_pushButton_7_clicked()
{
    StudyWindow window;
    window.setModal(true);
    window.exec();
}

void MainWindow::on_pushButton_6_clicked()
{
    StudyWindow window;
    window.setModal(true);
    window.exec();
}

void MainWindow::on_pushButton_5_clicked()
{
    StudyWindow window;
    window.setModal(true);
    window.exec();
}

void MainWindow::on_pushButton_8_clicked()
{
    StudyWindow window;
    window.setModal(true);
    window.exec();
}

void MainWindow::on_pushButton_9_clicked()
{
    StudyWindow window;
    window.setModal(true);
    window.exec();
}

void MainWindow::on_pushButton_10_clicked()
{
    StudyWindow window;
    window.setModal(true);
    window.exec();
}

void MainWindow::on_vozr_clicked()
{
    GameWindow gwindow;
    gwindow.setModal(true);
    gwindow.exec();
}

void MainWindow::on_impr_clicked()
{
    GameWindow gwindow;
    gwindow.setModal(true);
    gwindow.exec();
}

void MainWindow::on_post_clicked()
{
    GameWindow gwindow;
    gwindow.setModal(true);
    gwindow.exec();
}

void MainWindow::on_klas_clicked()
{
    GameWindow gwindow;
    gwindow.setModal(true);
    gwindow.exec();
}

void MainWindow::on_real_clicked()
{
    GameWindow gwindow;
    gwindow.setModal(true);
    gwindow.exec();
}

void MainWindow::on_roko_clicked()
{
    GameWindow gwindow;
    gwindow.setModal(true);
    gwindow.exec();
}

void MainWindow::on_roma_clicked()
{
    GameWindow gwindow;
    gwindow.setModal(true);
    gwindow.exec();
}

void MainWindow::on_sure_clicked()
{
    GameWindow gwindow;
    gwindow.setModal(true);
    gwindow.exec();
}

void MainWindow::on_abst_clicked()
{
    GameWindow gwindow;
    gwindow.setModal(true);
    gwindow.exec();
}
