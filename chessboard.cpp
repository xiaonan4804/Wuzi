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
                pen.setWidth(20);
                painter.setPen(pen);
                painter.drawEllipse(i*60+20, j*60+20, 20, 20);
            }
            if (MyLocation.Location[i][j] == -1)
            {
                QPen pen(GreenColor);
                pen.setWidth(20);
                painter.setPen(pen);
                painter.drawEllipse(i*60+20, j*60+20, 20, 20);
            }
        }

    }
}
/*判断横竖斜，是否有5个连续棋子
输入：坐标和玩家， 输出1/0*/
int ChessBoard::fineFive(int x, int y, bool player)
{
    int count1=0;
    int count2=0;
    int count3=0;
    for (int i=0; i<5; i++)
    {
        if (player==false && MyLocation.Location[x+i][y]==1)
        {
            count1++;
        }
        else if (player==true && MyLocation.Location[x+i][y]==-1)
        {
            count1++;
        }
        else
        {
            break;
        }
    }
    for (int i=0; i<5; i++)
    {
        if (player==false && MyLocation.Location[x][y+i]==1)
        {
            count2++;
        }
        else if (player==true && MyLocation.Location[x][y+i]==-1)
        {
            count2++;
        }
        else
        {
            break;
        }
    }
    for (int i=0; i<5; i++)
    {
        if (player==false && MyLocation.Location[x+i][y+i]==1)
        {
            count3++;
        }
        else if (player==true && MyLocation.Location[x+i][y+i]==-1)
        {
            count3++;
        }
        else
        {
            break;
        }
    }

    if (count1==5 || count2==5 || count3==5)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*判断左斜，是否有5个连续棋子
输入：坐标和玩家， 输出1/0*/
int ChessBoard::fineFive2(int x, int y, bool player)
{
    int count4=0;
    for (int i=0; i<5; i++)
    {
        if (player==false && MyLocation.Location[x-i][y+i]==1)
        {
            count4++;
        }
        else if (player==true && MyLocation.Location[x-i][y+i]==-1)
        {
            count4++;
        }
        else
        {
            break;
        }
    }
    if (count4==5)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

/*扫描所有棋盘，调用findFive判断是否有5连子
输入：当前玩家， 输出：true/false*/
bool ChessBoard::isWin(bool player)
{
    for (int i=0; i<WIDTH; i++)
    {
        for (int j=0; j<HEIGH; j++)
        {
            int ret = fineFive(i, j, player);
            if (ret == 1)
            {
                return true;
            }
        }
    }

    for (int i=0; i<WIDTH; i++)
    {
        for (int j=0; j<HEIGH; j++)
        {
            int ret = fineFive2(i, j, player);
            if (ret == 1)
            {
                return true;
            }
        }
    }
    return false;
}



