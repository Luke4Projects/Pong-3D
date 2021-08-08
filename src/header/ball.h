#ifndef PONG_BALL_H
#define PONG_BALL_H

#include <glm/glm.hpp>
#include "header/paddle.h"

class Ball {
public:
    glm::vec3 pos;
    float xSpeed,zSpeed;
    void reset();
    void render(unsigned int shader);
    void update(float deltaTime, Paddle p1, Paddle p2);
};

#endif