/* Coding Challenge #1
 * Starfield
 * Created By Tim Dowling
 * Date: Dec 5, 2018
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

    std::cout << screen->didInitialize << std::endl;

    std::cout << "Starfield Completed" << std::endl;
    return 0;
}
