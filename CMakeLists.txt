cmake_minimum_required(VERSION 4.1)

project(afkBO6 VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(afkBO6
        src/main.cpp
        src/TUI.cpp
        src/Utils.cpp
        src/Movement.cpp
        src/Script.cpp
        include/Script.h
)

target_include_directories(afkBO6 PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(afkBO6 PRIVATE user32)
