#include "GameOverScreen.h"

void GameOverScreen::show(sf::RenderWindow& window) {
    // Display game over screen
    sf::Font font;
    if (!font.loadFromFile("C:/Users/Tristan/source/repos/A New/hypik.otf")) {
        // Handle error loading font
        return;
    }
    sf::Text gameOverText("Game Over", font, 50);
    gameOverText.setPosition(225, 250);
    window.draw(gameOverText);
}
