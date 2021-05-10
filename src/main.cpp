#include <iostream>
#include "board.h"
#include "constants.h"

namespace
{
    int a;
}
namespace foo
{
    int a;
}

int main()
{

    InitWindow(FIELD_WIDTH*DOT_WIDTH,FIELD_HEIGHT*DOT_HEIGHT,"Snake");
    SetTargetFPS(60);

    

    Board b;
    while(!WindowShouldClose())
    {
        b.update();

        BeginDrawing();

           ClearBackground(BLACK);
           b.draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}