#include "header/paddle.h"
#include <glad/glad.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>

// This draws the current paddle.
void Paddle::render(unsigned int shader) {

    glUseProgram(shader);
    
    // Translate the paddle to be rendered in the correct place and scale
    glm::mat4 model;
    model = glm::translate(model, this->pos);
    model = glm::scale(model, glm::vec3(1, 1, 2));
    glUniformMatrix4fv(glGetUniformLocation(shader, "model"), 1, GL_FALSE, glm::value_ptr(model));

    glDrawArrays(GL_TRIANGLES, 0, 36);

}