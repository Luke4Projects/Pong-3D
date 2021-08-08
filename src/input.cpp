#include "header/game.h"
#include "header/input.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Called on window resize, the event is set in the setup() function in game.cpp
void resizeEvent(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);

    // Update the projection matrix so that objects aren't strected
    glm::mat4 proj = glm::perspective(glm::radians(45.f), (float)width/(float)height, 0.1f, 100.0f);
    glUniformMatrix4fv(glGetUniformLocation(game.shader, "proj"), 1, GL_FALSE, glm::value_ptr(proj));

    // Update the view matrix
    glm::mat4 view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0.f, -1.f, -5.f));
    view = glm::rotate(view, glm::radians(25.f), glm::vec3(1.f, 0.f, 0.f));
    view = glm::rotate(view, glm::radians(90.f), glm::vec3(0.f, 1.f, 0.f));
    glUniformMatrix4fv(glGetUniformLocation(game.shader, "view"), 1, GL_FALSE, glm::value_ptr(view));
}

// This is called every frame in main(). Put all code for doing keyboard input in here
void keyboardInput(GLFWwindow* window) {

    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        game.player.pos.z+=3*game.deltaTime;
    }
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        game.player.pos.z-=3*game.deltaTime;
    }

}
