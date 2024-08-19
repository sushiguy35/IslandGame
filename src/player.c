#include "player.h"
#include <stdio.h>

// Initialize the player with specified values
void initPlayer(struct Player* player, int x, int y, int width, int height, int vx, int vy) 
{
    player->x = x;
    player->y = y;
    player->width = width;
    player->height = height;
    player->vx = vx;
    player->vy = vy;
}
