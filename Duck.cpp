//
// Created by Jason on 6/7/2024.
//

#include "Duck.h"
#include <iostream>

Duck::Duck(const std::string& textureFile, float x, float y) : duckSprite(textureFile),
                                                               increasing(false),
                                                               decreasing(false) {
    duckSprite.setPosition(x, y);
    duckSprite.setScale(2.f, 2.f);
    moveDistance = 30.f;

}

void Duck::moveLeft() {
    if(duckSprite.getPosition().x > 0.f) {
        duckSprite.move(-moveDistance, 0.f);
    }
}

void Duck::moveRight(float windowWidth) {
    if(duckSprite.getPosition().x < (windowWidth - (duckSprite.getGlobalBounds().width))) {
        duckSprite.move(moveDistance, 0.f);
    }
}

void Duck::moveOver() {
    increasing = true;
    decreasing = false;
    underwater = false;
}

void Duck::moveUnder() {
    setDuckSprite("duckSprite1.png");
    underwater = true;
    underwaterTimer.restart();
    increasing = false;
    decreasing = false;
    duckSprite.setScale(2.f, 2.f);
    flying = false;
}

void Duck::fly() {
    setDuckSprite("duckSprite2.png");
    flying = true;
    flyingTime.restart();
}

void Duck::updateSprite() {
    float time = upClock.getElapsedTime().asSeconds();
    if(increasing == true) {
        if(time < 2.f) {
            float amount = (1.f + 0.2f * time) * 2.f;
            duckSprite.setScale(amount, amount);
        }
        else {
            increasing = false;
            decreasing = true;
            upClock.restart();
        }
    }
    else if(decreasing == true) {
        if(time < 2.f) {
            float amount = (1.2f - 0.1f * time) * 2.f;
            duckSprite.setScale(amount, amount);
        }
        else {
            decreasing = false;
            duckSprite.setScale(2.f, 2.f);
        }
    }

    if(underwater == true && underwaterTimer.getElapsedTime().asSeconds() > 2.f) {
        underwater = false;
    }

    if(flying == true && flyingTime.getElapsedTime().asSeconds() > 5.f) {
        setDuckSprite("duckSprite1.png");
        flying = false;
    }
}


void Duck::updatePosition(sf::Event event) {
    if(event.key.code == sf::Keyboard::Left) {
        moveLeft();
    }
    else if(event.key.code == sf::Keyboard::Right) {
        moveRight(600.f);
    }
    else if(event.key.code == sf::Keyboard::Up && upCooldownTimer.getElapsedTime().asSeconds() > 2.5f) {
        moveOver();
        upCooldownTimer.restart();
    }
    else if(event.key.code == sf::Keyboard::Down && downCooldownTimer.getElapsedTime().asSeconds() > 4.f) {
        moveUnder();
        downCooldownTimer.restart();
    }
    else if(event.key.code == sf::Keyboard::Space && spaceCooldownTimer.getElapsedTime().asSeconds() > 15.f) {
        fly();
        spaceCooldownTimer.restart();
    }
}

void Duck::draw(sf::RenderWindow& window) {
    window.draw(duckSprite);
}

sf::Sprite& Duck::getSprite() {
    return duckSprite;
}

bool Duck::getUnderWaterStatus() {
    return underwater;
}

void Duck::setDuckSprite(const std::string& textureFile) {
    duckSprite.loadTexture(textureFile);
}

bool Duck::getFlyingStatus() {
    return flying;
}