#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "taglib/fileref.h"
#include "qstandardpaths.h"
#include "qmediaplayer.h"
#include "qdiriterator.h"

QMediaPlayer* MediaPlayer;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MediaPlayer = new QMediaPlayer;
    std::vector<TagLib::FileRef> songs;

    QString musicFolder = QStandardPaths::standardLocations(QStandardPaths::MusicLocation)[0];
    QDirIterator it(musicFolder, QStringList() << "*.flac", QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext())
    {
        QString fileName = it.next();
        qDebug() << fileName;

        TagLib::FileRef newSong(fileName.toStdString().c_str());
        songs.push_back(newSong);
    }

    ui->TableMusic->setRowCount(songs.size());
    ui->TableMusic->hideColumn(5);

    for(int i = 0; i < songs.size(); i++) {
        QString track = QString::number(songs[i].tag()->track());
        QString title = songs[i].tag()->title().toCString();
        int length = songs[i].audioProperties()->lengthInSeconds();
        QString formattedLength = QString("%1:%2").arg(length/60).arg(length%60); //todo: add 0 for single digit seconds
        QString artist = songs[i].tag()->artist().toCString();
        QString album = songs[i].tag()->album().toCString();
        QString path = songs[i].file()->name();

        QTableWidgetItem* cellTrack = new QTableWidgetItem(); // ui->TableMusic->item(0, 0);
        cellTrack->setText(track);
        QTableWidgetItem* cellTitle = new QTableWidgetItem(); // ui->TableMusic->item(0, 0);
        cellTitle->setText(title);
        QTableWidgetItem* cellLength = new QTableWidgetItem(); // ui->TableMusic->item(0, 0);
        cellLength->setText(formattedLength);
        QTableWidgetItem* cellArtist = new QTableWidgetItem(); // ui->TableMusic->item(0, 0);
        cellArtist->setText(artist);
        QTableWidgetItem* cellAlbum = new QTableWidgetItem(); // ui->TableMusic->item(0, 0);
        cellAlbum->setText(album);
        QTableWidgetItem* cellPath = new QTableWidgetItem(); // ui->TableMusic->item(0, 0);
        cellPath->setText(path);

        ui->TableMusic->setItem(i, 0, cellTrack);
        ui->TableMusic->setItem(i, 1, cellTitle);
        ui->TableMusic->setItem(i, 2, cellLength);
        ui->TableMusic->setItem(i, 3, cellArtist);
        ui->TableMusic->setItem(i, 4, cellAlbum);
        ui->TableMusic->setItem(i, 5, cellPath);
    }



    ui->TableMusic->sortByColumn(0);
    ui->TableMusic->sortByColumn(4);
    ui->TableMusic->sortByColumn(3);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_TableMusic_cellDoubleClicked(int row, int column)
{
    MediaPlayer->stop();

    QString filePath = ui->TableMusic->item(row, 5)->text();
    MediaPlayer->setMedia(QUrl::fromLocalFile(filePath));
    MediaPlayer->setVolume(ui->SliderVolume->value());
    MediaPlayer->play();
}
