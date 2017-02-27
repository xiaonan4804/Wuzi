#include "chesslocation.h"

ChessLocation::ChessLocation()
{
    for (int i=0; i<this->width; i++)
    {
        for (int j=0; j<this->height; j++)
        {
            Location[i][j] = 0;
        }
    }

}
