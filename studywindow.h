#ifndef STUDYWINDOW_H
#define STUDYWINDOW_H

#include <QDialog>

namespace Ui {
class StudyWindow;
}

class StudyWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StudyWindow(QWidget *parent = 0);
    ~StudyWindow();

private:
    Ui::StudyWindow *ui;
};

#endif // STUDYWINDOW_H
