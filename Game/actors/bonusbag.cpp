#include "bonusbag.h"

namespace Student {



Bonusbag::Bonusbag() :

    isRemoved_(false)
{
    location_ = Interface::Location();
    location_.setXY(10, 10);
}

Bonusbag::~Bonusbag()
{
    
}

Interface::Location Bonusbag::giveLocation() const
{
    return location_;
}

void Bonusbag::move(Interface::Location loc)
{
    location_ = loc;
}

bool Bonusbag::isRemoved() const
{
    return isRemoved_;
}

void Bonusbag::remove()
{
    isRemoved_ = true;
}

}
