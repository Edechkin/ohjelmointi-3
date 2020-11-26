#include "bomb.hh"

#include <QTimer>

namespace Student {

Bomb::Bomb(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/explosion.png").scaled(QSize(30, 30)));

    this->setZValue(1);

    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(remove()));
}

void Bomb::remove()
{

}

}
