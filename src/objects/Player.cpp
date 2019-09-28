//
// Created by mahdi on 28.09.19.
//

#include "../../include/objects/Player.h"

Game::Object::Player::Player() : GameObject() {

}

Game::Object::Player::Player(const std::string& name, int health, int power) : GameObject(name, health, power) {

}

void Game::Object::Player::run() {

}
