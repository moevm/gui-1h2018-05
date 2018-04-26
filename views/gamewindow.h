#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>

#include "controllers/controller.h"

#include "views/firstgamedialog.h"
#include "views/secondgamedialog.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GameWindow(Controller* controller, QString style, QWidget *parent = 0);
    ~GameWindow();

private slots:
    void on_ButtonGame1_clicked();

    void on_ButtonGame2_clicked();

private:
    Ui::GameWindow *ui;
    Controller* m_controller;
    QString m_style;
};

#endif // GAMEWINDOW_H
