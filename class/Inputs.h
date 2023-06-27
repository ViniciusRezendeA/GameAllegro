
#ifndef INPUTS_H
#define INPUTS_H
#include <iostream>
#include <allegro5/allegro5.h>
/********************************************************
 * FILENAME : Inputs.h
 * DESCRIPTION : Responsavel por analisar os inputs
 *
 * PUBLIC FUNCTIONS :
 * static Position getMousePosition()
 * static void setMousePosition(int x, int y)
 * static bool checkLeftClick()
 * static bool checkRightClick()
 * static bool checkMiddleClick()
 * static bool checkKeyDown(KeyCode keyCode)
 * static bool checkKeyUp(KeyCode keyCode)
 * static bool checkKeyIsPressing(KeyCode keyCode)
 * static void init()
 * static void update(ALLEGRO_EVENT event)
 * NOTES :
 *
 *
 * AUTHOR : Vinicius Rezende
 * START DATE : 22 Jun 23
 ********************************************************/
using namespace std;

#define SEEN 1
#define RELESE 2
typedef int KeyCode;
class Inputs
{
public:
    static unsigned char keys[ALLEGRO_KEY_MAX];
    static ALLEGRO_MOUSE_STATE state;
    static void checkKeyStatus()
    {
        for (int i = 0; i < ALLEGRO_KEY_MAX; i++)
        {
            keys[i] &= SEEN;
        }
    }

public:
    /*
      NAME : static Position getMousePosition()
      * DESCRIPTION : Função para pegar a posição do mouse
      * INPUTS :
      * PARAMETERS :
      *
      * RETURN :
      *   Position() posição que o mouse esta
      */
    static Position getMousePosition()
    {
        return Position(state.x, state.y);
    }
    /*
  NAME : static void setMousePosition(int x, int y)
  * DESCRIPTION : Função para definor a posição do mouse
  * INPUTS :
  * PARAMETERS :
  *   int x: valor do eixo X do mouse
  *   int y: valor do eixo Y do mouse
  * RETURN :
  *
  */
    static void setMousePosition(int x, int y)
    {
        state.x = x;
        state.y = y;
    }
    /*
  NAME : static bool checkLeftClick()
  * DESCRIPTION : Função para conferir se o botão esquerdo do meio do mouse foi clicado
  * INPUTS :
  * PARAMETERS :
  *
  * RETURN :
  *   true: o botão esquerdo foi clicado
  *   fale: o botão esquerdo não foi clicado
  */
    static bool checkLeftClick()
    {
        return state.buttons & 1;
    }
    /*
  NAME : static bool checkRightClick()
  * DESCRIPTION : Função para conferir se o botão direito do mouse foi clicado
  * INPUTS :
  * PARAMETERS :
  *
  * RETURN :
  *   true: o botão direito foi clicado
  *   fale: o botão direito não foi clicado
  */
    static bool checkRightClick()
    {

        return state.buttons & 2;
    }
    /*
   NAME : static bool checkMiddleClick()
   * DESCRIPTION : Função para conferir se o botão do meio do mouse foi clicado
   * INPUTS :
   * PARAMETERS :
   *
   * RETURN :
   *   true: o botão do meio foi clicado
   *   fale: o botão do meio não foi clicado
   */
    static bool checkMiddleClick()
    {

        return state.buttons & 4;
    }
    /*
    NAME : static bool checkKeyDown(KeyCode keyCode)
    * DESCRIPTION : Função para conferir se uma determinada tecla foi apertada
    * INPUTS :
    * PARAMETERS :
    *   KeyCode keyCode: valor da tecla que deseja conferir
    * RETURN :
    *   true: a tecla foi apertada
    *   fale: a tecla não foi apertada
    */
    static bool checkKeyDown(KeyCode keyCode)
    {
        return keys[keyCode] == 3;
    }
    /*
    NAME : static bool checkKeyUp(KeyCode keyCode)
    * DESCRIPTION : Função para conferir se uma determinada tecla foi solta
    * INPUTS :
    * PARAMETERS :
    *   KeyCode keyCode: valor da tecla que deseja conferir
    * RETURN :
    *   true: a tecla foi solta
    *   fale: a tecla não foi solta
    */
    static bool checkKeyUp(KeyCode keyCode)
    {
        return keys[keyCode] == 2;
    }
    /*
    NAME : static bool checkKeyIsPressing(KeyCode keyCode)
    * DESCRIPTION : Função para conferir se uma determinada tecla esta pressionada
    * INPUTS :
    * PARAMETERS :
    *   KeyCode keyCode: valor da tecla que deseja conferir
    * RETURN :
    *   true: a tecla esta pressionada
    *   fale: a tecla não esta pressionada
    */
    static bool checkKeyIsPressing(KeyCode keyCode)
    {
        return keys[keyCode];
    }
    /*
    NAME : static void init()
    * DESCRIPTION : Função para preencher todo o vetor  keys
    * INPUTS :
    * PARAMETERS :
    * RETURN :
    */
    static void init()
    {

        memset(keys, 0, sizeof(keys));
    }
    /*
    NAME : static void update(ALLEGRO_EVENT event)
    * DESCRIPTION : Função para atualizar o valor do input de acordo com os eventos pree definidos
    * INPUTS :
    * PARAMETERS :
    *ALLEGRO_EVENT event evento a ser verificado
    * RETURN :
    */
    static void update(ALLEGRO_EVENT event)
    {

        switch (event.type)
        {
        case ALLEGRO_EVENT_KEY_DOWN:
            Inputs::keys[event.keyboard.keycode] = SEEN | RELESE;
            break;
        case ALLEGRO_EVENT_KEY_UP:

            Inputs::keys[event.keyboard.keycode] &= RELESE;
            break;
        case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
            Inputs::setMousePosition(event.mouse.x, event.mouse.y);
          
            break;
        case ALLEGRO_EVENT_TIMER:
            Inputs::checkKeyStatus();
            break;
        }
    }
};
#endif
