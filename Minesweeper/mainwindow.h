#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "rightclickbtn.h"
#include <stdlib.h>
#include <QDebug>
#include <QGridLayout>
#include <QMessageBox>
#include <QLabel>
#include "icons.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QElapsedTimer>
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

typedef struct Field{
    int value;
    bool visited;
    bool flagged;
} Field ;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(int, int);
    MainWindow(int, int, int);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int xDim = 10;
    int yDim = 10;
    int nrBomb;

    QLabel *bombsLabel;
    QLabel * timeLabel;

    QElapsedTimer* elapsedt;
    QTimer *timer;

    QGridLayout *btnLay;
    RightClickBtn *** newBtns;
    icons *icons;
    Field **fields;

    void start();
    void newGame();
    void generate();
    void count(int, int);
    void increment(int, int);
    void show(int, int);
    void clear(int, int);
    int btnsLeft();
    void fill();
    void print();
    void restart();
    void connect();
    void setIcons(int, int);
private slots:
    void actionBtn(int,int);
    void refreshTime();
    void onRightClick(int, int);
    void winmsg();
    void losemsg();
signals :
    void win();
    void lose();
};
#endif // MAINWINDOW_H
