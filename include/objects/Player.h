//
// Created by mahdi on 28.09.19.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H


#include "GameObject.h"
namespace Game {
    namespace Object {
        class Player : public GameObject {
        private:
            boost::signals2::signal<void (MonsterType)> sig;
        public:
            Player();

            Player(const std::string& name, int health, int power);

            void run() override;

            void onAttack(std::function<void(MonsterType)> slot);
        };
    }
}

#endif //GAME_PLAYER_H
