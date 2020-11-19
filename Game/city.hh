#ifndef CITY_HH
#define CITY_HH

#include "../Course/CourseLib/interfaces/icity.hh"
#include "../Course/CourseLib/interfaces/iactor.hh"
#include "../Course/CourseLib/graphics/simplemainwindow.hh"
#include "../Course/CourseLib/actors/nysse.hh"
#include "../Course/CourseLib/actors/passenger.hh"
#include "../Course/CourseLib/actors/stop.hh"

#include <memory>
#include <QTime>


namespace Student {


class City : public Interface::ICity
{
public:
    City();

    void setBackground(QImage& basicbackground, QImage& bigbackground);

    void setClock(QTime clock);

    void addStop(std::shared_ptr<Interface::IStop> stop);

    void startGame();

    void addActor(std::shared_ptr<Interface::IActor> newactor);

    void removeActor(std::shared_ptr<Interface::IActor> actor);

    void actorRemoved(std::shared_ptr<Interface::IActor> actor);

    bool findActor(std::shared_ptr<Interface::IActor> actor) const;

    void actorMoved(std::shared_ptr<Interface::IActor> actor);

    std::vector<std::shared_ptr<Interface::IActor>> getNearbyActors(Interface::Location loc) const;

    bool isGameOver() const;

private:

    std::vector< std::shared_ptr<Interface::IActor> > actors_;
    //std::list< std::shared_ptr<CourseSide::Passenger> > passengers_;
    //std::list< std::shared_ptr<CourseSide::Nysse> > buses_;
    //std::vector< std::shared_ptr<CourseSide::Stop> > stops_;

    // Current time
    QTime time_;

    CourseSide::SimpleMainWindow* window_;
};

}
#endif // CITY_HH
