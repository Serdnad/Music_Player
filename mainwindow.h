#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qmediaplayer.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_TableMusic_cellDoubleClicked(int row, int column);

    void on_SliderVolume_sliderMoved(int position);

    void on_ButtonToggle_clicked();

    void on_ButtonNext_clicked();

    void on_ButtonPrev_clicked();

    void on_MediaPlayer_stateChanged(QMediaPlayer::State state);
    void on_MediaPlayer_positionChanged(qint64 position);
    void on_MediaPlayer_mediaStatusChanged(QMediaPlayer::MediaStatus status);

    void on_SliderSeekTrack_sliderReleased();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
