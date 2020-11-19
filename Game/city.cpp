#include "city.hh"

#include <QTime>
#include <QDebug>

namespace Student {

City::City() :
    actors_(),
    time_()
{

    window_ = new CourseSide::SimpleMainWindow();

    QImage file(":/kartta_pieni_500x500.png");

    window_->setPicture(file);

    window_->show();

}


void City::setBackground(QImage &basicbackground, QImage& bigbackground)
{

}

void City::setClock(QTime clock)
{
    time_.setHMS(clock.hour(), clock.minute(), clock.second());
}

void City::addStop(std::shared_ptr<Interface::IStop> stop)
{

}

void City::startGame()
{

}

void City::addActor(std::shared_ptr<Interface::IActor> newactor)
{
    window_->addActor(newactor->giveLocation().giveX(),
                      newactor->giveLocation().giveY());
    actors_.push_back(newactor);
}

void City::removeActor(std::shared_ptr<Interface::IActor> actor)
{

}

void City::actorRemoved(std::shared_ptr<Interface::IActor> actor)
{

}

bool City::findActor(std::shared_ptr<Interface::IActor> actor) const
{

}

void City::actorMoved(std::shared_ptr<Interface::IActor> actor)
{
    window_->updateCoords(actor->giveLocation().giveX(),
                          actor->giveLocation().giveY());
}

std::vector<std::shared_ptr<Interface::IActor> > City::getNearbyActors(Interface::Location loc) const
{

}

bool City::isGameOver() const
{

}

}
