#ifndef BONUSBAG_H
#define BONUSBAG_H

#include "../Course/CourseLib/interfaces/iactor.hh"
#include "../Course/CourseLib/core/location.hh"

namespace Student {

class Bonusbag : public Interface::IActor
{

public:
    Bonusbag();
    ~Bonusbag();

    Interface::Location giveLocation() const;

    void move(Interface::Location loc);

    bool isRemoved() const;

    void remove();

private:
    Interface::Location location_;
    bool isRemoved_;


};
}
#endif // BONUSBAG_H
