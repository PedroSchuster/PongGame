#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "player.h"
#include "ball.h"
#include "game_controller.h"
#include <vector>

void CreateScoreText(sf::Text* scoreLabel, sf::Text* scoreText, sf::Font* font, sf::Window &window){
    scoreLabel->setFont(*font);
    scoreLabel->setString("Score");
    scoreLabel->setCharacterSize(50); 
    scoreLabel->setFillColor(sf::Color::White);
    scoreLabel->setPosition(window.getSize().x / 2 - scoreLabel->getGlobalBounds().width / 2, 20);

    scoreText->setFont(*font);
    scoreText->setCharacterSize(40);
    scoreText->setFillColor(sf::Color::White);
    scoreText->setPosition(window.getSize().x / 2 - 50, 80);
}

void CreateGameOverText(sf::Text* gameOverText, sf::Text* playAgainText, sf::Font* font, sf::Window &window) {
    gameOverText->setFont(*font);
    gameOverText->setString("Jogador X venceu!");
    gameOverText->setCharacterSize(80);
    gameOverText->setFillColor(sf::Color::White);

    sf::FloatRect gameOverBounds = gameOverText->getLocalBounds();
    gameOverText->setOrigin(gameOverBounds.left + gameOverBounds.width / 2.0f,
                            gameOverBounds.top + gameOverBounds.height / 2.0f);
    gameOverText->setPosition(window.getSize().x / 2.0f, window.getSize().y / 2.0f - 50);

    playAgainText->setFont(*font);
    playAgainText->setString("Clique Enter para jogar novamente ou Esc para fechar o programa");
    playAgainText->setCharacterSize(40);
    playAgainText->setFillColor(sf::Color::White);

    sf::FloatRect playAgainBounds = playAgainText->getLocalBounds();
    playAgainText->setOrigin(playAgainBounds.left + playAgainBounds.width / 2.0f,
                             playAgainBounds.top + playAgainBounds.height / 2.0f);
    playAgainText->setPosition(window.getSize().x / 2.0f, window.getSize().y / 2.0f + 50);
}



int main()
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    sf::RenderWindow window(desktop, "My window", sf::Style::Fullscreen);

    int initialState = 0;
    int* gameState = &initialState;

    Player *player1 = new Player(1, window);
    Player *player2 = new Player(2, window);

    Ball *ball = new Ball(window);

    std::vector<Player *> players;
    players.push_back(player1);
    players.push_back(player2);

    GameController *gm = new GameController(ball, players, gameState);

    sf::Font* font = new sf::Font();
    if (!font->loadFromFile("Starjedi.ttf")) 
    {
        std::cerr << "Erro ao carregar a fonte!" << std::endl;
    }

    sf::Text* scoreLabel = new sf::Text();
    sf::Text* scoreText = new sf::Text();
    CreateScoreText(scoreLabel, scoreText, font, window);

    sf::Text* gameOverText = new sf::Text();
    sf::Text* playAgainText = new sf::Text();

    CreateGameOverText(gameOverText, playAgainText, font, window);

    while (window.isOpen())
    {
        sf::Event event;    
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        
        if (*gameState == 0){
            scoreText->setString(std::to_string(player1->GetScore()) + " : " + std::to_string(player2->GetScore()));

            player1->Draw();
            player2->Draw();

            player1->Update();
            player2->Update();

            ball->Draw();
            ball->Update();

            gm->CheckCollision();

            window.draw(*scoreLabel);
            window.draw(*scoreText);
        }
        else if(*gameState == 1){
            gameOverText->setString("Jogador 1 venceu!");
            window.draw(*gameOverText);
            window.draw(*playAgainText);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                gm->ResetGame();
            }
        }
        else if(*gameState == 2){
            gameOverText->setString("Jogador 2 venceu!");
            window.draw(*gameOverText);
            window.draw(*playAgainText);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                gm->ResetGame();
            }
        }
        window.display();
    }

    delete player1;
    delete player2;
    
    delete gm;
    delete ball;

    delete scoreLabel;
    delete scoreText;
    delete gameOverText;
    
    return 0;
}
