#pragma once
#include "Player.h"
#include "Enemy.h"

class Scene {
public:
    Scene();
    void Update(const char* keys, const char* preKeys);
    void Draw();

private:
    Player player_;
    Enemy enemyA_;
    Enemy enemyB_;
    Enemy enemyC_;  // 追加
    Enemy enemyD_;  // 追加
    bool isGame_;
    bool isGameOver_;
    bool isClear_;
};
