/* Coding Challenge #1
 * Starfield
 * Created By Tim Dowling
 * Date: Dec 5, 2018
 */

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <time.h>
#include "../../Utilities/Screen.h"
#include "Star.h"

// Declare Functions
void update();
void render();

// Declare the width and height that the window will be.
const int WINDOW_WIDTH = 1000;
const int WINDOW_HEIGHT = 800;

// Declare the max number of stars to be created.
const int MAX_STARS = 100;

// Declare the Screen object.
Screen *screen;

// Create a vector container to hold all the stars.
std::vector<Star> stars;

int main(int argc, char const *argv[])
{
    // Initialize the randomizer
    srand(time(NULL));

    // Set the title of the project
    char title[] = "CC1";

    // Initialize the screen
    screen = new Screen(WINDOW_WIDTH, WINDOW_HEIGHT, title);

    // Declare a switch for the main game loop
    bool isRunning = true;

    /* Setup game objects  */

    // Initialize Stars
    for(int i = 0; i < MAX_STARS; i++)
    {
        int x = rand() % WINDOW_WIDTH;
        int y = rand() % WINDOW_HEIGHT;
        int z = rand() % WINDOW_WIDTH;

        Star s(x, y, z);
        stars.push_back(s);
    }
    

    // Main Game Loop
    std::cout << "Game Starting!" << std::endl;
    while (isRunning){
        SDL_Event e;
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                isRunning = false;
            }
        }

        update();

        screen->clear();
        render();
        screen->present();
    }

    std::cout << "Game Ended" << std::endl;
    screen->terminate();
    delete screen;

    std::cout << "Starfield Completed" << std::endl;
    return 0;
}

void update(){

}

void render() {
    
    for(auto s = stars.begin(); s != stars.end(); s++)
    {
        screen->renderStar(s->getX(), s->getY());
    }
    
}