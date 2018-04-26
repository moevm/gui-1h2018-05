#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "studywindow.h"
#include "gamewindow.h"
#include "addpict.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_controller(new Controller(this))
{
    ui->setupUi(this);
    this->showMaximized();
    ui->AddButton->hide();

    connect(m_controller, SIGNAL(dataBaseIsConnected()), this, SLOT(onDataBaseConnected()));
    connect(m_controller, SIGNAL(dataBaseIsDisconnected()), this, SLOT(onDataBaseDisconnected()));

    m_controller->openDataBase();
}

MainWindow::~MainWindow()
{
    delete m_controller;
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    GameWindow window(m_controller, ui->vozrozjdenie_label->text(), this);
    window.setModal(true);
    window.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    GameWindow window(m_controller, ui->impressionism_label->text(), this);
    window.setModal(true);
    window.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    GameWindow window(m_controller, ui->postimpressionism_label->text(), this);
    window.setModal(true);
    window.exec();
}

void MainWindow::on_pushButton_7_clicked()
{
    GameWindow window(m_controller, ui->classicism_label->text(), this);
    window.setModal(true);
    window.exec();
}

void MainWindow::on_pushButton_6_clicked()
{
    GameWindow window(m_controller, ui->realism_label->text(), this);
    window.setModal(true);
    window.exec();
}

void MainWindow::on_pushButton_5_clicked()
{
    GameWindow window(m_controller, ui->simvolism_label->text(), this);
    window.setModal(true);
    window.exec();
}

void MainWindow::on_pushButton_8_clicked()
{
    GameWindow window(m_controller, ui->romantism_label->text(), this);
    window.setModal(true);
    window.exec();
}

void MainWindow::on_pushButton_9_clicked()
{
    GameWindow window(m_controller, ui->surrealism_label->text(), this);
    window.setModal(true);
    window.exec();
}

void MainWindow::on_pushButton_10_clicked()
{
    GameWindow window(m_controller, ui->abstractionism_label->text(), this);
    window.setModal(true);
    window.exec();
}

void MainWindow::on_vozr_clicked()
{
    QString style = ui->vozrozjdenie_label->text();
    StudyWindow gwindow(m_controller, style, this);
    gwindow.setModal(true);
    gwindow.exec();
}

void MainWindow::on_impr_clicked()
{
    QString style = ui->impressionism_label->text();
    StudyWindow gwindow(m_controller, style, this);
    gwindow.setModal(true);
    gwindow.exec();
}

void MainWindow::on_post_clicked()
{
    QString style = ui->postimpressionism_label->text();
    StudyWindow gwindow(m_controller, style, this);
    gwindow.setModal(true);
    gwindow.exec();
}

void MainWindow::on_klas_clicked()
{
    QString style = ui->classicism_label->text();
    StudyWindow gwindow(m_controller, style, this);
    gwindow.setModal(true);
    gwindow.exec();
}

void MainWindow::on_real_clicked()
{
    QString style = ui->realism_label->text();
    StudyWindow gwindow(m_controller, style, this);
    gwindow.setModal(true);
    gwindow.exec();
}

void MainWindow::on_roko_clicked()
{
    QString style = ui->simvolism_label->text();
    StudyWindow gwindow(m_controller, style, this);
    gwindow.setModal(true);
    gwindow.exec();
}

void MainWindow::on_roma_clicked()
{
    QString style = ui->romantism_label->text();
    StudyWindow gwindow(m_controller, style, this);
    gwindow.setModal(true);
    gwindow.exec();
}

void MainWindow::on_sure_clicked()
{
    QString style = ui->surrealism_label->text();
    StudyWindow gwindow(m_controller, style, this);
    gwindow.setModal(true);
    gwindow.exec();
}

void MainWindow::on_abst_clicked()
{
    QString style = ui->abstractionism_label->text();
    StudyWindow gwindow(m_controller, style, this);
    gwindow.setModal(true);
    gwindow.exec();
}

void MainWindow::onDataBaseConnected()
{
    qDebug() << "Database is connected";
}

void MainWindow::onDataBaseDisconnected()
{
    qDebug() << "Database is disconnected";
}


void MainWindow::on_signInPushButton_clicked()
{
    LoginDialog(m_controller, this).exec();
}
