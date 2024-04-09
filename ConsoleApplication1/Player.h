#pragma once
#include <SFML/Graphics.hpp>

class Player {
public:
    Player(sf::Vector2f position);
    void move(sf::Vector2f offset);
    void draw(sf::RenderWindow& window);
    sf::Vector2f getPosition() const;

    // Add const qualifier to getHitbox member function
    const sf::CircleShape& getHitbox() const;

private:
    void updateHitbox();
    sf::Sprite sprite;
    sf::Texture texture;
    sf::CircleShape hitbox; // Use sf::CircleShape for hitbox
    sf::Vector2f position;
    sf::Vector2u windowSize;
};
