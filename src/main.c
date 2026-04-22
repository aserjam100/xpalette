#include <raylib.h>

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
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
