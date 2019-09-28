//
// Created by mahdi on 28.09.19.
//

#include "../../include/objects/Player.h"

Game::Object::Player::Player() : GameObject() {

}

Game::Object::Player::Player(const std::string& name, int health, int power) : GameObject(name, health, power) {

}

void Game::Object::Player::run() {
    if (!m_thread)
        m_thread = std::unique_ptr<std::thread>(new std::thread([this](){
            while(true)
            {
                char ch = ' ';
                printf("Please select the monster to attack: 'o' : the orc, 'd': the dragon\n");
                ch = getchar();
                if (isGameEnded || !isLive())
                    break;
                if (ch == 'o')
                    sig(MonsterType::ORC);
                else if (ch == 'd')
                    sig(MonsterType::DRAGON);
                else
                    sig(MonsterType::UNKNOWN);

            }
        }));
}

void Game::Object::Player::onAttack(std::function<void(MonsterType)> slot) {
    sig.connect(slot);
}
