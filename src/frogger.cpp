#include <SFML/Graphics.hpp>


namespace frogger
{
    void initGame(sf::Texture& texture);
    void drawGame(sf::RenderWindow& window);

    sf::RectangleShape frog(sf::Vector2f(100.f, 100.f));

    

    void run()
    {
        sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
        sf::Texture texture;

        initGame(texture);

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();

            drawGame(window);
            
            window.display();
        }
    }


    void initGame(sf::Texture& texture)
    {
        frog.setFillColor(sf::Color::Green);
        texture.loadFromFile("res/frogx2ver2.png");

        frog.setTexture(&texture);
        frog.setTextureRect(sf::IntRect(1, 1, 100, 100));
    }

    void drawGame(sf::RenderWindow& window)
    {
        window.draw(frog);
    }
}
