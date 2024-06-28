#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // Define the video mode (dimensions)
    sf::VideoMode videoMode = sf::VideoMode(800, 600);

    // Create a window object with specific dimensions and a title
    sf::RenderWindow window(videoMode, "SFML Window");

    // Main loop that continues until the window is closed
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window
        window.clear(sf::Color::Blue);

        // Draw a circle
        sf::CircleShape circle(50); // Radius 50
        circle.setFillColor(sf::Color::Red);
        circle.setPosition(300, 300); // Set position
        window.draw(circle);

        // Load and draw the texture
        sf::Texture outscal_texture;
        if (!outscal_texture.loadFromFile("assets/textures/outscal_logo.png")) {
            std::cerr << "Error loading texture" << std::endl;
            return -1; // Exit if texture loading fails
        }
        sf::Sprite outscal_sprite;
        outscal_sprite.setTexture(outscal_texture);

        // Set sprite properties
        outscal_sprite.setPosition(200, 100); // Position
        outscal_sprite.setRotation(45); // Rotation in degrees
        outscal_sprite.setScale(0.5, 0.5); // Scale factor

        window.draw(outscal_sprite);

        // Load and draw the text
        sf::Font font;
        if (!font.loadFromFile("assets/fonts/OpenSans.ttf")) {
            std::cerr << "Error loading font" << std::endl;
            return -1; // Exit if font loading fails
        }
        sf::Text text("Hello SFML!", font, 50);
        text.setFillColor(sf::Color::Red);
        text.setPosition(150, 450); // Set position for the text
        window.draw(text);

        // Display what was drawn
        window.display();
    }

    return 0;
}