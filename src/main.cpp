#include <SDL2/SDL.h>
#include "screen.h"
#include <iostream>
#include <random>

// Const framerate values
const int TARGET_FPS = 60;
const int FRAME_DELAY = 1000 / TARGET_FPS;

int main(int argc, char* argv[]) {
    // Initialize SDL2
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create an SDL Window
    SDL_Window* window = SDL_CreateWindow(
        "Game Boy Emulator Window", 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        640, 480, 
        SDL_WINDOW_SHOWN
    );

    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create an SDL Renderer for drawing
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Framerate timing variables
    Uint32 frameStart;
    int frameTime;

    // Main event loop
    bool running = true;
    SDL_Event event;

    while (running) {
        frameStart = SDL_GetTicks(); // Current time in ms

        // Handle events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 4);

        // Test animation
        int pixels[160][144];
        for(int i = 0; i < 160; i++) {
            for(int j = 0; j < 144; j++) {
                pixels[i][j] = dis(gen);
            }
        }

        // Create the Gameboy Screen
        Screen screen = Screen(pixels);

        // Display one frame
        screen.DrawFrame(renderer);

        // Wait for framerate timing
        frameTime = SDL_GetTicks() - frameStart;
        if(FRAME_DELAY > frameTime) {
            SDL_Delay(FRAME_DELAY - frameTime);
        }
    }

    // Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}