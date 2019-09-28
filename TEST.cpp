//
// Created by mahdi on 28.09.19.
//

#include "include/objects/GameObject.h"
#include "include/objects/Player.h"

void test1_test_objects() {
    //Game::Objects::GameObject o; // must rise an compilation error due as abstraction
    Game::Object::Player p(); // Default constructor
    Game::Object::Player p2("mahdi", 40, 2); // Constructor with configuration, the name, health and, power of each attack
}