//
// Created by mahdi on 28.09.19.
//

#include "GameObject.h"

GameObject::GameObject() {

}

GameObject::GameObject(std::string name, int health, int power) : m_name(name), m_health(health), m_power(power){

}

GameObject::GameObject(GameObject &&movedObject)
    :m_name(std::move(movedObject.m_name)),
    m_health(std::move(movedObject.m_health)),
    m_power(std::move(movedObject.m_power))
{

}
