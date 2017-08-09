#include <QApplication>
#include <QGraphicsScene>
#include "player.h"
#include "fruit.h"
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene *s = new QGraphicsScene();

    //create player
    Player *item = new Player();
    Fruit *fruit = new Fruit();

    //add player
    s->addItem(item);
    s->addItem(fruit);

    //make player focus
    item->setFlag(QGraphicsItem::ItemIsFocusable);
    item->setFocus();

    QGraphicsView *view = new QGraphicsView(s);

    //create fixed window
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
    view->setFixedSize(800, 600);
    s->setSceneRect(0,0,800,600);

    item->setPos(view->width()/2, view->height()/2);
    return a.exec();
}
