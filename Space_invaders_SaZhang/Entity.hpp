#pragma once
#include <iostream>
#include <windows.h>
#include <algorithm> 

class Entity {
protected:
    int x, y;
    char symbol;

public:
    Entity(int startX, int startY, char sym);
    virtual ~Entity();

    virtual void move(int dx, int dy);
    virtual void draw() const;

    int getX() const;
    int getY() const;
};