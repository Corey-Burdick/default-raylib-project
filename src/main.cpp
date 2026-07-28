#include <raylib.h>
#include <game.h>
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

Game* g_gameInstance = nullptr;

void updateDrawFrame(void) {
  if (g_gameInstance) {
    g_gameInstance->update();
    g_gameInstance->draw();
  }
}

int main() {
  
  Game game;
  g_gameInstance = &game;

  InitWindow(400, 300, "Raylib Sample Project | FPS: 0");

  #ifdef __EMSCRIPTEN__
  emscripten_set_main_loop(updateDrawFrame, 0, 1);
  #else
  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    updateDrawFrame();
  }
  #endif

  CloseWindow();
}
