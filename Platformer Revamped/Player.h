#pragma once
#include <SFML/Graphics.hpp>

class Player :public sf::RectangleShape {
private:
    sf::Vector2f position;
    sf::Vector2f velocity;

    sf::Vector2f dimensions;

    float movement_speed;
    float speed_factor = 60.f;

    sf::Vector2f gravity_vec = { 0, 1 };
    sf::Vector2f jump_vec = { 0, -20 };

    bool jumped = false;

    bool grounded() const;
public:
    Player(sf::Vector2f p);

    void update(float dt);

    void groundCollision();

    void show(sf::RenderWindow& window) const;

    void SetPosition(sf::Vector2f position);
};

