#include <raylib.h>
#include "raygui.h"
#include "palette.h"

int main(void){
  const int width = 800;
  const int height = 800;

  InitWindow(width, height, "Palette App");
  
  Palette p;
  palette_init(&p);
  palette_add(&p, RED);
  palette_add(&p, BLUE);
  palette_add(&p, GREEN);

  const int ScreenFPS = 60;
  SetTargetFPS(ScreenFPS);

  while(!WindowShouldClose()){
    int posX = 50;
    int posY = 120;
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Hello World!", 10, 10, 40, DARKGRAY);
    if(GuiButton((Rectangle){10,60,120,30}, "Click Me")){
      // This block runs on the frame the button was clicked
      TraceLog(LOG_INFO, "Button Clicked!");
    }
    for(int i = 0; i < palette_count(&p); i++){
      DrawRectangle(posX, posY, 80, 50, palette_get(&p, i));
      posX += 100;
    }
    EndDrawing();
  }

  CloseWindow();
  return 0;
}

