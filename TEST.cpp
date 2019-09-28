//
// Created by mahdi on 28.09.19.
//

#include "include/objects/GameObject.h"
#include "include/objects/Player.h"
#include "include/objects/Orc.h"
#include "include/objects/Dragon.h"
#include "include/objects/ObjectFactory.h"
#include "include/objects/Board.h"

void test1_test_objects() {
    //Game::Objects::GameObject o; // must rise an compilation error due as abstraction
    Game::Object::Player p(); // Default constructor
    Game::Object::Player p2("Mahdi", 40, 2); // Constructor with configuration, the name, health and, power of each attack

    Game::Object::Orc o1("Orc", 7, 1); // Constructor with configuration, the name, health and, power of each attack
    Game::Object::Dragon d1("Dragon", 20, 3); // Constructor with configuration, the name, health and, power of each attack

    // Uses the abstract factories for creation
    auto p3 = Game::Object::PlayerFactory::getInstance().create("Mahdi", 40, 2);
    auto o2 = Game::Object::OrcFactory::getInstance().create("Orc", 7, 1);
    auto d2 = Game::Object::DragonFactory::getInstance().create("Dragon", 20, 3);

    p3->getHealth();
    o2->getHealth();
    d2->getHealth();

    p3->getPower();
    o2->getPower();
    d2->getPower();

    p3->setHealth(10);
    o2->setHealth(3);
    d2->setHealth(-7);
    assert(d2->getHealth() >= 0);

    Game::Object::Board& b = Game::Object::Board::getInstance();

    delete p3;
    delete o2;
    delete d2;
}

void test2_test_game() {
    Game::Object::Board& b = Game::Object::Board::getInstance();
    b.initialize("Mahdi"); // initializes the objects of game
    b.start(); // starts the game async
    b.join(); // joins until the game ends;
}