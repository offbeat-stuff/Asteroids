#include <raylib.h>

#include "common.h"
#include "ui.h"

#include <stdlib.h>

void draw_centered_text(const char *text, int posX, int posY, int fontSize, Color color, int padding, BUTTON *arr, int index)
{
  int width = MeasureText(text, fontSize);
  int height = fontSize;
  int xPos = posX - (width / 2);
  int yPos = posY - (height / 2);
  DrawText(text, xPos, yPos, fontSize, color);

  arr[index].start = (Vector2){xPos - padding, yPos - padding};
  arr[index].size = (Vector2){width + (2 * padding), height + (2 * padding)};

  DrawRectangleLines(xPos - padding, yPos - padding, width + (2 * padding), height + (2 * padding), color);
}

#define reset_size(r, y)                \
  {                                     \
    r.size = y;                         \
    r.data = calloc(y, sizeof(BUTTON)); \
  }

BUTTONS draw_start_screen(BUTTONS *result)
{
  reset_size((*result), 3);
  int bias = -(HEIGHT / 4);
  int step = 50;
  draw_centered_text("Start Game", WIDTH / 2, (HEIGHT / 2) + bias, 20, RED, 10, result->data, 0);
  draw_centered_text("What even is this?", WIDTH / 2, (HEIGHT / 2) + bias + step, 20, RED, 10, result->data, 1);
  draw_centered_text("Quit", WIDTH / 2, (HEIGHT / 2) + bias + (2 * step), 20, RED, 10, result->data, 2);
}

BUTTONS draw_ui(APP_STATE state)
{
  BUTTONS result = {};
  result.size = 0;
  result.data = (BUTTON *)0;
  int border_padding = 10;
  DrawRectangleLines(border_padding, border_padding, WIDTH - (2 * border_padding), HEIGHT - (2 * border_padding), WHITE);

  switch (state)
  {
  case START_SCREEN:
  {
    draw_start_screen(&result);
  }
  break;
  case END_SCREEN:
  {
    int bias = -(HEIGHT / 4);
    int step = 50;
    draw_centered_text("Restart Game", WIDTH / 2, (HEIGHT / 2) + bias, 20, RED, 10, result.data, 0);
    draw_centered_text("What even is this?", WIDTH / 2, (HEIGHT / 2) + bias + step, 20, RED, 10, result.data, 1);
    draw_centered_text("Quit", WIDTH / 2, (HEIGHT / 2) + bias + (2 * step), 20, RED, 10, result.data, 2);
  }
  break;
  default:
    break;
  }

  return result;
}