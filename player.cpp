#include "player.h"
#include "fruit.h"
#include <QDebug>
#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsScene>

Player::Player(){
    setRect(0, 0, 10, 10);
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this,SLOT(move()));
    timer->start(50);
    d = left;
}

void Player::keyPressEvent(QKeyEvent *event)
{
    //left
    if(event->key() == Qt::Key_Left && d != right){
        d = left;
    }
    //Right
    else if(event->key() == Qt::Key_Right && d != left){
        d = right;
    }
    //Up
    else if(event->key() == Qt::Key_Up && d != down){
        d = up;
    }
    //Down
    else if(event->key() == Qt::Key_Down && d != up){
        d = down;
    }
}

void Player::move()
{
    QList<QGraphicsItem *> coll = collidingItems();

    //check for collision
    for(int i = 0; i < coll.size(); i++){
        if(typeid(*coll[i]) == typeid(Fruit)){
            scene()->removeItem(coll[i]);
            delete coll[i];
            Fruit *fruit = new Fruit();
            scene()->addItem(fruit);
        }
    }

    if(d == left && pos().x() > 0){
        setPos(x()-10, y());
    }
    else if(d == right && pos().x() + 100 < 800){
        setPos(x()+10, y());
    }
    else if(d == up){
        setPos(x(), y()-10);
    }
    else if(d == down){
        setPos(x(), y()+10);
    }
}
