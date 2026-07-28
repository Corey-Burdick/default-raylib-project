#include <raylib.h>

int main() {

  InitWindow(400, 300, "Raylib Sample Project");

  while(!WindowShouldClose()) {
    SetWindowTitle(TextFormat("Raylib Sample Project | FPS: %i", GetFPS()));
    BeginDrawing();
      ClearBackground(RAYWHITE);
    EndDrawing();
  }
}
