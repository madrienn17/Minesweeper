#include "welcomewindow.h"
#include "mainwindow.h"
#include "ui_welcomewindow.h"

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
