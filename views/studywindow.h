#ifndef STUDYWINDOW_H
#define STUDYWINDOW_H

#include <QDialog>
#include <QListWidgetItem>
#include "controllers/controller.h"

namespace Ui {
class StudyWindow;
}

class StudyWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StudyWindow(Controller* controller, QString style, QWidget *parent = 0);
    ~StudyWindow();

private slots:
    void on_listArtist_itemClicked(QListWidgetItem *item);

    void on_next_clicked();

    void on_previous_clicked();

private:
    Ui::StudyWindow *ui;
    Controller* m_controller;
    QString m_style;
    QStringList m_artists;
    QString m_currentArtist;
    QStringList m_currentArtistPicturesNames;
    QStringList m_currentArtistPicturesImages;
    size_t m_currentPictureIndex;

    void openPicture();
};

#endif // STUDYWINDOW_H
