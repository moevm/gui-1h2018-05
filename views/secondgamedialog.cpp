#include "secondgamedialog.h"
#include "ui_secondgamedialog.h"

SecondGameDialog::SecondGameDialog(Controller *controller, QString style, size_t steps, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondGameDialog),
    m_controller(controller),
    m_style(style),
    m_steps(steps),
    m_currentStep(0)
{
    ui->setupUi(this);
    generateQuestion();
}

SecondGameDialog::~SecondGameDialog()
{
    delete ui;
}

void SecondGameDialog::generateQuestion()
{
    ui->artistLabel->clear();
    ui->descriptionLabel->clear();
    ui->answerComboBox->clear();

    QStringList artists = m_controller->getArtistsByStyle(m_style);
    if(artists.size() > 0)
    {

        std::random_device rd;
        std::mt19937 random(rd());

        std::uniform_int_distribution<int> randomArtistIndex(0, artists.size() - 1);
        int artistIndex = randomArtistIndex(random);
        QString artist = artists[artistIndex];

        QStringList allArtistsPictures;
        for(auto artist : artists)
        {
            QStringList artistsPictures = m_controller->getPicturesNamesByArtist(artist);
            allArtistsPictures += artistsPictures;
        }

        QStringList pictures = m_controller->getPicturesNamesByArtist(artist);
        if(pictures.size() > 0)
        {
            std::uniform_int_distribution<int> randomPictureIndex(0, pictures.size() - 1);
            int pictureIndex = randomPictureIndex(random);
            QString pictureTitle = pictures[pictureIndex];
            QString description = m_controller->getPictureYear(artist, pictureTitle);

            m_answer = pictureTitle;

            QString pictureImageName = m_controller->getPictureImageName(artist, pictureTitle);
            QString file = QDir::currentPath() + "/images/" + pictureImageName;
            qDebug() << file;

            QGraphicsScene *scene = new QGraphicsScene(this);
            scene->addPixmap(QPixmap::fromImage(QImage(file)));
            ui->pictureGraphicsView->setScene(scene);
            ui->artistLabel->setText(artist);
            ui->descriptionLabel->setText(description);
            ui->answerComboBox->addItems(allArtistsPictures);
        }
        else
        {
            QMessageBox(QMessageBox::Warning, "Error", "Empty pictures list").exec();
            this->close();
        }
    }
    else
    {
        QMessageBox(QMessageBox::Warning, "Error", "Empty artist list").exec();
        this->close();
    }
}

void SecondGameDialog::on_exitPushButton_clicked()
{
    this->close();
}

void SecondGameDialog::on_nextPushButton_clicked()
{
    if(ui->answerComboBox->currentText() == m_answer)
    {
        m_currentStep++;
        if(m_steps == m_currentStep)
        {
            QMessageBox(QMessageBox::Information, "Win", "You are win!").exec();
            this->close();
        }
        else
        {
            QMessageBox(QMessageBox::Information, "Correct", "Awesome! You are right!").exec();
            generateQuestion();
        }
    }
    else
    {
        QMessageBox(QMessageBox::Critical, "Incorrect", "Sorry. Try again").exec();
        generateQuestion();
    }
}
