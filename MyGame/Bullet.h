#pragma once
#include "Jelly.h"
#include "../pch.h"
class Bullet {
public:
    Bullet(const std::string& texturePath, int x, int y);
    void Update();
    void Draw();

    int GetXCoord() const;
    int GetYCoord() const;

private:
    Jelly::Unit bullet;
};