//
// Created by mahdi on 28.09.19.
//

#include "../../include/objects/Dragon.h"

constexpr int Game::Object::Dragon::interval;
Game::Object::Dragon::Dragon() {

}

Game::Object::Dragon::Dragon(const std::string &name, int health, int power) : GameObject(name, health, power) {

}

void Game::Object::Dragon::run() {
    if (!m_thread)
        m_thread = std::unique_ptr<std::thread>(new std::thread([this](){
            while(true)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(interval));
                if (isGameEnded || !isLive())
                    break;
                attack();
            }
        }));
}