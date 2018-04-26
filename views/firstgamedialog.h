#ifndef FIRSTGAMEDIALOG_H
#define FIRSTGAMEDIALOG_H

#include <QDialog>

#include "controllers/controller.h"

namespace Ui {
class FirstGameDialog;
}

class FirstGameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FirstGameDialog(Controller* controller, QString style, size_t steps = 3, QWidget *parent = 0);
    ~FirstGameDialog();

private slots:
    void on_exitPushButton_clicked();

    void on_applyPushButton_clicked();

private:
    Ui::FirstGameDialog *ui;

    Controller* m_controller;
    QString m_style;
    size_t m_steps;
    size_t m_currentStep;

    void startGame();

    void generateQuestion();

    QString m_answer;
};

#endif // FIRSTGAMEDIALOG_H
