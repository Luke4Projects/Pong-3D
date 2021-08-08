#ifndef PONG_PADDLE_H
#define PONG_PADDLE_H

#include <glm/glm.hpp>

class Paddle {
public:
    glm::vec3 pos;
    void render(unsigned int shader);
};

#endif