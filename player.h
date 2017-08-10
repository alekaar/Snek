#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QObject>

class Player: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Player();
    void keyPressEvent(QKeyEvent *event);
    enum Dir{left, right, up, down};
public slots:
    void move();
private:
    enum Player::Dir d;
    int w = 10;
    int h = 10;

};


#endif // PLAYER_H
