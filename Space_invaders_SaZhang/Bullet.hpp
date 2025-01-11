#pragma once
#include "Entity.hpp"

template <typename T>
class Bullet : public Entity {
public:
    Bullet(int startX, int startY);

    void moveUp();
    void moveDown();
};

#include "Bullet.inl"