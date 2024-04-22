#include <raylib.h>

#include "include/common.h"
#include "include/ui.h"

void draw_centered_text(const char *text, int posX, int posY, int fontSize, Color color, int padding)
{
  int width = MeasureText(text, fontSize);
  int height = fontSize;
  int xPos = posX - (width / 2);
  int yPos = posY - (height / 2);
  DrawText(text, xPos, yPos, fontSize, color);
  DrawRectangleLines(xPos - padding, yPos - padding, width + (2 * padding), height + (2 * padding), color);
}

void draw_ui(APP_STATE state)
{
  int border_padding = 10;
  DrawRectangleLines(border_padding, border_padding, WIDTH - (2 * border_padding), HEIGHT - (2 * border_padding), WHITE);

  switch (state)
  {
  case UI:
  {
    int bias = -(HEIGHT / 4);
    int step = 50;
    draw_centered_text("Start Game", WIDTH / 2, (HEIGHT / 2) + bias, 20, RED, 10);
    draw_centered_text("What even is this?", WIDTH / 2, (HEIGHT / 2) + bias + step, 20, RED, 10);
    draw_centered_text("Quit", WIDTH / 2, (HEIGHT / 2) + bias + (2 * step), 20, RED, 10);
  }
  break;
  case END_SCREEN:
  {
    int bias = -(HEIGHT / 4);
    int step = 50;
    draw_centered_text("Restart Game", WIDTH / 2, (HEIGHT / 2) + bias, 20, RED, 10);
    draw_centered_text("What even is this?", WIDTH / 2, (HEIGHT / 2) + bias + step, 20, RED, 10);
    draw_centered_text("Quit", WIDTH / 2, (HEIGHT / 2) + bias + (2 * step), 20, RED, 10);
  }
  break;
  default:
    break;
  }
}