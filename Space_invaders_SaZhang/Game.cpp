#include "Game.hpp"

Game::Game() : player(40, 23), running(true), moveRight(true), score(0), enemySpeed(50), speedTimer(0) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) {
            enemies.emplace_back(2 + j * 6, 2 + i * 2);
        }
    }

    houses.emplace_back(20, 20);
    houses.emplace_back(35, 20);
    houses.emplace_back(50, 20);
    houses.emplace_back(65, 20);
}

void Game::drawBorder() {
    for (int i = 0; i < 80; ++i) {
        COORD coord = { static_cast<SHORT>(i), 0 };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "#";

        coord = { static_cast<SHORT>(i), 24 };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "#";
    }

    for (int i = 0; i < 25; ++i) {
        COORD coord = { 0, static_cast<SHORT>(i) };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "#";

        coord = { 79, static_cast<SHORT>(i) };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "#";
    }
}

void Game::moveEnemies() {
    if (speedTimer >= 5000) {
        enemySpeed = enemySpeed - 5 > 10 ? enemySpeed - 5 : 10; 
        speedTimer = 0;
    }

    bool hitBorder = false;

    for (auto& enemy : enemies) {
        if ((moveRight && enemy.getX() >= 78) || (!moveRight && enemy.getX() <= 1)) {
            hitBorder = true;
            break;
        }
    }

    if (hitBorder) {
        for (auto& enemy : enemies) {
            enemy.moveDown();
        }
        moveRight = !moveRight;
    }
    else {
        for (auto& enemy : enemies) {
            enemy.move(moveRight ? 1 : -1, 0);
        }
    }

    for (const auto& enemy : enemies) {
        if (enemy.getY() >= 23) {
            running = false;
        }
    }
}


void Game::handleEnemyShooting() {
    for (auto& enemy : enemies) {
        if (std::rand() % 100 < 1) { 
            enemyBullets.emplace_back(enemy.getX(), enemy.getY() + 1);
        }
    }
}

void Game::checkCollisions() {
    // player bullet collisions
    for (auto bulletIt = playerBullets.begin(); bulletIt != playerBullets.end(); ) {
        bool hit = false;
        for (auto enemyIt = enemies.begin(); enemyIt != enemies.end(); ) {
            if (bulletIt->getX() == enemyIt->getX() && bulletIt->getY() == enemyIt->getY()) {
                score += 100 - (enemyIt->getY() * 4); 
                enemyIt = enemies.erase(enemyIt);
                hit = true;
                break;
            }
            else {
                ++enemyIt;
            }
        }
        if (hit) {
            bulletIt = playerBullets.erase(bulletIt);
        }
        else {
            ++bulletIt;
        }
    }

    // enemy bullet collisions sa kucama
    for (auto bulletIt = enemyBullets.begin(); bulletIt != enemyBullets.end(); ) {
        bool hit = false;
        for (auto& house : houses) {
            if (!house.isDestroyed() && bulletIt->getX() == house.getX() && bulletIt->getY() == house.getY()) {
                house.takeDamage();
                hit = true;
                break;
            }
        }
        if (hit) {
            bulletIt = enemyBullets.erase(bulletIt);
        }
        else {
            ++bulletIt;
        }
    }

    // enemy bullet collision sa player
    for (auto bulletIt = enemyBullets.begin(); bulletIt != enemyBullets.end(); ) {
        if (bulletIt->getX() == player.getX() && bulletIt->getY() == player.getY()) {
            player.loseLife();
            bulletIt = enemyBullets.erase(bulletIt);
            if (player.getLives() <= 0) {
                running = false;
            }
        }
        else {
            ++bulletIt;
        }
    }
}

void Game::draw() {
    system("cls");
    drawBorder();
    player.draw();

    for (const auto& enemy : enemies) {
        enemy.draw();
    }
    for (const auto& bullet : playerBullets) {
        bullet.draw();
    }
    for (const auto& bullet : enemyBullets) {
        bullet.draw();
    }
    for (const auto& house : houses) {
        house.draw();
    }

    COORD infoCoord = { 0, 25 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), infoCoord);
    std::cout << "Score: " << score << " Lives: " << player.getLives();
}

void Game::handleInput() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            player.moveLeft();
            break;
        case 'd':
            player.moveRight();
            break;
        case ' ': 
            playerBullets.emplace_back(player.getX(), player.getY() - 1);
            break;
        case 27: 
            running = false;
            break;
        }
    }
}

void Game::update() {
    static int timeElapsed = 0;
    timeElapsed += enemySpeed;
    speedTimer += enemySpeed;

    for (auto& bullet : playerBullets) {
        bullet.moveUp();
    }

    for (auto& bullet : enemyBullets) {
        bullet.moveDown();
    }

    playerBullets.erase(std::remove_if(playerBullets.begin(), playerBullets.end(), [](const Bullet<int>& b) {
        return b.getY() < 0;
        }), playerBullets.end());

    enemyBullets.erase(std::remove_if(enemyBullets.begin(), enemyBullets.end(), [](const Bullet<int>& b) {
        return b.getY() >= 24;
        }), enemyBullets.end());

    if (timeElapsed >= enemySpeed) {
        moveEnemies();
        timeElapsed = 0;
    }

    handleEnemyShooting();
    checkCollisions();

    if (enemies.empty()) {
        running = false;
        system("cls");
        std::cout << "YOU WIN! Final Score: " << score << std::endl;
    }
}

void Game::run() {
    while (isRunning()) {
        handleInput();
        update();
        draw();
        Sleep(enemySpeed);
    }
    if (!enemies.empty()) {
        system("cls");
        std::cout << "Game Over! Final Score: " << score << std::endl;
    }
}

bool Game::isRunning() const {
    return running;
}