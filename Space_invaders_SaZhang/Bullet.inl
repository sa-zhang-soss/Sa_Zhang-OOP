#include "Bullet.hpp"

template <typename T>
Bullet<T>::Bullet(int startX, int startY) : Entity(startX, startY, '^') {}

template <typename T>
void Bullet<T>::moveUp() {
    move(0, -1);
}

template <typename T>
void Bullet<T>::moveDown() {
    move(0, 1);
}