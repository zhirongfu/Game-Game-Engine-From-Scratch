#include "Alien.h"

Alien::Alien(const std::string& texturePath, int x, int y)
    : alien(texturePath, x, y) {}

void Alien::Update() {
    alien.UpdateYCoord(-3); // Move alien downward
}

void Alien::Draw() {
    Jelly::Renderer::Draw(alien);
}

int Alien::GetXCoord() const {
    return alien.GetXCoord();
}

int Alien::GetYCoord() const {
    return alien.GetYCoord();
}