
#ifndef Tube_H
#define Tube_H
#include "GameObject.h"
#include "Inputs.h"
#include "Player.h"
using namespace std;
/*
 * FILENAME : Tube.h
 * DESCRIPTION : Responsavel pela criação do obstaculo
 *
 * PUBLIC FUNCTIONS :
 * ~Tube()
 * void update()
 * void draw()
 * void move()
 * bool collision(Player *InitialPlayer)
 * bool pointer(Player *InitialPlayer)
 * Tube(Position position, const char *path)
 * NOTES :
 *
 *
 * AUTHOR : Vinicius Rezende
 * START DATE : 22 Jun 23
 */
class Tube : public GameObject
{
protected:
    ALLEGRO_BITMAP *image;
    bool passou = false;

public:
    /*
       NAME : void draw()
       * DESCRIPTION : responsavel pela exibição do player na tela
       * INPUTS :
       * PARAMETERS :
       *
       * RETURN :
       */
    void draw()
    {
        al_draw_bitmap(this->image, this->getPosition().eixoX, this->getPosition().eixoY, 0);
    }
    ALLEGRO_BITMAP *getBitMap()
    {
        return this->image;
    }

    /*
    NAME : Tube(Position position, const char *path)
    * DESCRIPTION : construtor do Tube
    * INPUTS :
    * PARAMETERS :
    * Position position: posição do player
    * const char *path: caminho da imagem do player
    * RETURN :
    */

    Tube(Position position, const char *path)
    {

        this->setPosition(position);
        this->image = al_load_bitmap(path);
        this->setImagePath(path);
    };
    /*
    NAME : void move()
    * DESCRIPTION : responsavel por aplicar a fisica e simular a movimentação do tubo
    * INPUTS :
    * PARAMETERS :
    *
    * RETURN :
    */
    void move()
    {

        Position newPosition = this->getPosition();
        newPosition.eixoX = newPosition.eixoX - 3;
        this->setPosition(newPosition);
    }

    /*
        NAME : void update()
        * DESCRIPTION : responsavel pela atualização da posição do tubo
        * INPUTS :
        * PARAMETERS :
        *
        * RETURN :
    */
    void update()
    {
        if (this->getPosition().eixoX < -400)
        {
            this->setPosition(Position((D_WIDHT + 20), -randmWithLimit(40, 200)));
        }
        move();
    }
    /*
        NAME : collision(Player *InitialPlayer)
        * DESCRIPTION : responsavel por conferir se o jogador colidiu com o tubo
        * INPUTS :
        * PARAMETERS :  Player *InitialPlayer
        *
        * RETURN : boleam
    */
    bool collision(Player *InitialPlayer)
    {

        float collider[][2] = {{InitialPlayer->getPosition().eixoX, InitialPlayer->getPosition().eixoY},
                               {InitialPlayer->getPosition().eixoX, InitialPlayer->getPosition().eixoY + al_get_bitmap_height(InitialPlayer->image)},
                               {InitialPlayer->getPosition().eixoX + al_get_bitmap_width(InitialPlayer->image), InitialPlayer->getPosition().eixoY},
                               {InitialPlayer->getPosition().eixoX + al_get_bitmap_width(InitialPlayer->image), InitialPlayer->getPosition().eixoY + al_get_bitmap_height(InitialPlayer->image)}};
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
    /*
    NAME : pointer(Player *InitialPlayer)
    * DESCRIPTION : responsavel por conferir se o jogador marcou ponto
    * INPUTS :
    * PARAMETERS :  Player
    *
    * RETURN : boleam
    */
    bool pointer(Player *InitialPlayer)
    {

        float collider[][2] = {{InitialPlayer->getPosition().eixoX, InitialPlayer->getPosition().eixoY},
                               {InitialPlayer->getPosition().eixoX, InitialPlayer->getPosition().eixoY + al_get_bitmap_height(InitialPlayer->image)},
                               {InitialPlayer->getPosition().eixoX + al_get_bitmap_width(InitialPlayer->image), InitialPlayer->getPosition().eixoY},
                               {InitialPlayer->getPosition().eixoX + al_get_bitmap_width(InitialPlayer->image), InitialPlayer->getPosition().eixoY + al_get_bitmap_height(InitialPlayer->image)}};

        for (int i = 0; i < 4; i++)
        {

            if (collider[i][0] < this->getPosition().eixoX + 92 && collider[i][0] > this->getPosition().eixoX + 10)
            {
                if (collider[i][1] < this->getPosition().eixoY + 308 || collider[i][1] > this->getPosition().eixoY + 520)
                {
                }
                else
                {

                    return true;
                }
            }
            else
            {
                return false;
            }
        }
        return false;
    }
    /*
    NAME : ~Tube()
    * DESCRIPTION : responsavel por destroir o bitmap do tubo
    * INPUTS :
    * PARAMETERS :
    *
    * RETURN :
    */
    ~Tube()
    {
        al_destroy_bitmap(this->image);
    }
};

#endif
