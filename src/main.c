#include <raylib.h>

#include "include/common.h"
#include "include/ui.h"

#include <stdlib.h>

int isButtonPressed(BUTTON button, float x, float y)
{
  return (button.start.x < x && x < (button.start.x + button.size.x) && button.start.y < y && y < (button.start.y + button.size.y));
}

int main()
{
  InitWindow(WIDTH, HEIGHT, "Asteroids");

  APP_STATE app_state = UI;
  int init = 0;
  BUTTONS buttons = {};

  while (!WindowShouldClose())
  {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
      if (init)
      {
        float x = GetMouseX();
        float y = GetMouseY();
        int pressed = -1;
        if (buttons.size > 0 && isButtonPressed(buttons.data[0],x,y)) {
          app_state = (app_state + 1) % 3;
        }
      }
    }
    BeginDrawing();
    ClearBackground(BLACK);
    {
      init = 1;
      buttons = draw_ui(app_state);
    }
    EndDrawing();
  }

  if (init)
  {
    free(buttons.data);
  }

  CloseWindow();
}