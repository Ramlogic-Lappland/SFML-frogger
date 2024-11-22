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
    RectangleShape obstacleBody1;
    Obstacle obstacle2;
    RectangleShape obstacleBody2;
    Obstacle obstacle3;
    RectangleShape obstacleBody3;

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

        obstacleBody1 = RectangleShape(Vector2f(obstacle1.size.x, obstacle1.size.y));
        obstacleBody1.setFillColor(Color::White);
        obstacleBody2 = RectangleShape(Vector2f(obstacle1.size.x, obstacle1.size.y));
        obstacleBody2.setFillColor(Color::White);
        obstacleBody3 = RectangleShape(Vector2f(obstacle1.size.x, obstacle1.size.y));
        obstacleBody3.setFillColor(Color::White);


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
        obstacle1.size.y = 40.f;
        obstacle1.pos.x = static_cast<float>(0 - obstacle1.size.x);
        obstacle1.pos.y = 200.f;

        obstacle2.size.x = 80.f;
        obstacle2.size.y = 40.f;
        obstacle2.pos.x = static_cast<float>(0 - obstacle2.size.x);
        obstacle2.pos.y = 400.f;

        obstacle3.size.x = 80.f;
        obstacle3.size.y = 40.f;
        obstacle3.pos.x = static_cast<float>(0 - (obstacle3.size.x * 6));
        obstacle3.pos.y = 400.f;
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
        if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            player.pos.y += 200 * elapsed.asSeconds();
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
            obstacle1.pos.x = static_cast<float>(0 - obstacle1.size.x);
        }

        if (obstacle2.pos.x < static_cast<float>(screen.x + obstacle1.size.x))
        {
            obstacle2.pos.x += 200 * elapsed.asSeconds();
        }
        else if (obstacle2.pos.x > static_cast<float>(screen.x + obstacle2.size.x))
        {
            obstacle2.pos.x = static_cast<float>(0 - obstacle2.size.x);
        }

        if (obstacle3.pos.x < static_cast<float>(screen.x + obstacle3.size.x))
        {
            obstacle3.pos.x += 200 * elapsed.asSeconds();
        }
        else if (obstacle3.pos.x > static_cast<float>(screen.x + obstacle3.size.x))
        {
            obstacle3.pos.x = static_cast<float>(0 - (obstacle3.size.x));
        }


        frog.setPosition(player.pos.x, player.pos.y);
        obstacleBody1.setPosition(obstacle1.pos.x, obstacle1.pos.y);
        obstacleBody2.setPosition(obstacle2.pos.x, obstacle2.pos.y);
        obstacleBody3.setPosition(obstacle3.pos.x, obstacle3.pos.y);
    }

    void drawGame()
    {
        window->draw(frog);
        window->draw(obstacleBody1);
        window->draw(obstacleBody2);
        window->draw(obstacleBody3);
    }
}
