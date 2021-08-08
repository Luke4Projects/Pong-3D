#include "header/game.h"

// Renders everything for the game
// This should be called every frame in the main game loop
void Game::render() {

    // Clear the background black
    glClearColor(0.2f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Update the AI
    if(this->AI.pos.z < ball.pos.z) {
        this->AI.pos.z+=3*this->deltaTime;
    }
    if(this->AI.pos.z > ball.pos.z) {
        this->AI.pos.z-=3*this->deltaTime;
    }

    // render the player and Ai
    this->player.render(this->shader);
    this->AI.render(this->shader);

    // render and update the ball
    this->ball.update(this->deltaTime, this->player, this->AI);
    this->ball.render(this->shader);

}