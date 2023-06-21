
#ifndef INPUTS_H
#define INPUTS_H
#include <iostream>
#include <allegro5/allegro5.h>
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
    static Position getMousePosition()
    {
        return Position(state.x, state.y);
    }
    static void setMousePosition(int x, int y)
    {
        state.x = x;
        state.y = y;
    }
    static bool checkLeftClick()
    {
        return state.buttons & 1;
    }
    static bool checkRightClick()
    {

        return state.buttons & 2;
    }
    static bool checkMiddleClick()
    {

        return state.buttons & 4;
    }
    static bool checkKeyDown(KeyCode keyCode)
    {
        return keys[keyCode] == 3;
    }
    static bool checkKeyUp(KeyCode keyCode)
    {
        return keys[keyCode] == 2;
    }
    static bool checkKeyIsPressing(KeyCode keyCode)
    {
        return keys[keyCode];
    }
    static void init()
    {
  
        memset(keys, 0, sizeof(keys));

    }
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
