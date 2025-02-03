#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>

class Screen {
    private:
        // Screen has 160 x 144 resolution
        int pixels[160][144]; // Light -> Dark | 1, 2, 3 | 0 is transparent

    public:
        // Default constructor
        Screen() {
            for(int i = 0; i < 160; i++) {
                for(int j = 0; j < 144; j++) {
                    pixels[i][j] = 1;
                }
            }
        }

        // Parameterized constructor
        Screen(int pixels[160][144]) {
            setPixels(pixels);
        }

        // Getter
        int (&getPixels())[160][144] {
            return pixels;
        }

        // Setter
        void setPixels(int pixels[160][144]) {
            for(int i = 0; i < 160; i++) {
                for(int j = 0; j < 144; j++) {
                    this -> pixels[i][j] = pixels[i][j];
                }
            }
        }

        // toString function
        std::string toString(Screen aS) {
            std::string out = "";
            for(int i = 0; i < 160; i++) {
                for(int j = 0; j < 144; j++) {
                    out += aS.getPixels()[i][j];
                }
                out += "\n";
            }
            return out;
        }

        // Draw the pixels to the screen
        void DrawFrame(SDL_Renderer* renderer) {
            for(int i = 0; i < 160; i++) {
                for(int j = 0; j < 144; j++) {
                    int pixelVal = 255 / getPixels()[i][j];
                    SDL_SetRenderDrawColor(renderer, pixelVal, pixelVal, pixelVal, 255);
                    SDL_RenderDrawPoint(renderer, i, j);
                }
            }
            SDL_RenderPresent(renderer);
        }
};