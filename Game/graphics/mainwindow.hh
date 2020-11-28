#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include "../Course/CourseLib/interfaces/iactor.hh"
#include "../Course/CourseLib/core/location.hh"
#include "../Course/CourseLib/actors/stop.hh"
#include "../Course/CourseLib/graphics/simpleactoritem.hh"
#include "./actors/player.hh"
#include "usergraphicsitem.hh"
#include "actoritem.hh"

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <iostream>
#include <memory>
#include <QVector>
#include <map>

namespace Ui {
class MainWindow;
}

namespace Student {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();

    void setSize(int w, int h);
    void setTick(int t);

    void addActor(std::shared_ptr<Interface::IActor>);
    void addStop(std::shared_ptr<Interface::IStop>);
    void addPlayer(std::shared_ptr<Student::Player>);

    void removeActor(std::shared_ptr<Interface::IActor>);

    void updateCoords(std::shared_ptr<Interface::IActor>);
    void setPicture(QImage &img);

    void changeDirection(char dir);
    void addBomb();

    void roundOver();

signals:
    void gameStarted();

private slots:
    void on_startButton_clicked();
    void movePlayer();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *map;
    QTimer *timer;
    std::map<std::shared_ptr<Interface::IActor>, Student::ActorItem*> actors_;
    std::map<std::shared_ptr<Interface::IStop>, Student::ActorItem*> stops_;
    Student::ActorItem* last_;

    std::shared_ptr<Student::Player> player_;
    Student::UserGraphicsItem* playerItem_;

    int width_ = 500; //pxls
    int height_ = 500;
    int tick_ = 10; //ms
};

} //namespace
#endif // MAINWINDOW_HH
