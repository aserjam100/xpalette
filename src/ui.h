#ifndef UI_H
#define UI_H
#include <raylib.h>

typedef struct{
  Rectangle picker;
  Rectangle controls;
  Rectangle palette;
} Layout;

Layout ui_compute_layout(int screen_w, int screen_h);

#endif
