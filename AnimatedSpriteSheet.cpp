//
// Created by Jason on 5/16/2024.
//

#include "AnimatedSpriteSheet.h"
#include <iostream>

void AnimatedSpriteSheet::init(const std::string &filepath) {
    if(!texture.loadFromFile(filepath)) {
        exit(28);
    }

    int width = texture.getSize().x;
    int height = texture.getSize().y;
    intRect = sf::IntRect(0, 0, width, height);
    setTexture(texture);
    setTextureRect(intRect);
}

AnimatedSpriteSheet::AnimatedSpriteSheet(const std::string &filepath) {
    init(filepath);
}

AnimatedSpriteSheet::AnimatedSpriteSheet()
        : AnimatedSpriteSheet("lake_background2.png") {

}

void AnimatedSpriteSheet::loadTexture(const std::string& filepath) {
    texture.loadFromFile(filepath);

    int width = texture.getSize().x;
    int height = texture.getSize().y;
    intRect = sf::IntRect(0, 0, width, height);
    setTexture(texture);
    setTextureRect(intRect);
}