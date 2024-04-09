#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "GameOverScreen.h" // Include GameOverScreen header
#include <vector> // Include vector header for storing enemies

int main() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    // Create the player
    Player player(sf::Vector2f(400, 300));

    // Create a vector to store enemies
    std::vector<Enemy> enemies;

    // Spawn 5 enemies
    for (int i = 0; i < 5; ++i) {
        float startX = 100.f * i; // Adjust initial x position of enemies
        float startY = 100.f; // Adjust initial y position of enemies
        float speed = 1000.f; // Adjust speed of enemies
        float boundaryLeft = 0.f; // Adjust left boundary
        float boundaryRight = 800.f; // Adjust right boundary
        enemies.emplace_back(startX, startY, speed, boundaryLeft, boundaryRight);
    }

    sf::Clock clock;
    bool gameOver = false;

    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                // Close window
                window.close();
            }
        }

        if (!gameOver) {
            // Move the player
            sf::Vector2f movement(0.f, 0.f);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                movement.x -= 1.f;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                movement.x += 1.f;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                movement.y -= 1.f;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                movement.y += 1.f;
            }
            player.move(movement);

            // Update the enemies
            sf::Time deltaTime = clock.restart();
            for (auto& enemy : enemies) {
                enemy.update(deltaTime.asSeconds());
                // Check if any enemy reaches bottom boundary
                if (enemy.getPosition().y > 600) {
                    gameOver = true;
                }
            }
        }

        // Clear the window
        window.clear();

        if (gameOver) {
            // Display game over screen
            GameOverScreen::show(window);
        }
        else {
            // Draw the player and enemies
            player.draw(window);
            for (const auto& enemy : enemies) {
                enemy.draw(window);
            }
        }

        // Display the content of the window
        window.display();
    }

    return 0;
}
