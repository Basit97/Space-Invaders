#include <SFML/Graphics.hpp>

class Player {
public:
    sf::Texture player_texture;
    sf::Sprite player_sprite;
    sf::Vector2f position;

    Player() {
        position.x = 400;
        position.y = 400;
    }

    void move(float dx, float dy) {
        position.x += dx;
        position.y += dy;
    }

    sf::Vector2f getPosition() const {
        return position;
    }
};

int main() {
    // Create a video mode object
    sf::VideoMode videoMode(800, 600);
    // Create a render window object
    sf::RenderWindow window(videoMode, "SFML Window");

    // Create a player object
    Player player;
    // Load the player texture
    if (!player.player_texture.loadFromFile("assets/textures/player_ship.png")) {
        // Handle error
        return -1;
    }
    // Set the texture to the player sprite
    player.player_sprite.setTexture(player.player_texture);

    // Main loop
    while (window.isOpen()) {
        // Event handling
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Input handling
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player.move(-1.0f, 0.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player.move(1.0f, 0.0f);
        }

        // Clear the window
        window.clear(sf::Color::Blue);

        // Set the player position
        player.player_sprite.setPosition(player.getPosition());
        // Draw the player to the screen
        window.draw(player.player_sprite);

        // Display the window
        window.display();
    }

    return 0;
}