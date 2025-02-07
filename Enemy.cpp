#include "Enemy.h"
#include <Novice.h>

Enemy::Enemy(int x, int y, int speedX, int speedY)
    : posX_(x), posY_(y), speedX_(speedX), speedY_(speedY), radius_(15), active_(true) {}

void Enemy::Update() {
    if (!active_) return;
    posX_ += speedX_;
    posY_ += speedY_;
    if (posX_ <= 0 || posX_ >= 1280) speedX_ *= -1;
    if (posY_ <= 0 || posY_ >= 720) speedY_ *= -1;
}

void Enemy::Draw() {
    if (active_) {
        Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, RED, kFillModeSolid);
    }
}

void Enemy::SetActive(bool active) { active_ = active; }
bool Enemy::IsActive() const { return active_; }

int Enemy::GetPosX() const { return posX_; }
int Enemy::GetPosY() const { return posY_; }
int Enemy::GetRadius() const { return radius_; }
