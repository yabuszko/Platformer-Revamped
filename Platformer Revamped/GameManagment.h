#pragma once
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Tile.h"

class GameManagment {
private:
    const unsigned int block_size = 50;

    int which_level_have_i_ended_on;

    std::vector<Tile*> tiles;
    Player* player;
public:
    GameManagment(Player* p);

    void LoadLevelData(unsigned int which);
    void ShowEverything(sf::RenderWindow& window);
};
