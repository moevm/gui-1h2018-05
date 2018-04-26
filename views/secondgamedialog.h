#ifndef SECONDGAMEDIALOG_H
#define SECONDGAMEDIALOG_H

#include <QDialog>

#include "controllers/controller.h"

namespace Ui {
class SecondGameDialog;
}

class SecondGameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SecondGameDialog(Controller *controller, QString style, size_t steps, QWidget *parent = 0);
    ~SecondGameDialog();

private slots:
    void on_exitPushButton_clicked();

    void on_nextPushButton_clicked();

private:
    Ui::SecondGameDialog *ui;
    Controller* m_controller;
    QString m_style;
    size_t m_steps;
    size_t m_currentStep;

    void generateQuestion();

    QString m_answer;
};

#endif // SECONDGAMEDIALOG_H
