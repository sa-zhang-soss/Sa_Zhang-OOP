#pragma once
#include "Entity.hpp"

class Enemy : public Entity {
public:
    Enemy(int startX, int startY);

    void moveDown();
};
