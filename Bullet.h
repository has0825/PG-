#pragma once

class Enemy; 

class Bullet {
public:
    Bullet(int x, int y, int speedX, int speedY);
    void Update();
    void Draw();
    bool CheckCollision(Enemy& enemy);
    bool IsActive() const;

private:
    int posX_, posY_;
    int speedX_, speedY_;
    bool active_;
};
