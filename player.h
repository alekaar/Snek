#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QList>
#include <QPointF>
#include "body.h"

class Player: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Player();
    void keyPressEvent(QKeyEvent *event);
    enum Dir{left, right, up, down};
    void moveTail();
    void grow();

public slots:
    void move();

private:
    enum Player::Dir d;
    int w = 10;
    int h = 10;
    QList<Body*> tail;
    QPointF prev;
    QTimer *timer;

};


#endif // PLAYER_H
