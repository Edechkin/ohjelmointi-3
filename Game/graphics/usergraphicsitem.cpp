#include "usergraphicsitem.hh"

#include <QKeyEvent>

namespace Student {

UserGraphicsItem::UserGraphicsItem(QGraphicsItem *parent):
    QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/player.png").scaled(QSize(90, 90)));

    setTransformOriginPoint(45,45);

}

void UserGraphicsItem::keyPressEvent(QKeyEvent *event){
    // move the player left and right
    if (event->key() == Qt::Key_A){
        if (pos().x() - 10 > 0) {
            setPos(x()-2,y());
            setRotation(180);
        }
    }
    else if (event->key() == Qt::Key_D){
        if (pos().x() + 10 < 405){
            setPos(x()+2,y());
            setRotation(0);
        }
    }
    else if (event->key() == Qt::Key_W){
        if (pos().y() - 10 > 0){
            setPos(x(),y()-2);
            setRotation(270);
        }
    }
    else if (event->key() == Qt::Key_S){
        if (pos().y() + 10 < 405){
            setPos(x(),y()+2);
            setRotation(90);
        }
    }
}

}
