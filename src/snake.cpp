#include "snake.h"

Snake::Snake()
{
    snake_dots.resize(3);
    dir = Diretion::RIGHT;

    for (size_t i = 0; i < snake_dots.size(); i++)
    {
        snake_dots[i].x = FIELD_WIDTH/2-i;
        snake_dots[i].y = FIELD_HEIGHT/2;
    }
}

void Snake::update()
{
    for (size_t i = snake_dots.size()-1; i > 0; i--)
    {
        snake_dots[i]=snake_dots[i-1];
    }
    switch (dir)
    {
        case Diretion::LEFT:snake_dots[0].x -= 1;break;
        case Diretion::RIGHT:snake_dots[0].x += 1;break;
        case Diretion::UP:snake_dots[0].y -= 1;break;
        case Diretion::DOWN:snake_dots[0].y += 1;break;
    }
}

void Snake::draw()
{
    for (size_t i = 0; i < snake_dots.size(); i++)
    {
        if(i==0)
        {
            DrawRectangle(snake_dots[i].x*FIELD_WIDTH,snake_dots[i].y*FIELD_HEIGHT,DOT_WIDTH,DOT_HEIGHT,GREEN);
        }else
        {
            DrawRectangle(snake_dots[i].x*FIELD_WIDTH,snake_dots[i].y*FIELD_WIDTH,DOT_WIDTH,DOT_HEIGHT,BLUE);
        }
    }
}

bool Snake::alive()
{
    if(snake_dots.size()>3)
    {
        for (size_t i = 1; i < snake_dots.size()-1; i++)
        {
            if(snake_dots[0].x == snake_dots[i].x && snake_dots[0].y == snake_dots[i].y)
            return false;
        }
    }
    if(snake_dots[0].x < 0) return false;
    if(snake_dots[0].y < 0)return false;
    if(snake_dots[0].x > FIELD_HEIGHT-1)return false;
    if(snake_dots[0].y > FIELD_WIDTH-1)return false;

    return true;
}

void Snake::setDir(Diretion d)
{
    dir = d; 
}