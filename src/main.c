#include <stdio.h>
#include <SDL2/SDL.h>
#include "graphics.h"  // Assuming this header file contains declarations for initGraphics(), render(), and closeGraphics()
#include "player.h"

#define ACCELERATION 0.5
#define MAX_SPEED 10
#define FRICTION 0.95  // Friction to gradually slow down the player

int main(int argc, char* argv[]) {
    // Initialize SDL graphics
    if (initGraphics() != 0) {
        printf("Failed to initialize graphics.\n");
        return 1;
    }

    struct Player player;
    initPlayer(&player, 0, 0, 25, 50, 0, 0);

    // Main loop
    int running = 1;
    SDL_Event event;

    while (running) {
        // Process events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }

        // Get the current state of the keyboard
        const Uint8* state = SDL_GetKeyboardState(NULL);

        // Handle keyboard input with acceleration
        if (state[SDL_SCANCODE_W]) {
            player.vy -= ACCELERATION;  // Accelerate upwards
        }
        if (state[SDL_SCANCODE_S]) {
            player.vy += ACCELERATION;  // Accelerate downwards
        }
        if (state[SDL_SCANCODE_D]) {
            player.vx += ACCELERATION;  // Accelerate to the right
        }
        if (state[SDL_SCANCODE_A]) {
            player.vx -= ACCELERATION;  // Accelerate to the left
        }

        // Apply friction to gradually slow down the player
        player.vx *= FRICTION;
        player.vy *= FRICTION;

        // Apply speed limits
        if (player.vx > MAX_SPEED) player.vx = MAX_SPEED;
        if (player.vx < -MAX_SPEED) player.vx = -MAX_SPEED;
        if (player.vy > MAX_SPEED) player.vy = MAX_SPEED;
        if (player.vy < -MAX_SPEED) player.vy = -MAX_SPEED;

        // Update player position
        player.x += player.vx;
        player.y += player.vy;

        // Render graphics
        render(player);

        // Delay to control frame rate (e.g., 60 FPS)
        SDL_Delay(16);
    }

    // Clean up and close graphics
    closeGraphics();

    return 0;
}
