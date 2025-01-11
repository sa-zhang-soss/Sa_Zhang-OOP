#include "House.hpp"

House::House(int startX, int startY) : Entity(startX, startY, '#'), health(3) {}

void House::takeDamage() {
    if (health > 0) --health;
    if (health == 2) symbol = 'X';
    else if (health == 1) symbol = '.';
    else symbol = ' ';
}

bool House::isDestroyed() const {
    return health <= 0;
}

void House::draw() const {
    if (!isDestroyed()) Entity::draw();
}
