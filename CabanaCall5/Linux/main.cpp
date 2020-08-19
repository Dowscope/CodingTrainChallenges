/* Cabana Challenge #5
 * Marching Squares
 * Created By Tim Dowling
 * Date: Aug 16, 2020
 */

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <time.h>
#include "Screen.h"

// Declare Functions
void update();
void render();
void initializeGame();

// Declare the width and height that the window will be.
const int WINDOW_WIDTH = 1000;
const int WINDOW_HEIGHT = 800;

// Declare the resolution between points
const int RESOLUTION = 20;

// Declare the Screen object.
Screen *screen;

// Declare Global Variables
int *points;     // Container of points

int main(int argc, char const *argv[])
{
    // Initialize the randomizer
    srand(time(NULL));

    // Set the title of the project
    char title[] = "Cabana Callenge 5";

    // Initialize the screen
    screen = new Screen(WINDOW_WIDTH, WINDOW_HEIGHT, title);

    // Declare a switch for the main game loop
    bool isRunning = true;

    /* Setup game objects  */    
    initializeGame();

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
    delete points;
    screen->terminate();
    delete screen;

    std::cout << "Challenge Completed" << std::endl;
    return 0;
}

void update(){

}

void render() {
    // Calc columns and rows
    int cols = WINDOW_WIDTH / RESOLUTION;
    int rows = WINDOW_HEIGHT / RESOLUTION;

    // Render the points on the screen
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            screen->renderPoint(j * RESOLUTION, i * RESOLUTION, 4, points[j + i * rows]);
        }
    }
}

void initializeGame() {
    std::cout << "Initializing Game....";

    // Calc columns and rows
    int cols = WINDOW_WIDTH / RESOLUTION;
    int rows = WINDOW_HEIGHT / RESOLUTION;

    points = new int[cols*rows];

    // Randomize the points
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int x = rand() % 2;
            points[j+i*cols] = x;
        }
    }
    std::cout << "Completed" << std::endl;
}