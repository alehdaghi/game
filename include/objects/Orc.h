//
// Created by mahdi on 28.09.19.
//

#ifndef GAME_ORC_H
#define GAME_ORC_H

#include "GameObject.h"

namespace Game {
    namespace Object {

        class Orc : public GameObject {
        private:
        public:
            Orc();
            Orc(const std::string& name, int health, int power);

            void run() override;
        };

    }
}
#endif //GAME_ORC_H
