#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDebug>
#include <QFont>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    /*初始化窗口大小和位置*/
    ui->setupUi(this);
    ui->centralWidget->resize(1000, 800);
    ui->frame->setGeometry(10, 10, 600, 600);
    this->resize(1000, 800);
    ui->pushButton_reset->setGeometry(700, 20, 75, 25);
    ui->pushButton_test->setGeometry(700, 50, 75, 25);
    ui->lineEdit_position->setGeometry(700,80, 150, 20);
    ui->label_pic1->setGeometry(700, 120, 200, 200);
    ui->label_pic2->setGeometry(700, 120, 200, 200);
    ui->label_playerN->setGeometry(700, 350, 150, 50);

    /*鼠标事件*/
    this->centralWidget()->setMouseTracking(true);
    this->setMouseTracking(true);
    ui->frame->setMouseTracking(true);

    /*头像图片*/
    image1.load(filePath1);
    image2.load(filePath2);
    ui->label_pic1->setPixmap(QPixmap::fromImage(image1.scaled(1080/8, 1622/8)));
    ui->label_pic2->setPixmap(QPixmap::fromImage(image2.scaled(1080/8, 1622/8)));
    ui->label_pic1->setVisible(true);
    ui->label_pic2->setVisible(false);
    //QFont font(24);
    //ui->label_playerN->setFont(font);

    connect(ui->pushButton_reset, SIGNAL(clicked(bool)), this, SLOT(ResetBoard()));
    connect(ui->pushButton_test, SIGNAL(clicked(bool)), this, SLOT(TestBoard()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ResetBoard()
{
    //qDebug("reset pressed\n");
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            ui->frame->MyLocation.Location[i][j] = 0;
        }
    }
    ui->frame->update();
}

void MainWindow::TestBoard()
{
    qDebug("test pressed\n");

}

void MainWindow::mouseMoveEvent ( QMouseEvent * event )
{
    QPoint pos = event->pos();
    ui->lineEdit_position->setText("Position: (" + QString::number(pos.x()) + ", " + QString::number(pos.y()) + ")");
}
void MainWindow::mousePressEvent ( QMouseEvent * event )
{


}
void MainWindow::mouseReleaseEvent ( QMouseEvent * event )
{
    QPoint pos = event->pos();
    if (ui->frame->MyLocation.Location[(pos.x()-10)/60][(pos.y()-10)/60] == 0 &&
            pos.x()<=610 && pos.y()<=610)
    {
        if (player == false)
        {
            ui->frame->MyLocation.Location[(pos.x()-10)/60][(pos.y()-10)/60] = 1;
            ui->frame->update();
            PlayerInfo();
            bool iswin = ui->frame->isWin(player);
            if (iswin == true)
            {
                PlayerWinning();
            }
            player = true;
        }
        else
        {
            ui->frame->MyLocation.Location[(pos.x()-10)/60][(pos.y()-10)/60] = -1;
            ui->frame->update();
            PlayerInfo();
            bool iswin = ui->frame->isWin(player);
            if (iswin == true)
            {
                PlayerWinning();
            }
            player = false;
        }
    }
}

void MainWindow::PlayerInfo(void)
{
    if (player==false)      //player1
    {
        ui->label_pic1->setVisible(true);
        ui->label_pic2->setVisible(false);
        ui->label_playerN->setText("Player 1");
    }
    else            //player2
    {
        ui->label_pic1->setVisible(false);
        ui->label_pic2->setVisible(true);
        ui->label_playerN->setText("Player 2");
    }

}

void MainWindow::PlayerWinning()
{
    Winning PlayerWin(player, this);

    int ret = PlayerWin.exec();
    if (ret == PlayerWin.Accepted)
    {
        ResetBoard();
        player = false;
    }
    else if(ret == PlayerWin.Rejected)
    {
        exit(0);
    }

}

