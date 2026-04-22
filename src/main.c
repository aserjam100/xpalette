#include <raylib.h>
#include "raygui.h"
#include "palette.h"
#include "ui.h"

int main(void){
  const int width = 800;
  const int height = 800;

  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(width, height, "Palette App");
  SetWindowMinSize(600, 600);
  const int ScreenFPS = 60;
  SetTargetFPS(ScreenFPS);

  Palette p;
  palette_init(&p);
  palette_add(&p, RED);
  palette_add(&p, BLUE);
  palette_add(&p, GREEN);

  while(!WindowShouldClose()){
    Layout layout = ui_compute_layout(GetScreenWidth(), GetScreenHeight());

    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawRectangleRec(layout.picker, (Color){255, 200, 200, 255});
    DrawRectangleRec(layout.controls, (Color){200, 255, 200, 255});
    DrawRectangleRec(layout.palette, (Color){200, 200, 255, 255});

    DrawText("PICKER", layout.picker.x + 10, layout.picker.y + 10, 20, DARKGRAY);
    DrawText("CONTROLS", layout.controls.x + 10, layout.controls.y + 10, 20, DARKGRAY);
    DrawText("PALETTE", layout.palette.x + 10, layout.palette.y + 10, 20, DARKGRAY);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}

