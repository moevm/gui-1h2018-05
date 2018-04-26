#include "firstgamedialog.h"
#include "ui_firstgamedialog.h"

FirstGameDialog::FirstGameDialog(Controller *controller, QString style, size_t steps, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FirstGameDialog),
    m_controller(controller),
    m_style(style),
    m_steps(steps),
    m_currentStep(0)
{
    ui->setupUi(this);
    generateQuestion();
}

FirstGameDialog::~FirstGameDialog()
{
    delete ui;
}

void FirstGameDialog::startGame()
{

}

void FirstGameDialog::generateQuestion()
{
    ui->pictureLabel->clear();
    ui->answerComboBox->clear();

    QStringList artists = m_controller->getArtistsByStyle(m_style);
    if(artists.size() > 0)
    {

        std::random_device rd;
        std::mt19937 random(rd());

        std::uniform_int_distribution<int> randomArtistIndex(0, artists.size() - 1);
        int artistIndex = randomArtistIndex(random);
        QString artist = artists[artistIndex];

        m_answer = artist;

        QStringList pictures = m_controller->getPicturesNamesByArtist(artist);
        if(pictures.size() > 0)
        {
            std::uniform_int_distribution<int> randomPictureIndex(0, pictures.size() - 1);
            int pictureIndex = randomPictureIndex(random);
            QString pictureTitle = pictures[pictureIndex];

            QString pictureImageName = m_controller->getPictureImageName(artist, pictureTitle);
            QString file = QDir::currentPath() + "/images/" + pictureImageName;
            qDebug() << file;

            //QMessageBox(QMessageBox::Information, "path", file).exec();

            QGraphicsScene *scene = new QGraphicsScene(this);
            scene->addPixmap(QPixmap::fromImage(QImage(file)));
            ui->pictureGraphicsView->setScene(scene);
            ui->pictureLabel->setText(pictureTitle);
            ui->answerComboBox->addItems(artists);
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

void FirstGameDialog::on_exitPushButton_clicked()
{
    this->close();
}

void FirstGameDialog::on_applyPushButton_clicked()
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
