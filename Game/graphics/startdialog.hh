#ifndef STARTDIALOG_HH
#define STARTDIALOG_HH

#include <QDialog>
#include <QPushButton>
#include <QSpinBox>

namespace Ui {
class StartDialog;
}

namespace Student {

class StartDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StartDialog(QWidget *parent = nullptr);
    ~StartDialog();

signals:
    void beginClicked(int userInput);
    void endClicked();

public slots:
    void accept() override;
    void reject() override;

private slots:
    void on_userInput_valueChanged(int value);

private:
    Ui::StartDialog *ui;

    int userInput_;
};

}

#endif // STARTDIALOG_HH
