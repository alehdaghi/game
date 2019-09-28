//
// Created by mahdi on 28.09.19.
//

#include <iostream>
#include "objects/Board.h"
#include "objects/Player.h"
#include "objects/ObjectFactory.h"



Game::Object::Board::Board() {

}

void Game::Object::Board::run() {

    if (!isInitialized)
        throw std::runtime_error("The Board not initialized!");
    std::dynamic_pointer_cast<Player>(m_player)->onAttack(
            std::bind(&Board::onPlayerAttacked, this, std::placeholders::_1));
    m_orc->onAttack(std::bind(&Board::onOrcAttacked, this));
    m_dragon->onAttack(std::bind(&Board::onDragonAttacked, this));
    m_player->run();
    m_orc->run();
    m_dragon->run();
}

void Game::Object::Board::initialize(const std::string& name) {
    m_player = std::shared_ptr<GameObject>(PlayerFactory::getInstance().create(name, 40, 2));
    m_orc = std::shared_ptr<GameObject>(OrcFactory::getInstance().create(name, 7, 1));
    m_dragon = std::shared_ptr<GameObject>(DragonFactory::getInstance().create(name, 20, 3));
    isInitialized = true;
}

void Game::Object::Board::start() {
    run();
}

void Game::Object::Board::join() {
    m_player->join();
    m_orc->join();
    m_dragon->join();
}

void Game::Object::Board::onPlayerDied() {
    std::cout << "The game is over! you lose: "<< std::endl;
    m_orc->finish();
    m_dragon->finish();
    m_player->finish();
}

void Game::Object::Board::onOrcAttacked() {
    m_player->setHealth(m_player->getHealth() - m_orc->getPower());
    if (!m_player->isLive())
        onPlayerDied();
    else
        std::cout << "Orc just attacked! your health is: " << m_player->getHealth() << std::endl;
}

void Game::Object::Board::onDragonAttacked() {
    m_player->setHealth(m_player->getHealth() - m_dragon->getPower());
    if (!m_player->isLive())
        onPlayerDied();
    else
        std::cout << "Dragon just attacked! your health is: " << m_player->getHealth() << std::endl;
}

void Game::Object::Board::onPlayerAttacked(Game::Object::MonsterType type) {
    if (type == MonsterType::DRAGON) {
        if (!m_dragon->isLive())
            std::cout << "You killed Dragon before! select another monster!" << std::endl;
        m_dragon->setHealth(m_dragon->getHealth() - m_player->getPower());
        if (m_dragon->isLive())
            std::cout << "You just attacked Dragon! it's health is: " << m_dragon->getHealth() << std::endl;
        else
            std::cout << "Bravo!!, You killed Dragon!" << std::endl;
    }
    else if (type == MonsterType::ORC) {
        if (!m_orc->isLive())
            std::cout << "You killed Orc before! select another monster!" << std::endl;
        m_orc->setHealth(m_orc->getHealth() - m_player->getPower());
        if (m_orc->isLive())
            std::cout << "You just attacked Orc! it's health is: " << m_orc->getHealth() << std::endl;
        else
            std::cout << "Bravo!!, You killed Orc!" << std::endl;
    }
    else {
        std::cout << "Your select is not here!" << std::endl;
    }
    if (!m_orc->isLive() && !m_dragon->isLive()) {
        m_player->finish();
        std::cout << "Excellent!!, You won!" << std::endl;
    }

}


