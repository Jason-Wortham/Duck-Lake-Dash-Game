//
// Created by Jason on 6/7/2024.
//

#ifndef SFML_PROJECT_FONTS_H
#define SFML_PROJECT_FONTS_H


#include <SFML/Graphics.hpp>
#include <map>

class Fonts {
public:
    enum fontEnum{
        OPEN_SANS_BOLD,
        OPEN_SANS_REGULAR
    };
    static sf::Font& getFont(fontEnum font);


private:
    inline static std::map<fontEnum, sf::Font> fonts;
    static void loadFont(fontEnum font);
    static std::string getFontPath(fontEnum font);

};

#endif //SFML_PROJECT_FONTS_H
