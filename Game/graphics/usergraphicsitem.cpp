#include "usergraphicsitem.hh"

namespace Student {

UserGraphicsItem::UserGraphicsItem(QGraphicsItem *parent) :
    QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/player.png").scaled(QSize(90, 90)));

    this->setZValue(2);
    setTransformOriginPoint(53,43);

}

bool UserGraphicsItem::move(char dir)
{
    if (dir == 'a'){
        if (pos().x() - 3 > 0) {
            setPos(x()-2,y());
            setRotation(180);
            return true;
        }
    }
    else if (dir == 'd'){
        if (pos().x() + 3 < 405){
            setPos(x()+2,y());
            setRotation(0);
            return true;
        }
    }
    else if (dir == 'w'){
        if (pos().y() - 3 > 0){
            setPos(x(),y()-2);
            setRotation(270);
            return true;
        }
    }
    else if (dir == 's'){
        if (pos().y() + 3 < 405){
            setPos(x(),y()+2);
            setRotation(90);
            return true;
        }
    }
    return false;
}

/*
void UserGraphicsItem::keyPressEvent(QKeyEvent *event){

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
*/

}
