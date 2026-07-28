#pragma once
#include <raylib.h>

class Game {
  private:
    Shader _fragShader;
    int _timeLoc;

  public:
    Game();
    ~Game();

    void update();
    void draw();
};
