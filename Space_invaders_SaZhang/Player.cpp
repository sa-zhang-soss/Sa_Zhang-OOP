#include "Player.hpp"

Player::Player(int startX, int startY) : Entity(startX, startY, 'A'), lives(3) {}

void Player::moveLeft() {
    if (x > 1) move(-1, 0);
}

void Player::moveRight() {
    if (x < 78) move(1, 0);
}

void Player::loseLife() {
    if (lives > 0) --lives;
}

int Player::getLives() const {
    return lives;
}