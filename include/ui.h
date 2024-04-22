#include "common.h"

typedef struct BUTTON_DATA_STRUCT
{
  Vector2 start;
  Vector2 size;
} BUTTON;

typedef struct BUTTON_DATA_ARRAY_S
{
  int size;
  BUTTON *data;
} BUTTONS;

BUTTONS draw_ui(APP_STATE);