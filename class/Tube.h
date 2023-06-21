
#ifndef Tube_H
#define Tube_H
#include "GameObject.h"
#include "Inputs.h"
class Tube : public GameObject
{
protected:
    ALLEGRO_BITMAP *image;


public:
    void draw()
    {

        al_draw_scaled_bitmap(this->image,
                              0, 0, al_get_bitmap_width(this->image), al_get_bitmap_height(this->image),
                              this->getPosition().eixoX, this->getPosition().eixoY, al_get_bitmap_width(image), al_get_bitmap_height(image),
                              15);
    }
    Tube(Position position,const char *path)
    {

        this->setPosition(position);
        this->image = al_load_bitmap(path);
    };
    void start()
    {
         srand(al_get_time());
    }
    void move()
    {

        Position newPosition = this->getPosition();
        newPosition.eixoX = newPosition.eixoX - 3;
        this->setPosition(newPosition);
    }
    int randmWithLimit(int min, int max)
    {
       
        int alNumber = rand();
        int result = alNumber %(max - min) + min;
        return result;
    }
    void update()
    {
        if (this->getPosition().eixoX < -400)
        {
            this->setPosition(Position((D_WIDHT + 20), -randmWithLimit(40,200)));
        }
        move();
    }
     ~Tube(){
        al_destroy_bitmap(this->image);
    }
};

#endif