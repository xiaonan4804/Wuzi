#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->resize(1000, 800);
    ui->frame->setGeometry(10, 10, 600, 600);
    this->resize(1000, 800);
    ui->pushButton_reset->setGeometry(700, 20, 75, 25);
    ui->pushButton_test->setGeometry(700, 50, 75, 25);
    ui->lineEdit_position->setGeometry(700,80, 150, 20);

    this->centralWidget()->setMouseTracking(true);
    this->setMouseTracking(true);
    ui->frame->setMouseTracking(true);

    connect(ui->pushButton_reset, SIGNAL(clicked(bool)), this, SLOT(ResetBoard()));
    connect(ui->pushButton_test, SIGNAL(clicked(bool)), this, SLOT(TestBoard()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ResetBoard()
{
    qDebug("reset pressed\n");
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
    ui->frame->MyLocation.Location[5][5] = 1;
    ui->frame->MyLocation.Location[4][4] = -1;
    ui->frame->update();

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
            player = true;
        }
        else
        {
            ui->frame->MyLocation.Location[(pos.x()-10)/60][(pos.y()-10)/60] = -1;
            player = false;
        }
        ui->frame->update();
    }

}

