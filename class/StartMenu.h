
#ifndef StartMenu_H
#define StartMenu_H
#include "GameObject.h"
#include "Inputs.h"
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
    StartMenu(float x, float y, const char *path)
    {

        this->x = x;
        this->y = y;
        this->image = al_load_bitmap(path);
    }
 
    void changePressState(bool pressed)
    {
        this->pressed = pressed;
        this->iniciar = pressed;
    }
    bool checkBtnIsPress()
    {
        return this->pressed;
    }
    bool getStart()
    {
        return this->iniciar;
    }
    void update()
    {

        if (
            Inputs::getMousePosition().eixoX > D_HEIGTH / 2 - al_get_bitmap_height(this->image) && Inputs::getMousePosition().eixoX < D_HEIGTH)
        {
            this->iniciar = true;
            return;
        }
    }
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
    ~StartMenu()
    {
        pressed = true;
        al_destroy_bitmap(this->image);
    }
};
#endif