//
// Created by Jason on 6/7/2024.
//

#include "Fonts.h"

sf::Font &Fonts::getFont(Fonts::fontEnum font) {
    if(fonts.count(font) == 0)
        loadFont(font);
    return fonts[font];
}

void Fonts::loadFont(Fonts::fontEnum font) {
    fonts[font].loadFromFile(getFontPath(font));
}

std::string Fonts::getFontPath(Fonts::fontEnum font) {
    switch(font) {
        case OPEN_SANS_BOLD:
            return "OpenSans-Bold.ttf";
        case OPEN_SANS_REGULAR:
            return "open-sans.regular.ttf";
    }
}