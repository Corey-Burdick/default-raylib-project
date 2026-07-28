#include <raylib.h>
#include <game.h>
#include <ctime>
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

  InitWindow(1280, 720, "Raylib Sample Project | FPS: 0");

  Game game;
  g_gameInstance = &game;
  SetRandomSeed(time(NULL));

  #ifdef __EMSCRIPTEN__
  emscripten_set_main_loop(updateDrawFrame, 0, 1);
  #else
  //SetTargetFPS(60);
  while (!WindowShouldClose()) {
    updateDrawFrame();
  }
  #endif

}
