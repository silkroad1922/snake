#ifndef BOARD_H
#define BOARD_H
#pragma once

#include "snake.h"
#include <raylib.h>
#include <cstddef>
#include <unistd.h>
#include <memory>
#include <chrono>



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
    std::chrono::_V2::system_clock::time_point start;
    std::chrono::_V2::system_clock::time_point finish;
    std::chrono::duration<double> delta;

};

#endif