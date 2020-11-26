#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include "../Course/CourseLib/interfaces/iactor.hh"
#include "../Course/CourseLib/actors/stop.hh"
#include "../Course/CourseLib/graphics/simpleactoritem.hh"

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

    void removeActor(std::shared_ptr<Interface::IActor>);

    void updateCoords(std::shared_ptr<Interface::IActor>);
    void setPicture(QImage &img);

signals:
    void gameStarted();

private slots:
    void on_startButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *map;
    QTimer *timer;
    std::map<std::shared_ptr<Interface::IActor>, CourseSide::SimpleActorItem*> actors_;
    std::map<std::shared_ptr<Interface::IStop>, CourseSide::SimpleActorItem*> stops_;
    CourseSide::SimpleActorItem* last_;

    int width_ = 500; //pxls
    int height_ = 500;
    int tick_ = 500; //ms
};

} //namespace
#endif // MAINWINDOW_HH
