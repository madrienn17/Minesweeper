#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <QObject>
#include <QWidget>

namespace Ui {
 class WelcomeWindow;
}

class WelcomeWindow : public QWidget
{
    Q_OBJECT
public:
    WelcomeWindow(QWidget *parent = nullptr);
    ~WelcomeWindow();
private :
    Ui :: WelcomeWindow * ui;
private slots :
    void on_exitBtn_clicked();
    void on_startBtn_clicked();
};

#endif // WELCOMEWINDOW_H
