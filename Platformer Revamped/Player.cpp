#include "Player.h"

bool Player::grounded() const
{
    return getPosition().y >= sf::VideoMode::getDesktopMode().height - dimensions.y;
}

Player::Player(sf::Vector2f p) {
    position = p;
    velocity = { 0, 0 };

    movement_speed = 2;
    dimensions = { 50, 100 };

    setPosition(position);
    setSize(dimensions);
    setFillColor(sf::Color::Green);
}

void Player::update(float dt)
{
    velocity.x = 0;

    float deltaTime = dt * speed_factor;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) velocity.x -= 5.f;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) velocity.x += 5.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && grounded()) velocity.y = jump_vec.y;

    position += velocity * deltaTime;
    velocity += gravity_vec * deltaTime;

    groundCollision();

    setPosition(position);
}

void Player::groundCollision()
{
    if (position.y >= sf::VideoMode::getDesktopMode().height - dimensions.y) {
        position = { position.x,  sf::VideoMode::getDesktopMode().height - dimensions.y };
        velocity.y = 0.f;
    }
}

void Player::show(sf::RenderWindow& window) const
{
    window.draw(*this);
}

void Player::SetPosition(sf::Vector2f position)
{
    this->position = position;
}
