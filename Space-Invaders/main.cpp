#include <SFML/Graphics.hpp>

int main() {
    // Create a window with a title and size
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Shapes");

    // Create a green circle
    float circleRadius = 50.0f;
    sf::CircleShape greenCircle(circleRadius);
    greenCircle.setFillColor(sf::Color::Green);
    greenCircle.setPosition(window.getSize().x / 4 - circleRadius, window.getSize().y / 2 - circleRadius);

    // Create a red square
    float squareSize = 100.0f;
    sf::RectangleShape redSquare(sf::Vector2f(squareSize, squareSize));
    redSquare.setFillColor(sf::Color::Red);
    redSquare.setPosition(window.getSize().x / 2 - squareSize / 2, window.getSize().y / 2 - squareSize / 2);

    // Create a blue triangle
    sf::ConvexShape blueTriangle;
    blueTriangle.setPointCount(3);
    blueTriangle.setPoint(0, sf::Vector2f(0, squareSize));
    blueTriangle.setPoint(1, sf::Vector2f(squareSize / 2, 0));
    blueTriangle.setPoint(2, sf::Vector2f(squareSize, squareSize));
    blueTriangle.setFillColor(sf::Color::Blue);
    blueTriangle.setPosition(window.getSize().x * 3 / 4 - squareSize / 2, window.getSize().y / 2 - squareSize / 2);

    // Main loop that continues until the window is closed
    while (window.isOpen()) {
        // Create an event object
        sf::Event event;

        // Poll for events
        while (window.pollEvent(event)) {
            // Check if the event type is a close event or a key press event for Esc key
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }
        }

        // Clear the window with a white color
        window.clear(sf::Color::White);

        // Draw the shapes
        window.draw(greenCircle);
        window.draw(redSquare);
        window.draw(blueTriangle);

        // Display the contents of the window
        window.display();
    }

    return 0;
}
