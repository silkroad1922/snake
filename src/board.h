#ifndef BOARD_H
#define BOARD_H
#pragma once

#include "snake.h"
#include <raylib.h>
#include <cstddef>
#include <memory>
#include <chrono>
#include <io.h>



class Board
{
public:
    Board();
    void draw();
    void setFood();
    void checkFood();
    void update();
    void setEvent(KeyboardKey);
    void handlerEvent();

 private:
 
    bool gameOver = false;
    Vector2 food;
    std::unique_ptr<Snake> snake;
    KeyboardKey event;
    float dt;
    //std::chrono::system_clock::time_point start;
   // std::chrono::system_clock::time_point finish;
    
   // std::chrono::duration<double> delta;

};

#endif