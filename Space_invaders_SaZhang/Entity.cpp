#include "Entity.hpp"

Entity::Entity(int startX, int startY, char sym) : x(startX), y(startY), symbol(sym) {}

Entity::~Entity() {}

void Entity::move(int dx, int dy) {
    x += dx;
    y += dy;
}

void Entity::draw() const {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << symbol;
}

int Entity::getX() const {
    return x;
}

int Entity::getY() const {
    return y;
}