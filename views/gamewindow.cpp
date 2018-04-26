#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(Controller *controller, QString style, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWindow),
    m_controller(controller),
    m_style(style)
{
    ui->setupUi(this);
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::on_ButtonGame1_clicked()
{
    FirstGameDialog(m_controller, m_style, 3, this).exec();
}

void GameWindow::on_ButtonGame2_clicked()
{
    SecondGameDialog(m_controller, m_style, 3, this).exec();
}
