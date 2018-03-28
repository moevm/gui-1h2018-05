#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "studywindow.h"
#include "gamewindow.h"
#include "addpict.h"


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
    GameWindow window;
    window.setModal(true);
    window.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    GameWindow window;
    window.setModal(true);
    window.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    hide();
    GameWindow window;
    window.setModal(true);
    window.exec();
}

void MainWindow::on_pushButton_7_clicked()
{
    GameWindow window;
    window.setModal(true);
    window.exec();
}

void MainWindow::on_pushButton_6_clicked()
{
    GameWindow window;
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
    GameWindow window;
    window.setModal(true);
    window.exec();
}

void MainWindow::on_pushButton_9_clicked()
{
    GameWindow window;
    window.setModal(true);
    window.exec();
}

void MainWindow::on_pushButton_10_clicked()
{
    GameWindow window;
    window.setModal(true);
    window.exec();
}

void MainWindow::on_vozr_clicked()
{

    StudyWindow gwindow;
    gwindow.setModal(true);
    gwindow.exec();
}

void MainWindow::on_impr_clicked()
{
    StudyWindow gwindow;
    gwindow.setModal(true);
    gwindow.exec();
}

void MainWindow::on_post_clicked()
{
    StudyWindow gwindow;
    gwindow.setModal(true);
    gwindow.exec();
}

void MainWindow::on_klas_clicked()
{
    StudyWindow gwindow;
    gwindow.setModal(true);
    gwindow.exec();
}

void MainWindow::on_real_clicked()
{
    StudyWindow gwindow;
    gwindow.setModal(true);
    gwindow.exec();
}

void MainWindow::on_roko_clicked()
{
    StudyWindow gwindow;
    gwindow.setModal(true);
    gwindow.exec();
}

void MainWindow::on_roma_clicked()
{
    StudyWindow gwindow;
    gwindow.setModal(true);
    gwindow.exec();
}

void MainWindow::on_sure_clicked()
{
    StudyWindow gwindow;
    gwindow.setModal(true);
    gwindow.exec();
}

void MainWindow::on_abst_clicked()
{
    StudyWindow gwindow;
    gwindow.setModal(true);
    gwindow.exec();
}

