#include "Tile.h"

Tile::Tile(sf::Vector2f dim, sf::Vector2f pos)
{
	dimensions = dim;
	position = pos;

	setFillColor(sf::Color(30, 30, 30));
	setPosition(position);
	setSize(dimensions);
}

void Tile::show(sf::RenderWindow& window) const
{
	window.draw(*this);
}
