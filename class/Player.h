
#ifndef Player_H
#define Player_H
#include "GameObject.h"
#include "Inputs.h"

/*
 * FILENAME : Player.h
 * DESCRIPTION : Responsavel pela criação do player
 *
 * PUBLIC FUNCTIONS :
 * ~Player()
 * void update()
 * void draw()
 * void move()
 * Player(Position position,const char *path,float velocidade)
 * NOTES :
 *
 *
 * AUTHOR : Vinicius Rezende
 * START DATE : 22 Jun 23
 */
class Player : public GameObject
{
public:
  ALLEGRO_BITMAP *image;
  float velocidadeAtual = 0;
  float gravidade = 9.8;
  float velocidade;

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
  /*
NAME : Player(Position position,const char *path,float velocidade)
* DESCRIPTION : construtor do player
* INPUTS :
* PARAMETERS :
*
* RETURN :
*/
  Player(Position position, const char *path, float velocidade)
  {

    this->setPosition(position);
    this->image = al_load_bitmap(path);
    this->velocidade = velocidade;
  };
  /*
    NAME : void move()
    * DESCRIPTION : responsavel por aplicar a fisica e simular a movimentação do player
    * INPUTS :
    * PARAMETERS :
    *
    * RETURN :
    */
  void move()
  {

    Position newPosition = this->getPosition();
    if (Inputs::checkKeyDown(ALLEGRO_KEY_SPACE))
    {
      this->velocidadeAtual = this->velocidadeAtual - this->velocidade;
    }
    this->velocidadeAtual = this->velocidadeAtual + this->gravidade / 60.0;
    newPosition.eixoY = newPosition.eixoY + (this->velocidadeAtual / 60.0) * 80;
    if (newPosition.eixoY > D_HEIGTH)
    {
      newPosition.eixoY = 0;
    }

    this->setPosition(newPosition);
  }
  /*
NAME : void update()
* DESCRIPTION : responsavel pela atualização da posição do player
* INPUTS :
* PARAMETERS :
*
* RETURN :
*/
  void update()
  {
    move();
  }
  /*
NAME : Player()
* DESCRIPTION : responsavel pela destruição do bitmap
* INPUTS :
* PARAMETERS :
*
* RETURN :
*/
  ~Player()
  {
    al_destroy_bitmap(this->image);
  }
};

#endif