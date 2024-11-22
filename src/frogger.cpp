#include "frogger.h"

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

namespace frogger
{
    void initGame();
    void initPlayer();
    void initObstacle();
    void updateGame();
    void drawGame();

    RenderWindow* window;
    Clock clock;
    Time elapsed;

    Vector2i screen = { 600, 600 };
    Player player;
    RectangleShape frog;
    Texture* frogTexture;

    Obstacle obstacle1;
    RectangleShape obstacleBody;
    

    void run()
    {
        window = new RenderWindow(VideoMode(600, 600), "Frogger");
         

        initGame();

        while (window->isOpen())
        {
            elapsed = clock.restart();

            Event event;
            while (window->pollEvent(event))
            {
                
                if (event.type == Event::Closed)
                    window->close();                         
            }
            updateGame();
            window->clear();

            drawGame();
            
            window->display();
        }
        delete window;
        delete frogTexture;
    }


    void initGame()
    {
        initPlayer();
        initObstacle();

        frog = RectangleShape(Vector2f(player.size.x, player.size.y));
        frog.setFillColor(Color::Green);

        obstacleBody = RectangleShape(Vector2f(obstacle1.size.x, obstacle1.size.y));
        obstacleBody.setFillColor(Color::White);


        frogTexture =  new Texture();
        if (!frogTexture->loadFromFile("res/frogx2ver2.png"))
        {
            std::cout << "Error to load texture"; 
        }

        frog.setTexture(frogTexture);
        frog.setTextureRect(IntRect(1, 1, 100, 100));  
    }

    void initObstacle()
    {
        obstacle1.size.x = 140.f;
        obstacle1.size.y = 60.f;


        obstacle1.pos.x = static_cast<float>(0 - obstacle1.size.x);
        obstacle1.pos.y = 200.f;
    }
    void initPlayer()
    {
        player.lives = 3;
        player.size = { 100.f, 100.f };
        player.pos.x = static_cast<float>(screen.x / 2);
        player.pos.y = static_cast<float>(screen.y  - 50);
    }

    void updateGame()
    {
        if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            player.pos.y -= 200 * elapsed.asSeconds();
        }
        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            player.pos.x += 200 * elapsed.asSeconds();
        }
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            player.pos.x -= 200 * elapsed.asSeconds();
        }

        if (obstacle1.pos.x < static_cast<float>(screen.x + obstacle1.size.x))
        {
            obstacle1.pos.x += 200 * elapsed.asSeconds();
        }
        else if (obstacle1.pos.x > static_cast<float>(screen.x + obstacle1.size.x))
        {
            initObstacle();
        }


        frog.setPosition(player.pos.x, player.pos.y);
        obstacleBody.setPosition(obstacle1.pos.x, obstacle1.pos.y);
    }

    void drawGame()
    {
        window->draw(frog);
        window->draw(obstacleBody);
    }
}
