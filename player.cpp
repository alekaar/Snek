#include "player.h"
#include <QDebug>
#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsScene>
#include "game.h"

extern Game *game;
extern Score *score;
extern Fruit *fruit;

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
    if(event->key() == Qt::Key_Left && d != right && prev != pos()){
        d = left;
        prev = pos();
    }
    //Right
    else if(event->key() == Qt::Key_Right && d != left && prev != pos()){
        d = right;
        prev = pos();
    }
    //Up
    else if(event->key() == Qt::Key_Up && d != down && prev != pos()){
        d = up;
        prev = pos();
    }
    //Down
    else if(event->key() == Qt::Key_Down && d != up && prev != pos()){
        d = down;
        prev = pos();
    }
}

void Player::move()
{
    prev = pos();
    //check for collision
    if(pos() == fruit->pos()){
        //remove
        scene()->removeItem(fruit);
        delete fruit;
        score->scored();
        //new fruit
        fruit = new Fruit();
        scene()->addItem(fruit);
        grow();
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

    if(!tail.isEmpty()){
        for(int i = 0; i < tail.size(); i++){
            if(pos() == tail[i]->pos()){
                qDebug() << i;
                timer->stop();
            }
        }
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
