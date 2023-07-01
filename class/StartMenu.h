
#ifndef StartMenu_H
#define StartMenu_H
#include "GameObject.h"
#include "Inputs.h"
/*
 * FILENAME : StartMenu.h
 * DESCRIPTION : Responsavel pela criação dos menus
 *
 * PUBLIC FUNCTIONS :
 * ~StartMenu()
 * void update()
 * void draw()
 * void changePressState(bool pressed)
 * bool checkBtnIsPress()
 * bool getStart()
 * StartMenu(float x, float y, const char *path)
 * NOTES :
 *
 *
 * AUTHOR : Vinicius Rezende
 * START DATE : 22 Jun 23
 */
class StartMenu : public GameObject
{
protected:
    float x;
    float y;
    int width;
    int height;
    bool pressed = false;
    bool iniciar = false;
    ALLEGRO_BITMAP *image;

public:
    /*
  NAME : StartMenu(float x, float y, const char *path)
  * DESCRIPTION : construtor do menu
  * INPUTS :
  * PARAMETERS :
  * float x: valor do eixo X do menu
  * float y: valor do eixo Y do menu
  * const char *path: caminho da imagem dos menus
  * RETURN :
  */
    StartMenu(float x, float y, const char *path)
    {

        this->x = x;
        this->y = y;
        this->image = al_load_bitmap(path);
    }
    /*
   NAME : changePressState(bool pressed)
   * DESCRIPTION : responsavel pela alteração dos valores de pressed e iniciar
   * INPUTS :
   * PARAMETERS :
   *bool pressed :valor de pressed e de iniciar
   * RETURN :
   */
    void changePressState(bool pressed)
    {
        this->pressed = pressed;
        this->iniciar = pressed;
    }
    /*
NAME :  checkBtnIsPress()
* DESCRIPTION : responsavel por coletar  o valor de pressed
* INPUTS :
* PARAMETERS :
*
* RETURN : this->pressed;
*/
    bool checkBtnIsPress()
    {
        return this->pressed;
    }
    /*
NAME : void draw()
* DESCRIPTION : responsavel por coletar  o valor de iniciar
* INPUTS :
* PARAMETERS :
*
* RETURN : this->iniciar;
*/
    bool getStart()
    {
        return this->iniciar;
    }
    /*
NAME : void update()
* DESCRIPTION : responsavel pela atualização da exibição do menu
* INPUTS :
* PARAMETERS :
*
* RETURN :
*/
    void update()
    {

        if (
            Inputs::getMousePosition().eixoX > D_HEIGTH / 2 - al_get_bitmap_height(this->image) && Inputs::getMousePosition().eixoX < D_HEIGTH)
        {

            Inputs::setMousePosition(0, 0);
            this->iniciar = true;
            return;
        }
    }
    /*
  NAME : void draw()
  * DESCRIPTION : responsavel pela exibição do menu na tela
  * INPUTS :
  * PARAMETERS :
  *
  * RETURN :
  */
    void draw()
    {
        if (this->iniciar && !this->pressed)
        {
        }
        else
        {

            al_draw_bitmap(this->image, (D_WIDHT - al_get_bitmap_width(this->image)) / 2, D_HEIGTH / 2, 0);
        }
    }
    /*
  NAME :  ~StartMenu()
  * DESCRIPTION : responsavel pela destruição do bitmap
  * INPUTS :
  * PARAMETERS :
  *
  * RETURN :
  */
    ~StartMenu()
    {
        pressed = true;
        al_destroy_bitmap(this->image);
    }
};
#endif