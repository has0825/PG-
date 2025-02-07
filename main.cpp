#include <Novice.h>
#include "Scene.h"

const char kWindowTitle[] = "LC1B_12_シミズグチ＿ハル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    // ライブラリの初期化
    Novice::Initialize(kWindowTitle, 1280, 720);

    // キー入力
    char keys[256] = { 0 };
    char preKeys[256] = { 0 };
     
    // シーン管理クラス
    Scene scene;

    while (Novice::ProcessMessage() == 0) {
        Novice::BeginFrame();

        memcpy(preKeys, keys, 256);
        Novice::GetHitKeyStateAll(keys);

        // シーンの更新と描画
        scene.Update(keys, preKeys);
        scene.Draw();

        Novice::EndFrame();

        // ESCキーでゲーム終了
        if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
            break;
        }
    }

    // ライブラリの終了
    Novice::Finalize();
    return 0;
}
