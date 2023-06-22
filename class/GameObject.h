
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "Global.h"

class GameObject
{
protected:
    Position _position = Position(0, 0);
    ALLEGRO_COLOR _backgroundColor;

public:
    Position getPosition()
    {
        return this->_position;
    };
    void setPosition(Position newPosition)
    {
        this->_position = newPosition;
    }
    ALLEGRO_COLOR getBackgroundColor()
    {
        return this->_backgroundColor;
    };

    void setBackgroundColor(ALLEGRO_COLOR newBackgroundColor)
    {
        this->_backgroundColor = newBackgroundColor;
    }
    GameObject() = default;
    GameObject(Position position, ALLEGRO_COLOR backgroundColor)
    {
        this->setPosition(position);
        this->setBackgroundColor(backgroundColor);
    };
   
    virtual void draw() = 0;
    virtual void update() = 0;
    
};

#endif