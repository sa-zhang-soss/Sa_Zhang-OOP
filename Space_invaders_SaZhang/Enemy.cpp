#include "Enemy.hpp"

Enemy::Enemy(int startX, int startY) : Entity(startX, startY, 'E') {}

void Enemy::moveDown() {
    move(0, 1);
}
