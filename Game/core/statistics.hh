#ifndef STATISTICS_HH
#define STATISTICS_HH

#include "../Course/CourseLib/interfaces/istatistics.hh"

namespace Student {

class Statistics : public Interface::IStatistics
{
public:
    Statistics();
    ~Statistics();

    void morePassengers(int num);
    void nysseRemoved();
    void newNysse();
    void nysseLeft();

};

}

#endif // STATISTICS_HH
