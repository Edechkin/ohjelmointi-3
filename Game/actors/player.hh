#ifndef PLAYER_HH
#define PLAYER_HH

#include "../Course/CourseLib/interfaces/iactor.hh"
#include "../Course/CourseLib/core/location.hh"

namespace Student {

class Player : public Interface::IActor {
public:
    Player();
    ~Player();

    Interface::Location giveLocation() const;
    void move(Interface::Location loc);
    bool isRemoved() const;
    void remove();

private:
    Interface::Location location_;

    bool isRemoved_;

};

}

#endif // PLAYER_HH
