//
// Created by Jason on 6/7/2024.
//

#include "EventManager.h"

EventManager::EventManager() : currentState(START_SCREEN) {

}

EventManager::GameState EventManager::getCurrentState() {
    return currentState;
}

void EventManager::setCurrentState(GameState newState) {
    currentState = newState;
}