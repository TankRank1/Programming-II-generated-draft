#include "Enemy.h"

Enemy::Enemy(float startX, float startY, float speed, float boundaryLeft, float boundaryRight)
    : x(startX), y(startY), moveSpeed(speed), boundaryLeft(boundaryLeft), boundaryRight(boundaryRight), movingRight(true) {
    // Load texture from file
    if (!texture.loadFromFile("C:/Users/Tristan/Pictures/icon 3.png")) {
        // Handle error if texture loading fails
        // For simplicity, we'll just load a default texture
        // You should handle this case properly in your code
        texture.loadFromFile("resources/default_enemy_texture.png");
    }
    // Set texture for sprite
    sprite.setTexture(texture);
}

void Enemy::update(float deltaTime) {
    // Update enemy position based on speed and direction
    if (movingRight) {
        x += moveSpeed * deltaTime;
        if (x > boundaryRight - sprite.getGlobalBounds().width) {
            x = boundaryRight - sprite.getGlobalBounds().width;
            movingRight = false;
            // Shift all enemies down when reaching the boundary
            y += sprite.getGlobalBounds().height;
        }
    }
    else {
        x -= moveSpeed * deltaTime;
        if (x < boundaryLeft) {
            x = boundaryLeft;
            movingRight = true;
            // Shift all enemies down when reaching the boundary
            y += sprite.getGlobalBounds().height;
        }
    }
    // Update sprite position
    sprite.setPosition(x, y);
}

void Enemy::draw(sf::RenderWindow& window) const {
    window.draw(sprite); // Draw the sprite
}

sf::Vector2f Enemy::getPosition() const {
    return sf::Vector2f(x, y);
}
