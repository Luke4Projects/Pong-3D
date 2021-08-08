#include <iostream>
#include "header/game.h"
#include "header/input.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Game game;

int main() {
    
    // Setup the game class
    if(game.setup() < 0) {
        return -1;
    }

    bool projSet = false;

    float lastCalledFrame = (float)glfwGetTime(); // used for getting delta time value

    // The main game loop
    while(!glfwWindowShouldClose(game.window)) {

        // Set the projection matrix if it hasn't been set yet
        if(!projSet) {
            // set the projection matrix
            glm::mat4 proj = glm::perspective(glm::radians(45.f), 1280.f/720.f, 0.1f, 100.0f);
            glUniformMatrix4fv(glGetUniformLocation(game.shader, "proj"), 1, GL_FALSE, glm::value_ptr(proj));
            // set the view matrix
            glm::mat4 view = glm::mat4(1.0f);
            view = glm::translate(view, glm::vec3(0.f, -1.f, -5.f));
            view = glm::rotate(view, glm::radians(25.f), glm::vec3(1.f, 0.f, 0.f));
            view = glm::rotate(view, glm::radians(90.f), glm::vec3(0.f, 1.f, 0.f));
            glUniformMatrix4fv(glGetUniformLocation(game.shader, "view"), 1, GL_FALSE, glm::value_ptr(view));

            projSet = false;
        }

        // get delta time
        float currentFrame = (float)glfwGetTime();
        game.deltaTime = currentFrame - lastCalledFrame;
        lastCalledFrame = currentFrame;

        // call functions
        keyboardInput(game.window);
        game.render();

        // Poll events and swap buffers
        glfwSwapBuffers(game.window);
        glfwPollEvents();
    }
    
    // Cleanup
    glfwTerminate();
    return 0;
}
