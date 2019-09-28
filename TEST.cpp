//
// Created by mahdi on 28.09.19.
//

#include "GameObject.h"
#include "Player.h"

void test1_test_objects() {
    //GameObject o; // must rise an compilation error due as abstraction
    Player p(); // Default constructor
    Player p2("mahdi", 40, 2); // Constructor with configuration, the name, health and, power of each attack
}