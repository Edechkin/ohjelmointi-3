#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include "bomb.hh"

#include <QDebug>
#include <QKeyEvent>

const int PADDING = 10;

namespace Student {

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->gameView->setFixedSize(width_, width_);
    ui->centralwidget->setFixedSize(width_ + ui->startButton->width() + PADDING, height_ + PADDING);

    //disable scroll bars
    ui->gameView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->gameView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->startButton->move(width_ + PADDING , PADDING);
    ui->endButton->move(width_ + PADDING , (4 * PADDING));

    map = new QGraphicsScene(this);
    ui->gameView->setScene(map);
    map->setSceneRect(0,0,width_,height_);

    resize(minimumSizeHint());
    //ui->gameView->fitInView(0,0, MAPWIDTH, MAPHEIGHT, Qt::KeepAspectRatio);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, map, &QGraphicsScene::advance);
    timer->start(tick_);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setSize(int w, int h)
{
    width_ = w;
    height_ = h;
}

void MainWindow::setTick(int t)
{
    tick_ = t;
}

void MainWindow::addActor(std::shared_ptr<Interface::IActor> actor)
{
    int locX = actor->giveLocation().giveX();
    int locY = actor->giveLocation().giveY();
    Student::ActorItem* nActor = new Student::ActorItem(locX, 500 - locY, 1);
    actors_[actor] = nActor;
    map->addItem(nActor);
    last_ = nActor;
}

void MainWindow::addStop(std::shared_ptr<Interface::IStop> stop)
{
    int locX = stop->getLocation().giveX();
    int locY = stop->getLocation().giveY();
    Student::ActorItem* nActor = new Student::ActorItem(locX, 500 - locY, 2);
    stops_[stop] = nActor;
    map->addItem(nActor);
}


void MainWindow::addPlayer(std::shared_ptr<Player> player)
{
    player_ = player;
    int locX = player->giveLocation().giveX();
    int locY = player->giveLocation().giveY();
    playerItem_ = new Student::UserGraphicsItem();
    playerItem_->setPos(locX, locY);
    playerItem_->setFlag(QGraphicsItem::ItemIsFocusable);
    playerItem_->setFocus();
    map->addItem(playerItem_);
    connect(timer, &QTimer::timeout, this, &MainWindow::movePlayer);
}


void MainWindow::removeActor(std::shared_ptr<Interface::IActor> actorToRm)
{
    map->removeItem(actors_.at(actorToRm));
    actors_.erase(actorToRm);
}

void MainWindow::updateCoords(std::shared_ptr<Interface::IActor> actor)
{
    int locX = actor->giveLocation().giveX();
    int locY = actor->giveLocation().giveY();
    actors_[actor]->setCoord(locX, 500 - locY);
}

void MainWindow::setPicture(QImage &img)
{
    map->setBackgroundBrush(img);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_A){
        playerItem_->setDir('a');
    }
    else if (event->key() == Qt::Key_D){
        playerItem_->setDir('d');
    }
    else if (event->key() == Qt::Key_W){
        playerItem_->setDir('w');
    }
    else if (event->key() == Qt::Key_S){
        playerItem_->setDir('s');
    }
    else if (event->key() == Qt::Key_Space){
        Student::Bomb* bomb = new Student::Bomb();
        bomb->setPos(playerItem_->giveX() + 36, playerItem_->giveY() + 26);
        map->addItem(bomb);
    }
}

}

void Student::MainWindow::on_startButton_clicked()
{
    qDebug() << "Start clicked";
    emit gameStarted();
}

void Student::MainWindow::movePlayer()
{
    if(playerItem_->move()){
        Interface::Location newLoc = player_->giveLocation();
        newLoc.setXY(playerItem_->giveX(), playerItem_->giveY());
        player_->move(newLoc);
    }
}
