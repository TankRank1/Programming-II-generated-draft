#include "Player.h"

Player::Player(sf::Vector2f position) : position(position), windowSize(800, 600) {
    // Load texture from file
    if (!texture.loadFromFile("C:/Users/Tristan/Pictures/icon.png")) {
        // Handle error if texture loading fails
        // For simplicity, we'll just load a default texture
        // You should handle this case properly in your code
        texture.loadFromFile("resources/default_player_texture.png");
    }
    // Set texture for sprite
    sprite.setTexture(texture);

    // Set origin of the sprite to match the center of the hitbox
    sprite.setOrigin(50.f, 50.f); // Assuming hitbox size is 100x100

    // Set up hitbox as a circle
    hitbox.setRadius(50.f); // Adjust radius as needed
    hitbox.setOrigin(50.f, 50.f); // Center the hitbox
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineColor(sf::Color::Red);
    hitbox.setOutlineThickness(1.f);
    updateHitbox();
}

void Player::move(sf::Vector2f offset) {
    position += offset;
    updateHitbox();
    // Check window boundaries
    if (hitbox.getPosition().x - hitbox.getRadius() < 0)
        position.x = hitbox.getRadius();
    else if (hitbox.getPosition().x + hitbox.getRadius() > windowSize.x)
        position.x = windowSize.x - hitbox.getRadius();
    if (hitbox.getPosition().y - hitbox.getRadius() < 0)
        position.y = hitbox.getRadius();
    else if (hitbox.getPosition().y + hitbox.getRadius() > windowSize.y)
        position.y = windowSize.y - hitbox.getRadius();
    sprite.setPosition(position); // Update sprite position
    updateHitbox();
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite); // Draw the sprite
    window.draw(hitbox); // Draw the hitbox
}

sf::Vector2f Player::getPosition() const {
    return position;
}

const sf::CircleShape& Player::getHitbox() const {
    return hitbox;
}

void Player::updateHitbox() {
    hitbox.setPosition(position);
}
