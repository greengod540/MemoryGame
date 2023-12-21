#pragma once
#include <SDL.h>
#include <iostream>
#include <filesystem>

class TextureLoader {
public:
    SDL_Texture* CreateTexture(std::string imagePathBMP, SDL_Renderer* renderer);
};
