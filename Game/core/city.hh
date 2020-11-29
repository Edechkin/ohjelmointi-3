#ifndef CITY_HH
#define CITY_HH

#include "../Course/CourseLib/interfaces/icity.hh"
#include "../Course/CourseLib/interfaces/iactor.hh"
#include "../Course/CourseLib/actors/nysse.hh"
#include "../Course/CourseLib/actors/passenger.hh"
#include "../Course/CourseLib/actors/stop.hh"
#include "./graphics/mainwindow.hh"
#include "./actors/player.hh"
#include "statistics.hh"

#include <list>
#include <memory>
#include <QTime>
#include <QTimer>


namespace Student {


class City : public Interface::ICity, public QWidget
{

public:
    City();

    ~City();

    void setBackground(QImage& basicbackground, QImage& bigbackground);

    void setClock(QTime clock);

    void addStop(std::shared_ptr<Interface::IStop> stop);

    Student::MainWindow* window;

    void startGame();

    void addActor(std::shared_ptr<Interface::IActor> newactor);

    void removeActor(std::shared_ptr<Interface::IActor> actor);

    void actorRemoved(std::shared_ptr<Interface::IActor> actor);

    bool findActor(std::shared_ptr<Interface::IActor> actor) const;

    void actorMoved(std::shared_ptr<Interface::IActor> actor);

    void keyPressEvent(QKeyEvent* event);

    std::vector<std::shared_ptr<Interface::IActor>> getNearbyActors(Interface::Location loc) const;

    bool isGameOver() const;

private:

    std::list< std::shared_ptr<Interface::IActor> > actors_;
    std::vector< std::shared_ptr<Interface::IStop> > stops_;

    std::shared_ptr<Student::Player> player_;

    // Current time
    QTime time_;

    //Round length given by user
    int roundLength_ = 120;

    int roundHasLasted_ = 0;

    //Amount of bombs user can drop in a round
    int amOfBombs_ = 20;

    int bombsUsed_ = 0;

    bool gameStarted_;

    Statistics *ptr_;

};

}
#endif // CITY_HH
