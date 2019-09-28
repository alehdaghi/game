//
// Created by mahdi on 28.09.19.
//

#ifndef GAME_OBJECTFACTORY_H
#define GAME_OBJECTFACTORY_H

#include "../utility/ISingleton.hpp"

namespace Game {
    namespace Object {

        class GameObject;
        class Player;
        class Orc;
        class Dragon;

        class ObjectFactory {
        protected:
            ObjectFactory();

        public:
            virtual GameObject* create(const std::string& name, int health, int power) = 0;

        };

        class PlayerFactory : public ObjectFactory, public Utility::ISingleton<PlayerFactory> {
        private:
            friend class ISingleton;
            PlayerFactory();

        public:
            GameObject* create(const std::string& name, int health, int power) override ;
        };

        class OrcFactory : public ObjectFactory, public Utility::ISingleton<OrcFactory> {
        private:
            friend class ISingleton;
            OrcFactory();

        public:
            GameObject* create(const std::string& name, int health, int power) override ;
        };

        class DragonFactory : public ObjectFactory, public Utility::ISingleton<DragonFactory> {
        private:
            friend class ISingleton;
            DragonFactory();

        public:
            GameObject* create(const std::string& name, int health, int power) override ;
        };
    }
}


#endif //GAME_OBJECTFACTORY_H
