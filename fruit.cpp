#include "fruit.h"
#include <stdlib.h>

Fruit::Fruit()
{
    setRect(0,0,10,10);
    int randx = (rand() / 10) % 700;
    int randy = (rand() / 10) % 500;
    setPos(randx, randy);
}
