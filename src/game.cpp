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
    ClearBackground(RAYWHITE);
    BeginShaderMode(_fragShader);
      DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), WHITE);
    EndShaderMode();
  EndDrawing();
}
