#pragma once
#include "Bullet.h"
#include "Enemy.h"
#include <vector>

class Player {
public:
    Player();
    void Update(const char* keys, const char* preKeys);
    void Draw();
    void Shoot();
    bool CheckCollision(Enemy& enemy);
    std::vector<Bullet>& GetBullets();

    int GetPosX() const;
    int GetPosY() const;

private:
    int posX_, posY_;
    int speed_;
    int radius_;
    std::vector<Bullet> bullets_;
    bool canShoot_;  // 連射防止用フラグ
};
