#include "field.h"
#include <QPainter>

void Field::draw(QPainter& p)
{
    if (focused) {
        p.fillRect(x,y,width,height, QBrush(Qt::red));
    } else {
        p.fillRect(x,y,width,height, QBrush(Qt::white));
    }
    QPen pen = p.pen();

    pen.setColor(QColor(220,220,220));
    p.setPen(pen);

    p.drawRect(x,y,width,height);

    pen.setColor(Qt::black);
    p.setPen(pen);

    p.fillRect(20,y,50,height,QBrush(Qt::white));
    p.drawText(20,y,50,height,Qt::AlignRight,QString("%1").arg(position));
    p.drawText(x,y,width,height,Qt::AlignCenter,content);
}

uint32_t Field::getPosition() const
{
    return position;
}

void Field::setPosition(const uint &value)
{
    position = value;
}

Field::Field(uint16_t x, uint16_t y, QString content, uint32_t position, uint32_t size)
    : x(x), y(y), width(25), height(25), position(position), size(size), content(content), focused(false)
{

}

bool Field::isInArea(int mx,int my) {
    if (mx>x && mx<x+width && my>y && my<y+height) {
        return true;
    }
    return false;
}

void Field::setFocused(bool value)
{
    focused = value;
}
