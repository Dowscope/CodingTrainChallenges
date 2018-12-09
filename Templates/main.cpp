/* Coding Challenge
 * Name of Challenge: 
 * Created By Tim Dowling
 * Date: Dec 8, 2018
 */

#include <iostream>
#include <SDL2/SDL.h>
#include "Screen.h"

// Declare the width and height that the window will be.
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

// Declare the Screen object.
Screen *screen;

int main(int argc, char const *argv[])
{
    // Set the title of the project
    char title[] = "CC1";

    // Initialize the screen
    screen = new Screen(WINDOW_WIDTH, WINDOW_HEIGHT, title);

    // Declare a switch for the main game loop
    bool isRunning = true;

    // Main Game Loop
    std::cout << "Game Starting!" << std::endl;
    while (isRunning){
        SDL_Event e;
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                isRunning = false;
            }
        }
    }

    std::cout << "Game Ended" << std::endl;
    screen->terminate();
    delete screen;

    std::cout << "Starfield Completed" << std::endl;
    return 0;
}
