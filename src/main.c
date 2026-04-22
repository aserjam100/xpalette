#include <raylib.h>
#include "raygui.h"

int main(void){
  const int width = 800;
  const int height = 800;

  InitWindow(width, height, "Palette App");

  const int ScreenFPS = 60;
  SetTargetFPS(ScreenFPS);

  while(!WindowShouldClose()){
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Hello World!", 10, 10, 40, DARKGRAY);
    if(GuiButton((Rectangle){10,60,120,30}, "Click Me")){
      // This block runs on the frame the button was clicked
      TraceLog(LOG_INFO, "Button Clicked!");
    }
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
