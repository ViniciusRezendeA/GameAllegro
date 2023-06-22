
#ifndef Tube_H
#define Tube_H
#include "GameObject.h"
#include "Inputs.h"
#include "Bird.h"
class Tube : public GameObject
{
protected:
    ALLEGRO_BITMAP *image;

public:
    void draw()
    {
        al_draw_bitmap(this->image, this->getPosition().eixoX, this->getPosition().eixoY, 0);
    }
    ALLEGRO_BITMAP *getBitMap()
    {
        return this->image;
    }
    Tube(Position position, const char *path)
    {

        this->setPosition(position);
        this->image = al_load_bitmap(path);
        this->setImagePath(path);
    };

    void move()
    {

        Position newPosition = this->getPosition();
        newPosition.eixoX = newPosition.eixoX - 3;
        this->setPosition(newPosition);
    }
    int randmWithLimit(int min, int max)
    {

        int alNumber = rand();
        int result = alNumber % (max - min) + min;
        return result;
    }
    void update()
    {
        if (this->getPosition().eixoX < -400)
        {
            this->setPosition(Position((D_WIDHT + 20), -randmWithLimit(40, 200)));
        }
        move();
    }
    bool collision(Bird *InitialBird)
    {

        if (InitialBird->getPosition().eixoY < this->getPosition().eixoY + 280 || InitialBird->getPosition().eixoY > al_get_bitmap_height(this->image) - 450 && this->getPosition().eixoX == 200)
        {
            cout<<this->getPosition().eixoX;
            return true;
        }
        return false;
    }
    void destroy()
    {
        al_destroy_bitmap(this->image);
    }
};

#endif