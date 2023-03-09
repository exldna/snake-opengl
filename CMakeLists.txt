cmake_minimum_required(VERSION 3.14)
project(snake CXX)

set(SNAKE_SOURCES
    main.cpp
    glfw_system.hpp
    glfw_system.cpp
    window.hpp
    window.cpp
    )

add_executable(snake ${SNAKE_SOURCES})
target_compile_features(snake PUBLIC cxx_std_20)
target_include_directories(snake PUBLIC .)

find_package(glfw3 REQUIRED)
target_link_libraries(snake glfw)

find_package(glad REQUIRED)
target_link_libraries(snake glad)

find_package(OpenGL REQUIRED)
target_link_libraries(snake OpenGL::GL)

find_package(glm REQUIRED)
target_link_libraries(snake glm::glm)