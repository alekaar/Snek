#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QWidget>
#include <QApplication>
#include <QGraphicsScene>
#include "player.h"
#include "fruit.h"
#include "score.h"
#include <QGraphicsView>

class Game: public QGraphicsView
{
public:
    Game(QWidget *parent = 0);
    int getWidth();
    int getHeight();

    QGraphicsScene *s;
    Player *item;

private:
    int w = 800;
    int h = 600;
};

#endif // GAME_H
