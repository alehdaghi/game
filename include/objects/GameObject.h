//
// Created by mahdi on 28.09.19.
//

#ifndef GAME_GAMEOBJECT_H
#define GAME_GAMEOBJECT_H

#include <string>

/**
 * The abstract class of each objects in the Game
 *
 */
 namespace Game {
     namespace Object {

         class GameObject {
         private:
             std::string m_name;
             int m_health;
             int m_power;
         public:
             // constructor
             GameObject();

             GameObject(const std::string& name, int health, int power);

             GameObject(GameObject &&movedObject);

             virtual ~GameObject() = default; // Lets my children have own version of desructor

             virtual void run() = 0;
         };
     }
 }

#endif //GAME_GAMEOBJECT_H
