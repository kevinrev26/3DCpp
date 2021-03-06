// Copyright 2020 - Kevin Rivera @kevinrev26
#include <iostream>
#include <SFML/Graphics.hpp>
// Size of the window
sf::Vector2f viewSize(1024, 768);
// Setting the size of the window
sf::VideoMode vm(viewSize.x, viewSize.y);
// Define a default view window
sf::RenderWindow window(vm, "Hello World", sf::Style::Default);
// Textures and sprites objects
sf::Texture skyTexture;
sf::Sprite skySprite;
sf::Texture bgTexture;
sf::Sprite bgSprite;
sf::Texture heroTexture;
sf::Sprite heroSprite;

// Player position
sf::Vector2f playerPosition;
bool playerMoving = false;



// Initialization function
void init() {
    // Load Textures
    skyTexture.loadFromFile("Assets/graphics/sky.png");
    bgTexture.loadFromFile("Assets/graphics/bg.png");
    heroTexture.loadFromFile("Assets/graphics/hero.png");
    // Attach Textures
    skySprite.setTexture(skyTexture);
    bgSprite.setTexture(bgTexture);
    heroSprite.setTexture(heroTexture);

    // Positioning
    heroSprite.setPosition(sf::Vector2f(viewSize.x/2, viewSize.y/2));
    heroSprite.setOrigin(heroTexture.getSize().x/2,
                        heroTexture.getSize().y/2);
}

// Drawing function
void draw() {
    window.draw(skySprite);
    window.draw(bgSprite);
    window.draw(heroSprite);
}

void updateInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.key.code == sf::Keyboard::Escape ||
            event.type == sf::Event::Closed ) {
            window.close();
        }

        if (event.type == sf::Event::KeyPressed &&
            event.key.code == sf::Keyboard::Right) {
            playerMoving = true;
        }

        if (event.type == sf::Event::KeyReleased &&
            event.key.code == sf::Keyboard::Right) {
            playerMoving = false;
        }
    }
}

void update(float deltaTime) {
    if (playerMoving) {
        heroSprite.move(50.0f * deltaTime, 0);
    }
}

int main(int argc, char **argv) {
    //
    std::cout << "Starting rendering!\n";
    sf::Clock clock;
    // Initialize game objects
    init();
    while (window.isOpen()) {
        // Handle Keyboard Events
        updateInput();
        // Update Game Objects
        sf::Time dt = clock.restart();
        update(dt.asSeconds());
        // Clearing Game objects
        window.clear(sf::Color::Red);
        // Render Game Objects
        draw();
        window.display();
    }

    std::cout << "Close rendering!\n";

    return 0;
}
