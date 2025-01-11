#pragma once
#include "Player.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"
#include "House.hpp"
#include <deque>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <algorithm> 

class Game {
private:
    Player player;
    std::vector<Enemy> enemies;
    std::deque<Bullet<int>> playerBullets;
    std::deque<Bullet<int>> enemyBullets;
    std::vector<House> houses;
    bool running;
    bool moveRight;
    int score;
    int enemySpeed;
    int speedTimer;

    void drawBorder();
    void moveEnemies();
    void handleEnemyShooting();
    void checkCollisions();

public:
    Game();

    void draw();
    void handleInput();
    void update();
    void run();
    bool isRunning() const;
};