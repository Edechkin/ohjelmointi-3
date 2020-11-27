#include "bomb.hh"

#include <QTimer>

namespace Student {

Bomb::Bomb(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/explosion-14100.png").scaled(QSize(35, 35)));

    this->setZValue(1);

    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(remove()));

    timer->start(1000);
}

void Bomb::remove()
{
    delete this;
}

}
