#include <raylib.h>

#include "include/common.h"
#include "include/ui.h"

#include <stdio.h>

int main()
{
  InitWindow(WIDTH, HEIGHT, "Asteroids");

  APP_STATE app_state = UI;

  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(BLACK);
    draw_ui(app_state);
    EndDrawing();
  }

  CloseWindow();
}