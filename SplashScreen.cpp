//
// Created by Jason on 6/7/2024.
//

#include "SplashScreen.h"
#include "Fonts.h"
#include "MouseEvents.h"
#include "EventManager.h"

SplashScreen::SplashScreen() : start("Start Game", sf::Vector2f(200, 100), sf::Color::Green, sf::Color::Yellow, Fonts::getFont(Fonts::OPEN_SANS_BOLD)) {
    message.setFont(Fonts::getFont(Fonts::OPEN_SANS_REGULAR));
    message.setString("Welcome to Duck Lake Dash!");
    message.setCharacterSize(20);
    message.setFillColor(sf::Color::White);
    message.setPosition(20.f, 20.f);
}

SplashScreen::SplashScreen(const std::string& messageString) : start("Start Game", sf::Vector2f(200, 100), sf::Color::Green, sf::Color::Yellow, Fonts::getFont(Fonts::OPEN_SANS_BOLD)) {
    message.setFont(Fonts::getFont(Fonts::OPEN_SANS_REGULAR));
    message.setString(messageString);
    message.setCharacterSize(20);
    message.setFillColor(sf::Color::White);
    message.setPosition(20.f, 20.f);
}

void SplashScreen::show(sf::RenderWindow& window) {

    start.setPosition(200.f, 250.f);
    start.centerText(start, start.getText());

    setSize(sf::Vector2f(window.getSize().x, window.getSize().y));

    window.draw(*this);
    window.draw(message);
    window.draw(start);
}

void SplashScreen::eventHandler(sf::Event event, sf::RenderWindow& window, EventManager& eventManager) {
        start.eventHandler(window, event);

        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (MouseEvents::isClicked(start, window)) {
            eventManager.setCurrentState(EventManager::IN_GAME);
        }
}

sf::Text& SplashScreen::getMessage() {
    return message;
}

Button& SplashScreen::getButton() {
    return start;
}

void SplashScreen::setImage(const std::string& textureFile, sf::Vector2f position) {
    image.loadTexture(textureFile);
    image.setPosition(position.x, position.y);
}

void SplashScreen::drawImage(sf::RenderWindow& window) {
    window.draw(image);
}
