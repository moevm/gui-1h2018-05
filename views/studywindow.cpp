#include "studywindow.h"
#include "ui_studywindow.h"

StudyWindow::StudyWindow(Controller *controller, QString style, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudyWindow),
    m_controller(controller),
    m_style(style)
{
    ui->setupUi(this);
    this->showMaximized();

    m_artists = m_controller->getArtistsByStyle(m_style);
    ui->listArtist->addItems(m_artists);

    ui->graphicsView->setScene(new QGraphicsScene(this));
    ui->windowTitleLabel->setText(m_style);
}

StudyWindow::~StudyWindow()
{
    delete ui;
}

void StudyWindow::on_listArtist_itemClicked(QListWidgetItem *item)
{
    m_currentArtist = item->text();
    m_currentArtistPicturesNames = m_controller->getPicturesNamesByArtist(m_currentArtist);
    m_currentArtistPicturesImages = m_controller->getPicturesImagesByArtist(m_currentArtist);

    qDebug() << m_currentArtist;
    qDebug() << m_currentArtistPicturesNames;
    qDebug() << m_currentArtistPicturesImages;

    m_currentPictureIndex = 0;

    openPicture();
}

void StudyWindow::openPicture()
{
    QString file = QDir::currentPath() + "/images/" +
            m_controller->getPictureImageName(m_currentArtist,
                                              m_currentArtistPicturesNames.operator [](m_currentPictureIndex));
    qDebug() << file;

    //QMessageBox(QMessageBox::Information, "path", file).exec();

    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->addPixmap(QPixmap::fromImage(QImage(file)));
    ui->graphicsView->setScene(scene);
    ui->titleLabel->setText(m_currentArtistPicturesNames.operator [](m_currentPictureIndex));

    ui->yearLabel->setText(m_controller->getPictureYear(m_currentArtist, m_currentArtistPicturesNames.operator [](m_currentPictureIndex)));
}

void StudyWindow::on_next_clicked()
{
    if((int)(m_currentPictureIndex+1) < m_currentArtistPicturesNames.size() &&
       (int)(m_currentPictureIndex+1) < m_currentArtistPicturesImages.size())
    {
        m_currentPictureIndex++;
        openPicture();
    }
}

void StudyWindow::on_previous_clicked()
{
    if((int)(m_currentPictureIndex-1) >= 0 &&
       (int)(m_currentPictureIndex-1) < m_currentArtistPicturesImages.size() &&
       (int)(m_currentPictureIndex-1) < m_currentArtistPicturesNames.size())
    {
        m_currentPictureIndex--;
        openPicture();
    }
}
