#ifndef SNAKE_H
#define SNAKE_H
#pragma once

#include <raylib.h>
#include <vector>
#include "constants.h"
#include <math.h>


class Snake
{

    public:

        enum class Diretion {LEFT,RIGHT,UP,DOWN};
        std::vector<Vector2> snake_dots;

        Snake();
        bool alive();
        void update();
        void draw();
        void setDir(Diretion);

    private:
    
        Diretion dir;
};

#endif