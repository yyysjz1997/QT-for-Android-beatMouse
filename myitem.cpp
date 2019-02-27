#include "myitem.h"
#include <QPixmap>
#include <QDebug>
#include <handler.h>
#include <QCursor>

myitem::myitem()
{
    this->setPixmap(QPixmap(":/bg/pic/bg.png"));
    this->start = false;
    this->mouse = false;
    this->setCursor(QCursor(QPixmap(":/mouse/pic/chui_up.png")));
}

void myitem::setPic(QString path)
{
    this->setPixmap(QPixmap(path));
}

void myitem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(QPixmap(":/mouse/pic/chui.png")));
    if(this->isStart())
    {
        handler *hand = handler::getInstance();
        if(this->ismouse())
        {
            hand->addScore();
            this->setPixmap(QPixmap(":/mouse/pic/beat.png"));
            //qDebug()<<"打的是老鼠";
        }
        else
        {
            //qDebug()<<"打的不是老鼠";
        }
    }
}

void myitem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(QPixmap(":/mouse/pic/chui_up.png")));
}

void myitem::setmouse(bool mouse)
{
    this->mouse = mouse;
}

bool myitem::ismouse()
{
    return this->mouse;
}

void myitem::setStart(bool start)
{
    this->start = start;
}

bool myitem::isStart()
{
    return this->start;
}
