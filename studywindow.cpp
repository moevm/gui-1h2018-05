#include "studywindow.h"
#include "ui_studywindow.h"

StudyWindow::StudyWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudyWindow)
{
    ui->setupUi(this);
}

StudyWindow::~StudyWindow()
{
    delete ui;
}
