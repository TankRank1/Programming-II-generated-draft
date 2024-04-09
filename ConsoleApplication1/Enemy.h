#pragma once
#include <SFML/Graphics.hpp>

class Enemy {
public:
    Enemy(float startX, float startY, float speed, float boundaryLeft, float boundaryRight);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window) const; // Declare draw function as const
    sf::Vector2f getPosition() const; // Added getPosition member function

private:
    sf::Sprite sprite;
    sf::Texture texture;
    float x, y;
    float moveSpeed;
    float movingRight;
    float boundaryLeft, boundaryRight;
};
