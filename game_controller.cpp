#include "game_controller.h"
#include <iostream>
#define WINDOW_X 1920
#define MAX_SCORE 5

GameController::GameController(Ball *pBall, std::vector<Player *> pPlayers, int* pGameState) : ball(pBall), players(pPlayers), gameState(pGameState){}

void GameController::CheckCollision(){
    if (ball){
        sf::FloatRect ballPos = ball->GetGlobalBounds();
        for (auto x : players){
            if (x && ballPos.intersects(x->GetGlobalBounds())){
                ball->SetRebounce();
            }
        }
        if (ball->GetXPos() + ballPos.getSize().x < 0){
            ball->SetPosition();
            players[1]->SetScore();
            CheckVictory();
        }
        else if (ball->GetXPos() > WINDOW_X){
            ball->SetPosition();
            players[0]->SetScore();
            CheckVictory();
        }
    }
}

void GameController::CheckVictory(){
    if (players[0]->GetScore() >= MAX_SCORE){
        *gameState = 1;
        }
    else if (players[1]->GetScore() >= MAX_SCORE){
        *gameState = 2;
    }
}

void GameController::ResetGame(){
    *gameState = 0;
    ball->SetPosition();
    players[0]->ResetScore();
    players[1]->ResetScore();
}