#ifndef BODY_H
#define BODY_H

#include <QGraphicsRectItem>

class Body : public QGraphicsRectItem
{

public:
    explicit Body(QGraphicsRectItem *parent = nullptr);

signals:

public slots:

private:
    int w = 10;
    int h = 10;
};

#endif // BODY_H
