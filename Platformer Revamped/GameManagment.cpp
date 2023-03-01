#include "GameManagment.h"

GameManagment::GameManagment(Player* p)
{
    player = p;
	which_level_have_i_ended_on = 0; // change later
}

void GameManagment::LoadLevelData(unsigned int which)
{
    sf::Image level_image;
    if (!level_image.loadFromFile("level" + std::to_string(which) + ".png"))
        std::cerr << "error loading a file" << std::endl;
    std::cout << level_image.getSize().x << " " << level_image.getSize().y << std::endl;

    for (int x = 0; x < level_image.getSize().x; x++) {
        for (int y = 0; y < level_image.getSize().y; y++) {
            if (level_image.getPixel(x, y) == sf::Color(255, 0, 0)) { // Player
                player->SetPosition(sf::Vector2f(x * block_size, sf::VideoMode::getDesktopMode().height - (y * block_size)));
            }
            else if (level_image.getPixel(x, y) == sf::Color::Black) { // Tile
                tiles.push_back(new Tile(sf::Vector2f(block_size, block_size), sf::Vector2f(x * block_size, y * block_size))); // fix
            }
        }
    }

}

void GameManagment::ShowEverything(sf::RenderWindow& window)
{
    for (auto &tile : tiles) {
        tile->show(window);
    }

    player->show(window);
}
