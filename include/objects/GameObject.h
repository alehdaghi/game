//
// Created by mahdi on 28.09.19.
//

#ifndef GAME_GAMEOBJECT_H
#define GAME_GAMEOBJECT_H

#include <string>
#include <thread>
#include <atomic>
#include <boost/signals2.hpp>

/**
 * The abstract class of each objects in the Game
 * Each Object has own thread to behave simultaneously. Also, when an object does any attack, it fires a signal
 */
namespace Game {
    namespace Object {

        class GameObject {
        protected:
            std::string m_name;
            std::atomic_int m_health;
            int m_power;
            std::unique_ptr<std::thread> m_thread;
            boost::signals2::signal<void ()> sig;
            std::atomic_bool isGameEnded {false};
        public:
            // constructor
            GameObject();

            GameObject(const std::string& name, int health, int power);

            GameObject(const GameObject &movedObject) = delete;


            virtual ~GameObject() = default; // Lets my children have own version of desructor

            virtual void onAttack(std::function<void()> slot);
            virtual void run() = 0;
            virtual void attack() ;
            virtual void join();

            int getHealth();

            void setHealth(int health);

            int getPower();
            bool isLive();

            void finish();
        };

        enum class MonsterType{
            ORC,
            DRAGON,
            UNKNOWN
        };
    }
}

#endif //GAME_GAMEOBJECT_H
