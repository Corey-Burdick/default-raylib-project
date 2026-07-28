#include <game.h>

Game::Game() {

}

Game::~Game() {

}

void Game::update() {
  SetWindowTitle(TextFormat("Raylib Sample Project | FPS: %i", GetFPS()));
}

void Game::draw() {
  BeginDrawing();
    ClearBackground(RAYWHITE);
    for (int x = 0; x * 4 < GetScreenWidth(); x++) {
      for (int y = 0; y * 4 < GetScreenHeight(); y++) {
        int r = GetRandomValue(0, 255);
        int g = GetRandomValue(0, 255);
        int b = GetRandomValue(0, 255);
        Color randomColor = {static_cast<unsigned char>(r), static_cast<unsigned char>(g), static_cast<unsigned char>(b), 255};
        DrawRectangle(x * 4, y * 4, 4, 4, randomColor);
      }
    }
  EndDrawing();
}
