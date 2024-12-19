//
// Created by Jason on 6/7/2024.
//

#ifndef SFML_PROJECT_MOUSEEVENTS_H
#define SFML_PROJECT_MOUSEEVENTS_H
#include <SFML/Graphics.hpp>

class MouseEvents {
public:
    template<typename T>
    static bool isHovered(const T& obj, sf::RenderWindow& window);

    template<typename T>
    static bool isClicked(const T& obj, sf::RenderWindow& window);
};

#include "MouseEvents.cpp"
#endif //SFML_PROJECT_MOUSEEVENTS_H
