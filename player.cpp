#include "player.h"
#define WIDTH 10.0
#define HEIGHT 100.0
#define SPEED 0.2
#define WINDOW_HEIGHT 1040

Player::Player(int pPlayer, sf::RenderWindow &pWindow) : player(pPlayer), window(&pWindow)
{
    score = 0;
    Player::rect = new sf::RectangleShape(sf::Vector2f(WIDTH, HEIGHT));
    rect->setFillColor(sf::Color::White);
    
    float windowWidth = window->getSize().x;
    float windowHeight = window->getSize().y;

    if (player == 1){
        rect->setPosition(0, (windowHeight / 2) - rect->getSize().y);
    } 
    else if (player == 2){
        rect->setPosition(windowWidth - rect->getSize().x, (windowHeight / 2) - rect->getSize().y);
    }

    position = rect->getPosition();

}

void Player::Draw(){
    window->draw(*rect);
}

void Player::Update(){
    if (player == 1){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && 
        rect->getPosition().y > 0){
            position.y -= SPEED;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && 
        rect->getPosition().y + rect->getSize().y < WINDOW_HEIGHT){
            position.y += SPEED;
        }
        rect->setPosition(position);
    }
    else if (player == 2){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && 
        rect->getPosition().y > 0){
            position.y -= SPEED;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && 
        rect->getPosition().y + rect->getSize().y < WINDOW_HEIGHT){
            position.y += SPEED;
        }
        rect->setPosition(position);
    }
}


sf::FloatRect Player::GetGlobalBounds(){
    return rect->getGlobalBounds();
}

void Player::SetScore(){
    score++;
}

void Player::ResetScore(){
    score = 0;
}

int Player::GetScore(){
    return score;
}