#pragma once
#include <SFML/Graphics.hpp>

class Player
{
    public:
        Player(int pPlayer,sf::RenderWindow &window);
        void Update();
        void Draw();
        sf::FloatRect GetGlobalBounds();
        sf::RectangleShape *rect;
        int GetScore();
        void SetScore();
        void ResetScore();
    private:
        sf::RenderWindow *window;
        sf::Vector2f position;
        int player;
        int score;
};