#include "startdialog.hh"
#include "ui_startdialog.h"

namespace Student {

StartDialog::StartDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartDialog)
{
    ui->setupUi(this);
}

StartDialog::~StartDialog()
{
    delete ui;
}

void StartDialog::on_userInput_valueChanged(int value)
{
    userInput_ = value;
}

void StartDialog::accept()
{
    this->done(1);
    emit beginClicked(userInput_);
}

void StartDialog::reject()
{
    this->done(0);
    emit endClicked();
}

}
