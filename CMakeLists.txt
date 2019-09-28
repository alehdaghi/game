cmake_minimum_required(VERSION 3.10)
project(game)

include_directories("include")
set(CMAKE_CXX_STANDARD 14)
find_package(Boost REQUIRED COMPONENTS serialization system )

add_executable(game main.cpp TEST.cpp src/objects/GameObject.cpp include/objects/GameObject.h src/objects/Player.cpp include/objects/Player.h src/objects/Orc.cpp include/objects/Orc.h src/objects/Dragon.cpp include/objects/Dragon.h include/utility/ISingleton.hpp src/objects/ObjectFactory.cpp include/objects/ObjectFactory.h src/objects/Board.cpp include/objects/Board.h)
target_link_libraries(game
        pthread
        ${Boost_LIBRARIES}
        )