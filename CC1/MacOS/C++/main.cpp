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
#include "Screen.h"
#include "Star.h"

// Declare Functions
void update();
void render();
int map(float value, int start1, int stop1, int start2, int stop2);

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
    char title[] = "Coding Challenge #1 - Starfield";

    // Initialize the screen
    screen = new Screen(WINDOW_WIDTH, WINDOW_HEIGHT, title);

    // Declare a switch for the main game loop
    bool isRunning = true;

    /* Setup game objects  */

    // Initialize Stars
    for(int i = 0; i < MAX_STARS; i++)
    {
        int x = rand() % (WINDOW_WIDTH + 1) + (-WINDOW_WIDTH / 2);
        int y = rand() % (WINDOW_HEIGHT + 1) + (-WINDOW_HEIGHT / 2);
        int z = rand() % (WINDOW_WIDTH + 1) + (-WINDOW_WIDTH / 2);

        Star s(x, y, z);
        stars.push_back(s);
    }
    
    // Create a last time reference.
    Uint32 timeout = SDL_GetTicks() + Uint32(4000/60);
    // Main Game Loop
    std::cout << "Game Starting!" << std::endl;
    while (isRunning){
        SDL_Event e;
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                isRunning = false;
            }
        }

        if ( SDL_TICKS_PASSED( SDL_GetTicks(), timeout ) ){
            update();

            screen->clear();
            render();
            screen->present();

            timeout = SDL_GetTicks() + Uint32(4000/60);
        }
    }

    std::cout << "Game Ended" << std::endl;
    screen->terminate();
    delete screen;

    std::cout << "Starfield Completed" << std::endl;
    return 0;
}

void update(){
    
    for(auto s = stars.begin(); s != stars.end(); s++)
    {
        s->update();

        int x = s->getX();
        int y = s->getY();
        int z = s->getZ();

        x = map( float(x) / float(z), 1, 0, -WINDOW_WIDTH/2, WINDOW_WIDTH/2);
        y = map( float(y) / float(z), 1, 0, -WINDOW_HEIGHT/2, WINDOW_HEIGHT/2);

        s->setX(x);
        s->setY(y);
    }
}

void render() {
    
    for(auto s = stars.begin(); s != stars.end(); s++)
    {
        screen->renderStar(s->getX(), s->getY());
    }
    
}

// Helper Functions
int map(float value, int start1, int stop1, int start2, int stop2){
    float out = float(start2) + (float(stop2) - float(start2)) *
                ((value - float(start1)) / (float(stop1) - float(start1)));
    
    return int(out);
}