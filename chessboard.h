#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QObject>
#include <QFrame>
#include "chesslocation.h"

class ChessBoard : public QFrame
{
    Q_OBJECT
public:
    ChessBoard(QWidget *parent);
    ChessLocation MyLocation;
    bool isWin(bool player);
    int fineFive(int x, int y, bool player);
    int fineFive2(int x, int y, bool player);

private:
    void paintEvent(QPaintEvent * event);


};

#endif // CHESSBOARD_H
