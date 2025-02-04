#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>

class Screen {
    private:
        // Screen has 160 x 144 resolution
        // Map has 256 x 256 resolution
        uint8_t map[256][256]; // Light -> Dark | 1, 2, 3 | 0 is transparent
        uint8_t sprites;

    public:
        // Default constructor
        Screen() {
            for(int i = 0; i < 256; i++) {
                for(int j = 0; j < 256; j++) {
                    map[i][j] = 1;
                }
            }
        }

        // Parameterized constructor
        Screen(int map[256][256]) {
            setMap(map);
        }

        // Getter
        unit8_t (&getMap())[256][256] {
            return map;
        }

        // Setter
        void setMap(int map[256][256]) {
            for(int i = 0; i < 256; i++) {
                for(int j = 0; j < 256; j++) {
                    this -> map[i][j] = map[i][j];
                }
            }
        }

        // toString function
        std::string toString(Screen aS) {
            std::string out = "";
            for(int i = 0; i < 256; i++) {
                for(int j = 0; j < 256; j++) {
                    out += aS.getMap()[i][j];
                }
                out += "\n";
            }
            return out;
        }

        // Draw the pixels to the screen
        void DrawFrame(SDL_Renderer* renderer) {
            // Drawing screen, not map
            for(int i = 0; i < 160; i++) {
                for(int j = 0; j < 144; j++) {
                    int pixelVal = 255 / getMap()[i][j];
                    SDL_SetRenderDrawColor(renderer, pixelVal, pixelVal, pixelVal, 255);
                    SDL_RenderDrawPoint(renderer, i, j);
                }
            }
            SDL_RenderPresent(renderer);
        }
};