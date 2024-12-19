#include <iostream>
#include <SFML/Graphics.hpp>
#include "AnimatedSpriteSheet.h"
#include <ctime>
#include <cmath>
#include "SplashScreen.h"
#include "Duck.h"
#include "Obstacle.h"
#include "EventManager.h"


int main() {
    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(600, 500, 32), "Lake");
    window.setFramerateLimit(30);

    AnimatedSpriteSheet backgroundLayer1("lake_background2.png");
    backgroundLayer1.setPosition(0.f, -100.f);

    AnimatedSpriteSheet backgroundLayer2("lake_background3.png");
    backgroundLayer2.setPosition(-0.f, -100.f);

    Duck duck("duckSprite1.png", 265.f, 300.f);

    SplashScreen splashScreen("Welcome to Duck Lake Dash!\nJason Wortham\nCS3A\n37045\nSpring 24");
    splashScreen.setFillColor(sf::Color(53, 174, 230, 0));
    splashScreen.setImage("duckSprite3.png", sf::Vector2f(210.f, 97.f));
    splashScreen.getMessage().setCharacterSize(30);
    splashScreen.getMessage().setFillColor(sf::Color::Yellow);

    SplashScreen gameOver("Game Over");
    gameOver.setFillColor(sf::Color::Black);
    gameOver.getButton().getText().setString("Play Again");
    gameOver.getMessage().setPosition(170.f, 100.f);
    gameOver.getMessage().setCharacterSize(50);

    SplashScreen beatGame("You Won!");
    beatGame.setFillColor(sf::Color::Blue);
    beatGame.getButton().getText().setString("Play Again");
    beatGame.setFillColor(sf::Color(53, 174, 230, 0));
    beatGame.setImage("endOfGame.png", sf::Vector2f(0.f, 0.f));
    beatGame.getMessage().setPosition(195.f, 20.f);
    beatGame.getMessage().setCharacterSize(50);
    beatGame.getMessage().setFillColor(sf::Color::Black);

    sf::Texture sharkTexture;
    sharkTexture.loadFromFile("shark_sprite3.png");
    sf::Texture logTexture;
    logTexture.loadFromFile("log3.png");
    sf::Texture netTexture;
    netTexture.loadFromFile("net.png");
    sf::Texture dryLandTexture;
    dryLandTexture.loadFromFile("dryLand.png");
    sf::Texture boatTexture;
    boatTexture.loadFromFile("boat.png");

    std::vector<Obstacle> obstacles;
    obstacles.reserve(40);

    EventManager eventManager;
    eventManager.setCurrentState(EventManager::START_SCREEN);
    sf::Clock obstacleClock;

    while(window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {

            if(event.type == sf::Event::Closed) {
                window.close();
            }

            if(eventManager.getCurrentState() == EventManager::START_SCREEN) {
                splashScreen.eventHandler(event, window, eventManager);
                if(eventManager.getCurrentState() == EventManager::IN_GAME) {
                    obstacleClock.restart();
                }
            }
            else if(eventManager.getCurrentState() == EventManager::IN_GAME) {
                if(event.type == sf::Event::KeyPressed) {
                    duck.updatePosition(event);
                }

                if(obstacles.empty()) {
                    for(int i = 0; i < 5; i ++) {
                        Obstacle net(netTexture, (rand() % 600) - 100, -((rand() % 800) - 100.f), sf::Vector2f(0, (rand() % 50) + 30.f), sf::Vector2f(170.f, 10.f), sf::Vector2f(-0.2f, -3.5f));
                        obstacles.push_back(net);

                        Obstacle log(logTexture, (rand() % 800) - 300, -((rand() % 800) - 100.f), sf::Vector2f(0, (rand() % 100) + 50.f), sf::Vector2f(430.f, 30.f), sf::Vector2f(-0.02f, -0.6f));
                        obstacles.push_back(log);
                    }

                    for(int i = 0; i < 10; i ++) {
                        Obstacle shark(sharkTexture, rand() % 600 - 50, -((rand() % 3000) + 100.f), sf::Vector2f(0, (rand() % 150) + 100.f), sf::Vector2f(35.f, 80.f), sf::Vector2f(-1.f, -1.f));
                        obstacles.push_back(shark);
                    }

                    Obstacle boat(boatTexture, 800 + rand() % 200, 220, sf::Vector2f(-(rand() % 20) - 30.f, 0), sf::Vector2f(200.f, 100.f), sf::Vector2f(-0.2f, -0.6f));
                    obstacles.push_back(boat);

                    Obstacle dryLand(dryLandTexture, 0, -1600, sf::Vector2f(0, (rand() % 20) + 30.f), sf::Vector2f(600.f, 300.f), sf::Vector2f(0.f, 0.f));
                    obstacles.push_back(dryLand);
                }

            }
            else if(eventManager.getCurrentState() == EventManager::GAME_OVER) {
                duck.getSprite().setPosition(265.f, 300.f);
                obstacles.clear();
                gameOver.eventHandler(event, window, eventManager);
            }
            else if(eventManager.getCurrentState() == EventManager::BEAT_GAME) {
                duck.getSprite().setPosition(265.f, 300.f);
                obstacles.clear();
                beatGame.eventHandler(event, window, eventManager);
            }
        }

        float timeChange = obstacleClock.restart().asSeconds();

        window.clear(sf::Color::Black);

        window.draw(backgroundLayer1);

        if(duck.getUnderWaterStatus() == true) {
            duck.updateSprite();
            duck.draw(window);
        }

        window.draw(backgroundLayer2);

        if(eventManager.getCurrentState() == EventManager::START_SCREEN) {
            splashScreen.show(window);
            splashScreen.drawImage(window);
        }
        else if(eventManager.getCurrentState() == EventManager::IN_GAME) {
            for(int i = 0; i < obstacles.size(); i++) {
                obstacles[i].move(timeChange);
                obstacles[i].draw(window);

                if(obstacles[i].checkHit(duck.getSprite()) == true) {
                    if(i == obstacles.size() - 1) {
                        eventManager.setCurrentState(EventManager::BEAT_GAME);
                    }
                    else if(duck.getSprite().getScale().x == 2.f && duck.getUnderWaterStatus() == false && duck.getFlyingStatus() == false) {
                        eventManager.setCurrentState(EventManager::GAME_OVER);
                    }
                }
            }

            if(duck.getUnderWaterStatus() == false) {
                duck.updateSprite();
                duck.draw(window);
            }
        }
        else if(eventManager.getCurrentState() == EventManager::GAME_OVER) {
            gameOver.show(window);
        }
        else if(eventManager.getCurrentState() == EventManager::BEAT_GAME) {
            beatGame.drawImage(window);
            beatGame.show(window);
        }

        window.display();
    }

    return 0;
}
