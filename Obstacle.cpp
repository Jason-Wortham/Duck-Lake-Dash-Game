//
// Created by Jason on 6/7/2024.
//

#include "Obstacle.h"

Obstacle::Obstacle(const sf::Texture& texture, float x, float y, sf::Vector2f speed, sf::Vector2f size, sf::Vector2f hitboxOrigin) {
    obstacleSprite.setTexture(texture);
    obstacleSprite.setPosition(x, y);
    Obstacle::speed = speed;
    hitbox.left = x - (size.x * hitboxOrigin.x);
    hitbox.top = y - (size.y * hitboxOrigin.y);
    hitbox.width = size.x;
    hitbox.height = size.y;
}

void Obstacle::move(float time) {
    float movementx = speed.x * time;
    float movementy = speed.y * time;

    obstacleSprite.move(movementx, movementy);
    hitbox.left += movementx;
    hitbox.top += movementy;
}

bool Obstacle::checkHit(const sf::Sprite& duck) {

    return hitbox.intersects(duck.getGlobalBounds());
}

void Obstacle::draw(sf::RenderWindow& window) {
    window.draw(obstacleSprite);
}

sf::Sprite& Obstacle::getSprite() {
    return obstacleSprite;
}