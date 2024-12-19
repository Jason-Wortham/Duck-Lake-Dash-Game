//
// Created by Jason on 6/7/2024.
//

#ifndef SFML_PROJECT_OBSTACLE_H
#define SFML_PROJECT_OBSTACLE_H
#include <SFML/Graphics.hpp>

class Obstacle {
private:
    sf::Sprite obstacleSprite;
    sf::Texture texture;
    sf::Vector2f speed;
    sf::FloatRect hitbox;

public:
    Obstacle(const sf::Texture& texture, float x, float y, sf::Vector2f speed, sf::Vector2f size, sf::Vector2f hitboxOrigin);
    void move(float time);
    bool checkHit(const sf::Sprite& duck);
    void draw(sf::RenderWindow& window);
    sf::Sprite& getSprite();
};


#endif //SFML_PROJECT_OBSTACLE_H
