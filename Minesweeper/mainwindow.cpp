#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(int xDim, int yDim)
   : ui(new Ui::MainWindow),
     xDim(xDim), yDim(yDim)
{
    ui->setupUi(this);
    start();
    connect();
}

MainWindow::MainWindow(int xDim, int yDim, int nrBomb)
   : ui(new Ui::MainWindow),
     xDim(xDim), yDim(yDim), nrBomb(nrBomb)
{
    ui->setupUi(this);
    start();
    connect();
}

MainWindow::~MainWindow()
{
    delete ui;
}

