//
// Created by mahdi on 28.09.19.
//

#include "objects/ObjectFactory.h"
#include "objects/Player.h"
#include "objects/Orc.h"
#include "objects/Dragon.h"


Game::Object::ObjectFactory::ObjectFactory() {

}

Game::Object::PlayerFactory::PlayerFactory() : ObjectFactory(){

}

Game::Object::GameObject *Game::Object::PlayerFactory::create(const std::string& name, int health, int power) {
    return new Player(name, health, power);
}

Game::Object::GameObject *Game::Object::OrcFactory::create(const std::string& name, int health, int power) {
    return new Orc(name, health, power);
}

Game::Object::OrcFactory::OrcFactory() {

}

Game::Object::GameObject *Game::Object::DragonFactory::create(const std::string& name, int health, int power) {
    return new Dragon(name, health, power);
}

Game::Object::DragonFactory::DragonFactory() {

}
