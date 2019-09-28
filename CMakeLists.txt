cmake_minimum_required(VERSION 3.10)
project(game)

include_directories("include")
set(CMAKE_CXX_STANDARD 14)
find_package(Boost REQUIRED COMPONENTS serialization system )

set(GAME_HEADERS
        include/objects/GameObject.h
        include/objects/Orc.h
        include/objects/Dragon.h
        include/utility/ISingleton.hpp
        include/objects/ObjectFactory.h
        include/objects/Board.h
        )

set(GAME_SOURCES
        main.cpp
        src/objects/GameObject.cpp
        src/objects/Player.cpp
        src/objects/Orc.cpp
        src/objects/Dragon.cpp
        src/objects/ObjectFactory.cpp
        src/objects/Board.cpp
    )

set(GAME_TEST
        TEST.cpp
    )


add_executable(game ${GAME_SOURCES})
target_link_libraries(game
        pthread
        ${Boost_LIBRARIES}
        )