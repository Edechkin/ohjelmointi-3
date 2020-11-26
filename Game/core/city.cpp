#include "city.hh"

#include <algorithm>
#include <QDebug>
#include <QPushButton>

namespace Student {

City::City() :
    actors_(),
    stops_(),
    time_(),
    gameStarted_(false)
{

    window_ = new Student::MainWindow();



    QImage basicbackground(":/offlinedata/offlinedata/kartta_pieni_500x500.png");
    QImage bigbackground(":/offlinedata/offlinedata/kartta_iso_1095x592.png");

    setBackground(basicbackground, bigbackground);

    window_->show();

}

City::~City()
{

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
    window_->addStop(stop);
    stops_.push_back(stop);
}

void City::startGame()
{
    player_ = std::make_shared<Student::Player>(5);
    window_->addPlayer(player_);
    gameStarted_ = true;
}

void City::addActor(std::shared_ptr<Interface::IActor> newactor)
{
    if ( std::dynamic_pointer_cast<CourseSide::Nysse>(newactor) ){
        window_->addActor(newactor);
    }
    actors_.push_back(newactor);
}

void City::removeActor(std::shared_ptr<Interface::IActor> actor)
{
    window_->removeActor(actor);
    actors_.remove(actor);
}

void City::actorRemoved(std::shared_ptr<Interface::IActor> actor)
{

}

bool City::findActor(std::shared_ptr<Interface::IActor> actor) const
{
    /*std::list<std::shared_ptr<Interface::IActor>>::iterator iter;

    iter = std::find(actors_.begin(), actors_.end(), actor);*/

    //bool result = contains(actors_, actor);
}

void City::actorMoved(std::shared_ptr<Interface::IActor> actor)
{
    if ( std::dynamic_pointer_cast<CourseSide::Nysse>(actor) ){
        window_->updateCoords(actor);
    }
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
