#pragma once
#include <SFML/Graphics.hpp>

class Tile : public sf::RectangleShape
{
private:
	sf::Vector2f dimensions;
	sf::Vector2f position;
public:
	Tile(sf::Vector2f dim, sf::Vector2f pos);

	void show(sf::RenderWindow& window) const;
};

