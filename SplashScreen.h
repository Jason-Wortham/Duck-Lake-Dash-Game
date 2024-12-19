//
// Created by Jason on 6/7/2024.
//

#ifndef SFML_PROJECT_SPLASHSCREEN_H
#define SFML_PROJECT_SPLASHSCREEN_H
#include "Button.h"
#include "Fonts.h"
#include "EventManager.h"
#include "AnimatedSpriteSheet.h"

class SplashScreen : public sf::RectangleShape{
private:
    Button start;
    sf::Text message;
    AnimatedSpriteSheet image;

public:
    SplashScreen();
    SplashScreen(const std::string& messageString);
    void show(sf::RenderWindow& window);
    void eventHandler(sf::Event event, sf::RenderWindow& window, EventManager& eventManager);
    sf::Text& getMessage();
    Button& getButton();
    void setImage(const std::string& textureFile, sf::Vector2f position);
    void drawImage(sf::RenderWindow& window);
};


#endif //SFML_PROJECT_SPLASHSCREEN_H
