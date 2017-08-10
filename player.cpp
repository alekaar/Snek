#include "player.h"
#include <QDebug>
#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsScene>
#include "game.h"

extern Game *game;
extern Score *score;

Player::Player(){
    setRect(0, 0, w, h);
    QBrush br;

    //Paint head green
    br.setStyle(Qt::SolidPattern);
    br.setColor(Qt::green);
    setBrush(br);

    //moves the player
    timer = new QTimer();
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

    prev = pos();
    //check for collision
    for(int i = 0; i < coll.size(); i++){
        if(typeid(*coll[i]) == typeid(Fruit)){
            //remove
            scene()->removeItem(coll[i]);
            delete coll[i];
            score->scored();
            //new fruit
            Fruit *fruit = new Fruit();
            scene()->addItem(fruit);
            grow();
        }
        else if(typeid(*coll[i]) == typeid(Body)){
            //timer->stop();
        }
    }


    if(d == left && pos().x() > 0){
        setPos(x()-w, y());
    }
    else if(d == right && pos().x() + w < game->getWidth()){
        setPos(x()+w, y());
    }
    else if(d == up && pos().y() > 0){
        setPos(x(), y()-h);
    }
    else if(d == down && pos().y() + h < game->getHeight()){
        setPos(x(), y()+h);
    }
    moveTail();
}

//grow snek
void Player::grow(){
    Body *b = new Body();
    tail.prepend(b);
    game->scene()->addItem(b);
}

//move the snek
void Player::moveTail(){
    for(int i = 0; i < tail.size() - 1; i++){
        tail[i]->setPos(tail[i+1]->pos());
    }
    if(!tail.isEmpty()){
        tail.last()->setPos(prev);
    }
}
