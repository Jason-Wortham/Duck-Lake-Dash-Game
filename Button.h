//
// Created by Jason on 6/7/2024.
//

#ifndef SFML_PROJECT_BUTTON_H
#define SFML_PROJECT_BUTTON_H
#include <SFML/Graphics.hpp>
#include "MouseEvents.h"
#include "Fonts.h"
#include <cmath>
#include <iostream>

class Button : public sf::RectangleShape {
private:
    sf::Text text;
    sf::Color defaultColor, hoveredColor;

public:

    template<typename T>
    void centerText(const T &obj, sf::Text &text);

    Button();
    Button(const std::string& text);
    Button(const std::string& text, sf::Vector2f size);
    Button(const std::string& text, sf::Vector2f size, const sf::Color defaultColor, const sf::Color hoveredColor, sf::Font& font);

    const sf::Color &getDefaultColor() const;

    void setDefaultColor(const sf::Color &defaultColor);

    const sf::Color &getHoveredColor() const;

    void setHoveredColor(const sf::Color &hoveredColor);
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    std::string getValue() const;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::Text& getText();

    std::string getString();

};


template<typename T>
void Button::centerText(const T &obj, sf::Text &text)
{
    sf::FloatRect textRect = text.getGlobalBounds();
    sf::FloatRect tRect = obj.getGlobalBounds();
    sf::Vector2f center = {textRect.width/2.0f, textRect.height/2.0f};
    sf::Vector2f localBounds = {center.x + text.getLocalBounds().left, center.y + text.getLocalBounds().top};
    sf::Vector2f rounded = {std::round(localBounds.x), std::round(localBounds.y)};
    text.setOrigin(rounded);
    text.setPosition({tRect.left + tRect.width/2.0f, tRect.top + tRect.height/2.0f});
}



#endif //SFML_PROJECT_BUTTON_H
