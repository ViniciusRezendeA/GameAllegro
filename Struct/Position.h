#ifndef POSITION_H
#define POSITION_H
struct Position
{
    float eixoX;
    float eixoY;

    Position(float eixoX,float eixoY)
    {
        this->eixoX = eixoX;
        this->eixoY = eixoY;
    };
    
};
#endif