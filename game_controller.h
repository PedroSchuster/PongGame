#pragma once
#include "player.h"
#include "ball.h"
#include <vector>
#include <SFML/Graphics.hpp>

class GameController{

    public:
        GameController(Ball *pBall, std::vector<Player *> pPlayers, int* pGameState);
        void CheckCollision();
        void ResetGame();
    private:
        void CheckVictory();
        std::vector<Player *> players;
        Ball *ball;
        sf::RenderWindow *window;
        int *gameState;
};