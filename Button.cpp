//
// Created by Jason on 6/7/2024.
//

#include "Button.h"

Button::Button()
        : Button("", sf::Vector2f(50.f, 50.f),
                       sf::Color::Black,
                       sf::Color::White, Fonts::getFont(Fonts::OPEN_SANS_REGULAR)) {

}

Button::Button(const std::string &text)
        : Button(text, sf::Vector2f(50.f, 50.f)) {

}

Button::Button(const std::string &text, sf::Vector2f size)
        : Button(text, size,
                        sf::Color::Black,
                        sf::Color::White,
                       Fonts::getFont(Fonts::OPEN_SANS_REGULAR)) {

}

Button::Button(const std::string &text, sf::Vector2f size, const sf::Color defaultColor,
                           const sf::Color hoveredColor, sf::Font& font) : sf::RectangleShape(size),
                                                                           defaultColor(defaultColor), hoveredColor(hoveredColor), text(text, font) {

    setFillColor(defaultColor);
    this -> text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(30);
    setPosition(25, 280);

    centerText(*this, this->text);

    sf::RectangleShape::setFillColor(defaultColor);
}

void Button::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(MouseEvents::isHovered(*this, window))
    {
        sf::RectangleShape::setFillColor(hoveredColor);
    }
    else {
        sf::RectangleShape::setFillColor(defaultColor);
    }

    if(MouseEvents::isClicked(*this, window))
    {
        sf::RectangleShape::setFillColor(sf::Color::White);
    }

}

std::string Button::getValue() const {
    return text.getString();
}

const sf::Color &Button::getDefaultColor() const {
    return defaultColor;
}

void Button::setDefaultColor(const sf::Color &defaultColor) {
    Button::defaultColor = defaultColor;
}

const sf::Color &Button::getHoveredColor() const {
    return hoveredColor;
}

void Button::setHoveredColor(const sf::Color &hoveredColor) {
    Button::hoveredColor = hoveredColor;
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw((sf::RectangleShape)*this, states);
    target.draw(text, states);
}

sf::Text& Button::getText() {
    return Button::text;
}

std::string Button::getString() {
    return text.getString();
}
