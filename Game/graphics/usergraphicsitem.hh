#ifndef USERGRAPHICSITEM_HH
#define USERGRAPHICSITEM_HH

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

namespace Student {

class UserGraphicsItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit UserGraphicsItem(QGraphicsItem *parent = nullptr);
    void keyPressEvent(QKeyEvent* event);

private:

};
}

#endif // USERGRAPHICSITEM_HH
