//
// Created by Jason on 5/16/2024.
//

#ifndef SFML_PROJECT_ANIMATEDSPRITESHEET_H
#define SFML_PROJECT_ANIMATEDSPRITESHEET_H
#include <string>
#include <SFML/Graphics.hpp>

class AnimatedSpriteSheet : public sf::Sprite {
private:
    sf::IntRect intRect;
    sf::Texture texture;
    void init(const std::string& filepath);
public:
    AnimatedSpriteSheet(const std::string& filepath);
    AnimatedSpriteSheet();
    void loadTexture(const std::string& filepath);
};


#endif //SFML_PROJECT_ANIMATEDSPRITESHEET_H