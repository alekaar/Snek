#include "game.h"

Game::Game(QWidget *parent)
{
    s = new QGraphicsScene();
    //create player
    item = new Player();
    fruit = new Fruit();

    //add player
    s->addItem(item);
    s->addItem(fruit);

    //make player focus
    item->setFlag(QGraphicsItem::ItemIsFocusable);
    item->setFocus();

    //create fixed window
    setScene(s);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setFixedSize(w, h);
    s->setSceneRect(0,0,w,h);

    item->setPos(width()/2, height()/2);
    show();
}

int Game::getWidth()
{
    return w;
}

int Game::getHeight()
{
    return h;
}
