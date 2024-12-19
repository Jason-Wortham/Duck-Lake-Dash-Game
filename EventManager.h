//
// Created by Jason on 6/7/2024.
//

#ifndef SFML_PROJECT_EVENTMANAGER_H
#define SFML_PROJECT_EVENTMANAGER_H


class EventManager {
public:
    enum GameState {
        START_SCREEN,
        IN_GAME,
        GAME_OVER,
        BEAT_GAME
    };

    EventManager();

    GameState getCurrentState();
    void setCurrentState(GameState newState);

private:
    GameState currentState;
};


#endif //SFML_PROJECT_EVENTMANAGER_H

