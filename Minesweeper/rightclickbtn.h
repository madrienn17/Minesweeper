#ifndef RIGHTCLICKBTN_H
#define RIGHTCLICKBTN_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>

class RightClickBtn : public QPushButton
{
    Q_OBJECT
public:
    RightClickBtn(QWidget *parent=nullptr);
signals:
    void rightClick();
public slots:
    void mousePressEvent(QMouseEvent* event) override;
};

#endif // RIGHTCLICKBTN_H
