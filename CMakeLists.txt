cmake_minimum_required(VERSION 3.14)
project(snake CXX)

set(
    SNAKE_SOURCES
    main.cpp
    game.hpp game.cpp
    board.hpp board.cpp
    snake.hpp snake.cpp
    snake_controller.hpp snake_controller.cpp
    glfw_system.hpp glfw_system.cpp
    window.hpp window.cpp
    virtual_keys.hpp
    keys_input.hpp keys_input.cpp
    make_program.cpp make_program.hpp
    runtime.cpp runtime.hpp renderer.cpp renderer.hpp snake_renderer.cpp snake_renderer.hpp)

add_executable(snake ${SNAKE_SOURCES})
target_include_directories(snake PUBLIC .)
target_compile_features(snake PUBLIC cxx_std_20)

add_custom_target(
    copy_shaders
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/shaders
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/shaders ${CMAKE_CURRENT_BINARY_DIR}/shaders
    COMMENT "copying ${CMAKE_CURRENT_SOURCE_DIR}/shaders to ${CMAKE_CURRENT_BINARY_DIR}/shaders"
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

add_dependencies(snake copy_shaders)

find_package(glfw3 REQUIRED)
target_link_libraries(snake glfw)

find_package(glad REQUIRED)
target_link_libraries(snake glad::glad)

find_package(OpenGL REQUIRED)
target_link_libraries(snake OpenGL::GL)

find_package(glm REQUIRED)
target_link_libraries(snake glm::glm)