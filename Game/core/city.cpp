#include "city.hh"

#include <QDebug>
#include <QPushButton>

namespace Student {

City::City() :
    actors_(),
    stops_(),
    time_(),
    gameStarted_(false)
{

    window_ = new CourseSide::SimpleMainWindow();

    QImage basicbackground(":/offlinedata/offlinedata/kartta_pieni_500x500.png");
    QImage bigbackground(":/offlinedata/offlinedata/kartta_iso_1095x592.png");

    setBackground(basicbackground, bigbackground);

    window_->show();

}


void City::setBackground(QImage &basicbackground, QImage& bigbackground)
{
    window_->setPicture(basicbackground);
}

void City::setClock(QTime clock)
{
    time_.setHMS(clock.hour(), clock.minute(), clock.second());
    if ( gameStarted_ ) {
        ++roundHasLasted_;
    }
}

void City::addStop(std::shared_ptr<Interface::IStop> stop)
{
    //qDebug() << "adding a stop";
    window_->addActor(stop->getLocation().giveX(),stop->getLocation().giveY(),
                      255);
    stops_.push_back(stop);
}

void City::startGame()
{
    gameStarted_ = true;
}

void City::addActor(std::shared_ptr<Interface::IActor> newactor)
{
    window_->addActor(newactor->giveLocation().giveX(),
                      newactor->giveLocation().giveY(), 0);
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
    if ( roundHasLasted_ >= roundLength_ ) {
        return 1;
    }

    return 0;
}

}
