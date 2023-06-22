
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "Global.h"

class GameObject
{
protected:
    Position _position = Position(0, 0);
    const char *path;
    

public:
    Position getPosition()
    {
        return this->_position;
    };
    void setPosition(Position newPosition)
    {
        this->_position = newPosition;
    }
    const char * getImagePath()
    {
        return this->path;
    };

    void setImagePath(const char* path)
    {
        this->path = path;
    }
    GameObject() = default;
    GameObject(Position position, const char* path)
    {
        this->setPosition(position);
        this->setImagePath(path);
    };
   
    virtual void draw() = 0;
    virtual void update() = 0;
    
};

#endif