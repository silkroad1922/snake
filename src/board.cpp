#include "board.h"

 Board::Board():snake(std::make_unique<Snake>()),food({float(GetRandomValue(0,FIELD_WIDTH-1)),float(GetRandomValue(0,FIELD_HEIGHT-1))}) {}
void Board::setFood()
{
    food.x = GetRandomValue(0,FIELD_WIDTH-1);
    food.y = GetRandomValue(0,FIELD_HEIGHT-1);

    for (size_t i = 0; i < snake->snake_dots.size(); i++)
    {
        if(snake->snake_dots[i].x == food.x && snake->snake_dots[i].y == food.y)setFood();
    }
}

void Board::draw()
{
    if(gameOver)
    {
        DrawText("GameOver,press ESC",GetScreenWidth()/2 - MeasureText("GameOver,press ESC", 20)/2, GetScreenHeight()/2 - 50, 20, GRAY);
    }else{
    snake->draw();

    DrawRectangle(food.x*FIELD_WIDTH,food.y*FIELD_HEIGHT,DOT_WIDTH,DOT_HEIGHT,RED);
    }
}

void Board::checkFood()
{
    if(snake->snake_dots[0].x == food.x && snake->snake_dots[0].y == food.y)
    {
        snake->snake_dots.push_back(Vector2{0,0});
        setFood();
    }
}

void Board::update()
{
    dt += GetFrameTime() * 1.2;



    handlerEvent();   

    if(dt>0.2)
    {
        dt = 0;
        if(!snake->alive())gameOver = true;
        checkFood();
        switch (event)
        {
            case KEY_LEFT:snake->setDir(Snake::Diretion::LEFT);break;
            case KEY_RIGHT:snake->setDir(Snake::Diretion::RIGHT);break;
            case KEY_UP:snake->setDir(Snake::Diretion::UP);break;
            case KEY_DOWN:snake->setDir(Snake::Diretion::DOWN);break;
        }
        snake->update();
    }

}

void Board::setEvent(KeyboardKey k)
{
    event = k;
}

void Board::handlerEvent()
{
        if(IsKeyReleased(KEY_RIGHT) && event != KEY_LEFT)event = KEY_RIGHT;
        if(IsKeyReleased(KEY_LEFT)  && event != KEY_RIGHT)event = KEY_LEFT;
        if(IsKeyReleased(KEY_UP)    && event != KEY_DOWN)event = KEY_UP;
        if(IsKeyReleased(KEY_DOWN)  && event != KEY_UP)event = KEY_DOWN;

        setEvent(event);
}