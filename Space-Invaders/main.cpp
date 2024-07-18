/*#include <SFML/Graphics.hpp>
class Player {
public:
    Player(float startX, float startY, float moveSpeed)
        : position(startX, startY), move_speed(moveSpeed) {
        if (!player_texture.loadFromFile("assets/textures/player_ship.png")) {
            // Handle loading error
        }
        player_sprite.setTexture(player_texture);
        player_sprite.setPosition(position);
    }

    void move(float deltaX) {
        position.x += deltaX;
        player_sprite.setPosition(position);
    }

    sf::Vector2f getPosition() const {
        return position;
    }

    void setPosition(float x, float y) {
        position.x = x;
        position.y = y;
        player_sprite.setPosition(position);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(player_sprite);
    }

    float move_speed;

private:
    sf::Vector2f position;
    sf::Texture player_texture;
    sf::Sprite player_sprite;
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Player Movement");

    Player player(400.0f, 300.0f, 1.0f); // move_speed is set to 1.0f

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player.move(-1.0f); // Move left by 1 unit
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player.move(1.0f); // Move right by 1 unit
        }

        window.clear();
        player.draw(window);
        window.display();
    }

    return 0;
}
*/
#include "Header/GameService.h"
using namespace std;
GameService game_service;
game_service.ignite();


