#include "fruit.h"
#include <stdlib.h>

Fruit::Fruit()
{
    setRect(0,0,10,10);
    int randx = (rand() % 70) * 10;
    int randy = (rand() % 50) * 10;
    setPos(randx, randy);
}
