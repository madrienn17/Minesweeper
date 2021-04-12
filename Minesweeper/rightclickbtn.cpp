#include "rightclickbtn.h"

/*
* Helper class to handle right clicks, needed for flagging in the game
*/

RightClickBtn::RightClickBtn(QWidget *parent)
    :  QPushButton(parent) {}

void RightClickBtn::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::RightButton) {
        emit rightClick();
    }
    if (event->button() == Qt::LeftButton) {
        emit clicked();
    }
}
