#include <raylib.h>

#include "include/common.h"
#include "include/ui.h"

int main() {
  InitWindow(WIDTH,HEIGHT,"Asteroids");

  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(BLACK);
    draw_ui();
    EndDrawing();
  }
     
  CloseWindow();
}