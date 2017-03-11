#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <string>
#include <QImage>
#include <QPixmap>
#include "winning.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void mouseMoveEvent ( QMouseEvent * event );
    void mousePressEvent ( QMouseEvent * event );
    void mouseReleaseEvent ( QMouseEvent * event );

private slots:
    void ResetBoard();
    void TestBoard();

private:
    void PlayerInfo(void);
    void PlayerWinning();
    Ui::MainWindow *ui;
    bool player = false;    //player1: false
    QImage image1;
    QImage image2;
    QString filePath1 = "D:/QT/Project/0224Wuzi/wuzi/cat2.jpg";
    QString filePath2 = "D:/QT/Project/0224Wuzi/wuzi/photogirl.jpg";


};

#endif // MAINWINDOW_H
