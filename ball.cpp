#include "ball.h"
#include <cmath>
#include <iostream>
#define RADIUS 7
#define SPEED 0.2f
#define PI 3.14159
#define WINDOW_HEIGHT 1033

Ball::Ball(sf::RenderWindow &pWindow) : window(&pWindow){
    circle = new sf::CircleShape(RADIUS);
    circle->setFillColor(sf::Color::White);
    SetPosition();
    
    ballVelocity = sf::Vector2f(SPEED, SPEED);
}

void Ball::Draw(){
    window->draw(*circle);
}

void Ball::Update(){
    if (circle->getPosition().y <= 0){
        ballVelocity.y = -ballVelocity.y;
    }
    else if (circle->getPosition().y > WINDOW_HEIGHT){
        ballVelocity.y = -ballVelocity.y;
    }

    circle->move(ballVelocity);
}

sf::FloatRect Ball::GetGlobalBounds(){
    return circle->getGlobalBounds();
}

void Ball::SetRebounce(){
    ballVelocity.x = -ballVelocity.x;
}

float Ball::GetXPos(){
    return circle->getPosition().x;
}

void Ball::SetPosition(){
    circle->setPosition(window->getSize().x / 2, window->getSize().y / 2);
}