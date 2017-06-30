#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "taglib/fileref.h"
#include "qstandardpaths.h"
#include "qmediaplayer.h"
#include "qmediametadata.h"
#include "qmediaplaylist.h"
#include "qmediacontent.h"
#include "qdiriterator.h"
#include "taglib/id3v2tag.h"

QMediaPlayer* MediaPlayer;
QMediaPlaylist* MediaPlaylist;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //void on_MediaPlayer_stateChanged(QMediaPlayer::State);
    ui->setupUi(this);
    MediaPlayer = new QMediaPlayer;
    MediaPlaylist = new QMediaPlaylist;

    MediaPlayer->setPlaylist(MediaPlaylist);

    std::vector<TagLib::FileRef> songs;

    //Scans and loads music files. Consider making this its own function/class/file
    QString musicFolder = QStandardPaths::standardLocations(QStandardPaths::MusicLocation)[0];
    QDirIterator it(musicFolder, QStringList() << "*.flac" << "*.mp3", QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext())
    {
        QString fileName = it.next();
        qDebug() << fileName;

        TagLib::FileRef newSong(fileName.toStdString().c_str());
        songs.push_back(newSong);
    }

    ui->TableMusic->setRowCount(songs.size()+1);
    ui->TableMusic->hideColumn(6);
    ui->TableMusic->hideColumn(7);

    for(int i = 0; i < songs.size(); i++) {
        int track = songs[i].tag()->track();
        QString title = songs[i].tag()->title().toCString();
        int length = songs[i].audioProperties()->lengthInSeconds();
        QString formattedLength = QString("%1:%2").arg(length/60).arg(QString("%1").arg(length%60, 2, 10, QChar('0')));
        QString artist = songs[i].tag()->artist().toCString();
        QString album = songs[i].tag()->album().toCString();
        QString path = songs[i].file()->name();
        QString genre = songs[i].tag()->genre().toCString();


        QTableWidgetItem* cellTrack = new QTableWidgetItem(); cellTrack->setTextAlignment(Qt::AlignCenter|Qt::AlignRight);
        cellTrack->setData(Qt::EditRole, track);
        QTableWidgetItem* cellTitle = new QTableWidgetItem();
        cellTitle->setText(title);
        QTableWidgetItem* cellLength = new QTableWidgetItem(); cellLength->setTextAlignment(Qt::AlignCenter|Qt::AlignRight);
        cellLength->setText(formattedLength);
        QTableWidgetItem* cellArtist = new QTableWidgetItem();
        cellArtist->setText(artist);
        QTableWidgetItem* cellAlbum = new QTableWidgetItem();
        cellAlbum->setText(album);
        QTableWidgetItem* cellPath = new QTableWidgetItem();
        cellPath->setText(path);
        QTableWidgetItem* cellGenre = new QTableWidgetItem();
        cellGenre->setText(genre);
        QTableWidgetItem* cellID = new QTableWidgetItem();
        cellGenre->setData(Qt::EditRole, i);

        ui->TableMusic->setItem(i, 0, cellTrack);
        ui->TableMusic->setItem(i, 1, cellTitle);
        ui->TableMusic->setItem(i, 2, cellLength);
        ui->TableMusic->setItem(i, 3, cellArtist);
        ui->TableMusic->setItem(i, 4, cellAlbum);
        ui->TableMusic->setItem(i, 5, cellGenre);
        ui->TableMusic->setItem(i, 6, cellPath);
        ui->TableMusic->setItem(i, 7, cellID);
    }

    //todo: find each song's image
    QPixmap pixmap("/home/Andres/Music/Led_Zeppelin-Mothership-Remastered-2CD-FLAC-2015-PERFECT/front.jpg");

    ui->ImageView->setPixmap(pixmap.scaled(256, 256, Qt::KeepAspectRatio));


    ui->TableMusic->sortByColumn(0, Qt::SortOrder::AscendingOrder);
    ui->TableMusic->sortByColumn(4);
    ui->TableMusic->sortByColumn(3);

    //ui->TableMusic->columnAt(1).

    ui->TableMusic->resizeColumnsToContents();

    connect(MediaPlayer, SIGNAL(stateChanged(QMediaPlayer::State)), this, SLOT(on_MediaPlayer_stateChanged(QMediaPlayer::State)));
    connect(MediaPlayer, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), this, SLOT(on_MediaPlayer_mediaStatusChanged(QMediaPlayer::MediaStatus)));
    connect(MediaPlayer, SIGNAL(positionChanged(qint64)), this, SLOT(on_MediaPlayer_positionChanged(qint64)));
    //QObject::connect(&MediaPlayer, SIGNAL(stateChanged(QMediaPlayer::State)));
    //MediaPlayer->stateChanged(QMediaPlayer::state() {}); state);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_TableMusic_cellDoubleClicked(int row, int column)
{
    MediaPlaylist->clear();

    int row_iter = row-1;
    while(row_iter++ < ui->TableMusic->rowCount()-2 )// && row_iter - row < 10)
    {
        QString filePath = ui->TableMusic->item(row_iter, 6)->text();
        MediaPlaylist->addMedia(QUrl::fromLocalFile(filePath));
    }

    MediaPlayer->play();
}

