#pragma once
#include "Entity.hpp"

class Player : public Entity {
private:
    int lives;

public:
    Player(int startX, int startY);

    void moveLeft();
    void moveRight();
    void loseLife();
    int getLives() const;
};
