
#ifndef Bird_H
#define Bird_H
#include "GameObject.h"
#include "Inputs.h"
class Bird : public GameObject
{
protected:
    ALLEGRO_BITMAP *image;
    float velocidade = 0;
    float gravidade = 9.8;

public:
    void draw()
    {

        al_draw_scaled_bitmap(this->image,
                              0, 0, al_get_bitmap_width(this->image), al_get_bitmap_height(this->image),
                              this->getPosition().eixoX, this->getPosition().eixoY, 80, 80,
                              0);
    }
     ALLEGRO_BITMAP * getBitMap(){
        return this->image;
    }
    Bird(Position position,const char *path)
    {

        this->setPosition(position);
        this->image = al_load_bitmap(path);
    };
    void start()
    {
    }
    void move()
    {

        Position newPosition = this->getPosition();
        if (Inputs::checkKeyDown(ALLEGRO_KEY_SPACE))
        {
            velocidade = velocidade - 6;
        }
        velocidade = velocidade + this->gravidade / 60.0;
        newPosition.eixoY = newPosition.eixoY + (this->velocidade / 60.0) * 80;
        if (newPosition.eixoY > D_HEIGTH)
        {
            newPosition.eixoY = 0;
        }

        this->setPosition(newPosition);
    }
    void update()
    {
        move();
    }
    ~Bird()
    {
        al_destroy_bitmap(this->image);
    }
};

#endif