#include <game.h>

Game::Game() {
#if defined(PLATFORM_WEB)
  _fragShader = LoadShader(0, "assets/shaders/gradientWeb.fs");
#else
  _fragShader = LoadShader(0, "assets/shaders/gradient.fs");
#endif
}

Game::~Game() {
  UnloadShader(_fragShader);
}

void Game::update() {
  SetWindowTitle(TextFormat("Raylib Sample Project | FPS: %i", GetFPS()));

  int resolutionLoc = GetShaderLocation(_fragShader, "resolution");
  float resolution[2] = {(float)GetScreenWidth(), (float)GetScreenHeight()};
  SetShaderValue(_fragShader, resolutionLoc, resolution, SHADER_UNIFORM_VEC2); 
}

void Game::draw() {
  BeginDrawing();
    ClearBackground(BLACK);
    BeginShaderMode(_fragShader);
      DrawTriangle({(float)GetScreenWidth() / 2, 0.0f}, {0.0f, (float)GetScreenHeight()}, {(float)GetScreenWidth(), (float)GetScreenHeight()}, WHITE);
    EndShaderMode();
  EndDrawing();
}
