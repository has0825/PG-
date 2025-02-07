#include "Scene.h"
#include <Novice.h>

Scene::Scene()
    : player_(),
    enemyA_(100, 300, 4, 2),    // 速さ変更
    enemyB_(300, 300, -3, 1),   // 速さ変更
    enemyC_(500, 200, 2, -2),   // 速さ変更
    enemyD_(700, 400, -5, -3),  // 速さ変更
    isGame_(false),
    isGameOver_(false),
    isClear_(false) {}

void Scene::Update(const char* keys, const char* preKeys) {
    // タイトル画面で Enter を押したらゲーム開始
    if (!isGame_ && preKeys[DIK_RETURN] == 0 && keys[DIK_RETURN] != 0) {
        isGame_ = true;
        isGameOver_ = false;
        isClear_ = false;
        enemyA_.SetActive(true);
        enemyB_.SetActive(true);
        enemyC_.SetActive(true);
        enemyD_.SetActive(true);
        player_ = Player(); // プレイヤーを初期状態にリセット
    }

    // ゲームオーバーまたはクリア時に Enter を押すとタイトルに戻る
    if ((isGameOver_ || isClear_) && preKeys[DIK_RETURN] == 0 && keys[DIK_RETURN] != 0) {
        isGame_ = false;
        isGameOver_ = false;
        isClear_ = false;
        enemyA_ = Enemy(100, 300, 4, 2);    // 速さ変更
        enemyB_ = Enemy(300, 300, -3, 1);   // 速さ変更
        enemyC_ = Enemy(500, 200, 2, -2);   // 速さ変更
        enemyD_ = Enemy(700, 400, -5, -3);  // 速さ変更
        player_ = Player();
    }

    if (isGame_ && !isGameOver_ && !isClear_) {
        player_.Update(keys, preKeys);
        if (enemyA_.IsActive()) enemyA_.Update();
        if (enemyB_.IsActive()) enemyB_.Update();
        if (enemyC_.IsActive()) enemyC_.Update();
        if (enemyD_.IsActive()) enemyD_.Update();

        // 弾と敵の当たり判定
        std::vector<Bullet>& bullets = player_.GetBullets();
        for (auto& bullet : bullets) {
            if (enemyA_.IsActive() && bullet.CheckCollision(enemyA_)) {
                enemyA_.SetActive(false);
            }
            if (enemyB_.IsActive() && bullet.CheckCollision(enemyB_)) {
                enemyB_.SetActive(false);
            }
            if (enemyC_.IsActive() && bullet.CheckCollision(enemyC_)) {
                enemyC_.SetActive(false);
            }
            if (enemyD_.IsActive() && bullet.CheckCollision(enemyD_)) {
                enemyD_.SetActive(false);
            }
        }

        // すべての敵が消えたらクリア
        if (!enemyA_.IsActive() && !enemyB_.IsActive() && !enemyC_.IsActive() && !enemyD_.IsActive()) {
            isClear_ = true;
        }

        // 敵とプレイヤーの当たり判定
        if ((enemyA_.IsActive() && player_.CheckCollision(enemyA_)) ||
            (enemyB_.IsActive() && player_.CheckCollision(enemyB_)) ||
            (enemyC_.IsActive() && player_.CheckCollision(enemyC_)) ||
            (enemyD_.IsActive() && player_.CheckCollision(enemyD_))) {
            isGameOver_ = true;
        }
    }
}

void Scene::Draw() {
    if (!isGame_) {
        Novice::ScreenPrintf(500, 360, "Press ENTER to Start", WHITE);
    }
    else if (isGameOver_) {
        Novice::ScreenPrintf(500, 360, "Game Over! Press ENTER to Restart", WHITE);
    }
    else if (isClear_) {
        Novice::ScreenPrintf(500, 360, "Game Clear! Press ENTER to Restart", WHITE);
    }
    else {
        player_.Draw();
        if (enemyA_.IsActive()) enemyA_.Draw();
        if (enemyB_.IsActive()) enemyB_.Draw();
        if (enemyC_.IsActive()) enemyC_.Draw();
        if (enemyD_.IsActive()) enemyD_.Draw();
    }
}
