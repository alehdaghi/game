//
// Created by mahdi on 28.09.19.
//

#ifndef GAME_DRAGON_H
#define GAME_DRAGON_H

#include "GameObject.h"

namespace Game {
    namespace Object {

        class Dragon : public GameObject {
        private:
            constexpr static int interval = 2500;
        public:
            Dragon();
            Dragon(const std::string& name, int health, int power);

            void run() override;
        };

    }
}


#endif //GAME_DRAGON_H
