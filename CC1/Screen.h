#ifndef SCREEN_H
#define SCREEN_H

#include <SDL2/SDL.h>
#include <iostream>


class Screen
{
private:
    int _screenWidth, _screenHeight;
    char* _title;
    SDL_Window* mainWindow;
    SDL_Renderer* mainRenderer;

    bool _initialize();
public:
    Screen(int w, int h, char* aTitle);
    ~Screen();

    bool didInitialize = false;

    void clear();
    void present();
};

Screen::Screen(int w, int h, char* aTitle)
{
    this->_screenWidth = w;
    this->_screenHeight = h;
    this->_title = aTitle;

    didInitialize = _initialize();
}

Screen::~Screen()
{
}

bool Screen::_initialize()
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cout << "SCREEN_H: SDL did not initialize" << std::endl;
        return false;
    }

    // Create our game window
    mainWindow = SDL_CreateWindow(_title,
                                    SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED,
                                    _screenWidth,
                                    _screenHeight,
                                    0);
    if (mainWindow == NULL) {
        std::cout << "SCREEN_H: Window was not created" << std::endl;
        return false;
    }

    // Create our renderer
    mainRenderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED);
    if (mainRenderer == NULL) {
        std::cout << "SCREEN_H: Renderer was not created" << std::endl;
        return false;
    }
    return true;
}

// Function that will call the SDL function to clear the renderer
void Screen::clear() {
    SDL_SetRenderDrawColor(mainRenderer, 0, 0, 0, 255);
    SDL_RenderClear(mainRenderer);
}

// Function that will call the SDL function to present the renderer to the screen
void Screen::present() {
    SDL_RenderPresent(mainRenderer);
}

#endif