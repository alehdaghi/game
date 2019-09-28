#include <iostream>
#include <objects/Board.h>

int main() {
    Game::Object::Board& b = Game::Object::Board::getInstance();
    b.initialize("Mahdi");
    b.start();
    b.join();
    return 0;
}