#include "rightclickbtn.h"

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
