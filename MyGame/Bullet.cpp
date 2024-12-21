#include "Bullet.h"

Bullet::Bullet(const std::string& texturePath, int x, int y)
    : bullet(texturePath, x, y) {}

void Bullet::Update() {
    bullet.UpdateYCoord(10); // Move bullet upward
}

void Bullet::Draw() {
    Jelly::Renderer::Draw(bullet);
}

int Bullet::GetXCoord() const {
    return bullet.GetXCoord();
}

int Bullet::GetYCoord() const {
    return bullet.GetYCoord();
}