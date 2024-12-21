#pragma once
#include "Jelly.h"
#include "../pch.h"

class Alien {
public:
    Alien(const std::string& texturePath, int x, int y);
    void Update();
    void Draw();
    int GetXCoord() const;
    int GetYCoord() const;

private:
    Jelly::Unit alien;
};