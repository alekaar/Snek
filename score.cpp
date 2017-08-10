#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    score = 0;

    setPlainText(QString("Points: ") + QString::number(score));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 14));
}

void Score::scored()
{
    score += 10;
}

int Score::getScore()
{
    return score;
}


