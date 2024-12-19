//
// Created by Jason on 6/7/2024.
//

#ifndef SFML_PROJECT_DUCK_H
#define SFML_PROJECT_DUCK_H
#include "AnimatedSpriteSheet.h"

class Duck {
private:
    AnimatedSpriteSheet duckSprite;
    float moveDistance;
    bool increasing, decreasing;
    sf::Clock upClock;
    sf::Clock underwaterTimer;
    bool underwater = false;
    sf::Clock upCooldownTimer;
    sf::Clock downCooldownTimer;
    sf::Clock spaceCooldownTimer;
    sf::Clock flyingTime;
    void moveLeft();
    void moveRight(float windowWidth);
    void moveOver();
    void moveUnder();
    void fly();
    bool flying = false;

public:
    Duck(const std::string& textureFile, float x, float y);
    void updateSprite();
    void updatePosition(sf::Event event);
    void draw(sf::RenderWindow& window);
    sf::Sprite& getSprite();
    bool getUnderWaterStatus();
    void setDuckSprite(const std::string& textureFile);
    bool getFlyingStatus();
};


#endif //SFML_PROJECT_DUCK_H
