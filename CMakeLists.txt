cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)




include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(main main.cpp
        include/core/GameWindowManager.h
        src/core/GameWindowManager.cpp
        include/Event/EventManager.h
        src/Event/EventManager.cpp
        include/Core/GameLoop.h
        src/Core/GameLoop.cpp
        src/Gameplay/Ball.cpp
        include/Gameplay/Ball.h
        src/Gameplay/Paddle.cpp
        include/Gameplay/Paddle.h
        src/Gameplay/GameplayManager.cpp
        include/Gameplay/GameplayManager.h
        src/Gameplay/Boundary.cpp
        include/Gameplay/Boundary.h
        src/Utility/TimeService.cpp
        include/Utility/TimeService.h
        src/UI/UIService.cpp
        include/UI/UIService.h
)
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics)
set_target_properties(main PROPERTIES
        VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
)

target_compile_definitions(main PRIVATE
        PROJECT_ROOT="${CMAKE_SOURCE_DIR}"
)
