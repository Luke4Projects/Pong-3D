#ifndef PONG_GAME_H
#define PONG_GAME_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "paddle.h"
#include "ball.h"

class Game {
public:
    GLFWwindow* window;

    unsigned int shader;
    unsigned int VAO;

    Paddle player,AI;
    float deltaTime;
    Ball ball;

    int setup();
    void render();
};

extern Game game; // this is the global game variable. This is declared near the top of main.cpp

#endif