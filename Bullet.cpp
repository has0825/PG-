#include "Bullet.h"
#include "Enemy.h" 
#include <Novice.h>

Bullet::Bullet(int x, int y, int speedX, int speedY)
    : posX_(x), posY_(y), speedX_(speedX), speedY_(speedY), active_(true) {}

void Bullet::Update() {
    if (!active_) return;
    posY_ += speedY_;
    if (posY_ < 0) active_ = false;
}

void Bullet::Draw() {
    if (active_) {
        Novice::DrawEllipse(posX_, posY_, 5, 5, 0.0f, WHITE, kFillModeSolid);
    }
}

bool Bullet::CheckCollision(Enemy& enemy) {
    int distX = posX_ - enemy.GetPosX();
    int distY = posY_ - enemy.GetPosY();
    int dist = (distX * distX) + (distY * distY);
    int radius = 5 + enemy.GetRadius();
    if (dist <= radius * radius) {
        active_ = false;
        return true;
    }
    return false;
}

bool Bullet::IsActive() const { return active_; }
