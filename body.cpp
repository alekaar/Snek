#include "body.h"
#include <QBrush>

Body::Body(QGraphicsRectItem *parent)
{
    setRect(0, 0, w, h);
    QBrush br;

    //Paint body green
    br.setStyle(Qt::SolidPattern);
    br.setColor(Qt::blue);
    setBrush(br);
}
