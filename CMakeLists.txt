cmake_minimum_required(VERSION 3.28)
project(LearnSFML LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)
#src/Distribution.cpp src/Bucket.cpp src/Pop.cpp
add_executable(main src/Window.cpp src/Shape.cpp src/main.cpp  "src/Interaction.cpp" "src/physics.cpp" "src/Window.cpp" "src/Shape.cpp")
target_compile_features(main PRIVATE cxx_std_20)
target_link_libraries(main PRIVATE SFML::Graphics)
