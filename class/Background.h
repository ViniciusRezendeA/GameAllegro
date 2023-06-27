#ifndef Background_H
#define Background_H
/*
 * FILENAME : Background.h
 * DESCRIPTION : Responsavel pela criação do Background
 *
 * PUBLIC FUNCTIONS :
 * ~Background()
 * void update()
 * void draw()
 * Background(float x, float y, float velX, float velY, int dirX, int dirY, int width, int height, const char *path)
 * NOTES :
 *
 *
 * AUTHOR : Vinicius Rezende
 * START DATE : 22 Jun 23
 */

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
    /*
     NAME :  Background(float x, float y, float velX, float velY, int dirX, int dirY, int width, int height, const char *path)
     * DESCRIPTION : construtor da classe Background
     * INPUTS :
     * PARAMETERS :
     * float x: posição da imagem no eixo X
     * float y: posição da imagem no eixo Y
     * float velX: velocidade da imagem no eixo X
     * float velY:velocidade da imagem no eixo Y
     * int dirX: direção da imagem no eixo X
     * int dirY: direção da imagem no eixo Y
     * int width: tamanho da imagem
     * int height: altura da imagem
     * const char *path: camimho para imagem
     * RETURN :
     */
    Background(float x, float y, float velX, float velY, int dirX, int dirY, int width, int height, const char *path)
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

    /*
    NAME : void update()
    * DESCRIPTION : Função para atualizar a posição da imagem de acordo com a veloacidade e a direção
    * INPUTS :
    * PARAMETERS :
    *
    * RETURN :
    */
    void update()
    {
        this->x += this->velX * this->dirX;
        if (this->x + this->width <= 0)
        {
            this->x = 0;
        }
    }
    /*
    NAME : void draw()
    * DESCRIPTION : responsavel pela exibição do background
    * INPUTS :
    * PARAMETERS :
    *
    * RETURN :
    */
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
    /**
    NAME : ~Background()
    * DESCRIPTION : responsavel por destroir o bitmap do background
    * INPUTS :
    * PARAMETERS :
    *
    * RETURN :
    */
    ~Background()
    {
        al_destroy_bitmap(this->image);
    }
};
#endif