#include "header/ball.h"
#include <glad/glad.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void Ball::reset() {
    this->pos = glm::vec3(5.f, 0.f, 0.f);
    this->zSpeed = 0.f;
    this->xSpeed = -2.f;
}

// This draws the ball
void Ball::render(unsigned int shader) {

    glUseProgram(shader);
    
    // Translate the paddle to be rendered in the correct place and scale
    glm::mat4 model;
    model = glm::translate(model, this->pos);
    model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));
    glUniformMatrix4fv(glGetUniformLocation(shader, "model"), 1, GL_FALSE, glm::value_ptr(model));

    glDrawArrays(GL_TRIANGLES, 0, 36);

}

// This updates the ball's position based on the ball's current speed values
// This also does collision for the ball
void Ball::update(float deltaTime, Paddle p1, Paddle p2) {

    // Move the ball
    this->pos.x += this->xSpeed*deltaTime;
    this->pos.z += this->zSpeed*deltaTime;

    // Collide the ball with paddles
    if(this->pos.x + 0.2 > p1.pos.x && this->pos.x < p1.pos.x + 1 && this->pos.z + 0.2 > p1.pos.z-1 && this->pos.z < p1.pos.z + 1) {
        this->xSpeed = 2;
        this->pos.x = p1.pos.x+0.9f;
        if(this->zSpeed == 0) {
            this->zSpeed = 1;
        }
    }
    if(this->pos.x + 0.2 > p2.pos.x && this->pos.x < p2.pos.x + 1 && this->pos.z + 0.2 > p2.pos.z-1 && this->pos.z < p2.pos.z + 1) {
        this->xSpeed = -2;
        this->pos.x = p2.pos.x-1.1f;
        if(this->zSpeed == 0) {
            this->zSpeed = 1;
        }
    }

    // Collide the ball with the walls
    if(this->pos.z > 5) {
        this->zSpeed = -1;
    }
    if(this->pos.z < -5) {
        this->zSpeed = 1;
    }

}