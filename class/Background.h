
#ifndef Background_H
#define Background_H

class Background : public GameObject
{
protected:
    float x;
    float y;
    float velX;
    float velY;
    int dirX;
    int dirY;

    int width;
    int height;
    ALLEGRO_BITMAP *image;

public:
    Background(float x, float y, float velX, float velY, int dirX, int dirY, int width, int height,const char *path)
    {

        this->x = x;
        this->y = y;
        this->velX = velX;
        this->velY = velY;
        this->dirX = dirX;
        this->dirY = dirY;
        this->width = width;
        this->height = height;
        this->image = al_load_bitmap(path);
    }
    void start()
    {
    }
    void update()
    {
        this->x += this->velX * this->dirX;
        if (this->x + this->width <= 0)
        {
            this->x = 0;
        }
    }
    void draw()
    {

        al_draw_scaled_bitmap(this->image,
                              0, 0, al_get_bitmap_width(this->image), al_get_bitmap_height(this->image),
                              this->x, this->y, D_WIDHT, D_HEIGTH,
                              0);
        if (this->x + this->width < this->width)
        {
            al_draw_scaled_bitmap(this->image,
                                  0, 0, al_get_bitmap_width(this->image), al_get_bitmap_height(this->image),
                                  this->x + this->width, this->y, D_WIDHT, D_HEIGTH,
                                  0);
        }
    }
    ~Background(){
        al_destroy_bitmap(this->image);
    }
};
#endif