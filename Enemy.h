#pragma once

class Enemy {
public:
    Enemy(int x, int y, int speedX, int speedY);
    void Update();
    void Draw();
    void Respawn();

    int GetPosX() const;
    int GetPosY() const;
    int GetRadius() const;

    void SetActive(bool active);
    bool IsActive() const;

private:
    int posX_, posY_;
    int speedX_, speedY_;
    int radius_;
    bool active_;
};
