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
  EndDrawing();
}
