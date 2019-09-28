//
// Created by mahdi on 28.09.19.
//

#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include <utility/ISingleton.hpp>
#include <thread>
#include <memory>

/**
 * The Board Game which handles the whole of Game. It creates the objects, handles the attack event.
 */
namespace Game {
    namespace Object {
        class GameObject;
        enum class MonsterType;
        class Board : public Utility::ISingleton<Board>{
        private:
            Board();
            friend class ISingleton;

            // Objects of the game
            std::shared_ptr<GameObject> m_player;
            std::shared_ptr<GameObject> m_orc;
            std::shared_ptr<GameObject> m_dragon;
            bool isInitialized = false;


            // run the game
            void run();

            // Events fired by objects are handled here
            void onPlayerDied();
            void onOrcAttacked();
            void onDragonAttacked();
            // Events fired by player differs from monster! It can select the monster
            void onPlayerAttacked(MonsterType type);

        public:
            // Initialize the Game
            void initialize(const std::string& name);
            // Starts the game
            void start();
            //Joins until the game ends
            void join();


        };
    }
}


#endif //GAME_BOARD_H
