#include "Player.h"
#include <Novice.h>

Player::Player() : posX_(640), posY_(600), speed_(5), radius_(20), canShoot_(true) {}

void Player::Update(const char* keys, const char* preKeys) {
    // 移動処理（画面外に出ないように制限）
    if (keys[DIK_A] && posX_ - radius_ > 0) {
        posX_ -= speed_;
    }
    if (keys[DIK_D] && posX_ + radius_ < 1280) {
        posX_ += speed_;
    }
    if (keys[DIK_W] && posY_ - radius_ > 0) {
        posY_ -= speed_;
    }
    if (keys[DIK_S] && posY_ + radius_ < 720) {
        posY_ += speed_;
    }

    // 単発撃ち（キーを押した瞬間のみ発射）
    if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0 && canShoot_) {
        Shoot();
        canShoot_ = false;
    }
    if (keys[DIK_SPACE] == 0) {
        canShoot_ = true;  // キーを離したら発射可能にする
    }

    // 弾の更新
    for (auto& bullet : bullets_) {
        bullet.Update();
    }
}

void Player::Draw() {
    Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, BLUE, kFillModeSolid);
    for (auto& bullet : bullets_) {
        bullet.Draw();
    }
}

void Player::Shoot() {
    bullets_.emplace_back(posX_, posY_ - radius_, 0, -8);
}

bool Player::CheckCollision(Enemy& enemy) {
    int distX = posX_ - enemy.GetPosX();
    int distY = posY_ - enemy.GetPosY();
    int dist = (distX * distX) + (distY * distY);
    int radiusSum = radius_ + enemy.GetRadius();
    return dist <= radiusSum * radiusSum;
}

std::vector<Bullet>& Player::GetBullets() {
    return bullets_;
}

int Player::GetPosX() const { return posX_; }
int Player::GetPosY() const { return posY_; }
