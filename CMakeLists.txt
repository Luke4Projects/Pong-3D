cmake_minimum_required(VERSION 3.0.0)
project(Pong VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories("libraries/include")
link_directories("libraries/lib")

add_executable(Pong 
libraries/lib/glad.c

src/main.cpp
src/game.cpp src/header/game.h
src/render.cpp
src/header/shaders.h src/shaders.cpp
src/header/paddle.h src/paddle.cpp
src/header/ball.h src/ball.cpp
src/header/input.h src/input.cpp

)
target_link_libraries(Pong glfw3.lib opengl32.lib)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
