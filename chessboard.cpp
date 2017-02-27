#include "chessboard.h"
#include <QPainter>

ChessBoard::ChessBoard(QWidget *parent)
    : QFrame(parent)
{

}

void ChessBoard::paintEvent(QPaintEvent * event)
{
    QPainter painter(this);
    int width = this->width();
    int height = this->height();

    QColor LineColor(28, 23, 179);     //green
    QColor RedColor(255, 0, 0);     //green
    QColor GreenColor(0, 255, 0);     //green
    QPen pen(LineColor);
    pen.setWidth(2);
    painter.setPen(pen);

    for (int i=0; i<=width; i+=60)
    {
        painter.drawLine(0, i, width, i);
        painter.drawLine(i, 0, i, height);
    }

    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            if (MyLocation.Location[i][j] == 1)
            {
                QPen pen(RedColor);
                pen.setWidth(4);
                painter.setPen(pen);
                painter.drawEllipse(i*60+10, j*60+10, 40, 40);
            }
            if (MyLocation.Location[i][j] == -1)
            {
                QPen pen(GreenColor);
                pen.setWidth(4);
                painter.setPen(pen);
                painter.drawEllipse(i*60+10, j*60+10, 40, 40);
            }
        }

    }



}





