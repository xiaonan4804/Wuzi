#ifndef CHESSLOCATION_H
#define CHESSLOCATION_H

#define WIDTH 10
#define HEIGH 10

class ChessLocation
{
public:
    ChessLocation();

    int width = WIDTH;
    int height = WIDTH;
    int Location[WIDTH][WIDTH];

};

#endif // CHESSLOCATION_H
