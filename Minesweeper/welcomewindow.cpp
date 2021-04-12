#include "welcomewindow.h"
#include "mainwindow.h"
#include "ui_welcomewindow.h"

/*
* Starter window of the app, where you can choose your gameboard size preferences
* Two buttons: Exit and Start
*/

WelcomeWindow::WelcomeWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);
}

WelcomeWindow::~WelcomeWindow() {
    delete ui;
}

void WelcomeWindow::on_exitBtn_clicked()
{
    QApplication::quit();
}

void WelcomeWindow::on_startBtn_clicked()
{
    this->close();
    MainWindow *w = new MainWindow(ui->xSpin->value(), ui->ySpin->value(), ui->mineSpin->value());
    w->show();
}
