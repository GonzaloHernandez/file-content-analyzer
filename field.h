#ifndef FIELD_H
#define FIELD_H

#include <QPainter>

class Field
{
private:
    uint16_t    x,y;
    uint16_t    width,height;
    uint32_t    position;
    uint32_t    size;
    QString     content;
    bool        focused;
public:
    Field(uint16_t x,uint16_t y,QString content,uint32_t position,uint32_t size);
    void        draw(QPainter& p);
    bool        isInArea(int mx,int my);
    void        setFocused(bool value);
    uint32_t    getPosition() const;
    void        setPosition(const uint &value);
};

#endif // FIELD_H
