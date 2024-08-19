#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "player.h"

int drawcube(int x, int y, int w, int h, int r, int g, int b);
int initGraphics();
int render(struct Player player);
void closeGraphics();

#endif
