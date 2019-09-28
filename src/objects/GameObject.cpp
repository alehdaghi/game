//
// Created by mahdi on 28.09.19.
//

#include "../../include/objects/GameObject.h"

Game::Object::GameObject::GameObject() {

}

Game::Object::GameObject::GameObject(const std::string& name, int health, int power) : m_name(name), m_health(health), m_power(power){

}

void Game::Object::GameObject::join() {
    if (m_thread && m_thread->joinable())
        m_thread->join();
}

void Game::Object::GameObject::attack() {
    sig();
}

void Game::Object::GameObject::onAttack(std::function<void()> slot) {
    sig.connect(slot);
}

int Game::Object::GameObject::getHealth() {
    return m_health;
}

void Game::Object::GameObject::setHealth(int health) {
    if (health < 0)
        health = 0;
    m_health = health;
}

int Game::Object::GameObject::getPower() {
    return m_power;
}

bool Game::Object::GameObject::isLive() {
    return m_health > 0;
}

void Game::Object::GameObject::finish() {
    isGameEnded = true;
}


