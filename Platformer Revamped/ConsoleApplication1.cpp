#include <SFML/Graphics.hpp>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Player.h"
#include "GameManagment.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(0, 0), "Platformer", sf::Style::Fullscreen);
    window.setVerticalSyncEnabled(true);

    sf::Clock clock;

    Player player(sf::Vector2f(900, 850));
    GameManagment gameManagment(&player);

    gameManagment.LoadLevelData(0);

    while (window.isOpen())
    {
        sf::Time deltaTime = clock.restart();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            }
        }

        window.clear();

        player.update(deltaTime.asSeconds());

        gameManagment.ShowEverything(window);
        window.display();
    }

    return 0;
}