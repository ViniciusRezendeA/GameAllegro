
#ifndef Tube_H
#define Tube_H
#include "GameObject.h"
#include "Inputs.h"
#include "Player.h"
using namespace std;
class Tube : public GameObject
{
protected:
    ALLEGRO_BITMAP *image;
    bool passou = false;

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
    bool collision(Player *InitialPlayer)
    {
        //  97 x 854 px
        // cano de cima 308
        // cano de baixo 520
        float collider[][2] = {{InitialPlayer->getPosition().eixoX, InitialPlayer->getPosition().eixoY},
                               {InitialPlayer->getPosition().eixoX, InitialPlayer->getPosition().eixoY + al_get_bitmap_height(InitialPlayer->image)},
                               {InitialPlayer->getPosition().eixoX + al_get_bitmap_width(InitialPlayer->image), InitialPlayer->getPosition().eixoY},
                               {InitialPlayer->getPosition().eixoX + al_get_bitmap_width(InitialPlayer->image), InitialPlayer->getPosition().eixoY + al_get_bitmap_height(InitialPlayer->image)}};
        collider;
        for (int i = 0; i < 4; i++)
        {

            if (collider[i][0] < this->getPosition().eixoX + 92 && collider[i][0] > this->getPosition().eixoX)
            {
                if (collider[i][1] < this->getPosition().eixoY + 308 || collider[i][1] > this->getPosition().eixoY + 520)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool pointer(Player *InitialPlayer)
    {
        //  97 x 854 px
        // cano de cima 308
        // cano de baixo 520
        float collider[][2] = {{InitialPlayer->getPosition().eixoX, InitialPlayer->getPosition().eixoY},
                               {InitialPlayer->getPosition().eixoX, InitialPlayer->getPosition().eixoY + al_get_bitmap_height(InitialPlayer->image)},
                               {InitialPlayer->getPosition().eixoX + al_get_bitmap_width(InitialPlayer->image), InitialPlayer->getPosition().eixoY},
                               {InitialPlayer->getPosition().eixoX + al_get_bitmap_width(InitialPlayer->image), InitialPlayer->getPosition().eixoY + al_get_bitmap_height(InitialPlayer->image)}};
        collider;
        for (int i = 0; i < 4; i++)
        {

            if (collider[i][0] < this->getPosition().eixoX + 92 && collider[i][0] > this->getPosition().eixoX)
            {
                if (collider[i][1] < this->getPosition().eixoY + 308 || collider[i][1] > this->getPosition().eixoY + 520)
                {
                }
                else
                {
                  
                    return true;
                    
                }
            }else{
                return false;

            }
        }
        return false;
    }
    void destroy()
    {
        al_destroy_bitmap(this->image);
    }
};

#endif

// desenvolver um componente
// desenvolver um reciclerview
// desenvolver um fragment
// pode ser selecionado quantos componentes quiser;