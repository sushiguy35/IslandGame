#include <SDL2/SDL.h>
#include <stdio.h>
#include "graphics.h"

static SDL_Window* window = NULL;
static SDL_Surface* screenSurface = NULL;
static SDL_Renderer* renderer = NULL;

int drawcube(int x, int y, int w, int h, int r, int g, int b)
{
    // Clear the renderer with the current drawing color
    SDL_RenderClear(renderer);

    // Define the rectangle
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;

    // Set the drawing color to white (R: 255, G: 255, B: 255, A: 255)
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);

    // Fill the rectangle with the current drawing color
    SDL_RenderFillRect(renderer, &rect);

    // Optionally, set the drawing color back to black (R: 0, G: 0, B: 0, A: 255) for other drawing operations
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    // Update the screen with any rendering performed since the previous call
    SDL_RenderPresent(renderer);

}

int initGraphics() 
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) 
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("Simple SDL2 Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    if (window == NULL) 
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        printf("ERROR WHILE CREATING RENDERER %s\n", SDL_GetError());
    }

    screenSurface = SDL_GetWindowSurface(window);
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
    SDL_UpdateWindowSurface(window);

    return 0;
}

int render(struct Player player) 
{
    // Draw the player as a cube with a specified color
    drawcube(player.x, player.y, player.width, player.height, 200, 50, 50);
}

void closeGraphics() 
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}