void MainWindow::on_SliderVolume_sliderMoved(int position)
{
    MediaPlayer->setVolume(position);
}

void MainWindow::on_ButtonToggle_clicked()
{
    (MediaPlayer->state() == QMediaPlayer::PlayingState) ?
                (MediaPlayer->pause(), ui->ButtonToggle->setIcon(QIcon(":/Images/Images/Player_Play.png"))) :
                (MediaPlayer->play(), ui->ButtonToggle->setIcon(QIcon(":/Images/Images/Player_Pause.png")));
}

void MainWindow::on_ButtonNext_clicked()
{

    //todo: read from queue instead of just next song in table
//    ui->TableMusic->selectRow(ui->TableMusic->currentRow()+1);
//    QString nextFilePath = ui->TableMusic->item(ui->TableMusic->currentRow(), 6)->text();
//    MediaPlayer->setMedia(QUrl::fromLocalFile(nextFilePath));
//    MediaPlayer->play();

      MediaPlaylist->next();
}

void MainWindow::on_ButtonPrev_clicked()
{
    //todo: read from queue instead of just previous song in table
//    ui->TableMusic->selectRow(ui->TableMusic->currentRow()-1);
//    QString nextFilePath = ui->TableMusic->item(ui->TableMusic->currentRow(), 6)->text();
//    MediaPlayer->setMedia(QUrl::fromLocalFile(nextFilePath));
//    MediaPlayer->play();

    MediaPlaylist->previous();
}

void MainWindow::on_MediaPlayer_stateChanged(QMediaPlayer::State state)
{
    if(state == QMediaPlayer::PlayingState)
    {
        ui->ButtonToggle->setIcon(QIcon(":/Images/Images/Player_Pause.png"));
        //qDebug() << ui->TableMusic->item(ui->TableMusic->currentRow(), 2)->text();
        QString lengthStr = ui->TableMusic->item(ui->TableMusic->currentRow(), 2)->text();
        int length = lengthStr.split(':')[0].toInt() * 60 + lengthStr.split(':')[1].toInt();
        //qDebug() << length;
        ui->SliderSeekTrack->setRange(0, length);


        qDebug() << "URL:";
        qDebug() << MediaPlayer->media().resources().first().url().path(); //media.resources.first().url().path()//MediaPlayer->currentMedia().canonicalUrl().toString();


        ui->LabelSongInfo->setText("okay"); //MediaPlayer->metaData(QMediaMetaData::AlbumArtist).toString());
        ui->LabelTimeEnd->setText(MediaPlayer->metaData(QMediaMetaData::Duration).toString());
    }
    else if(state == QMediaPlayer::PausedState)
        ui->ButtonToggle->setIcon(QIcon(":/Images/Images/Player_Play.png"));
    else if(state ==QMediaPlayer::StoppedState)
    {

    }
}

void MainWindow::on_MediaPlayer_positionChanged(qint64 position)
{
    int time = position/1000;
    ui->SliderSeekTrack->setValue(time);
    ui->LabelTimeCurrent->setText(QString("%1:%2").arg(time/60).arg(QString("%1").arg(time%60, 2, 10, QChar('0'))));

    //qDebug() << MediaPlayer->isMetaDataAvailable();
    //qDebug() << MediaPlayer->metaData(QMediaMetaData::Duration).toString();
}

void MainWindow::on_SliderSeekTrack_sliderReleased()
{
    MediaPlayer->setPosition(ui->SliderSeekTrack->value()*1000);
}

void MainWindow::on_MediaPlayer_mediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    //qDebug() << "Media NOT loaded";
    if(status == QMediaPlayer::LoadedMedia)
    {
        qDebug() << "Media loaded";
        qDebug() << MediaPlayer->metaData(QMediaMetaData::AlbumTitle);
    }
    qDebug() << status;
    qDebug() << MediaPlayer->media().resources().first().url().path();
}
