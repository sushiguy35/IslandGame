#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>

// Structure representing a player
struct Player {
    int x, y;          // Position of the player
    int width, height; // Dimensions of the player
    int vx, vy;
};

// Function prototypes
void initPlayer(struct Player* player, int x, int y, int width, int height, int vx, int vy);

#endif
