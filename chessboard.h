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

private:
    void paintEvent(QPaintEvent * event);


};

#endif // CHESSBOARD_H
