#pragma once
#include "Entity.hpp"

class House : public Entity {
private:
    int health;

public:
    House(int startX, int startY);

    void takeDamage();
    bool isDestroyed() const;
    void draw() const override;
};