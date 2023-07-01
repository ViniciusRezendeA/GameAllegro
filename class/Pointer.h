#ifndef Pointer_H
#define Pointer_H
#include "GameObject.h"
#include "Inputs.h"

/*
 * FILENAME : Pointer.h
 * DESCRIPTION : Responsavel pela criação do Ponteiro
 *
 * PUBLIC FUNCTIONS :
 * ~Pointer()
 * void update()
 * void draw()
 * Pointer()
 * NOTES :
 *
 *
 * AUTHOR : Vinicius Rezende
 * START DATE : 22 Jun 23
 */

class Pointer : public GameObject
{
protected:
    int qPointer;
    ALLEGRO_COLOR letterColor;
    ALLEGRO_FONT *font = al_create_builtin_font();
    const char *text;

public:
    /*
    NAME : Pointer(ALLEGRO_COLOR letterColor, Position position, const char* text)
    * DESCRIPTION : construtor do Pointer
    * INPUTS :
    * PARAMETERS :
    * ALLEGRO_COLOR letterColor: cor do texto
    * Position position: posição do texto
    * const char* text: texto a ser exibido
    * RETURN :
    */
    Pointer(ALLEGRO_COLOR letterColor, Position position, const char *text)
    {
        this->letterColor = letterColor;
        this->setPosition(position);
        this->text = text;
    }
    /*
    NAME : void update()
    * DESCRIPTION : responsavel pela atualização do contador de pontos
    * INPUTS :
    * PARAMETERS :
    *
    * RETURN :
    */
    void update()
    {

        draw();
    }
    /*
    NAME : void update()
    * DESCRIPTION : responsavel por setar o valor dos pontos
    * INPUTS :
    * PARAMETERS :
    *
    * RETURN :
    */
    void setQPointer(int q)
    {
        this->qPointer = q;
    }
    /*
    NAME : void draw()
    * DESCRIPTION : responsavel pela exibição da pontuação
    * INPUTS :
    * PARAMETERS :
    *
    * RETURN :
    */
    void draw()
    {
        al_draw_textf(this->font, this->letterColor, this->getPosition().eixoX, this->getPosition().eixoY, 0, this->text, qPointer);
    }
    /*
NAME : ~Pointer()
* DESCRIPTION : responsavel pela destruição do bitmap
* INPUTS :
* PARAMETERS :
*
* RETURN :
*/
    ~Pointer()
    {
        al_destroy_font(this->font);
    }
};
#endif