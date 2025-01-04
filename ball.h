#pragma once
#include <SFML/Graphics.hpp>

class Ball{
    public:
        Ball(sf::RenderWindow &pWindow);
        void Update();
        void Draw();
        void SetRebounce();
        sf::FloatRect GetGlobalBounds();
        float GetXPos();
        void SetPosition();
    private:
        sf::CircleShape *circle;
        sf::RenderWindow *window;
        sf::Vector2f ballVelocity;
        int offset = 1;
};