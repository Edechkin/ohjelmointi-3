#include "../Course/CourseLib/creategame.hh"
#include "../Course/CourseLib/core/logic.hh"
#include "city.hh"

#include <QApplication>
#include <QImage>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(offlinedata);

    CourseSide::Logic* gamelogic = new CourseSide::Logic();

    std::shared_ptr<Interface::ICity> gameCity = Interface::createGame();

    gamelogic->fileConfig();

    gamelogic->takeCity(gameCity);

    gamelogic->finalizeGameStart();

    return a.exec();
}
