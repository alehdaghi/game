//
// Created by mahdi on 28.09.19.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H


#include "GameObject.h"

class Player : public GameObject {
private:
public:
    Player();
    Player(std::string name, int health, int power);

    void run() override;
};


#endif //GAME_PLAYER_H
